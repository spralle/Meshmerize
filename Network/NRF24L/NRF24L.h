#ifndef __NRF24L_H__
#define __NRF24L_H__

#include <stdint.h>

#include <IModule.h>
#include <Dev/SPI.h>
#include <Core/Pin.h>
#include <Core/Reg.h>
#include <Util/Delays.h>

#include "NRF24L_Constants.h"

#define NRF24L_DEFAULT_CHANNEL 66

enum Nrf24lDataRate
{
	NRF24L_1MBPS = 0,
	NRF24L_2MBPS,
	NRF24L_250KBPS
};

enum Nrf24lPaDbm
{
	NRF24L_PA_MIN=0,
	NRF24L_PA_LOW,
	NRF24L_PA_HIGH,
	NRF24L_PA_MAX
};

enum Nrf24lCrcMode
{
	NRF24L_CRC_DISABLED=0,
	NRF24L_CRC_8,
	NRF24L_CRC_16
};

template<typename CE, typename CSN>
class Nrf24l : IModule
{
	public:
	Nrf24l(Spi *aSpi)
	:mSpi(aSpi)
	{
		mChannel = 0x77;
	}
	
	~Nrf24l() {};
	
	//IModule
	bool init()
	{
		CE::setLow();
		CSN::setHigh();
		//writeRegister(EN_AA, 0xAA);
		//config
		switchChannel(mChannel);
		return true;
	}
	bool exit()
	{
		return true;
	}

	/**
	* aChannel number of channel 0-127 is valid
	*/
	void switchChannel(uint8_t aChannel)
	{
		mChannel = aChannel;
		writeRegister(RF_CH, 2400+mChannel);
	}
	void setRadioPower(Nrf24lPaDbm aPower)
	{
		
	}
	void setCrcMode(Nrf24lCrcMode aCrcMode);

	void openPipe(uint8_t aPipeNumber, uint8_t *aPipeAddress, uint8_t aAddressLength);
	void closePipe(uint8_t aPipeNumber);


	void powerUp();
	void powerDown();


	//private:
	Spi *mSpi;
	//Pin *mChipEnable;
	//Pin *mChipSelect;

	uint8_t mChannel;

	void writeRegister(uint8_t aRegister, uint8_t aData)
	{
		writeRegister(aRegister, &aData,1);
	}
	void writeRegister(uint8_t aRegister, uint8_t *aData, uint8_t aLength)
	{
		Delays::us(10);
		CSN::setLow();
		Delays::us(10);
		mSpi->write(aRegister);
		Delays::us(10);
		while(aLength--)
		{
			mSpi->write(*aData);
			aData++;
		}
		CSN::setHigh();
	}
	uint8_t readRegister(uint8_t aRegister)
	{
		uint8_t val;
		Delays::us(10);
		CSN::setLow();
		Delays::us(10);
		mSpi->write(R_REGISTER + aRegister);
		Delays::us(10);
		val = mSpi->write(NOP);
		Delays::us(10);
		CSN::setHigh();
		return val;
	}

};

#endif // __NRF24L_H__