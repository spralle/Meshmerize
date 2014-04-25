#ifndef __ARCH_AVR_PORTS_H__
#define __ARCH_AVR_PORTS_H__

#include <avr/io.h>

#define MAKE_PORT(CLASSNAME, DDR, PORT, TYPE) class CLASSNAME { protected:\
  CLASSNAME(){ }\
public:\
  static __inline TYPE value(){ return  PORT;}\
  static __inline void value(TYPE aValue){ PORT = aValue;} \
  static __inline TYPE direction(){ return  DDR;} \
  static __inline void direction(TYPE aValue){ DDR = aValue;} \
} 
#define MAKE_PORT_8(DDR, PORT) MAKE_PORT(DDR##_##PORT##_##PIN, DDR, PORT, uint8_t) 


#ifdef PORTA
typedef MAKE_PORT_8(PORTA, DDRA) PortA;
#endif

#ifdef PORTA
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

#endif //__ARCH_AVR_PORTS_H__