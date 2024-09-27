/*
 * switch_config.h
 *
 *  Created on: Sep 25, 2024
 *      Author: Lenovo
 */

#ifndef SWITCH_CONFIG_H_
#define SWITCH_CONFIG_H_
#include "stdTypes.h"

#define SWITCH_NUM   3

typedef struct {
	u8 SW_PortID;
	u8 SW_PinID;
	u8 SW_status;
}SW_t;

#endif /* SWITCH_CONFIG_H_ */
