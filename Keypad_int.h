/*****************************************/
/*	Author : Khaled Mohsen				 */
/*	Date   : 25-6-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : KeyPad_int.h		         */
/*****************************************/

#ifndef _KEYPAD_INTERFACE_H_
#define _KEYPAD_INTERFACE_H_

#define KEYPAD_U8_NULL_CHAR   '\0'
void KEYPAD_voidInit(void);
u8 KEYPAD_u8GetButton(void);

#endif