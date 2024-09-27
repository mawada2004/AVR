/*
 * main.c
 *
 *  Created on: Sep 25, 2024
 *      Author: Lenovo
 */
#include "stdTypes.h"
#include "ERROR_STATE.h"

#include "switch_config.h"
#include "switch_int.h"

#include "DIO_int.h"
#include <util/delay.h>



extern SW_t Switch_AstrSwitchState [SWITCH_NUM ];
int main(void)
{

	DIO_enuInit();
    Switch_enuInit(Switch_AstrSwitchState);
    u8 pinstate;

	while (1)
	{
			Switch_GetState(&Switch_AstrSwitchState[0],&pinstate);
			if (pinstate==0)
			{
			   DIO_enuSet_Pin_Val(DIO_PORTB,DIO_Pin0,DIO_u8HIGH);
			}
			else
			{
				 DIO_enuSet_Pin_Val(DIO_PORTB,DIO_Pin0,DIO_u8LOW);
			}

	}

	return 0;
}
