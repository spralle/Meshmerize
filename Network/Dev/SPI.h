#ifndef __SPI_H__
#define __SPI_H__

#include "../IModule.h"

class Spi : IModule
{
public:
	uint8_t write(uint8_t aValue);
	uint8_t read();
};

#endif //__SPI_H__