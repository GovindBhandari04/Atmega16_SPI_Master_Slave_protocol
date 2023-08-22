/*
 * SPI_Slave_protocol.c
 *
 * Created: 8/22/2023 11:21:08 AM
 * Author : Lenovo
 */ 

#include <avr/io.h>
#include <util/delay.h>

void SPI_write(char data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
}

unsigned char SPI_read()
{
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

int main(void)
{
    DDRB &= ~(1<<PB4) & ~(1<<PB5) & ~(1<<PB7);
	DDRB |= (1<<PB6);
	DDRC = 0XFF;
	
	SPCR |= (1<<SPE);
	
	SPCR &= ~(1<<MSTR);
	
    while (1) 
    {
		unsigned char data;
		PORTB &= ~(1<<PB4);
		data = SPI_read();
		if(data == 'a')
		{
			PORTC = 0XFF;
			PORTB |= (1<<PB4);
		}
		
		if(data == 'b')
		{
			PORTC = 0X00;
			PORTB |= (1<<PB4);
		}
		
    }
}

