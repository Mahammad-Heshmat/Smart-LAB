
/****************************************/
/*          Author: Khaled Mohsen       */        
/*          Date: 1-8-2022              */
/*          Version: 1.0                */
/*          Module: DIO                 */
/****************************************/
#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_
/*
* options: 
*		DIO_U8_INPUT
*       DIO_U8_OUTPUT
*/
#define DIO_U8_PIN0_DIR       DIO_U8_INPUT  //A0
#define DIO_U8_PIN1_DIR       DIO_U8_INPUT	//A1
#define DIO_U8_PIN2_DIR       DIO_U8_INPUT	//A2
#define DIO_U8_PIN3_DIR       DIO_U8_OUTPUT	//A3  BUZZER
#define DIO_U8_PIN4_DIR       DIO_U8_OUTPUT	//A4 LCD_D4
#define DIO_U8_PIN5_DIR       DIO_U8_OUTPUT	//A5 LCD_D5
#define DIO_U8_PIN6_DIR       DIO_U8_OUTPUT	//A6 LCD_D6
#define DIO_U8_PIN7_DIR       DIO_U8_OUTPUT	//A7 LCD_D7

#define DIO_U8_PIN8_DIR       DIO_U8_INPUT	//B0 
#define DIO_U8_PIN9_DIR       DIO_U8_OUTPUT	//B1 LCD_RS
#define DIO_U8_PIN10_DIR      DIO_U8_OUTPUT	//B2 LCD_RW
#define DIO_U8_PIN11_DIR      DIO_U8_OUTPUT	//B3 LCD_EN
#define DIO_U8_PIN12_DIR      DIO_U8_INPUT	//B4 KEYPAD_C1
#define DIO_U8_PIN13_DIR      DIO_U8_INPUT	//B5 KEYPAD_C2
#define DIO_U8_PIN14_DIR      DIO_U8_INPUT	//B6 KEYPAD_C3
#define DIO_U8_PIN15_DIR      DIO_U8_INPUT	//B7 KEYPAD_C4

#define DIO_U8_PIN16_DIR      DIO_U8_INPUT	//C0 
#define DIO_U8_PIN17_DIR      DIO_U8_INPUT	//C1 
#define DIO_U8_PIN18_DIR      DIO_U8_OUTPUT	//C2 LED
#define DIO_U8_PIN19_DIR      DIO_U8_OUTPUT	//C3 KEYPAD_R1
#define DIO_U8_PIN20_DIR      DIO_U8_OUTPUT	//C4 KEYPAD_R2
#define DIO_U8_PIN21_DIR      DIO_U8_OUTPUT	//C5 KEYPAD_R3
#define DIO_U8_PIN22_DIR      DIO_U8_OUTPUT	//C6 KEYPAD_R4
#define DIO_U8_PIN23_DIR      DIO_U8_INPUT	//C7

#define DIO_U8_PIN24_DIR      DIO_U8_OUTPUT	//D0 IN1 STEPPER
#define DIO_U8_PIN25_DIR      DIO_U8_OUTPUT	//D1 IN2 STEPPER
#define DIO_U8_PIN26_DIR      DIO_U8_INPUT	//D2
#define DIO_U8_PIN27_DIR      DIO_U8_OUTPUT	//D3 led2
#define DIO_U8_PIN28_DIR      DIO_U8_OUTPUT	//D4 IN3 STEPPER
#define DIO_U8_PIN29_DIR      DIO_U8_OUTPUT	//D5 IN4 STEPPER
#define DIO_U8_PIN30_DIR      DIO_U8_INPUT	//D6 
#define DIO_U8_PIN31_DIR      DIO_U8_INPUT	//D7 



/***** STEPPER MOTOR COILS******/
#define COIL_A	 DIO_U8_PIN24
#define COIL_B	 DIO_U8_PIN25
#define COIL_C	 DIO_U8_PIN28
#define COIL_D   DIO_U8_PIN29
/*******************************/

/***** SEVEN SEGMENT DATA ******/
#define SEG_A	 DIO_U8_PIN16
#define SEG_B	 DIO_U8_PIN17
#define SEG_C	 DIO_U8_PIN31
#define SEG_D    DIO_U8_PIN30
#define SEG_EN1	 DIO_U8_PIN1
#define SEG_EN2  DIO_U8_PIN8
/*******************************/


#endif

