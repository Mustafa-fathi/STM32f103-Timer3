/*
 * main.c
 *
 *  Created on: Oct 5, 2018
 *      Author: Hampota
 */
#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#include "MRCC_interface.h"
#include "MNVK_interface.h"
#include "GENERAL_PURPOSE_TIMER_interface.h"


void toggleLed (void)
{
	static u8 flag =0 ;
	if (flag ==0)
	{
		MDIO_set_pin(MDIO_PORTA   , 0);
		flag =1 ;

	}
	else
	{
		MDIO_clr_pin (MDIO_PORTA , 0);
				flag =0  ;
	}
}


u32 x;
void main()
{

MRCC_Initialize();
MRCC_EnableClock(BUS_ABP1,PERIPHERAL_TIMER3);
MRCC_EnableClock(BUS_ABP2,PERIPHERAL_GPIOA);
MDIO_Initialize();
MDIO_set_pin(MDIO_PORTA,1);
MNVK_EnableInt(29);  //enable interrupt in TIMER3
setCallBack(toggleLed);
MTIMER3_Initialize();
for (char i=0 ;i<20 ;i++)
{
	char c=0;
	c=5+10;
}
MTIMER3_disable();
x=MTIMER3_get_value();
for (char i=0 ;i<200 ;i++)
{
	char c=0;
	c=5+10;
}
while(1)
{

}

}

