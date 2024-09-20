/*
 * main.c
 *
 *  Created on: Sep 19, 2024
 *      Author: Lenovo
 */
#include <stdTypes.h>
#include <util/delay.h>

#define DDRA  *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA  *((volatile u8*)0x39)
typedef unsigned char u8;

#define DDRB  *((u8*)0x37)
#define PORTB *((u8*)0x38)
#define PINB  *((volatile u8*)0x36)

int main (void)
{
	//set led as output and low
	DDRA|=(1<<0);
	PORTA&=~(1<<0);

	DDRA|=(1<<2);
	PORTA&=~(1<<2);

	//set buttons as input and pulled up
	DDRB&=~(1<<0); //button 1
	PORTB|=(1<<0);

	DDRB&=~(1<<1); //button 2
	PORTB|=(1<<1);

	DDRB&=~(1<<2); //button 3
	PORTB|=(1<<2);

	while(1)
	{
		if (((PINB>>0) &1)==0 && ((PINB>>1) &1)==1)
		{
			//led 1 is on
			PORTA|=(1<<0);
			PORTA&=~(1<<2);
			_delay_ms(50);
		}
		else if (((PINB>>1) &1)==0 && ((PINB>>0) &1)==1)
			{
				//led 2 is on
				PORTA|=(1<<2);
				PORTA&=~(1<<0);
				_delay_ms(50);
			}
		else if (((PINB>>2) &1)==0 && ((PINB>>1) &1)==1 && ((PINB>>0) &1)==1)
			{
				//led 1 and 2 is on
				PORTA|=(1<<0);
				PORTA|=(1<<2);
			}
		else
			{
			  PORTA&=~(1<<0);
			  PORTA&=~(1<<2);

			}

	}




	return 0;
}

