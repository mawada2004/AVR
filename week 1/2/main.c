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
   // pin i in DDRA is output
	for(int i=0;i<=6;i++)
	{
		DDRA|=(1<<i);
	}


	while(1)
	{
		//pin x is high
		for(int i=0;i<6;i++)
		{
			PORTA|=(1<<i);
		   _delay_ms(500);

		}

		for(int i=5;i>=0;i--)
		{
			PORTA &=~(1<<i);
		    _delay_ms(500);

		}

	}

	return 0;
}
