/*
 * Reg.h
 *
 * Created: 2014-04-25 23:04:27
 *  Author: emil
 */ 


#ifndef __CORE_REG_H_
#define __CORE_REG_H_

#define MAKE_REG(CLASSNAME, ADDR, TYPE) class CLASSNAME { protected:\
	CLASSNAME(){ }\
	public:\
	typedef TYPE Type;\
	static __inline TYPE value(){ return  ADDR;}\
	static __inline void value(TYPE aValue){ ADDR = aValue;} \
}

#define MAKE_PORT(CLASSNAME, DDR, PORT, TYPE) class CLASSNAME { protected:\
	CLASSNAME(){ }\
	public:\
	static __inline TYPE value(){ return  PORT;}\
	static __inline void value(TYPE aValue){ PORT = aValue;} \
	static __inline TYPE direction(){ return  DDR;} \
	static __inline void direction(TYPE aValue){ DDR = aValue;} \
}
#define MAKE_REG_8(ADDR) MAKE_REG(_P##ADDR, ADDR, uint8_t)
#define MAKE_PORT_8(DDR, PORT) MAKE_PORT(DDR##_##PORT, DDR, PORT, uint8_t)

template<typename Reg>
class Regs
{
	static __inline void setBits(typename Reg::Type aFlags)
	{
		Reg::value(Reg::value() | aFlags);
	}
	
	static __inline void clearBits(typename Reg::Type aFlags)
	{
		Reg::value(Reg::value() & ~aFlags);
	}

	static __inline void set(typename Reg::Type aFlags, bool aValue)
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
	
	static __inline void toggleBits(typename Reg::Type aFlags)
	{
		Reg::value(Reg::value() ^ aFlags);
	}

	static __inline void isBitsSet(typename Reg::Type aFlags)
	{
		return Reg::value() & aFlags == aFlags;
	}
	
};

template<typename Reg, uint16_t BitFlags>
struct Bits
{
	static __inline void set() { Regs<Reg>::setBits(BitFlags);}	
	static __inline void clear() { Regs<Reg>::clearBits(BitFlags);}
	static __inline bool isSet() { return Regs<Reg>::isBitsSet(BitFlags);}
};


#endif //__CORE_REG_H_