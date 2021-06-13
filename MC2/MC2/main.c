/*
 * MC2.c
 *
 * Created: 6/8/2021 9:22:58 PM
 * Author : Omar Aly
 */ 


#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MSPI_interface.h"
#include "MDIO_interface.h"


#define F_CPU 16000000UL
#include "util/delay.h"


int main(void)
{
	// The purpose of this variable is to store the received data from SPI
	u8_t recievedByteSPI =0;

	//Configuring SPI pins
	mdio_setPinStatus(PORTB,PIN4,INPUT_FLOAT);
	mdio_setPinStatus(PORTB,PIN5,INPUT_FLOAT);
	mdio_setPinStatus(PORTB,PIN6,OUTPUT);
	mdio_setPinStatus(PORTB,PIN7,INPUT_FLOAT);
	
	//Setting actuators pins as output
	mdio_setPinStatus(PORTC,PIN2,OUTPUT);
	mdio_setPinStatus(PORTD,PIN3,OUTPUT);
	
	//Initializing SPI
	mspi_init(MSPI_SLAVE_DEVICE,MSPI_MSB_FIRST,MSPI_SAMPLE_R_SETUP_F,MSPI_CLK_PRE_64);
	
    while (1) 
    {
		//receiving the data from the master(MCU1)
		mspi_slaveSendRecv(0,&recievedByteSPI);
		//Switching over the received data
		switch (recievedByteSPI)
		{
			case 'a':
				mdio_setPinValue(PORTC,PIN2,HIGH);
				mdio_setPinValue(PORTD,PIN3,LOW);
				break;
			case 'b':
				mdio_setPinValue(PORTC,PIN2,LOW);
				mdio_setPinValue(PORTD,PIN3,HIGH);
				break;
			default:
				break;
		}
		//Adding the same delay so Proteus won't crash
		_delay_ms(50);
    }
}

