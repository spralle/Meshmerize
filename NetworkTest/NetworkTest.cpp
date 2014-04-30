/*
 * NetworkTest.cpp
 *
 * Created: 2014-04-25 19:37:00
 *  Author: sprawl
 */ 


#include <avr/io.h>
#include "../Network/Arch/AVR/Ports.h"
#include "../Network/Core/Pin.h"
#include "../Network/Arch/AVR/Dev/HardwareSpi.h"

int main(void)
{
	typedef Pin<Avr::PortB, 3> Mosi;
	typedef Pin<Avr::PortB, 4> Miso;
	typedef Pin<Avr::PortB, 5> Sck;

	HardwareSpi<Mosi, Miso, Sck> spi();
	typedef Pin<Avr::PortB, 7> Led;
	//typedef Pins<Avr::PortB, _BV(2));
	Led::makeOutput();
	Led::setHigh()
	while(true)
	{
		Delays::ms(1000);
		Led::toggle();
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