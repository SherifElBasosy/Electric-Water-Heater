#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

//DIO Registers

//PORTA
#define PORTA	*((volatile u8*) 0x3B)
#define DDRA	*((volatile u8*) 0x3A)
#define PINA	*((volatile u8*) 0x39)

//PORTB
#define PORTB	*((volatile u8*) 0x38)
#define DDRB	*((volatile u8*) 0x37)
#define PINB	*((volatile u8*) 0x36)

//PORTC
#define PORTC	*((volatile u8*) 0x35)
#define DDRC	*((volatile u8*) 0x34)
#define PINC	*((volatile u8*) 0x33)

//PORTD
#define PORTD	*((volatile u8*) 0x32)
#define DDRD	*((volatile u8*) 0x31)
#define PIND	*((volatile u8*) 0x30)

/****************************************/

#define Total_Ports		3
#define Total_Pins		7

//DIO Registers Given Names

#define	DIO_PORTA	0
#define	DIO_PORTB	1
#define	DIO_PORTC	2
#define	DIO_PORTD	3



#endif
