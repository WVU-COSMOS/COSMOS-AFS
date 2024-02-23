#include "esp_camera.h"

#define CAMERA_MODEL_WROVER_KIT
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
  // config.pixel_format = PIXFORMAT_RGB565; // PIXFORMAT_BMP, PIXFORMAT_RGB565 (not listed on esp32-cam docs, but is on ov2640), PIXFORMAT_JPEG
  config.pixel_format = PIXFORMAT_JPEG;
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
    
    char command = Serial.read();
    if (command == 'C') {

      camera_fb_t *fb = NULL;
      fb = esp_camera_fb_get(); // capture image

      if (fb) {
       
        // Send the length of the image data over Serial
        uint16_t fb_length = fb->len;
        // Serial.write((uint8_t*)&fb_length, sizeof(uint16_t));
        Serial.write((uint8_t*)&fb_length, sizeof(fb_length));
        uint16_t fb_width = fb->width;
        Serial.write((uint8_t*)&fb_width, sizeof(fb_width));
        
        // Send the image data over Serial
        Serial.write((uint8_t*)fb->buf, fb->len);

        esp_camera_fb_return(fb);

      } else {

        Serial.println("Camera capture failed");

      }
    }
  }
}