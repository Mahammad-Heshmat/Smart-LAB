/****************************************/
/*          Author: Khaled Mohsen       */        
/*          Date: 1-8-2022              */
/*          Version: 1.0                */
/*          Module: DIO                 */
/****************************************/
#ifndef DIO_INT_H_
#define DIO_INT_H_

#define DIO_U8_HIGH 1
#define DIO_U8_LOW  0

#define DIO_U8_PIN0       0  //A0
#define DIO_U8_PIN1       1	 //A1 (EN1) 7_SEG
#define DIO_U8_PIN2       2	 //A2
#define DIO_U8_PIN3       3	 //A3  BUZZER
#define DIO_U8_PIN4       4	 //A4 LCD_D4
#define DIO_U8_PIN5       5	 //A5 LCD_D5
#define DIO_U8_PIN6       6	 //A6 LCD_D6
#define DIO_U8_PIN7       7	 //A7 LCD_D7

#define DIO_U8_PIN8       8  //B0 (EN2) 7_SEG
#define DIO_U8_PIN9       9	 //B1 LCD_RS
#define DIO_U8_PIN10      10 //B2 LCD_RW
#define DIO_U8_PIN11      11 //B3 LCD_EN
#define DIO_U8_PIN12      12 //B4 KEYPAD_C1
#define DIO_U8_PIN13      13 //B5 KEYPAD_C2
#define DIO_U8_PIN14      14 //B6 KEYPAD_C3
#define DIO_U8_PIN15      15 //B7 KEYPAD_C4

#define DIO_U8_PIN16      16 //C0 (A) 7_SEG
#define DIO_U8_PIN17      17 //C1 (B) 7_SEG
#define DIO_U8_PIN18      18 //C2 LED
#define DIO_U8_PIN19      19 //C3 KEYPAD_R1
#define DIO_U8_PIN20      20 //C4 KEYPAD_R2
#define DIO_U8_PIN21      21 //C5 KEYPAD_R3
#define DIO_U8_PIN22      22 //C6 KEYPAD_R4
#define DIO_U8_PIN23      23 //C7

#define DIO_U8_PIN24      24 //D0 IN1 STEPPER
#define DIO_U8_PIN25      25 //D1 IN2 STEPPER
#define DIO_U8_PIN26      26 //D2
#define DIO_U8_PIN27      27 //D3 led2
#define DIO_U8_PIN28      28 //D4 IN3 STEPPER
#define DIO_U8_PIN29      29 //D5 IN4 STEPPER
#define DIO_U8_PIN30      30 //D6 (D) 7_SEG
#define DIO_U8_PIN31      31 //D7 (C) 7_SEG

void DIO_voidInit(void);
void DIO_voidSetPinValue(u8 Copy_u8Pin , u8 Copy_u8Value);
u8 DIO_u8GetPinValue(u8 Copy_u8Pin);

//************** STEPPER SECTION ****************************
void ST_A_on (void);
void ST_B_on (void);
void ST_C_on (void);
void ST_D_on (void);
//************************************************************

#endif