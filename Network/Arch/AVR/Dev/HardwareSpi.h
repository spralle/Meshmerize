/*
 * HardwareSpi.h
 *
 * Created: 2014-04-25 20:29:53
 *  Author: emil
 */ 


#ifndef __ARCH_AVR_DEV_HARDWARESPI_H_
#define __ARCH_AVR_DEV_HARDWARESPI_H_

enum SpiDataMode
{
	SpiDataMode0 = 0x00,
	SpiDataMode1 = 0x04,
	SpiDataMode2 = 0x08,
	SpiDataMode3 = 0x0c
};


#define SPI_MODE_MASK 0x0c
#define SPI_CLOCK_MASK 0x03  
#define SPI_2XCLOCK_MASK 0x01 

#include <stdint.h>
#include <Dev/SPI.h>

#include <avr/io.h>
#include <Arch/AVR/Ports.h>


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
		////Avr::BSPR0::setHigh();
// Set MOSI, SCK as Output
DDRB = (1<<5)|(1<<3);

// Enable SPI, Set as Master
//Prescaler: Fosc/16, Enable Interrupts
SPCR = (1<<SPE)|(1<<MSTR);	
		setDataMode(SpiDataMode0);
		setClockDivider(SPI_2XCLOCK_MASK);
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
	
	void setDataMode(SpiDataMode aMode)
	{
		//RSPCR::value( RSPCR::value() & ~SPI_MODE_MASK) | aMode;
		SPCR = (SPCR & ~SPI_MODE_MASK) | aMode;		
	}
	
	void setClockDivider(uint8_t aRate)
	{
		SPCR = (SPCR & ~SPI_CLOCK_MASK) | (aRate & SPI_CLOCK_MASK);
		SPSR = (SPSR & ~SPI_2XCLOCK_MASK) | ((aRate >> 2) & SPI_2XCLOCK_MASK);		
	}
};

#endif //__ARCH_AVR_DEV_HARDWARESPI_H_