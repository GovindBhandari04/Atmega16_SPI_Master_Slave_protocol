/*
 * SPI_begineer.c
 *
 * Created: 8/22/2023 10:21:27 AM
 * Author : Lenovo
 */ 

#include <avr/io.h>
#include <util/delay.h.>

unsigned char SPI_write(unsigned char data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
}

unsigned char SPI_read()
{
	SPDR = 0XFF;
	while(!(SPDR & (1<<SPIF)));
	return SPDR;
}

int main(void)
{
	DDRB |= (1<<DDB4)|(1<<DDB5)|(1<<DDB7);
	DDRB &= ~(1<<DDB6);
	
	
	SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR0);
	SPCR &= ~(1<<SPR1);
	SPSR &= ~(1<<SPI2X);
	 
 
    while (1) 
    {
		PORTB &= ~(1<<PB4);
		SPI_write('a');
		PORTB |= (1<<PB4);
		_delay_ms(1000);
		
		
		
		PORTB &= ~(1<<PB4);
		SPI_write('b');
		PORTB |= (1<<PB4);
		_delay_ms(1000);
		
    }
}

