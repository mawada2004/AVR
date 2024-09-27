/*
 * seven_seg_prog.c
 *
 *  Created on: Sep 27, 2024
 *      Author: Lenovo
 */
#include "ERROR_STATE.h"
#include "stdTypes.h"


#include "seven_seg_priv.h"
#include "seven_seg_config.h"

#include "DIO_int.h"

ES_t Seven_Seg_enuInit(void)
{
	u8 Local_u8ErrorState =ES_NOK;
	u32 Local_u32Cheak=0;

	Local_u32Cheak|=(DIO_enuSet_Pin_Dir(SEG_APORT,SEG_APIN,OUTPUT)<<0);
	Local_u32Cheak|=(DIO_enuSet_Pin_Dir(SEG_BPORT,SEG_BPIN,OUTPUT)<<2);
	Local_u32Cheak|=(DIO_enuSet_Pin_Dir(SEG_CPORT,SEG_CPIN,OUTPUT)<<4);
	Local_u32Cheak|=(DIO_enuSet_Pin_Dir(SEG_DPORT,SEG_DPIN,OUTPUT)<<6);
	Local_u32Cheak|=(DIO_enuSet_Pin_Dir(SEG_EPORT,SEG_EPIN,OUTPUT)<<8);
	Local_u32Cheak|=(DIO_enuSet_Pin_Dir(SEG_FPORT,SEG_FPIN,OUTPUT)<<10);
	Local_u32Cheak|=(DIO_enuSet_Pin_Dir(SEG_GPORT,SEG_GPIN,OUTPUT)<<12);

#if SEG_CMNPORT<=DIO_PORTD && SEG_CMNPIN<=DIO_Pin7
	DIO_enuSet_Pin_Dir(SEG_CMNPORT , SEG_CMNPIN , OUTPUT);

#elif SEG_CMNPORT == NOT_CONNECTED || SEG_CMNPIN == NOT_CONNECTED

#else
#error "your Common Pin has a wrong selection"
#endif

#if SEG_DOTPORT<=DIO_PORTD && SEG_DOTPIN<=DIO_Pin7
	DIO_enuSet_Pin_Dir(SEG_CMNPORT , SEG_CMNPIN , OUTPUT);

#elif SEG_DOTPORT == NOT_CONNECTED || SEG_DOTPIN == NOT_CONNECTED

#else
#error "your DOT Pin has a wrong selection"
#endif

	for (u8 i=0;i<12;i+=2)
	{
		if (((Local_u32Cheak>>i)&3) !=ES_OK)
		{
			return Local_u8ErrorState;
		}
	}
	   Local_u8ErrorState=ES_OK;

	return Local_u8ErrorState;
}

ES_t Seven_Seg_enuDisplay(u8 Copy_u8Num)
{
	u8 Local_u8ErrorState =ES_NOK;
	u32 Local_u32Cheak=0;
	if (Copy_u8Num<10)
	{
#if SEG_TYPE==COMMON_CATHODE
		Local_u32Cheak|=(DIO_enuSet_Pin_Val(SEG_APORT,SEG_APIN,((SEG_Au8NumDisplay[Copy_u8Num]>>0)&1))<<0);
		Local_u32Cheak|=(DIO_enuSet_Pin_Val(SEG_BPORT,SEG_BPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>1)&1))<<2);
		Local_u32Cheak|=(DIO_enuSet_Pin_Val(SEG_CPORT,SEG_CPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>2)&1))<<4);
		Local_u32Cheak|=(DIO_enuSet_Pin_Val(SEG_DPORT,SEG_DPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>3)&1))<<6);
		Local_u32Cheak|=(DIO_enuSet_Pin_Val(SEG_EPORT,SEG_EPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>4)&1))<<8);
		Local_u32Cheak|=(DIO_enuSet_Pin_Val(SEG_FPORT,SEG_FPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>5)&1))<<10);
		Local_u32Cheak|=(DIO_enuSet_Pin_Val(SEG_GPORT,SEG_GPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>6)&1))<<12);
#elif 	SEG_TYPE==COMMON_ANODE
		Local_u32Cheak|=(DIO_enuSet_Pin_Val(SEG_APORT,SEG_APIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>0)&1))<<0);
		Local_u32Cheak|=(DIO_enuSet_Pin_Val(SEG_BPORT,SEG_BPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>1)&1))<<2);
		Local_u32Cheak|=(DIO_enuSet_Pin_Val(SEG_CPORT,SEG_CPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>2)&1))<<4);
		Local_u32Cheak|=(DIO_enuSet_Pin_Val(SEG_DPORT,SEG_DPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>3)&1))<<6);
		Local_u32Cheak|=(DIO_enuSet_Pin_Val(SEG_EPORT,SEG_EPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>4)&1))<<8);
		Local_u32Cheak|=(DIO_enuSet_Pin_Val(SEG_FPORT,SEG_FPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>5)&1))<<10);
		Local_u32Cheak|=(DIO_enuSet_Pin_Val(SEG_GPORT,SEG_GPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>6)&1))<<12);

