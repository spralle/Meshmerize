/*
 * Delays.h
 *
 * Created: 2014-04-25 22:14:50
 *  Author: sprawl
 */ 


#ifndef __UTIL_DELAYS_H__
#define __UTIL_DELAYS_H__

#include <util/delay.h>

struct Delays
{
	inline static void ms(double aMilliseconds)
	{
		_delay_ms(aMilliseconds);
		
	}
	inline static void us(double aMicroseconds)
	{
		_delay_us(aMicroseconds);
	}
};


#endif //__UTIL_DELAYS_H__