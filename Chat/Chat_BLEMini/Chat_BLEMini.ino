/*******************************************
* This example is for Arduino board listed below working with BLEMini
* to demostrate a simple chatting application.
*
* Connect BLE Mini to Arduino RX/TX using the following settings:
*
* Board       RX      TX
* -----       -----   -----
* UNO         PIN8    PIN9  (PINs can be changed in file "known_boards.h")
* MEGA2560    PIN19   PIN18 (actually use the Serial1)
* Leonardo    PIN0    PIN1  (actually use the Serial1)
*
* For example:
*   BLE Mini TX -> Leonardo RX (PIN0)
*   BLE Mini RX -> Leonardo TX (PIN1)
*
*******************************************/
#include <Arduino.h>
#include <AltSoftSerial.h>

#if defined (__AVR_ATmega168__) || defined (__AVR_ATmega328P__)  
  AltSoftSerial BLEMini;  
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) || defined(__AVR_ATmega32U4__)
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
    Serial.println( BLEMini.read());
  }

  while ( Serial.available() )
  {
    unsigned char c = Serial.read();
    if (c != 'd')
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

