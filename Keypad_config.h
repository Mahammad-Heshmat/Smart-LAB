	/*****************************************/
/*	Author : Khaled Mohsen				 */
/*	Date   : 25-6-2022   		   		 */
/*	Version: 0.1				         */
/*	File   : KeyPad_config.h		         */
/*****************************************/

#ifndef _KEYPAD_CONFIG_H_
#define _KEYPAD_CONFIG_H_

#define KEYPAD_U8_R1	    DIO_U8_PIN19 //C3	
#define KEYPAD_U8_R2		DIO_U8_PIN20
#define KEYPAD_U8_R3		DIO_U8_PIN21
#define KEYPAD_U8_R4		DIO_U8_PIN22 //C6

#define KEYPAD_U8_C1		DIO_U8_PIN12 //B4
#define KEYPAD_U8_C2		DIO_U8_PIN13
#define KEYPAD_U8_C3		DIO_U8_PIN14
#define KEYPAD_U8_C4		DIO_U8_PIN15 //B7





#define R1C1  '1'
#define R1C2  '4'
#define R1C3  '7'
#define R1C4  '*'


#define R2C1  '2'
#define R2C2  '5'
#define R2C3  '8'
#define R2C4  '0'


#define R3C1  '3'
#define R3C2  '6'
#define R3C3  '9'
#define R3C4  '#'


#define R4C1  'A'
#define R4C2  'B'
#define R4C3  'C'
#define R4C4  'D'

/*
Options:

KEYPAD_U8_EXTERNAL_PULL_UP
KEYPAD_U8_INTERNAL_PULL_UP

*/
#define KEYPAD_U8_MODE      KEYPAD_U8_INTERNAL_PULL_UP

#endif