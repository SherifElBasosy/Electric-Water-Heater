#include "STD_Types.h"
#include "Bitwise_Operations.h"
#include "TWI_config.h"
#include "TWI_Int.h"
#include "TWI_Private.h"

void (*TWI_INT)();

void TWI_voidInit(){

	#if PRESCALER == PRESCALER_1
	CLEAR_BIT(TWSR , TWPS0);
	CLEAR_BIT(TWSR , TWPS1);
	#elif PRESCALER == PRESCALER_4
	SET_BIT(TWSR , TWPS0);
	CLEAR_BIT(TWSR , TWPS1);
	#elif PRESCALER == PRESCALER_16
	CLEAR_BIT(TWSR , TWPS0);
	SET_BIT(TWSR , TWPS1);
	#elif PRESCALER == PRESCALER_64
	SET_BIT(TWSR , TWPS0);
	SET_BIT(TWSR , TWPS1);
	#endif
	TWBR = BIT_RATE;

}

u8 TWI_u8Start(){
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while (GET_BIT(TWCR , TWINT) == 0);

	if((TWSR & 0xF8) == 0x08)
		return TRUE;
	else
		return FALSE;
}

void TWI_voidStop(){
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

u8 TWI_u8ReStart(){
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while (GET_BIT(TWCR , TWINT) == 0);

	if((TWSR & 0xF8) == 0x10)
		return TRUE;
	else
		return FALSE;
}

#if ACKNOWLEDGE == ACK_ENABLED

u8 TWI_u8SendAddressWrite(u8 Data){
	TWDR = Data;
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA) ;
	while (GET_BIT(TWCR , TWINT) == 0);

	if((TWSR & 0xF8) == 0x18)
		return TRUE;
	else
		return FALSE;
}

u8 TWI_u8SendData(u8 Data){
	TWDR = Data;
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while (GET_BIT(TWCR , TWINT) == 0);

	if((TWSR & 0xF8) == 0x28)
		return TRUE;
	else
		return FALSE;
}

u8 TWI_u8SendAddressRead(u8 Data){
	TWDR = Data;
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while (GET_BIT(TWCR , TWINT) == 0);

	if((TWSR & 0xF8) == 0x40)
		return TRUE;
	else
		return FALSE;
}


u8 TWI_u8ReadData(){
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while (GET_BIT(TWCR , TWINT) == 0);

	if((TWSR & 0xF8) == 0x50)
		return TWDR;
	else
		return FALSE;
}

#elif ACKNOWLEDGE == ACK_DISABLED

u8 TWI_u8SendAddressWrite(u8 Data){
	TWDR = Data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (GET_BIT(TWCR , TWINT) == 0);

	if((TWSR & 0xF8) == 0x20)
		return TRUE;
	else
		return FALSE;
}

u8 TWI_u8SendData(u8 Data){
	TWDR = Data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (GET_BIT(TWCR , TWINT) == 0);

	if((TWSR & 0xF8) == 0x30)
		return TRUE;
	else
		return FALSE;
}

u8 TWI_u8SendAddressRead(u8 Data){
	TWDR = Data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (GET_BIT(TWCR , TWINT) == 0);

	if((TWSR & 0xF8) == 0x48)
		return TRUE;
	else
		return FALSE;
}


u8 TWI_u8ReadData(){
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (GET_BIT(TWCR , TWINT) == 0);

	if((TWSR & 0xF8) == 0x58)
		return TWDR;
	else
		return FALSE;
}

#endif

void TWI_voidSetINTFunc(void (*ptr_func)()){
	TWI_INT = ptr_func;
}

void __vector_19 (void) __attribute__ ((signal,used,externally_visible)) ;\
void __vector_19 (void){

	(*TWI_INT)();
}
