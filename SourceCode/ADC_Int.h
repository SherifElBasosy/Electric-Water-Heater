#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_voidInit();
void ADC_voidEnable();
void ADC_voidDisable();
void ADC_voidStartConversion();
u8 ADC_u8IsConversionComplete();
u8 ADC_GetResult(u8 Channel);
void ADC_voidAutoTriggerEN();
void ADC_voidAutoTriggerDIS();
void ADC_INTEnable();
void ADC_INTDisable();
void ADC_voidSetINTFunc(void (*ptr_func)());

#endif
