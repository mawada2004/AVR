/*
 * led_config.h
 *
 *  Created on: Sep 25, 2024
 *      Author: Lenovo
 */

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_
#include "stdTypes.h"

#define Led_NUM 3

typedef struct
{
   u8 Led_PortID;
   u8 Led_PinID;
   u8 Led_Connection;
   u8 Led_InitiState;
}Led_t;



#endif /* LED_CONFIG_H_ */
