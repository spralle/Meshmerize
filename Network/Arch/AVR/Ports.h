#ifndef __ARCH_AVR_PORTS_H__
#define __ARCH_AVR_PORTS_H__

#include <avr/io.h>
#include "../../Core/Reg.h"
namespace Avr {


#ifdef PORTA
typedef MAKE_PORT_8(PORTA, DDRA) PortA;
#endif

#ifdef PORTB
typedef MAKE_PORT_8(PORTB, DDRB) PortB;
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