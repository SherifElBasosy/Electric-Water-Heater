#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCCR0	*((volatile u8*) 0x53)
#define TCNT0	*((volatile u8*) 0x52)
#define OCR0	*((volatile u8*) 0x5C)
#define TIMSK	*((volatile u8*) 0x59)


//TCCR0

#define CS00	0
#define CS01	1
#define CS02	2
#define WGM00	6
#define WGM01	3
#define COM00	4
#define COM01	5
#define FOC0	7


#define NORMAL_WGM		0
#define PWM_WGM			1
#define CTC_WGM			2
#define FASTPWM_WGM		3

#define NORMAL_OC0		0	//Normal (PWM)		//Normal (Fast PWM)
#define TOGGLE_OC0		1
#define CLEAR_OC0		2	//Clear on upcounting , Set on downcounting (PWM)	//Clear OC0 , set it on TOP (Fast PWM)
#define SET_OC0			3	//Set on upcounting , Clear on downcounting (PWM)	//Set OC0 , Clear it on TOP (Fast PWM)

#define CLOCK_NULL			0
#define PRESCALER_NULL		1
#define PRESCALER_8			2
#define PRESCALER_64		3
#define PRESCALER_256		4
#define PRESCALER_1024		5
#define EXTCLK_FALLINGEDGE	6
#define EXTCLK_RISINGEDGE	7

//TIMSK
#define TOIE0	0
#define OCIE0	1

//TIFR
#define TOV0	0	//Overflow
#define	OCF0	1	//Output compare flag

#endif
