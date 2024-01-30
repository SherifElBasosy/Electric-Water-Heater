#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADMUX	*((volatile u8*) 0x27)	//Contans Channels in first 5 bits
#define ADCSRA	*((volatile u8*) 0x26)
#define ADCH	*((volatile u8*) 0x25)
#define ADCL	*((volatile u8*) 0x24)
#define SFIOR	*((volatile u8*) 0x50)


//ADMUX
#define REFS0	6
#define REFS1	7
#define ADLAR	5	//Left Adjustment

//ADCSRA
#define ADEN	7
#define ADSC	6	//Remains 1 as conversion incomplete 0 when it is complete
#define ADATE	5	//Autotrigger enable
#define ADIF	4	//set to 1 when conversion is complete
#define ADIE	3
#define ADPS0	0
#define ADPS1	1
#define ADPS2	2

//SFIOR
#define ADTS0	5
#define ADTS1	6
#define ADTS2	7

//Configs
#define AREF				0
#define AVCC				1
#define Internal_Voltage	2

#define ADC_PRESCALER_2		0
#define ADC_PRESCALER_4		1
#define ADC_PRESCALER_8		2
#define ADC_PRESCALER_16	3
#define ADC_PRESCALER_32	4
#define ADC_PRESCALER_64	5
#define ADC_PRESCALER_128	6

#define RIGHT_ADJ	0
#define LEFT_ADJ	1

#define ADC0	0
#define ADC1	1
#define ADC2	2
#define ADC3	3
#define ADC4	4
#define ADC5	5
#define ADC6	6
#define ADC7	7

#define AUTOTRIGGER_DISABLE		0
#define FREE_RUNNING			1
#define ANALOG_COMPARATOR		2
#define EXTINT_REQUEST			3

#endif
