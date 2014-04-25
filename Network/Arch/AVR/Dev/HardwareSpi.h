/*
 * HardwareSpi.h
 *
 * Created: 2014-04-25 20:29:53
 *  Author: emil
 */ 


#ifndef __ARCH_AVR_DEV_HARDWARESPI_H_
#define __ARCH_AVR_DEV_HARDWARESPI_H_

class HardwareSpi : Spi
{
public:	
	virtual uint8_t write(uint8_t aValue);
	virtual	uint8_t read();
};



#endif //__ARCH_AVR_DEV_HARDWARESPI_H_