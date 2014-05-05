/*
 * IInputStream.h
 *
 * Created: 2014-05-05 17:51:06
 *  Author: Administrator
 */ 


#ifndef IINPUTSTREAM_H_
#define IINPUTSTREAM_H_

struct IInputStream
{
	virtual uint32_t available() = 0;
	virtual int16_t read() = 0;
	virtual uint32_t read(uint8_t *aBuffer, uint32_t aLength) = 0;
};


#endif /* IINPUTSTREAM_H_ */