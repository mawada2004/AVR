/*
 * DIO_int.h
 *
 *  Created on: Sep 24, 2024
 *      Author: Lenovo
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_
#include"ERROR_STATE.h"

#define DIO_u8OUTPUT     1
#define DIO_u8INPUT      0

#define DIO_u8HIGH       1
#define DIO_u8LOW        0
#define DIO_u8PULL_UP    1
#define DIO_u8FLOAT      0

#define DIO_Pin0   0
#define DIO_Pin1   1
#define DIO_Pin2   2
#define DIO_Pin3   3
#define DIO_Pin4   4
#define DIO_Pin5   5
#define DIO_Pin6   6
#define DIO_Pin7   7

#define DIO_PORTA  0
#define DIO_PORTB  1
#define DIO_PORTC  2
#define DIO_PORTD  3

ES_t DIO_enuInit(void);

ES_t DIO_enuSet_Port_Dir(u8 Copy_u8PortID , u8 Copy_u8Value);

ES_t DIO_enuSet_Port_Val(u8 Copy_u8PortID,u8 Copy_u8Value);

ES_t DIO_enuTog_Port_Val(u8 Copy_u8PortID);

ES_t DIO_Get_Port_Val(u8 Copy_u8PortID, u8 *Copy_pu8Value );

ES_t DIO_enuSet_Pin_Dir(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value);

ES_t DIO_enuSet_Pin_Val(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value);

ES_t DIO_enuTog_Pin_Val(u8 Copy_u8PortID , u8 Copy_u8PinID);

ES_t DIO_Get_Pin_Val(u8 Copy_u8PortID , u8 Copy_u8PinID, u8 *Copy_pu8Value );




#endif /* DIO_INT_H_ */
