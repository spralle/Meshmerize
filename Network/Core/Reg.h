/*
 * Reg.h
 *
 * Created: 2014-04-25 23:04:27
 *  Author: emil
 */ 


#ifndef __CORE_REG_H_
#define __CORE_REG_H_

#define __MAKE_REG(CLASSNAME, ADDR, TYPE) class CLASSNAME { protected:\
	CLASSNAME(){ }\
	public:\
	typedef TYPE Type;\
	static inline TYPE value(){ return  ADDR;}\
	static inline void value(TYPE aValue){ ADDR = aValue;} \
}

#define MAKE_PORT(CLASSNAME, DDR, PORT, TYPE) class CLASSNAME { protected:\
	CLASSNAME(){ }\
	public:\
	static inline TYPE value(){ return  PORT;}\
	static inline void value(TYPE aValue){ PORT = aValue;} \
	static inline TYPE direction(){ return  DDR;} \
	static inline void direction(TYPE aValue){ DDR = aValue;} \
}
#define __MAKE_REG_8(ADDR) __MAKE_REG(_P##ADDR, ADDR, uint8_t)
#define MAKE_PORT_8(DDR, PORT) MAKE_PORT(DDR##_##PORT, DDR, PORT, uint8_t)

template<typename Reg>
struct Regs
{
	static inline void setBits(typename Reg::Type aFlags)
	{
		Reg::value(Reg::value() | aFlags);
	}
	
	static inline void clearBits(typename Reg::Type aFlags)
	{
		Reg::value(Reg::value() & ~aFlags);
	}

	static inline void set(typename Reg::Type aFlags, bool aValue)
	{
		if(aValue)
		{
			setBits(aFlags);
		}
		else
		{
			clearBits(aFlags);
		}
	}
	
	static inline void toggleBits(typename Reg::Type aFlags)
	{
		Reg::value(Reg::value() ^ aFlags);
	}

	static inline void isBitsSet(typename Reg::Type aFlags)
	{
		return Reg::value() & aFlags == aFlags;
	}
	
};

template<typename Reg, uint16_t BitFlags>
struct Bits
{
	static inline void set() { Regs<Reg>::setBits(BitFlags);}	
	static inline void clear() { Regs<Reg>::clearBits(BitFlags);}
	static inline bool isSet() { return Regs<Reg>::isBitsSet(BitFlags);}
};

template<typename PortReg, typename DdrReg, typename PinReg> 
struct Port
{
	typedef PortReg Output;
	typedef PinReg Input;
	
	static inline void makeInput(uint8_t aBits) { Regs<PortReg>::clearBits(aBits); Regs<DdrReg>::clearBits(aBits); }
	static inline void makeOutput(uint8_t aBits) { Regs<DdrReg>::setBits(aBits); }
	static inline bool isInput(uint8_t aBits) { return !isOutput(aBits); }
	static inline bool isOutput(uint8_t aBits) { return Regs<DdrReg>::isBitsSet(aBits); }

	static inline void setHigh(uint8_t aBits) { Regs<PortReg>::setBits(aBits); }
	static inline void setLow(uint8_t aBits) { Regs<PortReg>::clearBits(aBits); }

};

template<typename Port, uint16_t Bits> 
struct Pins
{
	static inline void makeOutput() { Port::makeOutput(Bits);}
	static inline void makeInput() { Port::makeInput(Bits);}
	static inline bool isInput() { return !isOutput(); }
	static inline bool isOutput() { return Port::Output(Bits); }

	static inline void setHigh() { Port::setHigh(Bits);}
	static inline void setLow() { Port::setLow(Bits);}
	
};

template<typename Port, uint8_t PinNumber>
struct Pin : Pins<Port, 1<<PinNumber>
{
	
};



#endif //__CORE_REG_H_