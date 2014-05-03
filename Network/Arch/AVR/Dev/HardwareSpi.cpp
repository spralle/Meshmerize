#include "HardwareSpi.h"

template<typename MOSI, typename MISO, typename SCK>
void HardwareSpi<MOSI, MISO, SCK>::init()
{
	SCK::makeOutput();
	MOSI::makeOutput();
	SpcrMstr::setHigh();
	SpcrSpe::setHigh();
}

template<typename MOSI, typename MISO, typename SCK>
void HardwareSpi<MOSI, MISO, SCK>::exit()
{
	SpcrSpe::setLow();
}

template<typename MOSI, typename MISO, typename SCK>
uint8_t HardwareSpi<MOSI, MISO, SCK>::read()
{
	return Spdr::value();	
}

template<typename MOSI, typename MISO, typename SCK>
uint8_t HardwareSpi<MOSI, MISO, SCK>::write(uint8_t aValue)
{
	Spdr::value(aValue);
	while(!SpsrSpif::isHigh());
	return Spdr::value();
}
