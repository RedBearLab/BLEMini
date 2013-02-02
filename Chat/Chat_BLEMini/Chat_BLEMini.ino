
#include <Arduino.h>
#include <SoftwareSerial.h>

//BLE Mini is connected to pin 2 and 3.
SoftwareSerial BLEMini(2, 3);

void setup()
{
  BLEMini.begin(57600);
  
  Serial.begin(57600);
}

unsigned char buf[16] = {0};
unsigned char len = 0;

void loop()
{
  while ( BLEMini.available())
    Serial.write( BLEMini.read());

  while ( Serial.available() )
  {
    unsigned char c = Serial.read();
    if (c != 0xD)
    {
      if (len < 16)
        buf[len++] = c;
    }
    else
    {
      for (int i = 0; i < len; i++)
         BLEMini.write(buf[i]);
      len = 0;
    }
  }
}

