#ifndef __ARCH_AVR_PORTS_H__
#define __ARCH_AVR_PORTS_H__

#include <avr/io.h>
#include "../../Core/Reg.h"
namespace Avr {


#ifdef PORTA
	typedef __MAKE_REG_8(PORTA) RPORTA;
	typedef __MAKE_REG_8(DDRA) RDDRA;
	typedef __MAKE_REG_8(PINA) RPINA;
	typedef Port<RPORTA, RDDRA, RPINA> PortA;
#endif

#ifdef PORTB
	typedef __MAKE_REG_8(PORTB) RPORTB;
	typedef __MAKE_REG_8(DDRB) RDDRB;
	typedef __MAKE_REG_8(PINB) RPINB;
	typedef Port<RPORTB, RDDRB, RPINB> PortB;
#endif

#ifdef PORTC
	typedef __MAKE_REG_8(PORTC) RPORTC;
	typedef __MAKE_REG_8(DDRC) RDDRC;
	typedef __MAKE_REG_8(PINC) RPINC;
	typedef Port<RPORTC, RDDRC, RPINC> PortC;
#endif
#ifdef PORTD
	typedef __MAKE_REG_8(PORTD) RPORTD;
	typedef __MAKE_REG_8(DDRD) RDDRD;
	typedef __MAKE_REG_8(PIND) RPIND;
	typedef Port<RPORTD, RDDRD, RPIND> PortD;
#endif

#ifdef UBRR0
	typedef __MAKE_REG_8(UBRR0H) RUBRR0H;
	typedef __MAKE_REG_8(UBRR0L) RUBRR0L;
	typedef __MAKE_REG_16(UBRR0) RUBRR0;
#endif

#ifdef UCSR0A
	typedef __MAKE_REG_8(UCSR0A) RUCSR0A;
	typedef Bit<RUCSR0A, RXC0> BRXC0;//USART Receive Complete. Set when data is available and the data register has not be read yet.
	typedef Bit<RUCSR0A, TXC0> BTXC0;//USART Transmit Complete. Set when all data has transmitted.
	typedef Bit<RUCSR0A, UDRE0> BUDRE0; //USART Data Register Empty. Set when the UDR0 register is empty and new data can be transmitted.
	typedef Bit<RUCSR0A, FE0> BFE0;//Frame Error. Set when next byte in the UDR0 register has a framing error
	typedef Bit<RUCSR0A, DOR0> BDOR0; //Data OverRun. Set when the UDR0 was not read before the next frame arrived.
	typedef Bit<RUCSR0A, UPE0> BUPE0;//USART Parity Error. Set when next frame in the UDR0 has a parity error.
	typedef Bit<RUCSR0A, U2X0> BU2X0;//USART Double Transmission Speed. When set decreases the bit time by half doubling the speed.
	typedef Bit<RUCSR0A, MPCM0> BMPCM0;//Multi-processor Communication Mode. When set incoming data is ignored if no addressing information is provided
#endif

#ifdef UCSR0B
	typedef __MAKE_REG_8(UCSR0B) RUCSR0B;
	typedef Bit<RUCSR0B, TXB80> BTXB80;//Transmit Data Bit 8. When using 8 bit transmission the 8th bit to be submitted.
	typedef Bit<RUCSR0B, RXB80> BRXB80;//Receive Data Bit 8. When using 8 bit transmission the 8th bit received.
	typedef Bit<RUCSR0B, UCSZ02> BUCSZ02; //USART Character Size 0. Used together with UCSZ01 and UCSZ00 to set data frame size. Available sizes are 5-bit (000), 6-bit (001), 7-bit (010), 8-bit (011) and 9-bit (111).
	typedef Bit<RUCSR0B, TXEN0> BTXEN0;//Transmitter enable. Set to enable transmitter.
	typedef Bit<RUCSR0B, RXEN0> BRXEN0; //Receiver Enable. Set to enable receiver.
	typedef Bit<RUCSR0B, UDRIE0> BUDRIE0;//USART Data Register Empty Interrupt Enable. Set to allow data register empty interrupts.
	typedef Bit<RUCSR0B, TXCIE0> BTXCIE0;//TX Complete Interrupt Enable. Set to allow transmission complete interrupts.
	typedef Bit<RUCSR0B, RXCIE0> BRXCIE0;//RX Complete Interrupt Enable. Set to allow receive complete interrupts.
#endif

#ifdef UCSR0C
	typedef __MAKE_REG_8(UCSR0C) RUCSR0C;
#endif

#ifdef UDR0
	typedef __MAKE_REG_8(UDR0) RUDR0;
#endif
#ifdef SPCR
	typedef __MAKE_REG_8(SPCR) RSPCR;
	typedef Bit<RSPCR, MSTR> BMSTR;
	typedef Bit<RSPCR, SPE> BSPE;
	typedef Bit<RSPCR, SPR0> BSPR0;
#endif
#ifdef SPDR
	typedef __MAKE_REG_8(SPDR) RSPDR;
#endif
#ifdef SPSR
	typedef __MAKE_REG_8(SPSR) RSPSR;
	typedef Bit<RSPSR, SPIF> BSPIF;
	typedef Bit<RSPSR, DORD> BDORD;
#endif


}
#endif //__ARCH_AVR_PORTS_H__