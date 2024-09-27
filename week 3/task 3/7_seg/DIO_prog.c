/*
 * DIO_prog.c
 *
 *  Created on: Sep 24, 2024
 *      Author: Lenovo
 */
#include "ERROR_STATE.h"
#include "stdTypes.h"
#include "DIO_config.h"


ES_t DIO_enuInit()
{
   ES_t Local_enuErrorState=ES_NOK;
   DDRA=CONC(PA_Pin7_Dir,PA_Pin6_Dir,PA_Pin5_Dir,PA_Pin4_Dir,PA_Pin3_Dir,PA_Pin2_Dir,PA_Pin1_Dir,PA_Pin0_Dir);
   DDRB=CONC(PB_Pin7_Dir,PB_Pin6_Dir,PB_Pin5_Dir,PB_Pin4_Dir,PB_Pin3_Dir,PB_Pin2_Dir,PB_Pin1_Dir,PB_Pin0_Dir);
   DDRC=CONC(PC_Pin7_Dir,PC_Pin6_Dir,PC_Pin5_Dir,PC_Pin4_Dir,PC_Pin3_Dir,PC_Pin2_Dir,PC_Pin1_Dir,PC_Pin0_Dir);
   DDRD=CONC(PD_Pin7_Dir,PD_Pin6_Dir,PD_Pin5_Dir,PD_Pin4_Dir,PD_Pin3_Dir,PD_Pin2_Dir,PD_Pin1_Dir,PD_Pin0_Dir);

   PORTA=CONC(PA_Pin7_Val,PA_Pin6_Val,PA_Pin5_Val,PA_Pin4_Val,PA_Pin3_Val,PA_Pin2_Val,PA_Pin1_Val,PA_Pin0_Val);
   PORTB=CONC(PB_Pin7_Val,PB_Pin6_Val,PB_Pin5_Val,PB_Pin4_Val,PB_Pin3_Val,PB_Pin2_Val,PB_Pin1_Val,PB_Pin0_Val);
   PORTC=CONC(PC_Pin7_Val,PC_Pin6_Val,PC_Pin5_Val,PC_Pin4_Val,PC_Pin3_Val,PC_Pin2_Val,PC_Pin1_Val,PC_Pin0_Val);
   PORTD=CONC(PD_Pin7_Val,PD_Pin6_Val,PD_Pin5_Val,PD_Pin4_Val,PD_Pin3_Val,PD_Pin2_Val,PD_Pin1_Val,PD_Pin0_Val);

   Local_enuErrorState =ES_OK;
   return Local_enuErrorState;
}

ES_t DIO_enuSet_Port_Dir(u8 Copy_u8PortID , u8 Copy_u8Value )
{
   ES_t Local_enuErrorState=ES_NOK;
   if (Copy_u8PortID<=DIO_PORTD && Copy_u8Value<=OUTPUT)
   {
	   switch(Copy_u8PortID)
	   {
	      case DIO_PORTA:
	    	  DDRA=Copy_u8Value;
			  break;
	      case DIO_PORTB:
	    	  DDRB=Copy_u8Value;
			  break;
	      case DIO_PORTC:
	    	  DDRC=Copy_u8Value;
			  break;
	      case DIO_PORTD:
	    	  DDRD=Copy_u8Value;
			  break;
	   }
	   Local_enuErrorState = ES_OK;
   }
   else
   {
	   Local_enuErrorState=ES_OUT_OF_RANGE;
   }

   return Local_enuErrorState;
}

ES_t DIO_enuSet_Port_Val(u8 Copy_u8PortID,u8 Copy_u8Value)
{
	   ES_t Local_enuErrorState=ES_NOK;

	      if (Copy_u8PortID<=DIO_PORTD && Copy_u8Value<=OUTPUT)
	      {
	   	   switch(Copy_u8PortID)
	   	   {
	   	      case DIO_PORTA:
	   	    	  PORTA=Copy_u8Value;
	   			  break;
	   	      case DIO_PORTB:
	   	    	  PORTB=Copy_u8Value;
	   			  break;
	   	      case DIO_PORTC:
	   	    	  PORTC=Copy_u8Value;
	   			  break;
	   	      case DIO_PORTD:
	   	    	  PORTD=Copy_u8Value;
	   			  break;
	   	   }
	   	   Local_enuErrorState = ES_OK;
	      }
	      else
	      {
	   	   Local_enuErrorState=ES_OUT_OF_RANGE;
	      }

	   return Local_enuErrorState;
	}

ES_t DIO_enuTog_Port_Val(u8 Copy_u8PortID)
{
   ES_t Local_enuErrorState=ES_NOK;

   if (Copy_u8PortID<=DIO_PORTD)
   	      {
   	   	   switch(Copy_u8PortID)
   	   	   {
   	   	      case DIO_PORTA:
   	   	    	  PORTA=~PORTA;
   	   			  break;
   	   	      case DIO_PORTB:
   	   	    	  PORTB=~PORTB;
   	   			  break;
   	   	      case DIO_PORTC:
   	   	    	  PORTC=~PORTC;
   	   			  break;
   	   	      case DIO_PORTD:
   	   	    	  PORTD=~PORTD;
   	   			  break;
   	   	   }
   	   	   Local_enuErrorState = ES_OK;
   	      }
   	      else
   	      {
   	   	   Local_enuErrorState=ES_OUT_OF_RANGE;
   	      }


   return Local_enuErrorState;
}

