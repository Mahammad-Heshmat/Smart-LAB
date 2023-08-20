/*
 * EEPROM_int.h
 *
 *  Created on: FEB 1, 2019
 *      Author: Khaled Mohsen
 */

#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

void EEPROM_voidInit(void);
void EEPROM_VoidWriteByte(u16 Copy_Location , u8 Copy_Data);
u8 EEPROM_u8ReadByte(u16 Copy_Location);

#endif /* EEPROM_INT_H_ */
