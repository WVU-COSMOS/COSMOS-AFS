//// Development Information
// COSMOS-AFS
// 
// ESP32 Wrover code to capture single image when prompted via serial.
// 
// 
// Primary Developer Contact Information:
// Jacob P. Krell (JPK)
// Aerospace Engineering Undergraduate Student
// Statler College of Engineering & Mineral Resources
// Dept. Mechanical and Aerospace Engineering
// West Virginia University (WVU)
// jpk0024@mix.wvu.edu
//
//
//
// Development History
// Date              Developer        Comments
// ---------------   -------------    --------------------------------
// Nov. 27, 2023     JPK              'fb_length' is incorrect
//
////


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
  config.jpeg_quality = 63; // Quality of JPEG output. 0-63 lower means higher quality
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
       
        // 1024 = sizeof(fb->buf)
        // 256 = sizeof(fb->buf[0]) = sizeof(fb->buf[1]) = ... = sizeof(fb->buf[n])
        
        // Send number of bytes in image (using two bytes)
        // uint16_t fb_length = fb->len; // ATTEMPT 1 (FAILED):
        // uint16_t fb_length = sizeof((uint8_t*)fb->buf, fb->len); // = 1024, ATTEMPT 2 (FAILED):
        // uint16_t fb_length = fb->len * sizeof(uint8_t); // ATTEMPT 3 (FAILED):
        // Serial.write((uint8_t*)&fb_length, 2);

        // uint32_t fb_length = fb->len * sizeof(uint8_t); // ATTEMPT 4 (FAILED ... way too large):
        // Serial.write((uint8_t*)&fb_length, 4);
        
        // uint8_t l1 = fb->len; // ATTEMPT 5 (FAILED)
        // Serial.print("l1: ");
        // Serial.println(l1);
        // Serial.write((uint8_t*)&l1, 1);

        // uint16_t width = fb->width; // ATTEMPT 6 (FAILED ... adding got close but did not work)
        // uint16_t height = fb->height;
        // uint16_t len = fb->len;
        // Serial.write((uint8_t*)&width, 2);
        // Serial.write((uint8_t*)&height, 2);
        // Serial.write((uint8_t*)&len, 2);

        // FROM esp_camera.h
        // len ...... Length of the buffer in bytes
        // width .... Width of the buffer in pixels
        // height ... Height of the buffer in pixels

        // size_t len = fb->len;
        // Serial.write((uint8_t*)&len, 2);

        // Serial.println(sizeof(int)); // = 4

        // Serial.write((uint8_t*)&fb->len, 4); // ATTEMPT 7 (FAILED)

        // uint32_t l1 = fb->len; // ATTEMPT 8 (FAILED)
        // Serial.write((uint8_t*)&l1, 4);
  
        // Serial.write(fb->len); // ATTEMPT 9 (FAILED)
        
        // Serial.write((uint8_t*)fb->len, 2); // ATTEMPT 10 (FAILED)

        // Serial.write(fb->width & 0xFF); // = b'@\06' = 16390; ATTEMPT 11, to get width of pixels to know if size_t is uint16_t, etc
        // Serial.write(fb->width >> 8);
        // Serial.write(fb->height & 0xFF); // = b'xb0\x04' = 45060; ATTEMPT 11, to get height of pixels
        // Serial.write(fb->height >> 8);

        // SUMMARY OF ATTEMPTS TO SEND LENGTH:
        //  - could not get correct length from ESP32, so instead using 'ser.inWaiting()' in Python



        // Send image
        Serial.write((uint8_t*)fb->buf, fb->len);

        esp_camera_fb_return(fb);

      } else {

        Serial.println("Camera capture failed");

      }
    }
  }
}