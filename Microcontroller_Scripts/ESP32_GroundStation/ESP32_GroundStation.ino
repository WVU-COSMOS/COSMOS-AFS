#include <WiFi.h>

const char* ssid = "COSMOS";
const char* password = "cosmos";
const char* serverIP = "192.168.4.1";
const int serverPort = 80;

void setup() 
{
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() 
{
  while (Serial.available() > 0) 
  {
    String message = Serial.readStringUntil('\n');

    WiFiClient client;
    if (client.connect(serverIP, serverPort)) 
    {
      client.println(message);
      Serial.println("Mission Done");
      client.stop();
    }
  }
  
  delay(100);
}
