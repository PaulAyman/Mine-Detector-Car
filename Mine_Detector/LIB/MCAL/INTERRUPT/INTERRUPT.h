#ifndef INTERRUPT_H
#define INTERRUPT_H
#include "INTERRUPT_CFG.h"
void INT0_Enable();
void INT1_Enable();
void INT2_Enable();
void SET_CALLBACK(void (*L_Ptr_To_Func)(void), u8 Ex_INT);
#endif
