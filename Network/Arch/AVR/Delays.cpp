#include <util/delay.h>
#include "../../Util/Delays.h"
void Delays::ms(uint32_t aMilliseconds)
{
	_delay_ms(aMilliseconds);
}


void Delays::us(uint32_t aMicroseconds)
{
	_delay_us(aMicroseconds);
}
