/*
 * MUART_interface.h
 *
 * Created: 5/22/2021 11:22:23 AM
 *  Author: Omar Aly
 */ 


#ifndef MUART_INTERFACE_H_
#define MUART_INTERFACE_H_


#define MUART_2400_BR       (416)
#define MUART_4800_BR       (207)
#define MUART_9600_BR       (103)
#define MUART_19200_BR      (51)
#define MUART_115200_BR     (8)


void muart_init(u16_t au16_baudRate);


void muart_sendByte(u8_t au8_dataByte);

void muart_recieveByte(u8_t* au8_dataByte);


void muart_sendStream(u8_t* au8_dataStream, u8_t au8_dataSize);



#endif /* MUART_INTERFACE_H_ */