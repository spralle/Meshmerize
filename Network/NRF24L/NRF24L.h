#ifndef __NRF24L_H__
#define __NRF24L_H__

#include <stdint.h>

#include "../IModule.h"
#include "../SPI.h"
#include "../Core/Pin.h"

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

template<typename CE, typename CS>
class Nrf24l : IModule
{
public:
	Nrf24l(Spi *aSpi);
	~Nrf24l() {};
	
	//IModule
	bool init();
	bool exit();

	/**
	 * aChannel number of channel 0-127 is valid
	 */
	void switchChannel(uint8_t aChannel);
	void setRadioPower(Nrf24lPaDbm aPower);
	void setCrcMode(Nrf24lCrcMode aCrcMode);

	void openPipe(uint8_t aPipeNumber, uint8_t *aPipeAddress, uint8_t aAddressLength);
	void closePipe(uint8_t aPipeNumber);


	void powerUp();
	void powerDown();


private:
	Spi *mSpi;
	//Pin *mChipEnable;
	//Pin *mChipSelect;

	uint8_t mChannel; 

	void writeRegister(uint8_t aRegister, uint8_t aData);
	void writeRegister(uint8_t aRegister, uint8_t *aData, uint8_t aLength);
	uint8_t readRegister(uint8_t aRegister);

};

#endif // __NRF24L_H__