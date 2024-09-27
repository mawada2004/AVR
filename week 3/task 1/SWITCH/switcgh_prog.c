/*
 * switcgh_prog.c
 *
 *  Created on: Sep 25, 2024
 *      Author: Lenovo
 */

#include"ERROR_STATE.h"
#include "stdTypes.h"

#include "switch_config.h"

#include "DIO_int.h"


ES_t Switch_enuInit(SW_t *Copy_Ar_str_Switch)
{
	ES_t Local_enuErrorState =ES_NOK;
	if (Copy_Ar_str_Switch != NULL)
	{
		u8 Local_Iterator =0;
		for (Local_Iterator=0;Local_Iterator<SWITCH_NUM;Local_Iterator++)
		{
				Local_enuErrorState=DIO_enuSet_Pin_Dir(Copy_Ar_str_Switch[Local_Iterator].SW_PortID,Copy_Ar_str_Switch[Local_Iterator].SW_PinID,DIO_u8INPUT);
				Local_enuErrorState=DIO_enuSet_Pin_Val(Copy_Ar_str_Switch[Local_Iterator].SW_PortID,Copy_Ar_str_Switch[Local_Iterator].SW_PinID,Copy_Ar_str_Switch[Local_Iterator].SW_status);

		}
	}
	else
	{
		Local_enuErrorState =ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_t Switch_GetState(SW_t *Copy_Ar_str_Switch , u8 *Copy_pu8Switchstate){
	ES_t Local_enuErrorState =ES_NOK;

	if (Copy_Ar_str_Switch!=NULL && Copy_pu8Switchstate!=NULL)
	{
		Local_enuErrorState=DIO_Get_Pin_Val(Copy_Ar_str_Switch->SW_PortID,Copy_Ar_str_Switch->SW_PinID,Copy_pu8Switchstate);
	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}



	return Local_enuErrorState;
}