#else
#error "SEG type has a wrong selection";
#endif


	}
	else
	{
		Local_u8ErrorState=ES_OUT_OF_RANGE;
	}
	for (u8 i=0;i<12;i+=2)
		{
			if (((Local_u32Cheak>>i) & 3) !=ES_OK)
			{
				return Local_u8ErrorState;
			}
		}
		   Local_u8ErrorState=ES_OK;

	return Local_u8ErrorState;
}

ES_t Seven_Seg_enuEnableCMN(void)
{
	u8 Local_u8ErrorState =ES_NOK;
#if SEG_CMNPORT<=DIO_PORTD && SEG_CMNPIN<=DIO_Pin7
    #if SEG_TYPE==COMMON_CATHODE
	Local_u8ErrorState=DIO_enuSet_Pin_Val(SEG_CMNPORT,SEG_CMNPIN,DIO_u8LOW);
    #elif SEG_TYPE==COMMON_ANODE
	Local_u8ErrorState=DIO_enuSet_Pin_Val(SEG_CMNPORT,SEG_CMNPIN,HIGH);
    #else
	#error "SEG type has a wrong selection"
    #endif
#elif SEG_CMNPORT == NOT_CONNECTED || SEG_CMNPIN == NOT_CONNECTED

#else
#error "your Common Pin has a wrong selection"
#endif

	return Local_u8ErrorState;
}


ES_t Seven_Seg_enuDisableCMN(void)
{
	u8 Local_u8ErrorState =ES_NOK;
#if SEG_CMNPORT<=DIO_PORTD && SEG_CMNPIN<=DIO_Pin7
    #if SEG_TYPE==COMMON_CATHODE
	Local_u8ErrorState=DIO_enuSet_Pin_Val(SEG_CMNPORT,SEG_CMNPIN,HIGH);
    #elif SEG_TYPE==COMMON_ANODE
	Local_u8ErrorState=DIO_enuSet_Pin_Val(SEG_CMNPORT,SEG_CMNPIN,LOW);
    #else
	#error "SEG type has a wrong selection"
    #endif
#elif SEG_CMNPORT == NOT_CONNECTED || SEG_CMNPIN == NOT_CONNECTED

#else
#error "your Common Pin has a wrong selection"
#endif

	return Local_u8ErrorState;
}

ES_t Seven_Seg_enuEnableDOT(void)
{
	u8 Local_u8ErrorState =ES_NOK;
#if SEG_DOTPORT<=DIO_PORTD && SEG_DOTPIN<=DIO_Pin7
    #if SEG_TYPE==COMMON_CATHODE
	Local_u8ErrorState=DIO_enuSet_Pin_Val(SEG_DOTPORT,SEG_DOTPIN,HIGH);
    #elif SEG_TYPE==COMMON_ANODE
	Local_u8ErrorState=DIO_enuSet_Pin_Val(SEG_DOTPORT,SEG_DOTPIN,LOW);
    #else
	#error "SEG type has a wrong selection"
    #endif
#elif SEG_DOTPORT == NOT_CONNECTED || SEG_DOTPIN == NOT_CONNECTED

#else
#error "your DOT Pin has a wrong selection"
#endif


	return Local_u8ErrorState;
}

ES_t Seven_Seg_enuDisableDOT(void)
{
	u8 Local_u8ErrorState =ES_NOK;
#if SEG_DOTPORT<=DIO_PORTD && SEG_DOTPIN<=DIO_Pin7
    #if SEG_TYPE==COMMON_CATHODE
	Local_u8ErrorState=DIO_enuSet_Pin_Val(SEG_DOTPORT,SEG_DOTPIN,LOW);
    #elif SEG_TYPE==COMMON_ANODE
	Local_u8ErrorState=DIO_enuSet_Pin_Val(SEG_DOTPORT,SEG_DOTPIN,HIGH);
    #else
	#error "SEG type has a wrong selection"
    #endif
#elif SEG_DOTPORT == NOT_CONNECTED || SEG_DOTPIN == NOT_CONNECTED

#else
#error "your DOT Pin has a wrong selection"
#endif



	return Local_u8ErrorState;
}


/*
ES_t Seven_Seg_enuCleardisplay(void){
	u8 Local_u8ErrorState =ES_NOK;



	return Local_u8ErrorState;
}
*/


