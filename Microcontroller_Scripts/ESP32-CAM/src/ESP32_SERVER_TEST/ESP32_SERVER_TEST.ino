#include <WiFi.h>

// Defining the Wi-Fi host
const char* ssid     = "COSMOS";
const char* password = "123456789";
const int serverPort = 80;

WiFiServer server(serverPort);
WiFiClient wifiClient;

void setup() {
  Serial.begin(115200);

  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  
  server.begin();
}

void loop() {

}
