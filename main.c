/*
 * EMBADEDD SYSTEM PROJECT
 *
 * Created: 8/26/2022 9:26:11 PM
 * Author : MA7AMMAD_7ESHMAT
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <stdbool.h>
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "Keypad_int.h"
#include "FUNCTION.h"
#include "EEPROM_int.h"
#include "TWI_int.h"

int main (void)
{
DIO_voidInit();
LCD_voidInit();
KEYPAD_voidInit();
TWI_voidInit();
EEPROM_voidInit();
TWI_voidSetMyAddress(0);

 u16 address ;
u8 check1 ,check , check_pass ;
u8 task =0,task1 =0 , STU_COUNTER = 0 ;
u16 check_id ;
u8 LOCK , data ;

/*
	data = 225;
	address = 256;


	EEPROM_VoidWriteByte(address,data);
	_delay_ms(100);

	LCD_voidClear();
	LCD_voidSetCursor(LCD_U8_LINE1 ,0);
	check=EEPROM_u8ReadByte( address );
	LCD_voidSendNumber(check);
		
	LCD_voidSetCursor(LCD_U8_LINE2 ,0);
	check1=EEPROM_u8ReadByte( data );
	LCD_voidSendNumber(check1);
*/
	

while (1)
{
	//mainpage:
	LCD_voidClear();
	LCD_voidSetCursor(LCD_U8_LINE1 ,0);
	LCD_voidSendString("(A) ADMIN ");
	LCD_voidSetCursor(LCD_U8_LINE1 ,14);
	LCD_voidSendNumberII(STU_COUNTER);
	LCD_voidSetCursor(LCD_U8_LINE2 ,0);
	LCD_voidSendString("(B) STUDENT   IN");
	LCD_voidSetCursor(LCD_U8_LINE1 ,12);
	LCD_voidSendData(124);
	LCD_voidSetCursor(LCD_U8_LINE2 ,12);
	LCD_voidSendData(124);
	

	FUNCTION_GET_CHOICE (&task);

	switch (task)
	{
		case 'A' :  //MAIN ADMIN
				{
					check_id = FUNCTION_GET_ID();
					check_pass = FUNCTION_GET_PASSWORD ();
					check1 = FUNCTION_ENTER_CHECK( check_id , check_pass );
					if (check1 == 1 )
					{ FUNCTION_BUZZER (ON); }
					else 
					{
						FUNCTION_BUZZER (ALARM); 
						break;	
					}
					
					LCD_voidClear();
					LCD_voidSetCursor(LCD_U8_LINE1 ,0);
					LCD_voidSendString("(A) TO ENTER");
					LCD_voidSetCursor(LCD_U8_LINE2 ,0);
					LCD_voidSendString("(B) TO EDIT");

					FUNCTION_GET_CHOICE (&task1);
					switch (task1)
					{
						case 'A' :   // ENTER FOR ADMIN
						{
							STU_COUNTER++;
							FUNCTION_LAST_TEN(check_id);
							FUNCTION_BUZZER (ON);
							LCD_voidClear();
							LCD_voidSetCursor(LCD_U8_LINE1,4);
							LCD_voidSendString("WELCOME");
							FUNCTION_OPEN_DOOR();
							_delay_ms(5000);
							FUNCTION_CLOSE_DOOR();
							
							break;
						}
						
						case 'B' :
						{
							subpage:
							LCD_voidClear();
							LCD_voidSetCursor(LCD_U8_LINE1 ,0);
							LCD_voidSendString("A:ADD   B:DELETE");
							LCD_voidSetCursor(LCD_U8_LINE2 ,0);
							LCD_voidSendString("D:MORE  C:CHANGE");
							FUNCTION_GET_CHOICE (&task1);
							switch (task1)
							{
								case 'A' :  // ADD A NEW STUDENT
								{
									check = FUNCTION_GET_PASSWORD ();
									LCD_voidClear();
									LCD_voidSetCursor(LCD_U8_LINE1, 1);
									LCD_voidSendString("WRITE IT AGAIN");
									_delay_ms(700);
									check1 = FUNCTION_GET_PASSWORD ();
									if (check==check1)
									{
										check_id = FUNCTION_ADD_NEW_STUDENT(check);
										LCD_voidSetCursor( LCD_U8_LINE2 ,1);
										LCD_voidSendString("YOUR ID: ");
										LCD_voidSetCursor( LCD_U8_LINE2 ,10);
										LCD_voidSendNumber(check_id);
										FUNCTION_GET_CHOICE (&task1);  
									}
									else
									{
										LCD_voidClear();
										LCD_voidSetCursor(LCD_U8_LINE1, 3);
										LCD_voidSendString("TRY AGAIN");
										_delay_ms(700);
									}
									break;
								}
								
								case 'B' :   // FUNCTION TO DELEEEEEETE
								{
									check_id = FUNCTION_GET_ID();
									FUNCTION_DELET_ID (check_id);
									break;
								}
								
								case 'C' :   // FUNCTION TO CHANGE PASSSS
								{
									check_id = FUNCTION_GET_ID();
									FUNCTION_CHANGE_PASS (check_id);
									break;
								}
								
								case 'D' :   // MORE OPTIONS
								{
									LCD_voidClear();
									LCD_voidSetCursor(LCD_U8_LINE1 ,0);
									LCD_voidSendString("LOCK  NoST  L12");
									LCD_voidSetCursor(LCD_U8_LINE2 ,0);
									LCD_voidSendString("(A)   (B)   (C)");

									FUNCTION_GET_CHOICE (&task1);
										switch (task1)
										{
											case 'A' :  // LOCK THE LAB
											{
												address =256;
												LOCK = EEPROM_u8ReadByte(address);
														if (LOCK == 255 )
														{
															data=0;
															EEPROM_VoidWriteByte(address,data) ;
														}
														else if (LOCK == 0 )
														{
															data=255;
															EEPROM_VoidWriteByte(address,data) ;
														}
														goto subpage;
												break;
											}
								
											case 'B' :  // NUMBER OF STUDENT IN DATA BASE
											{
														FUNCTION_NoST();
														FUNCTION_GET_CHOICE (&choi);
												break;
											}
								
											case 'C' :   //  THE LAST TWELVE PERSON HAVE BEEN ENTERED
											{
														FUNCTION_PRINT_LAST_TEN();
												break;
											}
								
											default :
											{
												LCD_voidClear();
												LCD_voidSetCursor(LCD_U8_LINE1 ,0);
												LCD_voidSendString("UNDEFINED VALUE");
												FUNCTION_BUZZER(ALARM);
												break;
											}
										}
								}
								
								
								default :
								{
									LCD_voidClear();
									LCD_voidSetCursor(LCD_U8_LINE1 ,0);
									LCD_voidSendString("UNDEFINED VALUE");
									FUNCTION_BUZZER(ALARM);
									break;
								}
							}
							break;
						}
						
						default :
						{
							LCD_voidClear();
							LCD_voidSetCursor(LCD_U8_LINE1 ,0);
							LCD_voidSendString("UNDEFINED VALUE");
							FUNCTION_BUZZER(ALARM);
							break;
						}
					}
					
					
					
					break;
				}
		
		case 'B' :   // MAIN STUDENT
				{
					address=256;
					LOCK = EEPROM_u8ReadByte(address);
					if (LOCK = 255)
					{
						check_id = FUNCTION_GET_ID();
						check_pass = FUNCTION_GET_PASSWORD ();
						check1 = FUNCTION_ENTER_CHECK( check_id , check_pass );
						if (check1 == 1 )
						{
							STU_COUNTER++;
							FUNCTION_LAST_TEN(check_id);
							FUNCTION_BUZZER (ON);
							LCD_voidClear();
							LCD_voidSetCursor(LCD_U8_LINE1,4);
							LCD_voidSendString("WELCOME");
							FUNCTION_OPEN_DOOR();
							_delay_ms(5000);
							FUNCTION_CLOSE_DOOR();
						}
							else {FUNCTION_BUZZER (ALARM); }
					} 
					else if (LOCK = 0)
					{
						LCD_voidClear();
						LCD_voidSetCursor(LCD_U8_LINE1 ,4);
						LCD_voidSendString("SORRY !!");
						LCD_voidSetCursor(LCD_U8_LINE2 ,1);
						LCD_voidSendString("LAB IS LOCKED");
						_delay_ms(1500);
					}
						
							
					break;
				}
		
		default :
				{
					LCD_voidClear();
					LCD_voidSetCursor(LCD_U8_LINE1 ,0);
					LCD_voidSendString("UNDEFINED VALUE");
					FUNCTION_BUZZER (ALARM);
					_delay_ms(700);
					break;
				}
	}

}	
}