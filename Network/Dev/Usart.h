/*
 * IncFile1.h
 *
 * Created: 2014-05-03 14:22:24
 *  Author: emil
 */ 


#ifndef __DEV_USART_H__
#define __DEV_USART_H__

#include "../IModule.h"

class Usart : IModule
{
public:
	virtual bool init();
	virtual bool exit();
	virtual void write(uint8_t aByte);
	virtual void write(uint8_t *aBuffer, uint16_t aLength);
};

#endif /* __DEV_USART_H__ */