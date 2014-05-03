/*
* NetworkTest.cpp
*
* Created: 2014-04-25 19:37:00
*  Author: sprawl
*/

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <Arch/AVR/Ports.h>
#include <Arch/AVR/Dev/HardwareUsart.h>
#include <Core/Pin.h>
//#include "../Network/Arch/AVR/Dev/HardwareSpi.h"
//#include "../Network/Util/Delays.h"
int main(void)
{
	//typedef Pin<Avr::PortB, 3> Mosi;
	//typedef Pin<Avr::PortB, 4> Miso;
	//typedef Pin<Avr::PortB, 5> Sck;
	//
	//HardwareSpi<Mosi, Miso, Sck> spi();
	//typedef Pin<Avr::PortB, 5> Led;
	
	//typedef Pins<Avr::PortB, _BV(2));
	//DDRB |= _BV(DDB5);
	//typedef Bits<Avr::RUCSR0B, _BV(TXEN0)> BTXEN0;
	//BTXEN0::setHigh();
	typedef Pin<Avr::PortB, 5> Led;
	Led::makeOutput();
	HardwareUsart usart(9600);
	usart.init();
	
	//Avr::PortB::makeOutput(_BV(5));e
	//Led::makeOutput();
	//Led::setLow();
	while(true)
	{
		usart.write((uint8_t)'H');
		Led::setHigh();
		//Avr::PortB::setHigh(_BV(5));
		//PORTB |= _BV(5);
		_delay_ms(1000);
		usart.write((uint8_t)'L');
		Led::setLow();
		//Avr::PortB::setLow(_BV(5));
		//PORTB &= ~_BV(5);
		_delay_ms(100);
		//Delays::ms(1000);
		//Led::setLow();
		//Delays::ms(1000);
		//Led::setHigh();
	}
	//Pin<Avr::PortB, 1> CE;
	//Pin<Avr::PortB, 2> CSN;
	////Nrf24l<CE, CSN> nrf24l(spi);
	//
	//nrf24l.init();
	//nrf24l.powerUp();
	//while(true)
	//{
	//nrf24l.send("HELLO", 6);
	//}
	//
	//nrf24l.exit();
	//return 0;

}