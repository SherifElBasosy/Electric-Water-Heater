#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

void DIO_voidSetPORTDir(u8 PORT , u8 PIN , u8 Direction);
void DIO_voidSetPINValue(u8 PORT , u8 PIN , u8 Value);
u8 DIO_u8GetPINValue(u8 PORT , u8 PIN);
void DIO_voidTogglePIN(u8 PORT , u8 PIN);
void DIO_voidSetPORTValue(u8 PORT , u8 Value);

#endif
