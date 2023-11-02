#include<RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

void setup()
{
  Serial.begin(9600);
  
  if (!driver.init())
       Serial.println("init failed");
}

void loop() 
{
  if (Serial.available() > 0) {
    String message = Serial.readString();
    driver.send((uint8_t*)message.c_str(), message.length());
    driver.waitPacketSent();
  }
}
