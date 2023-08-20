/*
 * EEPROM_prg.c
 *
 *  Created on: FEB 1, 2019
 *      Author: Khaled Mohsen
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "EEPROM_int.h"
#include "EEPROM_priv.h"
#include "EEPROM_config.h"
#include "TWI_int.h"
//#include "DIO_interface.h"

//2408
void EEPROM_voidInit(void)
{
	TWI_voidInit();
}

//0b11100000000
//0bp2p1p0 000000000
void EEPROM_VoidWriteByte(u16 Copy_Location , u8 Copy_Data)
{

	u8 SLA_W = 0b10100000 ;
	u8 P0 = GET_BIT(Copy_Location , 8);
	u8 P1 = GET_BIT(Copy_Location , 9);
	u8 P2 = GET_BIT(Copy_Location , 10);
	SLA_W |= ((P0<<1) | (P1<<2) | (P2<<3));
	//0b10101110
	TWI_voidSendStart();
	if(True == TWI_u8CheckStatus(StrConTx))
	{

		TWI_voidSendByte(SLA_W);
		if(True == TWI_u8CheckStatus(SlA_W_Ack))
		{
			TWI_voidSendByte((u8)  Copy_Location);
			if(True == TWI_u8CheckStatus(Data_TX_Ack))
			{
				TWI_voidSendByte(Copy_Data);
				if(True == TWI_u8CheckStatus(Data_TX_Ack))
				{
					TWI_voidSendStop();
				}
			}
		}
	}
}

u8 EEPROM_u8ReadByte(u16 Copy_Location)
{

	u8 RetVal ;
	u8 SLA_W = 0b10100000;
	u8 SLA_R ;
	u8 P0 = GET_BIT(Copy_Location , 8);
	u8 P1 = GET_BIT(Copy_Location , 9);
	u8 P2 = GET_BIT(Copy_Location , 10);
	SLA_W |= (P0<<1) | (P1<<2) | (P2<<3);
	SLA_R = SLA_W + 1 ;
	//0b10101111
	TWI_voidSendStart();
	if(True == TWI_u8CheckStatus(StrConTx))
	{
		TWI_voidSendByte(SLA_W);
		if(True == TWI_u8CheckStatus(SlA_W_Ack))
		{
			TWI_voidSendByte((u8)  Copy_Location);
			if(True == TWI_u8CheckStatus(Data_TX_Ack))
			{
				TWI_voidSendStart();
				if(True == TWI_u8CheckStatus(RepStrConTx))
				{
					TWI_voidSendByte(SLA_R);
					if(True == TWI_u8CheckStatus(SLA_R_W_ACK)) //0x40
					{
						RetVal = TWI_u8ReceiveByteWithNoAck();
						TWI_voidSendStop();
					}
				}
			}
		}
	}

	return RetVal ;
}

