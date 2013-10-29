
#include "ble_Mini.h"

// UNO 
// TX: pin 1
// RX: pin 0
#if defined (__AVR_ATmega168__) || defined (__AVR_ATmega328P__) 
	#define BLEMINI Serial 

// other board
// board					TX			RX
// Leonardo			1				0
// MEGA					18			19
// DUE						18			19
#else 
	#define BLEMINI Serial1
#endif

void BLEMini_begin(unsigned long bound)
{
		BLEMINI.begin(bound);
}

int BLEMini_available()
{
		return BLEMINI.available();
}

void BLEMini_write(unsigned char dat)
{
		BLEMINI.write(dat);
}

void BLEMini_write_bytes(unsigned char *dat, unsigned char len)
{
		delay(10);
		if(len > 0)
			BLEMINI.write(dat, len);
}

int BLEMini_read()
{
	delay(10);	
	return BLEMINI.read();
}
