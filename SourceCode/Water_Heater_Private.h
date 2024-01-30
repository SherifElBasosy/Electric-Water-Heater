#ifndef WATER_HEATER_PRIVATE_H_
#define WATER_HEATER_PRIVATE_H_

enum MODES{
	HeatingMODE,
	CoolingMODE,
	IDLEMODE
};

#define Heating_Element_PORT	DIO_PORTD
#define Cooling_Element_PORT	DIO_PORTD
#define STATE_LED_PORT			DIO_PORTC
#define UP_Button_PORT			DIO_PORTA
#define Down_Button_PORT		DIO_PORTA

#define UP_Button_PIN			DIO_PIN6
#define Down_Button_PIN			DIO_PIN7
#define Heating_Element_PIN		DIO_PIN6
#define Cooling_Element_PIN		DIO_PIN7
#define STATE_LED_PIN			DIO_PIN7


#define MAX_TEMP	75
#define MIN_TEMP	35

#endif
