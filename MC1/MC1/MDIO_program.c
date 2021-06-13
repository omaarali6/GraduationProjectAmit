/************************************************************************/
/* Name: MDIO_program.c                                                 */
/* Author: Ahmed Ashraf                                                 */
/* Version: V1.0                                                        */
/* Usage: This file contains logical implementations of DIO Module      */
/************************************************************************/

/************************************************************************/
/*                              Includes                                */
/************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"

/************************************************************************/
/*                          Functions' definitions                      */
/************************************************************************/

void mdio_setPinStatus(u8_t au8_port, u8_t au8_pin, u8_t au8_status)
{
	/*Switching over GPIO Ports*/
	switch(au8_port)
	{
		/*In case of PORTA*/
		case PORTA:
			
			/*Switching over pin status*/
			switch(au8_status)
			{
				/*In case of OUTPUT*/
				case OUTPUT:
					
					/*Set the specified pins to 1 in DDR*/
					MDIO_DDRA |= au8_pin;
					
					/*Break from this case*/
					break;
				
				/*In case of INPUT_FLOAT*/
				case INPUT_FLOAT:
					
					/*Set the specified pins to 0 in DDR*/
					MDIO_DDRA &= ~au8_pin;
										
					/*Break from this case*/
					break;

				/*In case of INPUT_PULLUP*/
				case INPUT_PULLUP:
					
					/*Set the specified pins to 0 in DDR*/
					MDIO_DDRA &= ~au8_pin;

					/*Set the specified pins to 1 in PORT*/
					MDIO_PORTA |= au8_pin;
					
					/*Break from this case*/
					break;
			}
			
			/*Break from this case*/
			break;

		/*In case of PORTB*/
		case PORTB:
			
			/*Switching over pin status*/
			switch(au8_status)
			{
				/*In case of OUTPUT*/
				case OUTPUT:
					
					/*Set the specified pins to 1 in DDR*/
					MDIO_DDRB |= au8_pin;
					
					/*Break from this case*/
					break;
				
				/*In case of INPUT_FLOAT*/
				case INPUT_FLOAT:
					
					/*Set the specified pins to 0 in DDR*/
					MDIO_DDRB &= ~au8_pin;
										
					/*Break from this case*/
					break;

				/*In case of INPUT_PULLUP*/
				case INPUT_PULLUP:
					
					/*Set the specified pins to 0 in DDR*/
					MDIO_DDRB &= ~au8_pin;

					/*Set the specified pins to 1 in PORT*/
					MDIO_PORTB |= au8_pin;
					
					/*Break from this case*/
					break;
			}
			
			/*Break from this case*/
			break;

		/*In case of PORTC*/
		case PORTC:
			
			/*Switching over pin status*/
			switch(au8_status)
			{
				/*In case of OUTPUT*/
				case OUTPUT:
					
					/*Set the specified pins to 1 in DDR*/
					MDIO_DDRC |= au8_pin;
					
					/*Break from this case*/
					break;
				
				/*In case of INPUT_FLOAT*/
				case INPUT_FLOAT:
					
					/*Set the specified pins to 0 in DDR*/
					MDIO_DDRC &= ~au8_pin;
										
					/*Break from this case*/
					break;

				/*In case of INPUT_PULLUP*/
				case INPUT_PULLUP:
					
					/*Set the specified pins to 0 in DDR*/
					MDIO_DDRC &= ~au8_pin;

					/*Set the specified pins to 1 in PORT*/
					MDIO_PORTC |= au8_pin;
					
					/*Break from this case*/
					break;
			}
			
			/*Break from this case*/
			break;

		/*In case of PORTD*/
		case PORTD:
			
			/*Switching over pin status*/
			switch(au8_status)
			{
				/*In case of OUTPUT*/
				case OUTPUT:
					
					/*Set the specified pins to 1 in DDR*/
					MDIO_DDRD |= au8_pin;
					
					/*Break from this case*/
					break;
				
				/*In case of INPUT_FLOAT*/
				case INPUT_FLOAT:
					
					/*Set the specified pins to 0 in DDR*/
					MDIO_DDRD &= ~au8_pin;
										
					/*Break from this case*/
					break;

				/*In case of INPUT_PULLUP*/
				case INPUT_PULLUP:
					
					/*Set the specified pins to 0 in DDR*/
					MDIO_DDRD &= ~au8_pin;

					/*Set the specified pins to 1 in PORT*/
					MDIO_PORTD |= au8_pin;
					
					/*Break from this case*/
					break;
			}
			
			/*Break from this case*/
			break;

	}
	
	/*Return from this function*/
	return;
}

