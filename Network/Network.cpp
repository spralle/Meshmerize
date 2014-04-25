
//typedef MAKEPORT(PORTA,DDRA) PortA;

#include "Arch\AVR\AVR.h"
#include "Core\Pin.h"

#include "NRF24L\NRF24L.h"


int main(int argc, char* argv[])
{
	HardwareSpi spi;
	Pin<PortA, 9> CE; 
	Pin<PortA, 10> CSN; 
	Nrf24l<CE, CSN> nrf24l;

	nrf24l.init();
	nrf24l.powerUp();
	while(true)
	{
		nrf24l.send("HELLO", 6);
	}

	nrf24l.exit();
	return 0;
}

