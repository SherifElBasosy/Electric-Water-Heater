#include "STD_Types.h"
#include "Bitwise_Operations.h"
#include "DIO_Int.h"
#include "DIO_private.h"
#include "DIO_Config.h"
#include "Seven_Seg_Config.h"
#include <util/delay.h>

void SevenSeg_voidinit(){

	DIO_voidSetPORTDir(Seven_Seg_DataPORT , Seven_Seg_P0 , DIO_OUTPUT);
	DIO_voidSetPORTDir(Seven_Seg_DataPORT , Seven_Seg_P1 , DIO_OUTPUT);
	DIO_voidSetPORTDir(Seven_Seg_DataPORT , Seven_Seg_P2 , DIO_OUTPUT);
	DIO_voidSetPORTDir(Seven_Seg_DataPORT , Seven_Seg_P3 , DIO_OUTPUT);
	DIO_voidSetPORTDir(Seven_Seg_EnablePORT , Seven_Seg_ENR , DIO_OUTPUT);
	DIO_voidSetPORTDir(Seven_Seg_EnablePORT , Seven_Seg_ENL , DIO_OUTPUT);

}

void SevenSeg_voidDisplayOFF(){
	DIO_voidSetPINValue(Seven_Seg_EnablePORT , Seven_Seg_ENR , DIO_LOW);
	DIO_voidSetPINValue(Seven_Seg_EnablePORT , Seven_Seg_ENL , DIO_LOW);
}

void SevenSeg_voidDisplay(u8 Value){

	DIO_voidSetPINValue(Seven_Seg_EnablePORT , Seven_Seg_ENR, DIO_HIGH);
	DIO_voidSetPINValue(Seven_Seg_EnablePORT , Seven_Seg_ENL, DIO_LOW);

	DIO_voidSetPORTValue(Seven_Seg_DataPORT , ((Value / 10) << 4));

	_delay_ms(50);

	DIO_voidSetPINValue(Seven_Seg_EnablePORT , Seven_Seg_ENL, DIO_HIGH);
	DIO_voidSetPINValue(Seven_Seg_EnablePORT , Seven_Seg_ENR, DIO_LOW);

	DIO_voidSetPORTValue(Seven_Seg_DataPORT , ((Value % 10) << 4));

	_delay_ms(50);

	DIO_voidSetPINValue(Seven_Seg_EnablePORT , Seven_Seg_ENL, DIO_LOW);


}
