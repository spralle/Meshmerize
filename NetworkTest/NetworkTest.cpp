/*
* NetworkTest.cpp
*
* Created: 2014-04-25 19:37:00
*  Author: sprawl
*/

#define F_CPU 16000000
#include <avr/io.h>
#include <Arch/AVR/AVR.h>
#include <Core/Pin.h>
#include <NRF24L/NRF24L.h>

int main(void)
{
	typedef Pin<Avr::PortB, 1> CE;
	typedef Pin<Avr::PortB, 2> CSN;
	typedef Pin<Avr::PortB, 3> PMOSI;
	typedef Pin<Avr::PortB, 4> PMISO;
	typedef Pin<Avr::PortB, 5> PSCK;
	HardwareSpi<PMOSI, PMISO, PSCK> spi;
	uint8_t status = 0;
	CSN::makeOutput();
	CSN::setHigh();
	spi.init();
	////
	//typedef Pin<Avr::PortB, 5> Led;
	//led.makeOutput();
	HardwareUsart usart(9600);
	usart.init();
	Nrf24l<CE, CSN> nrf(&spi);
	usart.write((uint8_t)'S');
	nrf.init();
	nrf.setRadioPower(NRF24L_PA_MAX);
	nrf.setCrcMode(NRF24L_CRC_16);
	Delays::ms(1000);
	usart.write((uint8_t)'S');
	//
	//
	uint8_t buf[] = {0xDE, 0xAD, 0xBE, 0xEF};
	while(true)
	{
		
		nrf.send(buf, 4);
		//status = nrf.readRegister(STATUS);
		usart.write((uint8_t)'H');
		usart.write(65+status);
		//led.setHigh();
		//_delay_ms(1000);
		Delays::ms(1000);
		usart.write((uint8_t)'L');
		//led.setLow();
		Delays::ms(1000);
	}
}