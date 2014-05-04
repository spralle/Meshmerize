#include <Util/Delays.h>
#include <util/delay.h>

void Delays::ms()
{
	_delay_ms(1000);
}


void Delays::us(double aMicroseconds)
{
	_delay_us(aMicroseconds);
}
