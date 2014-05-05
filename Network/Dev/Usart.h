/*
 * IncFile1.h
 *
 * Created: 2014-05-03 14:22:24
 *  Author: emil
 */ 


#ifndef __DEV_USART_H__
#define __DEV_USART_H__

#include "../IModule.h"
#include <IO/IOutputStream.h>

class Usart : public IModule, public IOutputStream
{
public:
	virtual bool init()=0;
	virtual bool exit()=0;
	virtual void write(uint8_t aByte)=0;
	virtual uint32_t write(uint8_t *aBuffer, uint32_t aLength)=0;
};

#endif /* __DEV_USART_H__ */