#include "esp_camera.h"

#define CAMERA_MODEL_AI_THINKER // Has PSRAM
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
  // config.pixel_format = PIXFORMAT_JPEG; // for streaming
  // config.pixel_format = PIXFORMAT_RGB565; // for face detection/recognition
  config.pixel_format = PIXFORMAT_GRAYSCALE; // via ChatGPT
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;
  config.fb_location = CAMERA_FB_IN_PSRAM;
  config.jpeg_quality = 12;
  config.fb_count = 1;

  // if PSRAM IC present, init with UXGA resolution and higher JPEG quality
  //                      for larger pre-allocated frame buffer.
  if(config.pixel_format == PIXFORMAT_JPEG){
    if(psramFound()){
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
#if CONFIG_IDF_TARGET_ESP32S3
    config.fb_count = 2;
#endif
  }

  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

  sensor_t * s = esp_camera_sensor_get();
  // initial sensors are flipped vertically and colors are a bit saturated
  if (s->id.PID == OV3660_PID) {
    s->set_vflip(s, 1); // flip it back
    s->set_brightness(s, 1); // up the brightness just a bit
    s->set_saturation(s, -2); // lower the saturation
  }
  // drop down frame size for higher initial frame rate
  if(config.pixel_format == PIXFORMAT_JPEG){
    s->set_framesize(s, FRAMESIZE_QVGA);
  }
}

void loop() {
  
  if (Serial.available()) {
    char command = Serial.read();
    if (command == 'C') {
      // Capture an image
      camera_fb_t *fb = NULL;
      fb = esp_camera_fb_get();
      // Serial.println("fb got");
      
      if (fb) {
        
        // Serial.println("yes fb");
        
        // Send the image size as a header
        // Serial.write((const uint8_t *)"IMAGE_START", 11);
        // Serial.write((uint8_t *)&fb->len, sizeof(uint32_t));

        // Send the image data
        // Serial.write(fb->buf, fb->len);
        // Serial.println(fb->len); // fb-buf failed

        // Serial.write(fb->buf, fb->len); // successfully prints as weird images
        // Serial.write((uint8_t *)&fb->len, sizeof(uint32_t));
        // Serial.write((uint8_t *)&fb->buf, sizeof(uint32_t));



        // Serial.write(fb->buf, fb->len);



      // Iterate over the pixel data
      for (int i = 0; i < fb->len; i++) {
        // Send the pixel value as text to the Serial monitor
        Serial.print((uint8_t)fb->buf[i]);
        Serial.print(" ");
        
        // Optionally, add line breaks for readability
        if ((i + 1) % fb->width == 0) {
          Serial.println();
        }
      }





       
        // Serial.write(fb->buf);

        // Send a footer to indicate the end of the image
        // Serial.write((const uint8_t *)"IMAGE_END", 9);

        // Return the frame buffer to the camera library
        esp_camera_fb_return(fb);
      } else {
        Serial.println("Camera capture failed");
      }
    }
  }
}