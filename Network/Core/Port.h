#ifndef __PORT_H__
#define __Port_H__

template <typename Port>
struct Port
{
public:
	static __inline void set(bool aIsHigh) 
	{ 
		if(aIsHigh) 
		{
			setHigh();
		} else
		{
			setLow();
		}
	}
	static __inline void setHigh()	{ Port::port(Port::port() | (1<<PinNumber)) };
	static __inline void setLow()	{ Port::port(Port::port() & ~(1<<PinNumber)); };
	static __inline bool isHigh();
	static __inline bool isLow();
};


#endif //__PIN_H__