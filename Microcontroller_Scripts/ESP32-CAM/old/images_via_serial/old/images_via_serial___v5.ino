#include "esp_camera.h"

#define CAMERA_MODEL_AI_THINKER
#include "camera_pins.h"

void setup() {
  Serial.begin(115200);
  // Serial.setDebugOutput(true);
  // Serial.println();

  camera_config_t config;
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
  config.pixel_format = PIXFORMAT_JPEG;
  // config.pixel_format = PIXFORMAT_GRAYSCALE;
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;
  // config.fb_location = CAMERA_FB_IN_PSRAM;
  config.jpeg_quality = 12;
  config.fb_count = 1;

#if CONFIG_IDF_TARGET_ESP32S3
    config.fb_count = 2;
#endif

  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

  sensor_t * s = esp_camera_sensor_get();
}

void loop() {
  
  if (Serial.available()) {
    char command = Serial.read();
    if (command == 'C') {
      // Capture an image
      camera_fb_t *fb = NULL;
      fb = esp_camera_fb_get();
      
      if (fb) {

        int jpegDataSize = sizeof(fb->buf); // 4, for JPEG
        Serial.write(fb->buf, jpegDataSize); // (jpegData, jpegDataSize);
        

        // // Print length and width to confirm size of image (and skip lines)
        // Serial.println(fb->len); // 1920000 if Grayscale (for uncompressed 1200x1600)
        // Serial.println(fb->width); // 1600
        // Serial.println();
        
        // int rows = fb->len / fb->width; // 1200
        // // Iterate over the pixel array rows
        // for (int m = 0; m < rows; m++) {
        
        //   // // Send the pixel value as text to the Serial monitor
        //   // Serial.print((uint8_t)fb->buf[i]);
        //   // Serial.print(" ");
          
        //   Serial.print(m);
        //   Serial.print(" ");
        // }

        // Return the frame buffer to the camera library
        esp_camera_fb_return(fb);
      } else {
        Serial.println("Camera capture failed");
      }
    }
  }
}