/*
 * MC1.c
 *
 * Created: 6/8/2021 9:14:02 PM
 * Author : Omar Aly
 */ 

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#include "MSPI_interface.h"
#include "MUART_interface.h"

#define F_CPU 16000000UL
#include "util/delay.h"

int main(void)
{
	// The purpose of these 2 variables is to store the received data from SPI and UART
	u8_t recievedCharUART = 0;
	u8_t recievedByteSPI = 0;
	
	
	//Setting up I/O Modules
	
	//TX as output and RX as input
	mdio_setPinStatus(PORTD,PIN0,INPUT_FLOAT);
	mdio_setPinStatus(PORTD,PIN1,OUTPUT);
	//SS as output
	mdio_setPinStatus(PORTA,PIN0,OUTPUT);
	//Configuring SPI pins
	mdio_setPinStatus(PORTB,PIN4,OUTPUT);
	mdio_setPinStatus(PORTB,PIN5,OUTPUT);
	mdio_setPinStatus(PORTB,PIN6,INPUT_FLOAT);
	mdio_setPinStatus(PORTB,PIN7,OUTPUT);
	
	
	//Initializing SPI and UART
	muart_init(MUART_9600_BR);
	mspi_init(MSPI_MASTER_DEVICE,MSPI_MSB_FIRST,MSPI_SAMPLE_R_SETUP_F,MSPI_CLK_PRE_64);
	
	while (1)
	{
		//Receive the byte or character from the virtual terminal and save it in a variable
		muart_recieveByte(&recievedCharUART);
		//Use pin A0 as the slave selector instead of the SS pin, making it low first to start the communication with the slave
		mdio_setPinValue(PORTA,PIN0,LOW);
		//Send the received byte via SPI to the second MCU, making MCU1 act as a master and MCU2 as a slave
		mspi_masterSendRecv(recievedCharUART,&recievedByteSPI);
		//stopping the communication with MCU2 via setting the SS pin to high
		mdio_setPinValue(PORTA,PIN0,HIGH);
		//Adding a little delay so Proteus won't crash
		_delay_ms(50);

	}
	
	return 0;
}

