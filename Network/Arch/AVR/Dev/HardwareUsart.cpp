/*
 * HardwareUsart.cpp
 *
 * Created: 2014-05-03 19:58:56
 *  Author: Andreas
 */ 

#include "../Ports.h"
#include "HardwareUsart.h"
#define F_CPU 16000000

//typedef Bits<Avr::RUBRR0>


HardwareUsart::HardwareUsart(uint32_t aBaudrate) 
	: mBaudrate(aBaudrate)
{
		
}

bool HardwareUsart::init()
{
	uint16_t prescaler = (F_CPU / 8 / mBaudrate - 1) / 2;
	Avr::RUBRR0::value(prescaler);
	//Avr::BTXEN0::setHigh();
	//Avr::BRXEN0::setHigh();
	//Avr::RUCSR0B::value((1<<RXEN0)|(1<<TXEN0));
	//Avr::BTXEN0::setHigh();
	//Avr::BRXEN0::setHigh();
	Avr::RUCSR0B::value((1<<RXEN0)|(1<<TXEN0));
	Avr::RUCSR0C::value( ((1<<UCSZ00)|(1<<UCSZ01)));
	return true;
}

bool HardwareUsart::exit()
{
	 return true;
}

void HardwareUsart::write(uint8_t aByte)
{
	 while(!(Avr::BUDRE0::isHigh()));
	 Avr::RUDR0::value(aByte);
}

void HardwareUsart::write(uint8_t *aBuffer, uint16_t aLength)
{
	while(aLength--)
	{
		uint8_t val = *aBuffer;
		while(!(Avr::BUDRE0::isHigh()));
		Avr::RUDR0::value(val);
		aBuffer++;
	}
}
