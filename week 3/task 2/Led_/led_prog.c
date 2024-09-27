/*
 * led_prog.c
 *
 *  Created on: Sep 25, 2024
 *      Author: Lenovo
 */

#include "stdTypes.h"
#include "ERROR_STATE.h"

#include "led_priv.h"
#include "led_config.h"

#include "DIO_int.h"

ES_t LED_enuinit(Led_t * Copy_pstrLedConfig)
{
	ES_t Local_enuErrorstate=ES_NOK;
	if (Copy_pstrLedConfig!=NULL)
	{
		u8 Led_Iterator =0;
		for(Led_Iterator=0;Led_Iterator<=Led_NUM;Led_Iterator++)
		{
			if (Copy_pstrLedConfig[Led_Iterator].Led_Connection==LED_SOURCE)
			{
				if (Copy_pstrLedConfig[Led_Iterator].Led_InitiState==LED_ON)
				{
					Local_enuErrorstate=DIO_enuSet_Pin_Val(Copy_pstrLedConfig[Led_Iterator].Led_PortID,Copy_pstrLedConfig[Led_Iterator].Led_PinID,DIO_u8HIGH);
				}
				else if (Copy_pstrLedConfig[Led_Iterator].Led_InitiState==LED_OFF)
				{
					Local_enuErrorstate=DIO_enuSet_Pin_Val(Copy_pstrLedConfig[Led_Iterator].Led_PortID,Copy_pstrLedConfig[Led_Iterator].Led_PinID,DIO_u8LOW);
				}
				else
				{
					Local_enuErrorstate=ES_OUT_OF_RANGE;
				}
			}
			else if (Copy_pstrLedConfig[Led_Iterator].Led_Connection==LED_SINK)

			{
				if (Copy_pstrLedConfig[Led_Iterator].Led_InitiState==LED_ON)
				{
					Local_enuErrorstate=DIO_enuSet_Pin_Val(Copy_pstrLedConfig[Led_Iterator].Led_PortID,Copy_pstrLedConfig[Led_Iterator].Led_PinID,DIO_u8LOW);
				}
				else if (Copy_pstrLedConfig[Led_Iterator].Led_InitiState==LED_OFF)
				{
					Local_enuErrorstate=DIO_enuSet_Pin_Val(Copy_pstrLedConfig[Led_Iterator].Led_PortID,Copy_pstrLedConfig[Led_Iterator].Led_PinID,DIO_u8HIGH);
				}
				else
				{
					Local_enuErrorstate=ES_OUT_OF_RANGE;
				}
			}
		}

	}
	else
	{
		Local_enuErrorstate=ES_NULL_POINTER;
	}


	return Local_enuErrorstate;
}


ES_t LED_enuTurnON(Led_t * Copy_pstrLedConfig){
	ES_t Local_enuErrorstate=ES_NOK;

	if (Copy_pstrLedConfig!=NULL)
	{
		if (Copy_pstrLedConfig->Led_Connection==LED_SOURCE)
		{
			DIO_enuSet_Pin_Val(Copy_pstrLedConfig->Led_PortID,Copy_pstrLedConfig->Led_PinID,DIO_u8HIGH);
		}
		else if (Copy_pstrLedConfig->Led_Connection==LED_SINK)
		{
			DIO_enuSet_Pin_Val(Copy_pstrLedConfig->Led_PortID,Copy_pstrLedConfig->Led_PinID,DIO_u8LOW);
		}
		else
		{
			Local_enuErrorstate=ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorstate=ES_NULL_POINTER;
	}


	return Local_enuErrorstate;
}

ES_t LED_enuTurnOff(Led_t * Copy_pstrLedConfig){
	ES_t Local_enuErrorstate=ES_NOK;
	if (Copy_pstrLedConfig!=NULL)
		{
			if (Copy_pstrLedConfig->Led_Connection==LED_SOURCE)
			{
				DIO_enuSet_Pin_Val(Copy_pstrLedConfig->Led_PortID,Copy_pstrLedConfig->Led_PinID,DIO_u8LOW);
			}
			else if (Copy_pstrLedConfig->Led_Connection==LED_SINK)
			{
				DIO_enuSet_Pin_Val(Copy_pstrLedConfig->Led_PortID,Copy_pstrLedConfig->Led_PinID,DIO_u8HIGH);
			}
			else
			{
				Local_enuErrorstate=ES_OUT_OF_RANGE;
			}
		}
		else
		{
			Local_enuErrorstate=ES_NULL_POINTER;
		}



	return Local_enuErrorstate;
}

