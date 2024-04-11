#include <Servo.h>
#include <WiFi.h>
#include <Stepper.h>
#include <PubSubClient.h>
#include "driver/gpio.h"

// LED
#define BLUE_LED 2

// Reaction Wheels
#define ESC1 13
#define ESC2 12
#define ESC3 14
#define stopSpeed 1500

// Relays
#define RELAY1 27
#define RELAY2 15

// Steppers
#define STEPS_REVOLUTION 2048
#define STEPPER_SPEED 5

// Define pins for stepper motors
#define STP1_STEP 21
#define STP1_DIR 19
#define STP1_MS1 18
#define STP1_MS2 5

#define STP2_STEP 22
#define STP2_DIR 23
#define STP2_MS1 34
#define STP2_MS2 35

#define STP3_STEP 32
#define STP3_DIR 33
#define STP3_MS1 25
#define STP3_MS2 26

//Stepper stepper1 = Stepper(STEPS_REVOLUTION,STP1_STEP,STP1_DIR,STP1_MS1,STP1_MS2);
//Stepper stepper2 = Stepper(STEPS_REVOLUTION,STP2_STEP,STP2_DIR,STP2_MS1,STP2_MS2);
//Stepper stepper3 = Stepper(STEPS_REVOLUTION,STP3_STEP,STP3_DIR,STP3_MS1,STP3_MS2);

// Motors
Servo motor1;
Servo motor2;
Servo motor3;

// Defining the Wi-Fi host
const char* ssid     = "COSMOS";
const char* password = "cosmos123";
const int serverPort = 80;
WiFiServer server(serverPort);
WiFiClient wifiClient;

void app_main() 
{
    gpio_config_t io_conf;
    io_conf.mode = GPIO_MODE_OUTPUT;

    // Disable pull-up and pull-down
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;

    io_conf.pin_bit_mask = (1ULL << 2);
    gpio_config(&io_conf);

    // Configure all GPIO pins as outputs
    for (int i = 12; i < 36; i++) 
    {
        io_conf.pin_bit_mask = (1ULL << i);
        gpio_config(&io_conf);
    }
}

void setup() 
{
  Serial.begin(115200);
  delay(1000); // Wait for serial port to initialize
  Serial.setDebugOutput(false); // Disable debug output
  // Setting pins as output
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RELAY1,OUTPUT);
  pinMode(RELAY2,OUTPUT);

  pinMode(BLUE_LED, LOW);
  
  // Setting up the Brushless motors
  motor1.attach(ESC1);
  motor1.writeMicroseconds(1500);
  motor2.attach(ESC2);
  motor2.writeMicroseconds(stopSpeed);
  motor3.attach(ESC3);
  motor3.writeMicroseconds(stopSpeed);
  delay(3000);
  
  // Setting up the Stepper motors
  //stepper1.setSpeed(STEPPER_SPEED);
  //stepper2.setSpeed(STEPPER_SPEED);
  //stepper3.setSpeed(STEPPER_SPEED);

  // Set up the ESP32 as an access point
  WiFi.softAP(ssid, password);

  Serial.println("Access Point started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  // Start the server
  server.begin();
  Serial.println("Server started"); 
}

void loop() 
{ 
  WiFiClient client = server.available();

  if (client)
  {
    String currentLine = "";
    while (client.connected())
    {
      if (client.available())
      {             
        char c = client.read();             
        if (c == '*')
        {   
          processMessage(currentLine);                
          currentLine = "";
        }
        currentLine += c;
      }
    }
    client.stop();
  }
  
  if (Serial.available() > 0) 
  {
    String serialInput = Serial.readStringUntil('\n');
    //Serial.println(serialInput);
    performTask(serialInput);
  }
}

void processMessage(const String& message) 
{
  Serial.println(message);
}

void performTask(String command)
{
  int motorX, motorY, motorZ;
  int speedX, speedY, speedZ;
  int timeX, timeY, timeZ;

  if (sscanf(command.c_str(), "%d,%d,%d,%d,%d,%d,%d,%d,%d",
                                  &motorX,&motorY,&motorZ,
                                  &speedX,&speedY,&speedZ,
                                  &timeX, &timeY, &timeZ) == 9) 
  {
    int caseNumber = motorX * 1 + motorY * 2 + motorZ * 4;
    switch (caseNumber)
    {
      case 1:
          motor1spin(speedX);
          digitalWrite(BLUE_LED, HIGH);
          delay(timeX);
          digitalWrite(BLUE_LED, LOW);
          motor1off();
        break;

      case 2:
          motor2spin(speedY);
          digitalWrite(BLUE_LED, HIGH);
          delay(timeY);
          digitalWrite(BLUE_LED, LOW);
          motor2off();
        break;

      case 3:
          motor1spin(speedX);
          motor2spin(speedY);
          digitalWrite(BLUE_LED, HIGH);
          delay(timeX);
          digitalWrite(BLUE_LED, LOW);
          motor1off();
          motor2off();
        break;

      case 4:
          motor3spin(speedZ);
          digitalWrite(BLUE_LED, HIGH);
          delay(timeZ);
          digitalWrite(BLUE_LED, LOW);
          motor3off();
        break;

      default:
        Serial.println("Unknown case number");
        break;
    }
  }
}

void motor1spin(int mspeed) 
{
  // Motor1 On
  motor1.writeMicroseconds(mspeed);
}

void motor1off()
{
  // Motor1 Off
  motor1.writeMicroseconds(stopSpeed);
}

void motor2spin(int mspeed) 
{
  // Motor2 On
  motor2.writeMicroseconds(mspeed);
}

void motor2off()
{
  // Motor2 Off
  motor2.writeMicroseconds(stopSpeed);
}

void motor3spin(int mspeed) 
{
  // MotorZ On
  motor3.writeMicroseconds(mspeed); 
}

void motor3off()
{
  // MotorZ Off
  motor3.writeMicroseconds(stopSpeed);
}

//void stepper1spin(int steps)
//{
//  stepper1.step(steps);
//}
//
//void stepper2spin(int steps)
//{
//  stepper2.step(steps);
//}
//
//void stepper3spin(int steps)
//{
//  stepper3.step(steps);
//}