void mdio_setPinValue(u8_t au8_port, u8_t au8_pin, u8_t au8_value)
{
	/*Switching over GPIO Ports*/
	switch(au8_port)
	{
		/*In case of PORTA*/
		case PORTA:
			
			/*Switching over pin values*/
			switch(au8_value)
			{
				/*In case of LOW*/
				case LOW:
					
					/*Set the specified pins to 0 in PORT*/
					MDIO_PORTA &= ~au8_pin;
					
					/*Break from this case*/
					break;
				
				/*In case of HIGH*/
				case HIGH:
					
					/*Set the specified pins to 1 in PORT*/
					MDIO_PORTA |= au8_pin;
										
					/*Break from this case*/
					break;
			}
			
			/*Break from this case*/
			break;

		/*In case of PORTB*/
		case PORTB:
			
			/*Switching over pin values*/
			switch(au8_value)
			{
				/*In case of LOW*/
				case LOW:
					
					/*Set the specified pins to 0 in PORT*/
					MDIO_PORTB &= ~au8_pin;
					
					/*Break from this case*/
					break;
				
				/*In case of HIGH*/
				case HIGH:
					
					/*Set the specified pins to 1 in PORT*/
					MDIO_PORTB |= au8_pin;
										
					/*Break from this case*/
					break;
			}
			
			/*Break from this case*/
			break;

		/*In case of PORTC*/
		case PORTC:
			
			/*Switching over pin values*/
			switch(au8_value)
			{
				/*In case of LOW*/
				case LOW:
					
					/*Set the specified pins to 0 in PORT*/
					MDIO_PORTC &= ~au8_pin;
					
					/*Break from this case*/
					break;
				
				/*In case of HIGH*/
				case HIGH:
					
					/*Set the specified pins to 1 in PORT*/
					MDIO_PORTC |= au8_pin;
										
					/*Break from this case*/
					break;
			}
			
			/*Break from this case*/
			break;

		/*In case of PORTD*/
		case PORTD:
			
			/*Switching over pin values*/
			switch(au8_value)
			{
				/*In case of LOW*/
				case LOW:
					
					/*Set the specified pins to 0 in PORT*/
					MDIO_PORTD &= ~au8_pin;
					
					/*Break from this case*/
					break;
				
				/*In case of HIGH*/
				case HIGH:
					
					/*Set the specified pins to 1 in PORT*/
					MDIO_PORTD |= au8_pin;
										
					/*Break from this case*/
					break;
			}
			
			/*Break from this case*/
			break;
	}
	
	/*Return from this function*/
	return;	
}

void mdio_togglePinValue(u8_t au8_port, u8_t au8_pin)
{
	/*Switching over GPIO Ports*/
	switch(au8_port)
	{
		/*In case of PORTA*/
		case PORTA:
			
			/*Toggle a specified pin value in PORT*/
			MDIO_PORTA ^= au8_pin;						
		
			/*Break from this case*/
			break;

		/*In case of PORTB*/
		case PORTB:
			
			/*Toggle a specified pin value in PORT*/
			MDIO_PORTB ^= au8_pin;						
		
			/*Break from this case*/
			break;

		/*In case of PORTC*/
		case PORTC:
			
			/*Toggle a specified pin value in PORT*/
			MDIO_PORTC ^= au8_pin;						
		
			/*Break from this case*/
			break;

		/*In case of PORTD*/
		case PORTD:
			
			/*Toggle a specified pin value in PORT*/
			MDIO_PORTD ^= au8_pin;						
		
			/*Break from this case*/
			break;
	}
	
	/*Return from this function*/
	return;
}

u8_t mdio_getPinValue(u8_t au8_port, u8_t au8_pin)
{
	/*A local variable is used  to carry the current pin value*/
	u8_t au8_pinValue = 0;

	/*Switching over GPIO Ports*/
	switch(au8_port)
	{
		/*In case of PORTA*/
		case PORTA:
			
			/*Checking the current value of the specified pin in PIN*/
			if(MDIO_PINA & au8_pin)
			{
				/*Set the pin value to HIGH*/
				au8_pinValue = HIGH;
			}
			else
			{
				/*Set the pin value to LOW*/
				au8_pinValue = LOW;				
			}
						
			/*Break from this case*/
			break;

		/*In case of PORTB*/
		case PORTB:
			
			/*Checking the current value of the specified pin in PIN*/
			if(MDIO_PINB & au8_pin)
			{
				/*Set the pin value to HIGH*/
				au8_pinValue = HIGH;
			}
			else
			{
				/*Set the pin value to LOW*/
				au8_pinValue = LOW;				
			}
						
			/*Break from this case*/
			break;

		/*In case of PORTC*/
		case PORTC:
			
			/*Checking the current value of the specified pin in PIN*/
			if(MDIO_PINC & au8_pin)
			{
				/*Set the pin value to HIGH*/
				au8_pinValue = HIGH;
			}
			else
			{
				/*Set the pin value to LOW*/
				au8_pinValue = LOW;				
			}
						
			/*Break from this case*/
			break;

		/*In case of PORTD*/
		case PORTD:
			
			/*Checking the current value of the specified pin in PIN*/
			if(MDIO_PIND & au8_pin)
			{
				/*Set the pin value to HIGH*/
				au8_pinValue = HIGH;
			}
			else
			{
				/*Set the pin value to LOW*/
				au8_pinValue = LOW;				
			}
						
			/*Break from this case*/
			break;
	}
	
	/*Return the current pin value*/
	return au8_pinValue;
}