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
/**
 * Based on RF24, mirf among others
 */
template<typename CE, typename CSN>
class  __attribute__((packed)) Nrf24l : public IModule
{
	public:
	Nrf24l(Spi *aSpi, uint8_t aChannel=0x77)
	  :mSpi(aSpi)
	{
		mChannel = aChannel;
	}
	
	~Nrf24l() {};
	
	//IModule
	virtual bool init()
	{
		CE::makeOutput();
		CSN::makeOutput();
		CE::setLow();
		CSN::setHigh();
		Delays::ms(5);
		//writeRegister(EN_AA, 0xAA);
		//config
		switchChannel(mChannel);
		enableDynamicPayloads();
		return true;
	}
	virtual bool exit()
	{
		return true;
	}

	/**
	* aChannel number of channel 0-127 is valid
	*/
	void switchChannel(uint8_t aChannel)
	{
		mChannel = aChannel;
		writeRegister(RF_CH, 2400+aChannel);
	}
	void setRadioPower(Nrf24lPaDbm aPower)
	{
		
	}
	void setCrcMode(Nrf24lCrcMode aCrcMode)
	{
		uint8_t config = readRegister(CONFIG) & ~( _BV(CRCO) | _BV(EN_CRC)) ;
  
		if ( aCrcMode == NRF24L_CRC_DISABLED )
		{
		}
		else if ( aCrcMode == NRF24L_CRC_8)
		{
			config |= _BV(EN_CRC);
		}
		else //NRF24L_CRC_16
		{
			config |= _BV(EN_CRC);
			config |= _BV( CRCO );
		}
		writeRegister( CONFIG, config ) ;
	}

	void openPipe(uint8_t aPipeNumber, uint8_t *aPipeAddress, uint8_t aAddressLength);
	void closePipe(uint8_t aPipeNumber);


	void powerUp();
	void powerDown();
	
	void powerUpTx()
	{
		writeRegister(CONFIG, (readRegister(CONFIG) | _BV(PWR_UP)) & ~_BV(PRIM_RX));
		Delays::us(150);
	}
	void powerUpRx()
	{
		writeRegister(CONFIG, readRegister(CONFIG) | _BV(PWR_UP) | _BV(PRIM_RX));
		Delays::us(150);
	}
	
	void listen()
	{
		powerUpRx();
		flushRx();
		flushTx();
		CE::setHigh();
		
		//wait for radio to start
		Delays::us(130);
	}


	uint32_t send(uint8_t *aBuffer, uint32_t aLength)
	{
		CE::setLow();
		powerUpTx();
		flushTx();
		
		
		CSN::setLow();
		mSpi->write(W_TX_PAYLOAD);
		while(aLength--)
		{
			mSpi->write(*aBuffer);
			aBuffer++;
		}
		CE::setHigh();
		Delays::us(10);
		CE::setLow();
		return aLength;
	}


	//private:
	Spi *mSpi;
	uint8_t mChannel;

	void enableDynamicPayloads()
	{
		writeRegister(FEATURE,readRegister(FEATURE) | _BV(EN_DPL) );
		if ( ! readRegister(FEATURE) )
		{
			toggleFeatures();				
			writeRegister(FEATURE,readRegister(FEATURE) | _BV(EN_DPL) );
		}
		writeRegister(DYNPD,readRegister(DYNPD) | _BV(DPL_P5) | _BV(DPL_P4) | _BV(DPL_P3) | _BV(DPL_P2) | _BV(DPL_P1) | _BV(DPL_P0));
	}
	

	void toggleFeatures(void)
	{
		CSN::setLow();
		mSpi->write( ACTIVATE );
		mSpi->write( 0x73 );
		CSN::setHigh();
	}

	uint8_t flushTx()
	{
		uint8_t status;
		CSN::setLow();
		status = mSpi->write(FLUSH_TX);
		CSN::setHigh();
		return status;
	}

	uint8_t flushRx()
	{
		uint8_t status;
		CSN::setLow();
		status = mSpi->write(FLUSH_RX);
		CSN::setHigh();
		return status;
	}

	void writeRegister(uint8_t aRegister, uint8_t aData)
	{
		//Delays::us(10);
		CSN::setLow();
		//Delays::us(10);
		mSpi->write(W_REGISTER | (REGISTER_MASK  & aRegister));
		//Delays::us(10);
		mSpi->write(aData);
		CSN::setHigh();
	}
	void writeRegister(uint8_t aRegister, uint8_t *aData, uint8_t aLength)
	{
		//Delays::us(10);
		CSN::setLow();
		//Delays::us(10);
		mSpi->write(W_REGISTER | (REGISTER_MASK  & aRegister));
		//Delays::us(10);
		while(aLength--)
		{
			mSpi->write(*aData++);
		}
		CSN::setHigh();
	}
	uint8_t readRegister(uint8_t aRegister)
	{
		uint8_t val;
		//Delays::us(10);
		CSN::setLow();
		//Delays::us(10);
		mSpi->write(R_REGISTER  | (REGISTER_MASK & aRegister));
		//Delays::us(100);
		val = mSpi->write(NOP);
		//Delays::us(10);
		CSN::setHigh();
		return val;
	}

};

#endif // __NRF24L_H__