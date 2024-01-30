#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

void TIMER0_voidInit();
void TIMER0_voidSetTCNT(u8 Value);
void TIMER0_voidSetOCR0(u8 Value);
void TIMER0_voidOVFINT_ENABLE();
void TIMER0_voidOVFINT_DISABLE();
void TIMER0_voidCOMPINT_ENABLE();
void TIMER0_voidCOMPINT_DISABLE();
void TIMER0_voidSetOVFINTFunc(void (*ptr_func)());
void TIMER0_voidSetCOMPINTFunc(void (*ptr_func));

#endif
