/*
 * HardwareSpi.h
 *
 * Created: 2014-04-25 20:29:53
 *  Author: emil
 */ 


#ifndef __ARCH_AVR_DEV_HARDWARESPI_H_
#define __ARCH_AVR_DEV_HARDWARESPI_H_
#include <stdint.h>
#include <Dev/SPI.h>

#include <avr/io.h>



template <typename MOSI, typename MISO, typename SCK>
class HardwareSpi : public Spi
{
public:	
	virtual bool init()
	{
		//SCK::makeOutput();
		//MOSI::makeOutput();
		//Avr::BMSTR::setHigh();
		//Avr::BSPE::setHigh();
		//Avr::BSPR0::setHigh();
// Set MOSI, SCK as Output
DDRB = (1<<5)|(1<<3);

// Enable SPI, Set as Master
//Prescaler: Fosc/16, Enable Interrupts
SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);		
		return true;
	}
	virtual bool exit()
	{
		Avr::BSPE::setLow();
		return true;
	}
	virtual uint8_t write(uint8_t aValue)
	{
		//Avr::RSPDR::value(aValue);
		//while(!Avr::BSPIF::isHigh());
		//return Avr::RSPDR::value();
		  //// Load data into the buffer
		  SPDR = aValue;
		  
		  //Wait until transmission complete
		  while(!((SPSR)&(1<<SPIF)));
		  
		  // Return received data
		  return(SPDR);
	}
	virtual	uint8_t read()
	{
		return Avr::RSPDR::value();
	}
};

#endif //__ARCH_AVR_DEV_HARDWARESPI_H_