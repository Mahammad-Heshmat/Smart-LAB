/*****************************************/
/*	Author : Khaled Mohsen				 */
/*	Date   : 25-6-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : KeyPad_int.h		         */
/*****************************************/
#include "STD_types.h"
#include "DIO_int.h"
#include "KeyPad_private.h"
#include "KeyPad_config.h"
#include "KeyPad_int.h"

void KEYPAD_voidInit(void)
{
	DIO_voidSetPinValue(KEYPAD_U8_R1 , DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_R2 , DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_R3 , DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_R4 , DIO_U8_HIGH);
		
	#if KEYPAD_U8_MODE == KEYPAD_U8_INTERNAL_PULL_UP
    DIO_voidSetPinValue(KEYPAD_U8_C1 , DIO_U8_HIGH);
    DIO_voidSetPinValue(KEYPAD_U8_C2 , DIO_U8_HIGH);
    DIO_voidSetPinValue(KEYPAD_U8_C3 , DIO_U8_HIGH);
	DIO_voidSetPinValue(KEYPAD_U8_C4 , DIO_U8_HIGH);
	
	
	#elif KEYPAD_U8_MODE == KEYPAD_U8_EXTERNAL_PULL_UP
	
	#endif

}

u8 KEYPAD_u8GetButton(void)
{
	/* apply sequence 1*/
	DIO_voidSetPinValue( KEYPAD_U8_R1 , DIO_U8_LOW);
	DIO_voidSetPinValue( KEYPAD_U8_R2 , DIO_U8_HIGH);
    DIO_voidSetPinValue( KEYPAD_U8_R3 , DIO_U8_HIGH);
    DIO_voidSetPinValue( KEYPAD_U8_R4 , DIO_U8_HIGH);
	
	
	if( DIO_u8GetPinValue( KEYPAD_U8_C1) == DIO_U8_LOW )
	{
		return R1C1;
	}
	else if(DIO_u8GetPinValue( KEYPAD_U8_C2) == DIO_U8_LOW)
	{
		return R1C2;
	}
	else if(DIO_u8GetPinValue( KEYPAD_U8_C3) == DIO_U8_LOW)
	{
		return R1C3;
	}
	else if(DIO_u8GetPinValue( KEYPAD_U8_C4) == DIO_U8_LOW)
	{
		return R1C4;
	}
	
	
		/* apply sequence 2*/
	DIO_voidSetPinValue( KEYPAD_U8_R1 , DIO_U8_HIGH);
	DIO_voidSetPinValue( KEYPAD_U8_R2 , DIO_U8_LOW);
    DIO_voidSetPinValue( KEYPAD_U8_R3 , DIO_U8_HIGH);
    DIO_voidSetPinValue( KEYPAD_U8_R4 , DIO_U8_HIGH);
	
	
	if(DIO_u8GetPinValue( KEYPAD_U8_C1) == DIO_U8_LOW)
	{
		return R2C1;
	}
	else if(DIO_u8GetPinValue( KEYPAD_U8_C2) == DIO_U8_LOW)
	{
		return R2C2;
	}
	else if(DIO_u8GetPinValue( KEYPAD_U8_C3) == DIO_U8_LOW)
	{
		return R2C3;
	}
	else if(DIO_u8GetPinValue( KEYPAD_U8_C4) == DIO_U8_LOW)
	{
		return R2C4;
	}
	
	
			/* apply sequence 3*/
	DIO_voidSetPinValue( KEYPAD_U8_R1 , DIO_U8_HIGH);
	DIO_voidSetPinValue( KEYPAD_U8_R2 , DIO_U8_HIGH);
    DIO_voidSetPinValue( KEYPAD_U8_R3 , DIO_U8_LOW);
    DIO_voidSetPinValue( KEYPAD_U8_R4 , DIO_U8_HIGH);
	
	
	if(DIO_u8GetPinValue( KEYPAD_U8_C1) == DIO_U8_LOW)
	{
		return R3C1;
	}
	else if(DIO_u8GetPinValue( KEYPAD_U8_C2) == DIO_U8_LOW)
	{
		return R3C2;
	}
	else if(DIO_u8GetPinValue( KEYPAD_U8_C3) == DIO_U8_LOW)
	{
		return R3C3;
	}
	else if(DIO_u8GetPinValue( KEYPAD_U8_C4) == DIO_U8_LOW)
	{
		return R3C4;
	}
	
	
				/* apply sequence 4*/
	DIO_voidSetPinValue( KEYPAD_U8_R1 , DIO_U8_HIGH);
	DIO_voidSetPinValue( KEYPAD_U8_R2 , DIO_U8_HIGH);
    DIO_voidSetPinValue( KEYPAD_U8_R3 , DIO_U8_HIGH);
    DIO_voidSetPinValue( KEYPAD_U8_R4 , DIO_U8_LOW);
	
	
	if(DIO_u8GetPinValue( KEYPAD_U8_C1) == DIO_U8_LOW)
	{
		return R4C1;
	}
	else if(DIO_u8GetPinValue( KEYPAD_U8_C2) == DIO_U8_LOW)
	{
		return R4C2;
	}
	else if(DIO_u8GetPinValue( KEYPAD_U8_C3) == DIO_U8_LOW)
	{
		return R4C3;
	}
	else if(DIO_u8GetPinValue( KEYPAD_U8_C4) == DIO_U8_LOW)
	{
		return R4C4;
	}
	
    return KEYPAD_U8_NULL_CHAR;	
}