
#ifndef USART_H_
#define USART_H_

#define F_CPU 8000000UL
#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)

#include "main.h"

void USART_init(void);
unsigned char USART_receive(void);
void USART_send( unsigned char dataa);
void USART_putstring(char* StringPtr);
void USART_Flush(void);


#endif 