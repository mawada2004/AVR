/*
 * main.c
 *
 *  Created on: Sep 10, 2024
 *      Author: Lenovo
 */
#include <stdTypes.h>
#include <util/delay.h>

#define DDRA  *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA  *((volatile u8*)0x39)
typedef unsigned char u8;
int main(void)
{
   // pin 0A in DDRA is output
   DDRA|=(1<<0);


	while(1)
	{
		//pin 0A is high
		PORTA|=(1<<0);
		_delay_ms(500);

		//pin 0A is low
		PORTA &=~(1<<0);
		 _delay_ms(500);

	}

	return 0;
}
