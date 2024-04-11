#include <WiFi.h>

const char* ssid = "COSMOS";
const char* password = "cosmos123";
const char* serverIP = "192.168.4.1";
const int serverPort = 80;

void setup() {
  Serial.begin(115200);

  // Connect to the Wi-Fi network created by the server (access point)
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Check for incoming serial data
  while (Serial.available() > 0) {
    String message = Serial.readStringUntil('\n');

    // Establish connection to the server
    WiFiClient client;
    if (client.connect(serverIP, serverPort)) {
      //Serial.println("Connected to server");
      // Send the received character to the server
      client.println(message);
      Serial.println("Mission Sent");
      // Close the connection
      client.stop();
      //Serial.println("Connection closed");
    }
  }

  // Other code as needed

  delay(100); // Adjust the delay as needed
}