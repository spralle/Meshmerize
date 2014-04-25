#ifndef __ARCH_AVR_PORTS_H__
#define __ARCH_AVR_PORTS_H__

#include <avr/io.h>

#define MAKE_PORT(CLASSNAME, DDR, PORT, TYPE) class CLASSNAME { protected: \ 
  CLASSNAME(){ } \ 
public: \
  static __inline TYPE value(){ return  PORT;} \ 
  static __inline void value(TYPE aValue){ PORT = aValue;} \ 
  static __inline TYPE direction(){ return  DDR;} \ 
  static __inline void direction(TYPE aValue){ DDR = aValue;} \ 
} 
#define MAKE_PORT_8(DDR, PORT) AVROutputPin_F_named(DDR##_##PORT##_##PIN, DDR, PORT, uint8_t) 


typedef MAKE_PORT_8(PORTA, DDRA) PortA;
typedef MAKE_PORT_8(PORTB, DDRB) PortB;
typedef MAKE_PORT_8(PORTC, DDRC) PortC;
typedef MAKE_PORT_8(PORTD, DDRD) PortD;
typedef MAKE_PORT_8(PORTE, DDRE) PortE;
typedef MAKE_PORT_8(PORTF, DDRF) PortF;
typedef MAKE_PORT_8(PORTG, DDRG) PortG;


#endif //__ARCH_AVR_PORTS_H__