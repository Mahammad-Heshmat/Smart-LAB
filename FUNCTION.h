#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#define MAIN_ADDRESS  0
#define ALARM  0
#define ON  1
#include <stdbool.h>
#include "EEPROM_int.h"
u16 LAST_TEN [10]={0};
static u8 choi ;

u8 FUNCTION_GET_ID (void)
{
	u16 id ; 
	u8 button , i=0 ;
	u16 MIN [4];
	
	LCD_voidClear();
	LCD_voidSetCursor(LCD_U8_LINE1 , 3 );
	LCD_voidSendString("SIGN UR ID");

	while (i<4)
	{
		button = KEYPAD_u8GetButton();
		if(button != KEYPAD_U8_NULL_CHAR)
		{
			if (i<=3)
			{
				LCD_voidSetCursor(LCD_U8_LINE2 , i+6 );
				LCD_voidSendData(button);
				
				while(KEYPAD_u8GetButton() == button);
				MIN [i] = (button-= 48) ;
				i++;
			}
		}
	}

	MIN[0] *= 1000 ;
	MIN[1] *= 100 ;
	MIN[2] *= 10 ;
	
	id = (MIN[0]+MIN[1]+MIN[2]+MIN[3]);
	id = (id/34);
	id -=38;

	return id;
}

u8 FUNCTION_GET_PASSWORD (void)
{
u8 PASSWORD , button , i=0 ;
u8 MIN [8];
u8 FIN [4];

LCD_voidClear();
LCD_voidSetCursor(LCD_U8_LINE1 , 0 );
LCD_voidSendString("SIGN UR PASSWORD");


while (i<8)
{
	button = KEYPAD_u8GetButton();
	if(button != KEYPAD_U8_NULL_CHAR)
	{
		if (i<=7)
		{
			LCD_voidSetCursor(LCD_U8_LINE2 , i+4 );
			LCD_voidSendString("*");
			MIN [i] = button ;
			while(KEYPAD_u8GetButton() == button);
			i++;
		}
	}
}

for (u8 t=0 ;t<4 ;t++)
{
	FIN[t]= (20+(MIN[t]))-(MIN[t+4]);
}



PASSWORD = ((FIN[0])+(FIN[1])+(FIN[2])+(FIN[3]));

return PASSWORD;
}

void FUNCTION_GET_CHOICE (u8*choice)
{
	u8  i=0 ;
	while (i<2)
	{
		(*choice) = KEYPAD_u8GetButton();
		if((*choice) != KEYPAD_U8_NULL_CHAR)
		{
				while(KEYPAD_u8GetButton() == (*choice));
				i+=5;
		}
	}
}

void FUNCTION_BUZZER (u8 mode)
{
	switch (mode)
	{
		case 0:
		{
				DIO_voidSetPinValue(3 , 1);
				DIO_voidSetPinValue(18 , 1);
				_delay_ms(250);
				DIO_voidSetPinValue(3 , 0);
				DIO_voidSetPinValue(18 , 0);
				_delay_ms(100);
				DIO_voidSetPinValue(3 , 1);
				DIO_voidSetPinValue(18 , 1);
				_delay_ms(250);
				DIO_voidSetPinValue(3 , 0);	
				DIO_voidSetPinValue(18 , 0);
				_delay_ms(100);
				DIO_voidSetPinValue(3 , 1);
				DIO_voidSetPinValue(18 , 1);
				_delay_ms(250);
				DIO_voidSetPinValue(3 , 0);
				DIO_voidSetPinValue(18 , 0);	
				
		break;
		}
		case 1:
		{
			DIO_voidSetPinValue(27 , 1);
			DIO_voidSetPinValue(3 , 1);
			_delay_ms(50);
			DIO_voidSetPinValue(3 , 0);
			_delay_ms(100);
			DIO_voidSetPinValue(3 , 1);
			_delay_ms(200);
			DIO_voidSetPinValue(3 , 0);
			DIO_voidSetPinValue(27 , 0);
		break;
		}
	}
}

u8 FUNCTION_ENTER_CHECK(u16 ID , u8 PASS)
{
	u8 password ;
	password = EEPROM_u8ReadByte(ID);
	
	if ( PASS == password )
	{ return 1 ;} 
	else
	{ return 0 ;}
}

u16  FUNCTION_ADD_NEW_STUDENT(u8 PASSWORD)
{
	u16 ID ;
	
	LCD_voidClear();
	LCD_voidSetCursor( LCD_U8_LINE1 , 3);
	LCD_voidSendString("WAIT.");
	
	ID = EEPROM_u8ReadByte(MAIN_ADDRESS);
	_delay_ms(100);
	ID++ ;	
	LCD_voidSetCursor( LCD_U8_LINE1 , 9);
	LCD_voidSendString(".");
	EEPROM_VoidWriteByte(ID,PASSWORD);
	_delay_ms(100);
	EEPROM_VoidWriteByte(MAIN_ADDRESS,ID);
	_delay_ms(200);
	LCD_voidSetCursor( LCD_U8_LINE1 , 10);
	LCD_voidSendString("..");
	ID =((ID+38)*34);
	LCD_voidClear();
	LCD_voidSetCursor( LCD_U8_LINE1 , 6);
	LCD_voidSendString("DONE");
	_delay_ms(1000);
	return ID ;
}

