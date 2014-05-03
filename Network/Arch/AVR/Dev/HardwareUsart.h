/*
 * HardwareUsart.h
 *
 * Created: 2014-05-03 20:00:56
 *  Author: Andreas
 */ 


#ifndef __ARCH_AVR_DEV_HARDWAREUSART_H_
#define __ARCH_AVR_DEV_HARDWAREUSART_H_
#include <Dev/Usart.h>
class HardwareUsart : Usart
{
public:
	HardwareUsart(uint32_t aBaudrate=9600);
	bool init();
	bool exit();
	void write(uint8_t aByte);
	void write(uint8_t *aBuffer, uint16_t aLength);
	
private:
	uint32_t mBaudrate;
};



#endif /* __ARCH_AVR_DEV_HARDWAREUSART_H_ */