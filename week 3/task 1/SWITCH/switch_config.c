/*
 * switch_config.c
 *
 *  Created on: Sep 25, 2024
 *      Author: Lenovo
 */

#include "switch_config.h"
#include "DIO_int.h"

SW_t Switch_AstrSwitchState [SWITCH_NUM ]=
{
		{DIO_PORTA,DIO_Pin0,DIO_u8PULL_UP}
		,{DIO_PORTB,DIO_PORTB,DIO_Pin1,DIO_u8FLOAT}
		,{DIO_PORTA,DIO_Pin7,DIO_u8PULL_UP}
};
