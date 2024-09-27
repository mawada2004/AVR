/*
 * main.c
 *
 *  Created on: Sep 25, 2024
 *      Author: Lenovo
 */
#include "stdTypes.h"
#include "ERROR_STATE.h"

#include "DIO_int.h"

#include "led_config.h"
#include "led_int.h"
#include <util/delay.h>

extern Led_t Led_arrOstr[Led_NUM];

int main(void)
{

    DIO_enuInit();
	LED_enuinit(Led_arrOstr);
	while(1)
	{

		LED_enuTurnON(&Led_arrOstr[1]);
		_delay_ms(500);
		LED_enuTurnOff(&Led_arrOstr[1]);
		_delay_ms(500);
		LED_enuTurnON(&Led_arrOstr[2]);
		_delay_ms(500);
		LED_enuTurnOff(&Led_arrOstr[2]);
		_delay_ms(500);
	}


	return 0;
}
