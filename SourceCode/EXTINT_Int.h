#ifndef EXTINT_INTERFACE_H_
#define EXTINT_INTERFACE_H_

void EXITINT_voidInit();
void EXTINT_voidINTEnable(u8 INT_num);
void EXTINT_voidINTDisable(u8 INT_num);
void EXTINT0_Callback(void (*ptr_func)());
void EXTINT1_Callback(void (*ptr_func)());
void EXTINT2_Callback(void (*ptr_func)());

#endif
