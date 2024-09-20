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


int main(void)
{

	 u8 display[] = { 0x3F, 0x06, 0x5B,  // 0, 1, 2
			          0x4F, 0x66, 0x6D,  // 3, 4, 5
			          0x7D, 0x07, 0x7F,  // 6, 7, 8
			                    0x6F };  // 9


    //set the 7 seg as output and off
	DDRB=0xFF;
	PORTB=display[0];

	//set buttons as input pulled-up
	DDRA&=~(1<<0);
	PORTA|=(1<<0);

	DDRA&=~(1<<1);
	PORTA|=(1<<1);



	u8 count=0;

	while (1)
	{


		if(((PINA >> 0) & 1) == 0 && ((PINA >> 1) & 1) == 1)
		{

			if (((PINA >> 0) & 1) == 0)  // Confirm button is still pressed
		   {
				if (count < 9)
				   {
				     count++;
				    }

			PORTB=display[count];
			_delay_ms(100);
		   }
	   }

		if(((PINA >> 0) & 1) == 1 && ((PINA >> 1) & 1) == 0)
		{
			_delay_ms(50);
			if (((PINA >> 1) & 1) == 0)  // Confirm button is still pressed
			 {
				if (count > 9)
				 {
					 count--;
			     }
			PORTB=display[count];
		    _delay_ms(100);
		     }
	    }

	return 0;
}

