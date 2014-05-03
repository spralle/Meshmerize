/*
 * Reg.h
 *
 * Created: 2014-04-25 23:04:27
 *  Author: emil
 */ 


#ifndef __CORE_REG_H_
#define __CORE_REG_H_

	typedef volatile uint16_t& reg16_t;
	typedef volatile uint8_t& reg8_t;

namespace Internal
{
	template<typename Impl> 
	struct Reg8
	{
		typedef uint8_t Type;
		typedef uint8_t RegType;
		
		inline static RegType value() { return Impl::addr();}
		inline static void value(Type aBits) { Impl::addr() = aBits;}
	};
	template<typename Impl>
	struct Reg16
	{
		typedef uint16_t Type;
		typedef reg16_t RegType;
		
		inline static RegType value() { return Impl::addr();}
		inline static void value(Type aBits) { Impl::addr() = aBits;}
		
		struct Low :  Reg8<Low>
		{
			 static inline reg8_t value() { return (reg8_t)Impl::addr(); } 
		};
		struct High :  Reg8<High>
		{
			static inline reg8_t value() { return *(((volatile uint8_t *)(&Impl::addr())) + 1); }
		};
	};
}



#define __MAKE_REG(CLASSNAME, ADDR, TYPE, SIZE) struct CLASSNAME:Internal::Reg##SIZE<CLASSNAME> { \
	static inline TYPE addr(){ return  ADDR;}\
}

#define __MAKE_PORT(CLASSNAME, DDR, PORT, TYPE) class CLASSNAME { protected:\
	CLASSNAME(){ }\
	public:\
	static inline TYPE value(){ return  PORT;}\
	static inline void value(TYPE aValue){ PORT = aValue;} \
	static inline TYPE direction(){ return  DDR;} \
	static inline void direction(TYPE aValue){ DDR = aValue;} \
}
#define __MAKE_REG_8(ADDR) __MAKE_REG(_P##ADDR, ADDR, reg8_t,8)
#define __MAKE_REG_16(ADDR) __MAKE_REG(_P##ADDR, ADDR, reg16_t,16)
#define __MAKE_PORT_8(DDR, PORT) __MAKE_PORT(DDR##_##PORT, DDR, PORT, uint8_t)

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

	static inline bool isBitsSet(typename Reg::Type aFlags)
	{
		return (Reg::value() & aFlags) == aFlags;
	}
	
};

template<typename Reg, uint16_t BitFlags>
struct Bits
{
	static inline void setHigh() { Regs<Reg>::setBits(BitFlags);}	
	static inline void setLow() { Regs<Reg>::clearBits(BitFlags);}
	static inline bool isHigh() { return Regs<Reg>::isBitsSet(BitFlags);}
};

template<typename Reg, uint8_t BitNumber>
struct Bit : Bits<Reg, 1<<BitNumber>
{
	
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