#include <WiFi.h>
#include <PubSubClient.h>

// Defining the Wi-Fi host
const char* ssid     = "COSMOS";
const char* password = "123456789";
const int serverPort = 80;

// Defining Constants
const int ENAX_PIN = 19; // Connected to the ENAX pin L298N
const int X1_PIN = 18; // Connected to the X1 pin L298N
const int X2_PIN = 21; // Connected to the X2 pin L298N

const int ENAY_PIN = 15; // Connected to the ENAY pin L298N
const int Y1_PIN = 13; // Connected to the Y1 pin L298N
const int Y2_PIN = 12; // Connected to the Y2 pin L298N

const int ENAZ_PIN = 14; // Connected to the ENAZ pin L298N
const int Z1_PIN = 27; // Connected to the Z1 pin L298N
const int Z2_PIN = 26; // Connected to the Z2 pin L298N

const int ENAW_PIN = 32; // Connected to the ENAW pin L298N
const int W1_PIN = 33; // Connected to the W1 pin L298N
const int W2_PIN = 25; // Connected to the W2 pin L298N

// Iniciating Objects
WiFiServer server(serverPort);
WiFiClient wifiClient;

// Setup Function
void setup() 
{
  Serial.begin(115200);

  pinMode(ENAX_PIN, OUTPUT);
  pinMode(X1_PIN, OUTPUT);
  pinMode(X2_PIN, OUTPUT);

  pinMode(ENAY_PIN, OUTPUT);
  pinMode(Y1_PIN, OUTPUT);
  pinMode(Y2_PIN, OUTPUT);

  pinMode(ENAZ_PIN, OUTPUT);
  pinMode(Z1_PIN, OUTPUT);
  pinMode(Z2_PIN, OUTPUT);

  pinMode(ENAW_PIN, OUTPUT);
  pinMode(W1_PIN, OUTPUT);
  pinMode(W2_PIN, OUTPUT);
  
  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  
  server.begin();
}

void loop()
{ 
//  Serial.println("Spin motor X");
//  motorXClockwise(150);
//  delay(2000);
//  motorXoff();
//  delay(2000);
//
//  Serial.println("Spin motor Y");
  motorYClockwise(150);
  delay(10000);
  motorYoff();
  delay(5000);
//
//  Serial.println("Spin motor Z");
//  motorZClockwise(150);
//  delay(2000);
//  motorZoff();
//  delay(2000);
//
//  Serial.println("Spin motor W");
//  motorWClockwise(150);
//  delay(2000);
//  motorWoff();
//  delay(2000);
  
//  if (!mqttClient.connected()) {
//    connectToMQTT();
//  }
//
//  mqttClient.loop();
//  
//  WiFiClient client = server.available();
//
//  if (client)
//  {
//    String currentLine = "";
//    while (client.connected())
//    {
//      if (client.available())
//      {             
//        char c = client.read();             
//        if (c == '*')
//        {   
//          processMessage(currentLine);                
//          currentLine = "";
//        }
//        currentLine += c;
//      }
//    }
//    client.stop();
//  }
//
//  if (Serial.available() > 0) {
//    String serialInput = Serial.readStringUntil('\n');
//    motorCommand(serialInput);
//  }
}

void processMessage(const String& message) 
{
  Serial.println(message);
}