ES_t DIO_Get_Port_Val(u8 Copy_u8PortID, u8 *Copy_pu8Value )
{
   ES_t Local_enuErrorState=ES_NOK;
   if (Copy_u8PortID<=DIO_PORTD)
     	      {
     	   	   switch(Copy_u8PortID)
     	   	   {
     	   	      case DIO_PORTA:
     	   	    	*Copy_pu8Value=PINA;
     	   			  break;
     	   	      case DIO_PORTB:
     	   	    	*Copy_pu8Value=PINB;
     	   			  break;
     	   	      case DIO_PORTC:
     	   	    	*Copy_pu8Value=PINC;
     	   			  break;
     	   	      case DIO_PORTD:
     	   	    	*Copy_pu8Value=PIND;
     	   	    	  break;
     	   	   }
     	   	   Local_enuErrorState = ES_OK;
     	      }
     	      else
     	      {
     	   	   Local_enuErrorState=ES_OUT_OF_RANGE;
     	      }

   return Local_enuErrorState;
}

ES_t DIO_enuSet_Pin_Dir(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value)
{
   ES_t Local_enuErrorState=ES_NOK;
   if (Copy_u8PortID<=DIO_PORTD && Copy_u8PinID<=DIO_Pin7&& Copy_u8Value<=OUTPUT)
   {
	   switch (Copy_u8PortID)
	   {
	      case DIO_PORTA:
		    DDRA&=~(1<<Copy_u8PinID);
		    DDRA|=(Copy_u8Value<<Copy_u8PinID);
		    break;
	      case DIO_PORTB:
			DDRB&=~(1<<Copy_u8PinID);
			DDRB|=(Copy_u8Value<<Copy_u8PinID);
			break;
	      case DIO_PORTC:
			DDRC&=~(1<<Copy_u8PinID);
			DDRC|=(Copy_u8Value<<Copy_u8PinID);
			break;
	      case DIO_PORTD:
			DDRD&=~(1<<Copy_u8PinID);
			DDRD|=(Copy_u8Value<<Copy_u8PinID);
			break;
	   }
	   Local_enuErrorState=ES_OK;
   }
   else
   {
	   Local_enuErrorState=ES_OUT_OF_RANGE;
   }


   return Local_enuErrorState;
}

ES_t DIO_enuSet_Pin_Val(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value)
{

   ES_t Local_enuErrorState=ES_NOK;
      if (Copy_u8PortID<=DIO_PORTD && Copy_u8PinID<=DIO_Pin7&& Copy_u8Value<=OUTPUT)
      {
   	   switch (Copy_u8PortID)
   	   {
   	      case DIO_PORTA:
   		    PORTA&=~(1<<Copy_u8PinID);
   		    PORTA|=(Copy_u8Value<<Copy_u8PinID);
   		    break;
   	      case DIO_PORTB:
   			PORTB&=~(1<<Copy_u8PinID);
   			PORTB|=(Copy_u8Value<<Copy_u8PinID);
   			break;
   	      case DIO_PORTC:
   			PORTC&=~(1<<Copy_u8PinID);
   			PORTC|=(Copy_u8Value<<Copy_u8PinID);
   			break;
   	      case DIO_PORTD:
   			PORTD&=~(1<<Copy_u8PinID);
   			PORTD|=(Copy_u8Value<<Copy_u8PinID);
   			break;
   	   }
   	   Local_enuErrorState=ES_OK;
      }
      else
      {
   	   Local_enuErrorState=ES_OUT_OF_RANGE;
      }

   return Local_enuErrorState;
}

ES_t DIO_enuTog_Pin_Val(u8 Copy_u8PortID , u8 Copy_u8PinID )
{
   ES_t Local_enuErrorState=ES_NOK;
   if (Copy_u8PortID<=DIO_PORTD && Copy_u8PinID<=DIO_Pin7)
	 {
	   switch (Copy_u8PortID)
	   {
		  case DIO_PORTA:
			PORTA^=(1<<Copy_u8PinID);
			break;
		  case DIO_PORTB:
			PORTB^=(1<<Copy_u8PinID);
			break;
		  case DIO_PORTC:
			PORTC^=(1<<Copy_u8PinID);
			break;
		  case DIO_PORTD:
			PORTD^=(1<<Copy_u8PinID);
			break;
	   }
	   Local_enuErrorState=ES_OK;
         }
         else
         {
      	   Local_enuErrorState=ES_OUT_OF_RANGE;
         }

   return Local_enuErrorState;
}

ES_t DIO_Get_Pin_Val(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 *Copy_u8Value)
{
   ES_t Local_enuErrorState=ES_NOK;
   if (Copy_u8PortID<=DIO_PORTD && Copy_u8PinID<=DIO_Pin7)
	{
	   switch (Copy_u8PortID)
	   {
		  case DIO_PORTA:
			 *Copy_u8Value=((PINA>>Copy_u8PinID)&1);
			break;
		  case DIO_PORTB:
			 *Copy_u8Value=((PINB>>Copy_u8PinID)&1);
			break;
		  case DIO_PORTC:
			 *Copy_u8Value=((PINC>>Copy_u8PinID)&1);
			break;
		  case DIO_PORTD:
			 *Copy_u8Value=((PIND>>Copy_u8PinID)&1);
			break;
	   }
	   Local_enuErrorState=ES_OK;
		}
		else
		{
		   Local_enuErrorState=ES_OUT_OF_RANGE;
		}


   return Local_enuErrorState;
}

