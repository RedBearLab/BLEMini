/*******************************************
* This example is for Arduino board listed below working with BLEMini,chating with BLE app in ipod etc.
* BLEMini's TX map the RX below and its RX map the TX below
*
* Board       RX      TX
* UNO         PIN8    PIN9  (PINs can be changed in file "document/library/AltSoftSerial/config/known_boards.h")
* MEGA2560    PIN19   PIN18 (actually use the Serial1)
* Leonardo    PIN0    PIN1  (actually use the Serial1)
*******************************************/
#include <Arduino.h>
#include <AltSoftSerial.h>

// For UNO, AltSoftSerial library is required, please get it from:
// http://www.pjrc.com/teensy/td_libs_AltSoftSerial.html
#if defined (__AVR_ATmega168__) || defined (__AVR_ATmega328P__)  
  AltSoftSerial BLEMini;  
#else
  #define BLEMini Serial1
#endif

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
  {
    Serial.write( BLEMini.read() );
  }

  while ( Serial.available() )
  {
    unsigned char c = Serial.read();
    if (c != 0x0A)
    {
      if (len < 16)
        buf[len++] = c;
    }
    else
    {
      buf[len++] = 0x0A;
      
      for (int i = 0; i < len; i++)
         BLEMini.write(buf[i]);
      len = 0;
    }
  }
}

