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
#include <util/delay.h>

//Global Vars
static volatile u8 Heater_State = 0;
static volatile u8 Exit_Temp = 0;
static volatile u8 Temprature = 0;
static volatile u8 Exit_Current_State = 1;
static volatile u16 Average_Temp = 0;
static volatile u8 Measurment_Counts = 0;
volatile u8 DisplayTemp = 0;
//

void ToggleHeater_ON_OFF(){
	Exit_Current_State = 0;
}

void State_OFF(){

	//Test Case
	//EEPROM_voidWriteByte(1 , 50);
	//_delay_ms(1000);
	//
	Exit_Current_State = 1;

	//Disabling Timer and Seven Segments
	TIMER0_voidOVFINT_DISABLE();
	SevenSeg_voidDisplayOFF();

	//Turn Off Displays
	DIO_voidSetPINValue(Heating_Element_PORT , Heating_Element_PIN , DIO_LOW);
	DIO_voidSetPINValue(Cooling_Element_PORT , Cooling_Element_PIN , DIO_LOW);
	DIO_voidSetPINValue(STATE_LED_PORT , STATE_LED_PIN , DIO_LOW);

	//Set initial Temprature
	u8 Current_Temp = EEPROM_u8ReciveByte(1);
	if(Current_Temp < MIN_TEMP || Current_Temp > MAX_TEMP)
		Temprature = 60;
	else
		Temprature = Current_Temp;

	//

	while(Exit_Current_State){

	}
	State_ON();
}

void State_ON(){

	//Enabling and Setting Timer
	TIMER0_voidOVFINT_DISABLE();
	TIMER0_voidSetOVFINTFunc(Get_AverageTemprature);
	TIMER0_voidSetTCNT(203);
	TIMER0_voidOVFINT_ENABLE();

	Exit_Current_State = 1;

	while(Exit_Current_State){

		//Displaying Temprature
		SevenSeg_voidDisplay(Temprature);

		//Checking for Temprature Setting Change
		if((DIO_u8GetPINValue(UP_Button_PORT , UP_Button_PIN) == 0) || (DIO_u8GetPINValue(Down_Button_PORT , Down_Button_PIN) == 0)){
			_delay_ms(500);
			Temprature_SettingMODE();
			TIMER0_voidSetOVFINTFunc(Get_AverageTemprature);
			TIMER0_voidSetTCNT(203);
			TIMER0_voidOVFINT_ENABLE();
		}

		//Getting Current Water Temprature
		if(Measurment_Counts == 10){

			Average_Temp = Average_Temp / 10;

			if(Average_Temp < (Temprature - 5)){
				Average_Temp = 0;
				Measurment_Counts = 0;
				voidHeatingMode_ON();
			}
			else if (Average_Temp > (Temprature + 5)){
				Average_Temp = 0;
				Measurment_Counts = 0;
				voidCoolingMode_ON();
			}
			else{
				voidHeater_IdleState();
			}
		}
	}
	State_OFF();
}

void voidHeater_IdleState(){
	DIO_voidSetPINValue(Cooling_Element_PORT , Cooling_Element_PIN , DIO_LOW );
	DIO_voidSetPINValue(Heating_Element_PORT , Heating_Element_PIN , DIO_LOW );
	DIO_voidSetPINValue(STATE_LED_PORT , STATE_LED_PIN , DIO_LOW);
	Heater_State = IDLEMODE;
}

void voidHeatingMode_ON(){
	DIO_voidSetPINValue(Heating_Element_PORT , Heating_Element_PIN , DIO_HIGH );
	DIO_voidSetPINValue(Cooling_Element_PORT , Cooling_Element_PIN , DIO_LOW );
	Heater_State = HeatingMODE;
}

void voidCoolingMode_ON(){
	DIO_voidSetPINValue(Cooling_Element_PORT , Cooling_Element_PIN , DIO_HIGH );
	DIO_voidSetPINValue(Heating_Element_PORT , Heating_Element_PIN , DIO_LOW );
	DIO_voidSetPINValue(STATE_LED_PORT , STATE_LED_PIN , DIO_HIGH);
	Heater_State = CoolingMODE;
}

void Get_AverageTemprature(){

	static u8 ToggleLed = 0;
	static u8 OVFs = 0;
	OVFs++;

	if(OVFs == 13){
		Average_Temp += (ADC_GetResult(0) - 50);
		Measurment_Counts++;
		ToggleLed++;

		if((Heater_State == HeatingMODE) && (ToggleLed == 10)){
			DIO_voidTogglePIN(STATE_LED_PORT , STATE_LED_PIN);
			ToggleLed = 0;
		}

		OVFs = 0;
		TIMER0_voidSetTCNT(203);
	}
}


void Temprature_SettingMODE(){

	//Resetting Timer Settings
	TIMER0_voidOVFINT_DISABLE();
	TIMER0_voidSetOVFINTFunc(Exit_Temp_SettingMODE);
	TIMER0_voidSetTCNT(180);
	TIMER0_voidOVFINT_ENABLE();

	while(1){
		//Checking when to Exit this function
		if(Exit_Temp == 5){
			TIMER0_voidOVFINT_DISABLE();
			Exit_Temp = 0;
			break;
		}

		//Display Temprature on Seven Segment
		if(DisplayTemp)
			SevenSeg_voidDisplay(Temprature);

		//Checking for Increasing Temprature
		if((DIO_u8GetPINValue(UP_Button_PORT , UP_Button_PIN) == 0) && (Temprature < MAX_TEMP)){
			_delay_ms(500);
			Exit_Temp = 0;
			Temprature +=  5;
			EEPROM_voidWriteByte(1 , Temprature);
		}

		//Checking for Decreasing Temprature
		if ((DIO_u8GetPINValue(Down_Button_PORT , Down_Button_PIN) == 0) && (Temprature > MIN_TEMP)){
			_delay_ms(500);
			Exit_Temp = 0;
			Temprature -= 5;
			EEPROM_voidWriteByte(1 , Temprature);
		}
	}
}

void Exit_Temp_SettingMODE(){

	static u8 OVFs = 0;
	OVFs++;

	if(OVFs == 123){
		DisplayTemp ^= 1;
		Exit_Temp++;
		OVFs = 0;
		TIMER0_voidSetTCNT(180);
	}
}
