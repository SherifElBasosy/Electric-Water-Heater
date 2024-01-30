#include "STD_Types.h"
#include "Bitwise_Operations.h"
#include "DIO_Int.h"
#include "DIO_private.h"
#include "DIO_Config.h"

void DIO_voidSetPORTDir(u8 PORT , u8 PIN , u8 Direction){

	if(PORT > Total_Ports || PORT < 0 || PIN > Total_Pins || PIN < 0)
		return;

	switch(PORT){

		case DIO_PORTA:

			switch(Direction){

				case DIO_INPUT:
					CLEAR_BIT(DDRA , PIN);
				break;

				case DIO_OUTPUT:
					SET_BIT(DDRA , PIN);
				break;

			}
		break;

		case DIO_PORTB:

			switch(Direction){

				case DIO_INPUT:
					CLEAR_BIT(DDRB , PIN);
				break;

				case DIO_OUTPUT:
					SET_BIT(DDRB , PIN);
				break;

			}
		break;

		case DIO_PORTC:

			switch(Direction){

				case DIO_INPUT:
					CLEAR_BIT(DDRC , PIN);
				break;

				case DIO_OUTPUT:
					SET_BIT(DDRC , PIN);
				break;

			}
		break;

		case DIO_PORTD:

			switch(Direction){

				case DIO_INPUT:
					CLEAR_BIT(DDRD , PIN);
				break;

				case DIO_OUTPUT:
					SET_BIT(DDRD , PIN);
				break;

			}
		break;

	}

}

/****************************************************/

void DIO_voidSetPINValue(u8 PORT , u8 PIN , u8 Value){

	if(PORT > Total_Ports || PORT < 0 || PIN > Total_Pins || PIN < 0)
		return;

	switch(PORT){

		case DIO_PORTA:

			switch(Value){

				case DIO_LOW:
					CLEAR_BIT(PORTA , PIN);
				break;

				case DIO_HIGH:
					SET_BIT(PORTA , PIN);
				break;

			}
		break;

		case DIO_PORTB:

			switch(Value){

				case DIO_LOW:
					CLEAR_BIT(PORTB , PIN);
				break;

				case DIO_HIGH:
					SET_BIT(PORTB , PIN);
				break;

			}
		break;

		case DIO_PORTC:

			switch(Value){

				case DIO_LOW:
					CLEAR_BIT(PORTC , PIN);
				break;

				case DIO_HIGH:
					SET_BIT(PORTC , PIN);
				break;

			}
		break;

		case DIO_PORTD:

			switch(Value){

				case DIO_LOW:
					CLEAR_BIT(PORTD , PIN);
				break;

				case DIO_HIGH:
					SET_BIT(PORTD , PIN);
				break;

			}
		break;
	}

}

/************************************************************/

u8 DIO_u8GetPINValue(u8 PORT , u8 PIN){

	if(PORT > Total_Ports || PORT < 0 || PIN > Total_Pins || PIN < 0)
		return 0;

	u8 Value;

	switch(PORT){

		case DIO_PORTA:
			Value = GET_BIT(PINA , PIN);
		break;

		case DIO_PORTB:
			Value = GET_BIT(PINB , PIN);
		break;

		case DIO_PORTC:
			Value = GET_BIT(PINC , PIN);
		break;

		case DIO_PORTD:
			Value = GET_BIT(PIND , PIN);
		break;

	}

	return Value;

}

/**************************************************************/

void DIO_voidTogglePIN(u8 PORT , u8 PIN){

	if(PORT > Total_Ports || PORT < 0 || PIN > Total_Pins || PIN < 0)
		return;

	switch(PORT){

	case DIO_PORTA:
		TOGGLE_BIT(PORTA , PIN);
	break;

	case DIO_PORTB:
		TOGGLE_BIT(PORTB , PIN);
	break;

	case DIO_PORTC:
		TOGGLE_BIT(PORTC , PIN);
	break;

	case DIO_PORTD:
		TOGGLE_BIT(PORTD , PIN);
	break;

	}

}

/**************************************************************/

void DIO_voidSetPORTValue(u8 PORT , u8 Value){

	if(PORT > Total_Ports || PORT < 0)
		return;

	switch(PORT){

	case DIO_PORTA:
		PORTA = Value;
	break;

	case DIO_PORTB:
		PORTB = Value;
	break;

	case DIO_PORTC:
		PORTC = Value;
	break;

	case DIO_PORTD:
		PORTD = Value;
	break;

	}

}
