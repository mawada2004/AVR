/*
 * seven_seg_int.h
 *
 *  Created on: Sep 27, 2024
 *      Author: Lenovo
 */

#ifndef SEVEN_SEG_INT_H_
#define SEVEN_SEG_INT_H_

ES_t Seven_Seg_enuInit(void);

ES_t Seven_Seg_enuDisplay(u8 Copy_u8Num);

ES_t Seven_Seg_enuEnableCMN(void);

ES_t Seven_Seg_enuDisableCMN(void);

ES_t Seven_Seg_enuEnableDOT(void);

ES_t Seven_Seg_enuDisableDOT(void);

ES_t Seven_Seg_enuCleardisplay(void);



#endif /* SEVEN_SEG_INT_H_ */
