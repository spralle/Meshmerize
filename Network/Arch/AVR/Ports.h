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
//typedef MAKE_PORT_8(PORTB, DDRB) PortB;
	typedef __MAKE_REG_8(PORTB) __RPORTB;
	typedef __MAKE_REG_8(DDRB) __RDDRB;
	typedef __MAKE_REG_8(PINB) __RPINB;
	typedef Port<__RPORTB, __RDDRB, __RPINB> PortB;
#endif

#ifdef PORTC
typedef MAKE_PORT_8(PORTC, DDRC) PortC;
#endif
#ifdef PORTD
typedef MAKE_PORT_8(PORTD, DDRD) PortD;
#endif
#ifdef PORTE
typedef MAKE_PORT_8(PORTE, DDRE) PortE;
#endif
#ifdef PORTF
typedef MAKE_PORT_8(PORTF, DDRF) PortF;
#endif
#ifdef PORTG
typedef MAKE_PORT_8(PORTG, DDRG) PortG;
#endif

}
#endif //__ARCH_AVR_PORTS_H__