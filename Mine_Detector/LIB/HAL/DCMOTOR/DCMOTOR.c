/*
 * DCMOTOR.c
 *
 *  Created on: Oct 16, 2022
 *      Author: Paula Emad
 */
#include "avr/io.h"
#include "avr/delay.h"
#include "avr/interrupt.h"

#include "../../MCAL/DIO/DIO_CFG.h"
#include "../../MCAL/DIO/DIO.h"
#include "DCMOTOR.h"

void motor_Forward()
{
	DDRB=0xFF;
	SET_BIT(PORTB, motorLeftForward);
	CLEAR_BIT(PORTB, motorLeftBackward);

	SET_BIT(PORTB, motorRightForward);
	CLEAR_BIT(PORTB, motorRightBackward);

}

void motor_Backward()
{
	DDRB=0xFF;
	CLEAR_BIT(PORTB, motorLeftForward);
	SET_BIT(PORTB, motorLeftBackward);

	CLEAR_BIT(PORTB, motorRightForward);
	SET_BIT(PORTB, motorRightBackward);
}

void motor_Right()
{
	DDRB=0xFF;
	CLEAR_BIT(PORTB, motorLeftForward);
	SET_BIT(PORTB, motorLeftBackward);

	SET_BIT(PORTB, motorRightForward);
	CLEAR_BIT(PORTB, motorRightBackward);
}


void motor_LefT()
{
	DDRB=0xFF;
	SET_BIT(PORTB, motorLeftForward);
	CLEAR_BIT(PORTB, motorLeftBackward);

	CLEAR_BIT(PORTB, motorRightForward);
	SET_BIT(PORTB, motorRightBackward);
}


void motor_STOP()
{
	DDRB=0xFF;
	CLEAR_BIT(PORTB, motorLeftForward);
	CLEAR_BIT(PORTB, motorLeftBackward);

	CLEAR_BIT(PORTB, motorRightForward);
	CLEAR_BIT(PORTB, motorRightBackward);
}

