#ifndef EXTINT_PRIVATE_H_
#define EXTINT_PRIVATE_H_

#define MCUCR 	*((volatile u8*) 0x55)
#define MCUCSR	*((volatile u8*) 0x54)
#define GICR	*((volatile u8*) 0x5B)

//MCUCR
#define ISC00	0
#define ISC01	1
#define ISC10	2
#define ISC11	3

//MCUCSR
#define ISC2	6

//GICR
#define INT0	6
#define INT1	7
#define INT2	5

#define ENABLE		0
#define DISABLE		1

#define LOW_LEVEL		0
#define ANY_CHANGE  	1
#define FALLING_EDGE	2
#define RISING_EDGE		3


#endif
