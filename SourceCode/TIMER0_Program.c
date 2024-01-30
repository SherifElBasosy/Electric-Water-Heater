#include "Bitwise_Operations.h"
#include "STD_Types.h"
#include "TIMER0_Int.h"
#include "TIMER0_Private.h"
#include "TIMER0_Config.h"

void (*COMP_INT)();
void (*OVF_INT)();

void TIMER0_voidInit(){

	//Prescaler
	#if PRESCALER == CLOCK_NULL
	CLEAR_BIT(TCCR0 , CS00);
	CLEAR_BIT(TCCR0 , CS01);
	CLEAR_BIT(TCCR0 , CS02);
	#elif PRESCALER == PRESCALER_NULL
	SET_BIT(TCCR0 , CS00);
	CLEAR_BIT(TCCR0 , CS01);
	CLEAR_BIT(TCCR0 , CS02);
	#elif PRESCALER == PRESCALER_8
	CLEAR_BIT(TCCR0 , CS00);
	SET_BIT(TCCR0 , CS01);
	CLEAR_BIT(TCCR0 , CS02);
	#elif PRESCALER == PRESCALER_64
	SET_BIT(TCCR0 , CS00);
	SET_BIT(TCCR0 , CS01);
	CLEAR_BIT(TCCR0 , CS02);
	#elif PRESCALER == PRESCALER_256
	CLEAR_BIT(TCCR0 , CS00);
	CLEAR_BIT(TCCR0 , CS01);
	SET_BIT(TCCR0 , CS02);
	#elif PRESCALER == PRESCALER_1024
	SET_BIT(TCCR0 , CS00);
	CLEAR_BIT(TCCR0 , CS01);
	SET_BIT(TCCR0 , CS02);
	#elif PRESCALER == EXTCLK_FALLINGEDGE
	CLEAR_BIT(TCCR0 , CS00);
	SET_BIT(TCCR0 , CS01);
	SET_BIT(TCCR0 , CS02);
	#elif PRESCALER == EXTCLK_RISINGEDGE
	SET_BIT(TCCR0 , CS00);
	SET_BIT(TCCR0 , CS01);
	SET_BIT(TCCR0 , CS02);
	#endif

	//WGM
	#if WGM == NORMAL_WGM
	CLEAR_BIT(TCCR0 , WGM00);
	CLEAR_BIT(TCCR0 , WGM01);
	#elif WGM == PWM_WGM
	SET_BIT(TCCR0 , COM00);
	CLEAR_BIT(TCCR0 , COM01);
	#elif WGM == CTC_WGM
	CLEAR_BIT(TCCR0 , COM00);
	SET_BIT(TCCR0 , COM01);
	#elif WGM == FASTPWM_WGM
	SET_BIT(TCCR0 , COM00);
	SET_BIT(TCCR0 , COM01);
	#endif

	//COM
	#if COM == NORMAL_OC0
	CLEAR_BIT(TCCR0 , COM00);
	CLEAR_BIT(TCCR0 , COM01);
	#elif COM == TOGGLE_OC0
	SET_BIT(TCCR0 , COM00);
	CLEAR_BIT(TCCR0 , COM01);
	#elif COM == CLEAR_OC0
	CLEAR_BIT(TCCR0 , COM00);
	SET_BIT(TCCR0 , COM01);
	#elif COM == SET_OC0
	SET_BIT(TCCR0 , COM00);
	SET_BIT(TCCR0 , COM01);
	#endif
}

void TIMER0_voidSetTCNT(u8 Value){
	TCNT0 = Value;
}

void TIMER0_voidSetOCR0(u8 Value){
	OCR0 = Value;
}

void TIMER0_voidOVFINT_ENABLE(){
	SET_BIT(TIMSK , TOIE0);
}

void TIMER0_voidOVFINT_DISABLE(){
	CLEAR_BIT(TIMSK , TOIE0);
}

void TIMER0_voidCOMPINT_ENABLE(){
	SET_BIT(TIMSK , OCIE0);
}

void TIMER0_voidCOMPINT_DISABLE(){
	CLEAR_BIT(TIMSK , OCIE0);
}

//COMP INT
void TIMER0_voidSetCOMPINTFunc(void (*ptr_func)){
	COMP_INT = ptr_func;
}

//OVF INT
void TIMER0_voidSetOVFINTFunc(void (*ptr_func)()){
	OVF_INT = ptr_func;
}

void __vector_10 (void) __attribute__ ((signal,used , externally_visible)) ; \
void __vector_10 (void){
	(*COMP_INT)();
}

void __vector_11 (void) __attribute__ ((signal,used , externally_visible)) ; \
void __vector_11 (void){
	(*OVF_INT)();
}
