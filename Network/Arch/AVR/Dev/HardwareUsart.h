/*
* HardwareUsart.h
*
* Created: 2014-05-03 20:00:56
*  Author: Andreas
*/


#ifndef __ARCH_AVR_DEV_HARDWAREUSART_H_
#define __ARCH_AVR_DEV_HARDWAREUSART_H_
#include <Dev/Usart.h>
#define F_CPU 16000000
class HardwareUsart : Usart
{
	public:
	HardwareUsart(uint32_t aBaudrate=9600)
	{
		uint16_t prescaler = (F_CPU / 8 / aBaudrate - 1) / 2;
		Avr::RUBRR0::value(prescaler);
	}
	virtual bool init()
	{
		//Avr::BTXEN0::setHigh();
		//Avr::BRXEN0::setHigh();
		//Avr::RUCSR0B::value((1<<RXEN0)|(1<<TXEN0));
		//Avr::BTXEN0::setHigh();
		//Avr::BRXEN0::setHigh();
		Avr::RUCSR0B::value((1<<RXEN0)|(1<<TXEN0));
		Avr::RUCSR0C::value( ((1<<UCSZ00)|(1<<UCSZ01)));
		return true;
		
	}
	virtual bool exit()
	{
		return true;
	}
	virtual void write(uint8_t aByte)
	{
		while(!(Avr::BUDRE0::isHigh()));
		Avr::RUDR0::value(aByte);
	}
	virtual uint32_t write(uint8_t *aBuffer, uint32_t aLength)
	{
		while(aLength--)
		{
			uint8_t val = *aBuffer;
			while(!(Avr::BUDRE0::isHigh()));
			Avr::RUDR0::value(val);
			aBuffer++;
		}
		return aLength;
	}
	
	//private:
	//uint32_t mBaudrate;
};



#endif /* __ARCH_AVR_DEV_HARDWAREUSART_H_ */