#ifndef TWI_INT_H_
#define TWI_INT_H_

void TWI_voidInit();
u8 TWI_u8Start();
u8 TWI_u8ReStart();
u8 TWI_u8SendAddressWrite(u8 Data);
u8 TWI_u8SendData(u8 Data);
u8 TWI_u8SendAddressRead(u8 Data);
void TWI_voidStop();
u8 TWI_u8ReadData();

#endif
