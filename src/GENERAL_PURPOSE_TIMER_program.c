#include "LSTD_TYPES.h"

#include "GENERAL_PURPOSE_TIMER_private.h"
#include "GENERAL_PURPOSE_TIMER_interface.h"

void (*TIMER3_CallBack)(void);
volatile u16 n;

void MTIMER3_Initialize(void)
{ 


     TIMER3 -> TIMx_DIER =0x1; //enable interrupt

	 

     TIMER3 -> TIMx_PSC=3999 ; //8MHZ(8,000,000)  PSC=3999+1  -> 8000,000 /4000 	 =2000HZ =0.5ms
	 
	 TIMER3 -> TIMx_ARR =4000;   //it will take 2second to fire an interrupt
    //up-counter
	TIMER3 -> TIMx_CR1 |= 0x1;  //enable counter
	
}

void MTIMER3_disable(void)
{
	TIMER3 -> TIMx_CR1 &= ~0x1;  //disable counter
}

void setCallBack(void(*ptr)(void))
{
	TIMER3_CallBack=ptr;

}

void TIM3_IRQHandler(void)
{ //id --> 28   of interrupt
   
	n=TIMER3->TIMx_CNT;
	TIMER3->TIMx_SR =0x00;//clear interrupt flag
	TIMER3_CallBack();

}

u32 MTIMER3_get_value(void)
{

	return (TIMER3 ->TIMx_CNT);
}
