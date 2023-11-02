#include "esp_camera.h"
// "C:\Users\jakep\AppData\Local\Arduino15\packages\esp32\hardware\esp32\2.0.14\tools\sdk\esp32\include\esp32-camera\driver\include\esp_camera.h"

#define CAMERA_MODEL_AI_THINKER // Has PSRAM
#include "camera_pins.h"

// Define the baud rate for serial communication
#define SERIAL_BAUD_RATE 115200

camera_config_t config;

void setup() {
  // Initialize serial communication
  Serial.begin(SERIAL_BAUD_RATE);
  Serial.setDebugOutput(true);
  Serial.println();

  // Configure the camera settings
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sccb_sda = SIOD_GPIO_NUM;
  config.pin_sccb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.frame_size = FRAMESIZE_UXGA;
  config.pixel_format = PIXFORMAT_JPEG; // for streaming
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;
  config.fb_location = CAMERA_FB_IN_PSRAM;
  config.jpeg_quality = 12;
  config.fb_count = 1;
  
  // if PSRAM IC present, init with UXGA resolution and higher JPEG quality
  //                      for larger pre-allocated frame buffer.
  if (config.pixel_format == PIXFORMAT_JPEG) {
    if (psramFound()) {
      config.jpeg_quality = 10;
      config.fb_count = 2;
      config.grab_mode = CAMERA_GRAB_LATEST;
    } else {
      // Limit the frame size when PSRAM is not available
      config.frame_size = FRAMESIZE_SVGA;
      config.fb_location = CAMERA_FB_IN_DRAM;
    }
  } else {
    // Best option for face detection/recognition
    config.frame_size = FRAMESIZE_240X240;
  }

  // Initialize the camera module
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }
}

void loop() {
  
  camera_fb_t *fb = NULL;
  fb = esp_camera_fb_get();

  if (fb) {
    // Print image size
    Serial.printf("Sending image size: %u bytes\n", fb->len);

    // Send the image data length as a header
    Serial.write((const uint8_t *)"IMAGE_START", 11);  // Header to indicate the start of an image
    Serial.write((uint8_t *)&fb->len, sizeof(uint32_t)); // Send the image size as a 4-byte integer

    // Send the image data
    Serial.write((uint8_t *)fb->buf, fb->len);

    // Send a footer to indicate the end of the image
    Serial.write((const uint8_t *)"IMAGE_END", 9);

    // Return the frame buffer to the camera library
    esp_camera_fb_return(fb);
  } else {
    Serial.println("Camera capture failed");
  }

  
  
  
  

  
  // if (fb) {  
  //   // Print image size and send the image data via serial
  //   Serial.printf("Sending image size: %u bytes\n", fb->len);
  //   Serial.write((uint8_t *)fb->buf, fb->len);

  //   // Return the frame buffer to the camera library
  //   esp_camera_fb_return(fb);
  // } else {  
  //   Serial.println("Camera capture failed");
  //   Serial.write("test");
  // }



  
  delay(10000);  // Adjust the delay as needed between image captures
}

