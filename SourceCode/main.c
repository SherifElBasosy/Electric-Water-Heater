#include "STD_Types.h"
#include "Bitwise_Operations.h"
#include "DIO_private.h"
#include "DIO_Config.h"
#include "DIO_Int.h"
#include "ADC_Int.h"
#include "EEPROM_Int.h"
#include "Seven_Seg_Int.h"
#include "TIMER0_Int.h"
#include "EXTINT_Int.h"
#include "TWI_Int.h"
#include "Water_Heater_Int.h"
#include "Water_Heater_Private.h"
#include "GIE_Int.h"

int main(){

	//Initializing Drivers
	ADC_voidInit();
	TWI_voidInit();
	TIMER0_voidInit();
	SevenSeg_voidinit();
	EXITINT_voidInit();
	GlobalINTEnable();

	//Setting up Directions
	DIO_voidSetPORTDir(Heating_Element_PORT , Heating_Element_PIN , DIO_OUTPUT);
	DIO_voidSetPORTDir(Cooling_Element_PORT , Cooling_Element_PIN , DIO_OUTPUT);
	DIO_voidSetPORTDir(STATE_LED_PORT , STATE_LED_PIN , DIO_OUTPUT);
	DIO_voidSetPORTDir(UP_Button_PORT , UP_Button_PIN , DIO_INPUT);
	DIO_voidSetPORTDir(Down_Button_PORT , Down_Button_PIN , DIO_INPUT);
	DIO_voidSetPORTDir(DIO_PORTD , DIO_PIN0 , DIO_OUTPUT);

	//Setting DIO to Pull Up
	DIO_voidSetPINValue(UP_Button_PORT , UP_Button_PIN , DIO_HIGH);
	DIO_voidSetPINValue(Down_Button_PORT , Down_Button_PIN , DIO_HIGH);

	//Setting Interrupt Functions
	EXTINT_voidINTEnable(0);
	EXTINT0_Callback(ToggleHeater_ON_OFF);

	State_OFF();

return 0;
}

