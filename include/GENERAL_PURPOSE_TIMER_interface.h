#ifndef GENERAL_PURPOSE_TIMER_interface_H
#define GENERAL_PURPOSE_TIMER_interface_H



void MTIMER3_Initialize(void);
void setCallBack(void(*ptr)(void));
u32 MTIMER3_get_value(void);
void MTIMER3_disable(void);
#endif
