#ifndef __ARCH_AVR_PORTS_H__
#define __ARCH_AVR_PORTS_H__

#include <avr/io.h>
#include "../../Core/Reg.h"
namespace Avr {


#ifdef PORTA
	typedef __MAKE_REG_8(PORTA) __RPORTA;
	typedef __MAKE_REG_8(DDRA) __RDDRA;
	typedef __MAKE_REG_8(PINA) __RPINA;
	typedef Port<__RPORTA, __RDDRA, __RPINA> PortA;
#endif

#ifdef PORTB
	typedef __MAKE_REG_8(PORTB) __RPORTB;
	typedef __MAKE_REG_8(DDRB) __RDDRB;
	typedef __MAKE_REG_8(PINB) __RPINB;
	typedef Port<__RPORTB, __RDDRB, __RPINB> PortB;
#endif

#ifdef PORTC
	typedef __MAKE_REG_8(PORTC) __RPORTC;
	typedef __MAKE_REG_8(DDRC) __RDDRC;
	typedef __MAKE_REG_8(PINC) __RPINC;
	typedef Port<__RPORTC, __RDDRC, __RPINC> PortC;
#endif
#ifdef PORTD
	typedef __MAKE_REG_8(PORTD) __RPORTD;
	typedef __MAKE_REG_8(DDRD) __RDDRD;
	typedef __MAKE_REG_8(PIND) __RPIND;
	typedef Port<__RPORTD, __RDDRD, __RPIND> PortD;
#endif


}
#endif //__ARCH_AVR_PORTS_H__