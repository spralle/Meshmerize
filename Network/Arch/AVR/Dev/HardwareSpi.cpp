#include "HardwareSpi.h"

template<typename MOSI, typename MISO, typename SCK>
void HardwareSpi<MOSI, MISO, SCK>::init()
{
	SCK::makeOutput();
	MOSI::makeOutput();
	SpcrMstr::set();
	SpcrSpe::set();
}

template<typename MOSI, typename MISO, typename SCK>
void HardwareSpi<MOSI, MISO, SCK>::exit()
{
	SpcrSpe::clear();
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
	while(!SpsrSpif::isSet());
	return Spdr::value();
}
