#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidWriteByte(u16 Location , u8 Data);
u8 EEPROM_u8ReciveByte(u16 Location);

#endif
