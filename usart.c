/*
 * usart.c
 *
 * Created: 02.01.2017 10:55:06
 *  Author: 1621
 */ 
#include "usart.h"
/*****************************************************/
void USART_init(void)
{	
	UBRR0H = (uint8_t)(BAUD_PRESCALLER>>8);
	UBRR0L = (uint8_t)(BAUD_PRESCALLER);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
	UCSR0C = (3<<UCSZ00);
}
/*****************************************************/
unsigned char USART_receive(void)
{	
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;	
}
/*****************************************************/
void USART_send( unsigned char dataa)
{	
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = dataa;	
}
/*****************************************************/
void USART_putstring(char* StringPtr)
{
	while(*StringPtr != 0x00){
	USART_send(*StringPtr);
	StringPtr++;}	
}
/*****************************************************/
void USART_Flush(void)
{
	unsigned char dummy;
	while ( UCSR0A & (1<<RXC0) ) dummy = UDR0;	
}
/*****************************************************/