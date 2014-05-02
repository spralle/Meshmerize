#ifndef __PIN_H__
#define __PIN_H__

//template <typename Port, uint8_t PinNumber>
//struct Pin
//{
//public:
	//static __inline void set(bool aIsHigh) 
	//{ 
		//if(aIsHigh) 
		//{
			//setHigh();
		//} else
		//{
			//setLow();
		//}
	//}
	//static __inline void setHigh()	{ Port::value(Port::value() | (1<<PinNumber)); };
	//static __inline void setLow()	{ Port::value(Port::value() & ~(1<<PinNumber)); };
	//static __inline bool value()	{ return (Port::value() & (1<<PinNumber)) != 0;}
//
	//static __inline void output(bool aIsOutput)
	//{
		//if(aIsOutput) 
		//{
			//makeOutput();
		//} else
		//{
			//makeInput();
		//}
	//}
//
	//static __inline void makeOutput() { Port::direction(Port::direction() | (1<<PinNumber));};
	//static __inline void makeInput() { Port::direction(Port::direction() & ~(1<<PinNumber));};
//};


#endif //__PIN_H__