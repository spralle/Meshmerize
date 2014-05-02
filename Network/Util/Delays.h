/*
 * Delays.h
 *
 * Created: 2014-04-25 22:14:50
 *  Author: emil
 */ 


#ifndef __UTIL_DELAYS_H_
#define __UTIL_DELAYS_H_
class Delays
{
	public:
	inline static void ms(uint32_t aMilliseconds);
	inline static void us(uint32_t aMicroseconds);
};


#endif //__UTIL_DELAYS_H_