void FUNCTION_DELET_ID (u16 ID)
{
	u8 zero =0 ;
	LCD_voidClear();
	LCD_voidSetCursor(LCD_U8_LINE1, 3);
	LCD_voidSendString("DELETING.");
	_delay_ms(300);
	EEPROM_VoidWriteByte(ID,zero);
	_delay_ms(200);
	
	LCD_voidSetCursor(LCD_U8_LINE1, 12);
	LCD_voidSendString(". .");
	_delay_ms(200);
	LCD_voidClear();
	LCD_voidSetCursor(LCD_U8_LINE1, 6);
	LCD_voidSendString("DONE");
	_delay_ms(700);
}

void FUNCTION_CHANGE_PASS (u16 ID)
{
	 u8 newpass ;
	LCD_voidClear();
	LCD_voidSetCursor(LCD_U8_LINE1,1);
	LCD_voidSendString("NOW WRITE THE");
	LCD_voidSetCursor(LCD_U8_LINE2,2);
	LCD_voidSendString("NEW PASSWORD");
	_delay_ms(1500);
	newpass = FUNCTION_GET_PASSWORD ();
	 EEPROM_VoidWriteByte(ID,newpass);
	 _delay_ms(100);
	LCD_voidClear();
	LCD_voidSetCursor(LCD_U8_LINE1,6);
	LCD_voidSendString("DONE");
	_delay_ms(700);
}

void FUNCTION_OPEN_DOOR(void)
{
	for (u8 i=0 ;i<170 ;i++)
	{
		ST_D_on ();
		_delay_ms(5);
		ST_C_on ();
		_delay_ms(5);
		ST_B_on ();
		_delay_ms(5);
		ST_A_on ();
		_delay_ms(5);
	}
}

void FUNCTION_CLOSE_DOOR(void)
{
	for (u8 i=0 ;i<170 ;i++)
	{
		ST_A_on ();
		_delay_ms(5);
		ST_B_on ();
		_delay_ms(5);
		ST_C_on ();
		_delay_ms(5);
		ST_D_on ();
		_delay_ms(5);
	}
}

void FUNCTION_LAST_TEN (u16 MEMBER_ID)
{	
		for (u8 i=11 ; i>0 ; i--)
		{
			LAST_TEN [i] = LAST_TEN [i-1] ;
		}
		
		MEMBER_ID=((MEMBER_ID+38)*34);
		LAST_TEN [0]= MEMBER_ID ; 		
}

void FUNCTION_PRINT_LAST_TEN (void)
{
	LCD_voidClear();
	
	LCD_voidSetCursor(LCD_U8_LINE1 ,0);
	LCD_voidSendNumber(LAST_TEN [0]);
	
	LCD_voidSetCursor(LCD_U8_LINE1 ,6);
	LCD_voidSendNumber(LAST_TEN [1]);
	
	LCD_voidSetCursor(LCD_U8_LINE1 ,12);
	LCD_voidSendNumber(LAST_TEN [2]);
	
	LCD_voidSetCursor(LCD_U8_LINE2 ,0);
	LCD_voidSendNumber(LAST_TEN [3]);
	
	LCD_voidSetCursor(LCD_U8_LINE2 ,6);
	LCD_voidSendNumber(LAST_TEN [4]);
	
	LCD_voidSetCursor(LCD_U8_LINE2 ,12);
	LCD_voidSendNumber(LAST_TEN [5]);
	
	FUNCTION_GET_CHOICE (&choi);
	
	LCD_voidClear();
	
	LCD_voidSetCursor(LCD_U8_LINE1 ,0);
	LCD_voidSendNumber(LAST_TEN [6]);
	
	LCD_voidSetCursor(LCD_U8_LINE1 ,6);
	LCD_voidSendNumber(LAST_TEN [7]);
	
	LCD_voidSetCursor(LCD_U8_LINE1 ,12);
	LCD_voidSendNumber(LAST_TEN [8]);
	
	LCD_voidSetCursor(LCD_U8_LINE2 ,0);
	LCD_voidSendNumber(LAST_TEN [9]);
	
	LCD_voidSetCursor(LCD_U8_LINE2 ,6);
	LCD_voidSendNumber(LAST_TEN [10]);
	
	LCD_voidSetCursor(LCD_U8_LINE2 ,12);
	LCD_voidSendNumber(LAST_TEN [11]);
	
	FUNCTION_GET_CHOICE (&choi);
	
}

void FUNCTION_NoST (void)
{
	u8 PASS ,NOST =0 ;
	for(u8 i=1 ; i<255 ; i++)
	{
		PASS=EEPROM_u8ReadByte(i);
		if (PASS!=0)
		{
			NOST++;
		}
	}
	
	LCD_voidClear();
	LCD_voidSetCursor(LCD_U8_LINE1 , 3);
	LCD_voidSendString("THERE ARE");
	LCD_voidSetCursor(LCD_U8_LINE2 , 6);
	LCD_voidSendString("STUDENT");
	LCD_voidSetCursor(LCD_U8_LINE2 , 2);
	LCD_voidSendNumberIII(NOST);
	
}



#endif