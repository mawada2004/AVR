/*
 * switch_int.h
 *
 *  Created on: Sep 25, 2024
 *      Author: Lenovo
 */

#ifndef SWITCH_INT_H_
#define SWITCH_INT_H_

ES_t Switch_enuInit(SW_t *Copy_Ar_str_Switch);

ES_t Switch_GetState(SW_t *Copy_Ar_str_Switch , u8 *Copy_pu8Switchstate);

#endif /* SWITCH_INT_H_ */
