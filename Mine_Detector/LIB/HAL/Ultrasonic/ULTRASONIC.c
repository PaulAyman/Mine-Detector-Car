/*
 * ULTRASONIC.c
 *
 *  Created on: Oct 16, 2022
 *      Author: Paula Emad
 */
#include "avr/io.h"
#include "avr/delay.h"
#include "avr/interrupt.h"

#include "../../MCAL/Timer0/Timer0.h"
#include "../../MCAL/Timer0/Timer0_CFG.h"
#include "ULTRASONIC.h"
#include "../../MCAL/DIO/DIO_CFG.h"
#include "../../MCAL/DIO/DIO.h"



u32 Ultrasonic(){
	u32 distance;
	SET_BIT(DDRA,TRIG);//TRIG PA0 as output
	SET_BIT(PORTA,TRIG);//Set TRIG PA0 High
	_delay_us(10);
	CLEAR_BIT(DDRA,ECHO);//ECHO PA1 as input
	TIMER0_Init(normalMode, normalPort, Prescalar_64, 255, overflow);
    if(READ_BIT(PORTA,ECHO) == LOW)         //low= pulse ended
    {
        u8 time = TCNT0;           //time completed
        distance = time/58;     //distance completed
        TCNT0 = 0;        		//reset timer
    }

	return distance;
}