void motorCommand(String command) 
{
  int orientation; // 0 Clockwise - 1 CounterClockwise
  int motorX, motorY, motorZ, motorW;
  int speedX, speedY, speedZ, speedW;
  int duration;

  motorXClockwise(150);
  delay(5);
  motorXoff();
  delay(1000);

//  if (sscanf(command.c_str(), "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &orientation,
//                                    &motorX,&motorY,&motorZ,&motorW,
//                                    &speedX,&speedY,&speedZ,&speedW,
//                                    &duration) == 10) 
//  {
//    int caseNumber = motorX * 1 + motorY * 2 + motorZ * 4 + motorW * 8;
//    switch (caseNumber) 
//    {
//      case 1:
//        if(orientation)
//        {
//          motorXClockwise(speedX);
//          delay(duration);
//          motorXoff();
//        }
//        else
//        {
//          motorXCounterClockwise(speedX);
//          delay(duration);
//          motorXoff();
//        }
//        break;
//        
//      case 2:
//        if(orientation)
//        {
//          motorYClockwise(speedY);
//          delay(duration);
//          motorYoff();
//        }
//        else
//        {
//          motorYCounterClockwise(speedY);
//          delay(duration);
//          motorYoff();
//        }
//        break;
//        
//      case 3:
//        if(orientation)
//        {
//          motorXClockwise(speedX);
//          motorYClockwise(speedY);
//          delay(duration);
//          motorXoff();
//          motorYoff();
//        }
//        else
//        {
//          motorXCounterClockwise(speedX);
//          motorYCounterClockwise(speedY);
//          delay(duration);
//          motorXoff();
//          motorYoff();
//        }
//        break;
//
//      case 4:
//        if(orientation)
//        {
//          motorZClockwise(speedZ);
//          delay(duration);
//          motorZoff();
//        }
//        else
//        {
//          motorZCounterClockwise(speedZ);
//          delay(duration);
//          motorZoff();
//        }
//        break;
//
//      case 8:
//        if(orientation)
//        {
//          motorWClockwise(speedW);
//          delay(duration);
//          motorWoff();
//        }
//        else
//        {
//          motorWCounterClockwise(speedW);
//          delay(duration);
//          motorWoff();
//        }
//        break;
//        
//      default:
//        Serial.println("Unknown case number");
//        break;
//    }
//  } else {
//    Serial.println("Invalid command format");
//  }
}

void motorXClockwise(int mspeed) 
{
  // MotorX On
  digitalWrite(X1_PIN, HIGH);
  digitalWrite(X2_PIN, LOW);
  analogWrite(ENAX_PIN, mspeed); 
}

void motorXCounterClockwise(int mspeed) 
{
  // MotorX On
  digitalWrite(X1_PIN, LOW);
  digitalWrite(X2_PIN, HIGH);
  analogWrite(ENAX_PIN, mspeed); 
}

void motorXoff()
{
  // MotorX Off
  digitalWrite(X1_PIN, LOW);
  digitalWrite(X2_PIN, LOW);
}

void motorYClockwise(int mspeed) 
{
  // MotorY On
  digitalWrite(Y1_PIN, HIGH);
  digitalWrite(Y2_PIN, LOW);
  analogWrite(ENAY_PIN, mspeed); 
}

void motorYCounterClockwise(int mspeed) 
{
  // MotorY On
  digitalWrite(Y1_PIN, LOW);
  digitalWrite(Y2_PIN, HIGH);
  analogWrite(ENAY_PIN, mspeed); 
}

void motorYoff()
{
  // MotorY Off
  digitalWrite(Y1_PIN, LOW);
  digitalWrite(Y2_PIN, LOW);
}

void motorZClockwise(int mspeed) 
{
  // MotorZ On
  digitalWrite(Z1_PIN, HIGH);
  digitalWrite(Z2_PIN, LOW);
  analogWrite(ENAZ_PIN, mspeed); 
}

void motorZCounterClockwise(int mspeed) 
{
  // MotorZ On
  digitalWrite(Z1_PIN, LOW);
  digitalWrite(Z2_PIN, HIGH);
  analogWrite(ENAZ_PIN, mspeed); 
}

void motorZoff()
{
  // MotorZ Off
  digitalWrite(Z1_PIN, LOW);
  digitalWrite(Z2_PIN, LOW);
}

void motorWClockwise(int mspeed) 
{
  // MotorW On
  digitalWrite(W1_PIN, HIGH);
  digitalWrite(W2_PIN, LOW);
  analogWrite(ENAW_PIN, mspeed); 
}

void motorWCounterClockwise(int mspeed) 
{
  // MotorZ On
  digitalWrite(W1_PIN, LOW);
  digitalWrite(W2_PIN, HIGH);
  analogWrite(ENAW_PIN, mspeed); 
}

void motorWoff()
{
  // MotorW Off
  digitalWrite(W1_PIN, LOW);
  digitalWrite(W2_PIN, LOW);
}
