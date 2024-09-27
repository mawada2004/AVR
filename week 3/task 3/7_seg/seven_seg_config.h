/*
 * seven_seg_config.h
 *
 *  Created on: Sep 27, 2024
 *      Author: Lenovo
 */

#ifndef SEVEN_SEG_CONFIG_H_
#define SEVEN_SEG_CONFIG_H_

#include "DIO_private.h"

#define SEG_APIN      DIO_Pin0
#define SEG_APORT     DIO_PORTA

#define SEG_BPIN      DIO_Pin1
#define SEG_BPORT     DIO_PORTA

#define SEG_CPIN      DIO_Pin2
#define SEG_CPORT     DIO_PORTA

#define SEG_DPIN      DIO_Pin3
#define SEG_DPORT     DIO_PORTA

#define SEG_EPIN      DIO_Pin4
#define SEG_EPORT     DIO_PORTA

#define SEG_FPIN       DIO_Pin5
#define SEG_FPORT      DIO_PORTA

#define SEG_GPIN       DIO_Pin6
#define SEG_GPORT      DIO_PORTA

#define SEG_CMNPIN     NOT_CONNECTED
#define SEG_CMNPORT    NOT_CONNECTED

#define SEG_DOTPIN      NOT_CONNECTED
#define SEG_DOTPORT     NOT_CONNECTED

#define SEG_TYPE        COMMON_ANODE



#endif /* SEVEN_SEG_CONFIG_H_ */
