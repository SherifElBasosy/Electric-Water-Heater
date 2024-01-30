#include "STD_Types.h"
#include "Bitwise_Operations.h"
#include "EXTINT_Private.h"
#include "EXTINT_Config.h"

void (*INT0_INTFunc)();
void (*INT1_INTFunc)();
void (*INT2_INTFunc)();

void EXITINT_voidInit(){

	#if INT0_ENABLE == ENABLE
	#if Sense_Control == LOW_LEVEL
	CLEAR_BIT(MCUCR , ISC00);
	CLEAR_BIT(MCUCR , ISC01);
	#elif Sense_Control == ANY_CHANGE
	SET_BIT(MCUCR , ISC00);
	CLEAR_BIT(MCUCR , ISC01);
	#elif Sense_Control == FALLING_EDGE
	CLEAR_BIT(MCUCR , ISC00);
	SET_BIT(MCUCR , ISC01);
	#elif Sense_Control == RISING_EDGE
	SET_BIT(MCUCR , ISC00);
	SET_BIT(MCUCR , ISC01);
	#endif
	#endif

	#if INT1_ENABLE == ENABLE
	#if Sense_Control == LOW_LEVEL
	CLEAR_BIT(MCUCR , ISC10);
	CLEAR_BIT(MCUCR , ISC11);
	#elif Sense_Control == ANY_CHANGE
	SET_BIT(MCUCR , ISC10);
	CLEAR_BIT(MCUCR , ISC11);
	#elif Sense_Control == FALLING_EDGE
	CLEAR_BIT(MCUCR , ISC10);
	SET_BIT(MCUCR , ISC11);
	#elif Sense_Control == RISING_EDGE
	SET_BIT(MCUCR , ISC10);
	SET_BIT(MCUCR , ISC11);
	#endif
	#endif

	#if INT2_ENABLE == ENABLE
	#if Sense_Control == FALLING_EDGE
	CLEAR_BIT(MCUCSR , ISC2);
	#elif Sense_Control == RISING_EDGE
	SET_BIT(MCUCSR , ISC2);
	#endif
	#endif
}

void EXTINT_voidINTEnable(u8 INT_num){

	if(INT_num > 2 || INT_num < 0)
		return;

	switch (INT_num){

		case 0:
			SET_BIT(GICR , INT0);
			break;

		case 1:
			SET_BIT(GICR , INT1);
			break;

		case 2:
			SET_BIT(GICR , INT2);
		break;

}

}

void EXTINT_voidINTDisable(u8 INT_num){

	if(INT_num > 2 || INT_num < 0)
		return;

	switch (INT_num){

		case 0:
			CLEAR_BIT(GICR , INT0);
			break;

		case 1:
			CLEAR_BIT(GICR , INT1);
			break;

		case 2:
			CLEAR_BIT(GICR , INT2);
		break;

}

}

void EXTINT0_Callback(void (*ptr_func)()){
	INT0_INTFunc = ptr_func;
}

void EXTINT1_Callback(void (*ptr_func)()){
	INT1_INTFunc = ptr_func;
}

void EXTINT2_Callback(void (*ptr_func)()){
	INT2_INTFunc = ptr_func;
}

void __vector_1 (void) __attribute__ ((signal,used , externally_visible)) ; \
void __vector_1 (void){
	(*INT0_INTFunc)();
}

void __vector_2 (void) __attribute__ ((signal,used , externally_visible)) ; \
void __vector_2 (void){
	(*INT1_INTFunc)();
}

void __vector_3 (void) __attribute__ ((signal,used , externally_visible)) ; \
void __vector_3 (void){
	(*INT2_INTFunc)();
}
