/************************************************************************/
/* Name: MDIO_interface.h                                               */
/* Author: Ahmed Ashraf                                                 */
/* Version: V1.0                                                        */
/* Usage: This file contains interfacing information of DIO Module      */
/************************************************************************/

/*Header file guard*/
#ifndef MDIO_INTERFACE_H_
#define MDIO_INTERFACE_H_

/************************************************************************/
/*                           Interfacing macros                         */
/************************************************************************/

/*GPIO PORTs*/
#define PORTA        (0)
#define PORTB		 (1)
#define PORTC        (2)
#define PORTD        (3)

/*PORT Pins*/
#define PIN0         (0b00000001)
#define PIN1         (0b00000010)
#define PIN2         (0b00000100)
#define PIN3         (0b00001000)
#define PIN4         (0b00010000)
#define PIN5         (0b00100000) 
#define PIN6         (0b01000000)
#define PIN7         (0b10000000)

/*PORT Pins' status*/
#define OUTPUT       (0)
#define INPUT_FLOAT  (1)
#define INPUT_PULLUP (2)

/*PORT Pins' output values*/
#define LOW          (0)
#define HIGH         (1)

/************************************************************************/
/*                           Functions' prototypes                      */
/************************************************************************/

/*This function is responsible for setting a defined status for GPIO pin [OUTPUT - INPUT_FLOAT - INPUT_PULLUP]*/
void mdio_setPinStatus(u8_t au8_port, u8_t au8_pin, u8_t au8_status);

/*This function is responsible for setting a defined value for an OUTPUT GPIO pin [HIGH - LOW]*/
void mdio_setPinValue(u8_t au8_port, u8_t au8_pin, u8_t au8_value);

/*This function is responsible for toggling a defined value for an OUTPUT GPIO pin*/
void mdio_togglePinValue(u8_t au8_port, u8_t au8_pin);

/*This function is responsible for reading a defined value for an INPUT GPIO pin [HIGH - LOW]*/
u8_t mdio_getPinValue(u8_t au8_port, u8_t au8_pin);

#endif /* MDIO_INTERFACE_H_ */