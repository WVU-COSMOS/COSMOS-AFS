#include <WiFi.h>

const char* ssid     = "COSMOS";
const char* password = "cosmos";
const int serverPort = 80;

WiFiServer server(serverPort);

void setup() 
{
  Serial.begin(115200);

  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  
  server.begin();
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
}

void processMessage(const String& message) 
{
  Serial.println(message);
}
