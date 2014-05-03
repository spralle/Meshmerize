#include "NRF24L.h"
#include "NRF24L_Constants.h"

#include "../Util/Delays.h"


template<typename CE, typename CS>
Nrf24l<CE,CS>::Nrf24l(Spi *aSpi)
	: mSpi(aSpi)
	, mChannel(NRF24L_DEFAULT_CHANNEL)
{
	Delays::ms(1);
}

template<typename CE, typename CS>
bool Nrf24l<CE,CS>::init()
{
	CE::setLow();
	CS::setHigh();
	//writeRegister(EN_AA, 0xAA);
	//config
	switchChannel(mChannel);
	return true;
}

template<typename CE, typename CS>
void Nrf24l<CE,CS>::switchChannel(uint8_t aChannel)
{
	mChannel = aChannel;
	writeRegister(RF_CH, 2400+mChannel);
}


template<typename CE, typename CS>
void Nrf24l<CE,CS>::writeRegister(uint8_t aRegister, uint8_t aData)
{
	writeRegister(aRegister, &aData,1);
}


template<typename CE, typename CS>
void Nrf24l<CE,CS>::writeRegister(uint8_t aRegister, uint8_t *aData, uint8_t aLength)
{
	Delays::us(10);
	CS::setLow();
	Delays::us(10);
	mSpi->write(aRegister);
	Delays::us(10);
	while(aLength--)
	{
		mSpi->write(*aData);
		aData++;
	}
	CS::setHigh();
}
