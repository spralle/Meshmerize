#ifndef __SPI_H__
#define __SPI_H__

#include "../IModule.h"

class Spi : IModule
{
public:
	virtual uint8_t write(uint8_t aValue) = 0;
	virtual uint8_t read() = 0;
};

#endif //__SPI_H__