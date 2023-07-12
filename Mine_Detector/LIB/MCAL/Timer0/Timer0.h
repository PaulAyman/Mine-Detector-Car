/*
 * Timer0.h
 *
 *  Created on: Oct 14, 2022
 *      Author: Paula Emad
 */

#ifndef TIMER0_H
#define TIMER0_H

#include "../../UTILS/STD_TYPES.h"

void Force_OutputCompare();

void TIMER0_Init(u8 timer_Mode, u8 OutputCompareMode, u8 prescalar, u8 OutputCompareValue, u8 IntMode);

void Prescalar_Value(u8 prescalar);

void OC_ValueInit(u8 value);

void Timer_IntEnable(u8 mode);


#endif /* TIMER0_H */
