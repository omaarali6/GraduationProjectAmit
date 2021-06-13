/*
 * MUART_program.c
 *
 * Created: 5/22/2021 11:22:05 AM
 *  Author: Omar Aly
 */ 

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"

#include "MUART_private.h"
#include "MUART_interface.h"


void muart_init(u16_t au16_baudRate)
{
	MUART_UCSRA = 0;
	MUART_UCSRB = 0x18;
	MUART_UCSRC = 0x86;
	MUART_UBRRL = (u8_t) au16_baudRate;
	MUART_UBRRH = (u8_t) (au16_baudRate >> 8);
	return;	
}

void muart_sendByte(u8_t au8_dataByte)
{
	if (GET_BIT(MUART_UCSRA,5))
	{
		MUART_UDR = au8_dataByte;
		while(GET_BIT(MUART_UCSRA,6)==0);
		SET_BIT(MUART_UCSRA,6);
	}
}
void muart_recieveByte(u8_t* pu8_dataByte)
{
	if (GET_BIT(MUART_UCSRA,7))
	{ 
		*pu8_dataByte=MUART_UDR;
	}
}

void muart_sendStream(u8_t* pu8_dataStream, u8_t au8_dataSize)
{
	while (au8_dataSize --)
	{
		if (GET_BIT(MUART_UCSRA,5))
		{
			MUART_UDR = *pu8_dataStream;
			while(GET_BIT(MUART_UCSRA,6)==0);
			SET_BIT(MUART_UCSRA,6);
			pu8_dataStream++;
		}
	}
	
}