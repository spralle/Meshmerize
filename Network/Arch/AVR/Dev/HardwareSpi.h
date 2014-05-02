/*
 * HardwareSpi.h
 *
 * Created: 2014-04-25 20:29:53
 *  Author: emil
 */ 


#ifndef __ARCH_AVR_DEV_HARDWARESPI_H_
#define __ARCH_AVR_DEV_HARDWARESPI_H_
#include <stdint.h>
#include "../../../SPI.h"

#include <avr/io.h>



template <typename MOSI, typename MISO, typename SCK>
class HardwareSpi : Spi
{
public:	
	virtual void init();
	virtual void exit();
	virtual uint8_t write(uint8_t aValue);
	virtual	uint8_t read();
};


#include "../../../Core/Reg.h"

typedef __MAKE_REG_8(SPCR) Spcr;
typedef __MAKE_REG_8(SPDR) Spdr;
typedef __MAKE_REG_8(SPSR) Spsr;
typedef Bits<Spsr, SPIF> SpsrSpif;
typedef Bits<Spcr, MSTR> SpcrMstr;
typedef Bits<Spcr, SPE> SpcrSpe;



#endif //__ARCH_AVR_DEV_HARDWARESPI_H_