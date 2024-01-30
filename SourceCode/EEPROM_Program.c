#include "STD_Types.h"
#include "Bitwise_Operations.h"
#include "TWI_Int.h"
#include "EEPROM_Int.h"
#include "TWI_Private.h"

#define GetTWSR		(TWSR & 0xF8)

void EEPROM_voidWriteByte(u16 Location , u8 Data){


	u8 First_Location_Segment = (Location >> 8) & 0x03;
	u8 Address = 0b10100000 | (First_Location_Segment << 1);

	if(TWI_u8Start()){
		if(TWI_u8SendAddressWrite(Address)){
			if(TWI_u8SendData((u8) Location)){
				if(TWI_u8SendData(Data)){
					TWI_voidStop();
				}
			}
		}
	}

}

u8 EEPROM_u8ReciveByte(u16 Location){

	u8 First_Location_Segment = (Location >> 8) & 0x0F;
	u8 Address = 0b10100000 | (First_Location_Segment << 1);
	u8 Data = 0;

	if(TWI_u8Start()){
		if(TWI_u8SendAddressWrite(Address)){
			if(TWI_u8SendData((u8) Location)){
				if(TWI_u8ReStart()){
					if(TWI_u8SendAddressRead(Address+1)){
						Data = TWI_u8ReadData();
						TWI_voidStop();
					}
				}
			}
		}
	}
	return Data;
}

