#include "main.h"

char rx_buffer[16];
char str[16];
unsigned char rx_buffer_len = 0;;

char idn[5]={"*IDN?"};
char sw1[8]={"SWITCH 1"};
char sw2[8]={"SWITCH 2"};
char sw3[8]={"SWITCH 3"};
char sw4[8]={"SWITCH 4"};
char sw0[8]={"SWITCH 0"};	

bool Compare_arrays(char *a, char *b, size_t count);

ISR(USART_RX_vect)
{	
	char c = UDR0;
	if(c != '\n')
	{
		rx_buffer[rx_buffer_len] = c;
		rx_buffer_len++;
	}
	if(c == '\n')
	{
		for(unsigned char i = 0;i<rx_buffer_len;i++)
		{
			str[i] = rx_buffer[i];
		}
		for(unsigned char i = 0;i<16;i++)
	    {
			rx_buffer[i] = 0;
		}
		rx_buffer_len = 0;
		
		if (Compare_arrays(str, idn, 5) == true)
		{
			USART_putstring("TRS32,PSI_DC-DC,SN:001,V1.00\r\n");
			
		}
		if (Compare_arrays(str, sw1, 8) == true)
		{
			PORTB &= ~(1<<PORTB0);
			USART_putstring("1\r\n");
			
		}
		if (Compare_arrays(str, sw2, 8) == true)
		{
			PORTB &= ~(1<<PORTB1);
			USART_putstring("2\r\n");
			
		}
		if (Compare_arrays(str, sw3, 8) == true)
		{
			PORTB &= ~(1<<PORTB2);
			USART_putstring("3\r\n");
			
		}	
		if (Compare_arrays(str, sw4, 8) == true)
		{
			PORTB &= ~(1<<PORTB3);
			USART_putstring("4\r\n");
			
		}
		if (Compare_arrays(str, sw0, 8) == true)
		{
			PORTB |= 0x0F;
			USART_putstring("0\r\n");
			
		}
	}
	
	
	
	
}


int main(void)
{
	DDRB = 0x0F;
	PORTB  = 0xFF;
    USART_init();
	sei();
	
	
    while (1) 
    {
		
		
    }
}
bool Compare_arrays(char *a, char *b, size_t count)
{
	for (size_t i = 0; i < count; i++)
	if (a[i] != b[i])
	return false;
	return true;
}


