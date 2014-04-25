/*
 * NetworkTest.cpp
 *
 * Created: 2014-04-25 19:37:00
 *  Author: sprawl
 */ 


#include <avr/io.h>
#include "../Network/Arch/AVR/Ports.h"
#include "../Network/Core/Pin.h"

int main(void)
{
	HardwareSpi spi;
	Pin<PortA, 9> CE;
	Pin<PortA, 10> CSN;
	Nrf24l<CE, CSN> nrf24l(spi);

	nrf24l.init();
	nrf24l.powerUp();
	while(true)
	{
		nrf24l.send("HELLO", 6);
	}

	nrf24l.exit();
	return 0;

}