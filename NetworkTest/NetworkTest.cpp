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
	typedef Pin<Avr::PortB, 2> CS;
	typedef Pin<Avr::PortB, 3> PMOSI;
	typedef Pin<Avr::PortB, 4> PMISO;
	typedef Pin<Avr::PortB, 5> PSCK;
	HardwareSpi<PMOSI, PMISO, PSCK> spi;
	uint8_t status = 0;
	spi.init();
	////
	//typedef Pin<Avr::PortB, 5> Led;
	//led.makeOutput();
	HardwareUsart usart(9600);
	Nrf24l<CE, CS> nrf(&spi);
	usart.write((uint8_t)'S');
	nrf.init();
	//Delays::ms(1000);
	usart.write((uint8_t)'S');
	status = nrf.readRegister(STATUS);
	//
	//
	usart.init();
	//
	while(true)
	{
		usart.write((uint8_t)'H');
		usart.write(65+status);
		//led.setHigh();
		//_delay_ms(1000);
		Delays::ms(1000);
		//usart.write((uint8_t)'L');
		//led.setLow();
		_delay_ms(1000);
		//Delays::ms(1000);
	}
}