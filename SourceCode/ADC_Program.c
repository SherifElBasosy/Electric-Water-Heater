#include "Bitwise_Operations.h"
#include "ADC_Private.h"
#include "ADC_Config.h"
#include "STD_Types.h"
#include <avr/interrupt.h>

void (*ADC_INT)();

void ADC_voidEnable();

void ADC_voidInit(){

	#if VREF == AREF
	CLEAR_BIT(ADMUX , REFS0);
	CLEAR_BIT(ADMUX , REFS1);
	#elif VREF == AVCC
	SET_BIT(ADMUX , REFS0);
	CLEAR_BIT(ADMUX , REFS1);
	#elif VREF == Internal_Voltage
	SET_BIT(ADMUX , REFS0);
	SET_BIT(ADMUX , REFS1);
	#endif

	#if ADJUSTMENT_MODE == RIGHT_ADJ
	CLEAR_BIT(ADMUX , ADLAR);
	#elif ADJUSTMENT_MODE == LEFT_ADJ
	SET_BIT(ADMUX , ADLAR);
	#endif

	#if PRESCALER == ADC_PRESCALER_2
	CLEAR_BIT(ADCSRA , ADPS0);
	CLEAR_BIT(ADCSRA , ADPS1);
	CLEAR_BIT(ADCSRA , ADPS2);
	#elif PRESCALER == ADC_PRESCALER_4
	CLEAR_BIT(ADCSRA , ADPS0);
	SET_BIT(ADCSRA , ADPS1);
	CLEAR_BIT(ADCSRA , ADPS2);
	#elif PRESCALER == ADC_PRESCALER_8
	SET_BIT(ADCSRA , ADPS0);
	SET_BIT(ADCSRA , ADPS1);
	CLEAR_BIT(ADCSRA , ADPS2);
	#elif PRESCALER == ADC_PRESCALER_16
	CLEAR_BIT(ADCSRA , ADPS0);
	CLEAR_BIT(ADCSRA , ADPS1);
	SET_BIT(ADCSRA , ADPS2);
	#elif PRESCALER == ADC_PRESCALER_32
	SET_BIT(ADCSRA , ADPS0);
	CLEAR_BIT(ADCSRA , ADPS1);
	SET_BIT(ADCSRA , ADPS2);
	#elif PRESCALER == ADC_PRESCALER_64
	CLEAR_BIT(ADCSRA , ADPS0);
	SET_BIT(ADCSRA , ADPS1);
	SET_BIT(ADCSRA , ADPS2);
	#elif PRESCALER == ADC_PRESCALER_128
	SET_BIT(ADCSRA , ADPS0);
	SET_BIT(ADCSRA , ADPS1);
	SET_BIT(ADCSRA , ADPS2);
	#endif

	#if AUTOTRIGGER_SOURCE == AUTOTRIGGER_DISABLE
	CLEAR_BIT(ADCSRA , ADATE);
	CLEAR_BIT(SFIOR , ADTS0);
	CLEAR_BIT(SFIOR , ADTS1);
	CLEAR_BIT(SFIOR , ADTS2);
	#elif AUTOTRIGGER_SOURCE == FREE_RUNNING
	SET_BIT(ADCSRA , ADATE);
	CLEAR_BIT(SFIOR , ADTS0);
	CLEAR_BIT(SFIOR , ADTS1);
	CLEAR_BIT(SFIOR , ADTS2);
	#elif AUTOTRIGGER_SOURCE == ANALOG_COMPARATOR
	SET_BIT(ADCSRA , ADATE);
	SET_BIT(SFIOR , ADTS0);
	CLEAR_BIT(SFIOR , ADTS1);
	CLEAR_BIT(SFIOR , ADTS2);
	#elif AUTOTRIGGER_SOURCE == EXTINT_REQUEST
	SET_BIT(ADCSRA , ADATE);
	CLEAR_BIT(SFIOR , ADTS0);
	SET_BIT(SFIOR , ADTS1);
	CLEAR_BIT(SFIOR , ADTS2);
	#endif

	ADC_voidEnable();
}

void ADC_voidEnable(){
	SET_BIT(ADCSRA , ADEN);
}

void ADC_voidDisable(){
	CLEAR_BIT(ADCSRA , ADEN);
}

void ADC_voidStartConversion(){
	SET_BIT(ADCSRA , ADSC);
}

u8 ADC_u8IsConversionComplete(){
	return (GET_BIT(ADCSRA , ADSC));
}

u8 ADC_GetResult(u8 Channel){

	ADMUX &= 0xE0;
	Channel &= 0x1F;
	ADMUX |= Channel;

	ADC_voidStartConversion();
	while(ADC_u8IsConversionComplete());

	return ADCH;
}

void ADC_voidAutoTriggerEN(){
	SET_BIT(ADCSRA , ADATE);
}

void ADC_voidAutoTriggerDIS(){
	CLEAR_BIT(ADCSRA , ADATE);
}

void ADC_INTEnable(){
	SET_BIT(ADCSRA , ADIE);
}

void ADC_INTDisable(){
	CLEAR_BIT(ADCSRA , ADIE);
}

void ADC_voidSetINTFunc(void (*ptr_func)()){
	ADC_INT = ptr_func;
}

void __vector_16 (void) __attribute__ ((signal,used,externally_visible)); \
void __vector_16 (void){
	(*ADC_INT)();
}
