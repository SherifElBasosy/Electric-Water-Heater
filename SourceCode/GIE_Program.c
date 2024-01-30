#include "STD_Types.h"
#include "Bitwise_Operations.h"

#define SREG	*((volatile u8*) 0x5F)

void GlobalINTEnable(){
	SET_BIT(SREG , 7);
}

void GlobalINTDisable(){
	CLEAR_BIT(SREG , 7);
}
