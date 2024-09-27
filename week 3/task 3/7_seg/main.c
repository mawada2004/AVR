/*
 * main.c
 *
 *  Created on: Sep 27, 2024
 *      Author: Lenovo
 */

#include "ERROR_STATE.h"
#include "stdTypes.h"

#include "seven_seg_int.h"
#include "seven_seg_config.h"

#include "DIO_int.h"
#include <util/delay.h>

int main(void)
{
	DIO_enuInit();
	Seven_Seg_enuInit();
	while(1)
	{
		for(u8 i=0;i<9;i++)
		{
			Seven_Seg_enuDisplay(i);
			_delay_ms(200);
	  }
	}



	return 0;
}
