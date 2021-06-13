/*
 * MUART_private.h
 *
 * Created: 5/22/2021 11:23:04 AM
 *  Author: Omar Aly
 */ 


#ifndef MUART_PRIVATE_H_
#define MUART_PRIVATE_H_


#define MUART_UCSRC    (*(volatile u8_t *)(0x40))
#define MUART_UBRRH    (*(volatile u8_t *)(0x40))
#define MUART_UCSRA    (*(volatile u8_t *)(0x2B))
#define MUART_UCSRB    (*(volatile u8_t *)(0x2A))
#define MUART_UBRRL    (*(volatile u8_t *)(0x29))
#define MUART_UDR	   (*(volatile u8_t *)(0x2C))




#endif /* MUART_PRIVATE_H_ */