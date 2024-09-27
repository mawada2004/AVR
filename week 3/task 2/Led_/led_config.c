/*
 * led_config.c
 *
 *  Created on: Sep 25, 2024
 *      Author: Lenovo
 */
#include "led_config.h"
#include "led_priv.h"
#include "DIO_int.h"

Led_t Led_arrOstr[Led_NUM ]=
				  {
						  {DIO_PORTA,DIO_Pin5,LED_SOURCE,LED_OFF},
						  {DIO_PORTC,DIO_Pin2,LED_SOURCE,LED_OFF},
				          {DIO_PORTB,DIO_Pin3,LED_SINK,LED_ON}
				  };
