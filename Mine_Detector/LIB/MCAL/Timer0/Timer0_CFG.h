/*
 * Timer0_CFG.h
 *
 *  Created on: Oct 14, 2022
 *      Author: Paula Emad
 */

#ifndef TIMER0_CFG_H
#define TIMER0_CFG_H

#include "../../MCAL/DIO/DIO_CFG.h"

//TIMER MODE
#define normalMode				0
#define PWM_PhaseCorrect		1
#define CTC						2
#define fast_PWM				3

//Compare Output Mode
#define normalPort				0
#define toggle_OC0				1
#define clear_OC0				2
#define set_OC0					3

//Prescalars
#define NoClock					0
#define Prescalar_0				1
#define Prescalar_8				2
#define Prescalar_64			3
#define Prescalar_256			4
#define Prescalar_1024			5
#define extclk_FallingEdge		6
#define extclk_risingEdge		7

//Timer INT
#define compareMatch			0
#define overflow				1




#endif /* TIMER0_CFG_H_ */
