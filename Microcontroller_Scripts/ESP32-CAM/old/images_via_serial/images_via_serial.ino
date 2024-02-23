#include "esp_camera.h"

#define CAMERA_MODEL_AI_THINKER
#include "camera_pins.h"

void setup() {
  Serial.begin(115200, SERIAL_8N1);

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
  config.pixel_format = PIXFORMAT_RGB565; // PIXFORMAT_BMP, PIXFORMAT_RGB565 (not listed on esp32-cam docs, but is on ov2640), PIXFORMAT_JPEG
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;
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
    
    // char iter = '.';
    // Serial.write(iter); // constant stream just for debugging receive side (i.e., python)
    // delay(1000);
    
    char command = Serial.read();
    if (command == 'C') {
      
      // Serial.write(command); // send command back to confirm it was received

      camera_fb_t *im = NULL;
      im = esp_camera_fb_get(); // capture image
      
      if (im) {

        // Send image data:
        int imSize = sizeof(im->buf); // 4, for JPEG
        // Serial.write(im->buf, imSize); // (imData, imSize);
        
        Serial.write(imSize);
        Serial.write((uint8_t *)im->buf, imSize * 2); // * 2 because each pixel is 2 bytes
        
        // Return the frame buffer to the camera library
        esp_camera_fb_return(im);
      
      } else {
        Serial.println("Camera capture failed");
        
      }
    }
  }
}