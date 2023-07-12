/*
 * Timer0.c
 *
 *  Created on: Oct 14, 2022
 *      Author: Paula Emad
 */
#include "../../UTILS/BIT_MATH.h"
#include "../../UTILS/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/DIO/DIO_CFG.h"
#include "TIMER0_CFG.h"
#include "TIMER0.h"

#include "avr/interrupt.h"
#include "avr/io.h"
#include "avr/delay.h"


void Force_OutputCompare()
{
	if( (WGM01==0 && WGM00==1) || (WGM01==1 && WGM00==1) )	  //if two PWM modes
	{
		CLEAR_BIT(TCCR0, FOC0);			//clear bit
		return;
	}
	else
	{
		SET_BIT(TCCR0, FOC0);			//else set a force compare match
	}
}



//TIMER0 Initialization
void TIMER0_Init(u8 timer_Mode, u8 OutputCompareMode, u8 prescalar, u8 OutputCompareValue, u8 IntMode)
{
	switch(timer_Mode){
	/**********  normalMode  **********/
	case normalMode:
		CLEAR_BIT(TCCR0, WGM00);			// normal mode
		CLEAR_BIT(TCCR0, WGM01);

			switch(OutputCompareMode)
			{
			case normalPort:					// Normal port operation, OC0 disconnected
				CLEAR_BIT(TCCR0, COM00);
				CLEAR_BIT(TCCR0, COM01);
				break;

			case toggle_OC0:					// Toggle OC0 on compare match
				SET_BIT(TCCR0, COM00);
				CLEAR_BIT(TCCR0, COM01);
				break;

			case clear_OC0:						// Clear OC0 on compare match
				CLEAR_BIT(TCCR0, COM00);
				SET_BIT(TCCR0, COM01);
				break;

			case set_OC0:						// Set OC0 on compare match
				SET_BIT(TCCR0, COM00);
				SET_BIT(TCCR0, COM01);
				break;

			default: break;
			}

		break;


	/**********  PWM_PhaseCorrect  **********/
	case PWM_PhaseCorrect:
		SET_BIT(TCCR0, WGM00);				//PWM_PhaseCorrect mode
		CLEAR_BIT(TCCR0, WGM01);

			switch(OutputCompareMode)
			{
			case normalPort:					// Normal port operation, OC0 disconnected
				CLEAR_BIT(TCCR0, COM00);
				CLEAR_BIT(TCCR0, COM01);
				break;

//			case toggle_OC0:					//reserved
//				SET_BIT(TCCR0, COM00);
//				CLEAR_BIT(TCCR0, COM01);
//				break;

			case clear_OC0:						// Clear OC0 on compare match, Set OC0 on compare-
				CLEAR_BIT(TCCR0, COM00);		//-match when downcounting
				SET_BIT(TCCR0, COM01);
				break;

			case set_OC0:						// Set OC0 on compare match when up-counting. Clear OC0 on compare-
				SET_BIT(TCCR0, COM00);			//-match when downcounting
				SET_BIT(TCCR0, COM01);
				break;

			default: break;
			}

		break;


	/************   CTC   ************/
	case CTC:
		CLEAR_BIT(TCCR0, WGM00);				//CTC mode
		SET_BIT(TCCR0, WGM01);

			switch(OutputCompareMode)
			{
			case normalPort:					// Normal port operation, OC0 disconnected
				CLEAR_BIT(TCCR0, COM00);
				CLEAR_BIT(TCCR0, COM01);
				break;

			case toggle_OC0:					// Toggle OC0 on compare match
				SET_BIT(TCCR0, COM00);
				CLEAR_BIT(TCCR0, COM01);
				break;

			case clear_OC0:						// Clear OC0 on compare match
				CLEAR_BIT(TCCR0, COM00);
				SET_BIT(TCCR0, COM01);
				break;

			case set_OC0:						// Set OC0 on compare match
				SET_BIT(TCCR0, COM00);
				SET_BIT(TCCR0, COM01);
				break;

			default: break;
			}

		break;


	/***********  fast_PWM  ***********/
	case fast_PWM:
		SET_BIT(TCCR0, WGM00);				//fast_PWM mode
		SET_BIT(TCCR0, WGM01);

			switch(OutputCompareMode)
			{
			case normalPort:					// Normal port operation, OC0 disconnected
				CLEAR_BIT(TCCR0, COM00);
				CLEAR_BIT(TCCR0, COM01);
				break;

//			case toggle_OC0:					//reserved
//				SET_BIT(TCCR0, COM00);
//				CLEAR_BIT(TCCR0, COM01);
//				break;

			case clear_OC0:						// Clear OC0 on compare match, set OC0 at TOP
				CLEAR_BIT(TCCR0, COM00);
				SET_BIT(TCCR0, COM01);
				break;

			case set_OC0:						// Set OC0 on compare match, clear OC0 at TOP
				SET_BIT(TCCR0, COM00);
				SET_BIT(TCCR0, COM01);
				break;

			default: break;
			}

		break;

	default: break;
	}

	Prescalar_Value(prescalar);

	OC_ValueInit(OutputCompareValue);

	Timer_IntEnable(IntMode);

}



void Prescalar_Value(u8 prescalar)
{
	switch(prescalar)
		{
		case NoClock:
			CLEAR_BIT(TCCR0, CS00);
			CLEAR_BIT(TCCR0, CS01);
			CLEAR_BIT(TCCR0, CS02);
			break;

		case Prescalar_0:
			SET_BIT(TCCR0, CS00);
			CLEAR_BIT(TCCR0, CS01);
			CLEAR_BIT(TCCR0, CS02);
			break;

		case Prescalar_8:
			CLEAR_BIT(TCCR0, CS00);
			SET_BIT(TCCR0, CS01);
			CLEAR_BIT(TCCR0, CS02);
			break;

		case Prescalar_64:
			SET_BIT(TCCR0, CS00);
			SET_BIT(TCCR0, CS01);
			CLEAR_BIT(TCCR0, CS02);
			break;

		case Prescalar_256:
			CLEAR_BIT(TCCR0, CS00);
			CLEAR_BIT(TCCR0, CS01);
			SET_BIT(TCCR0, CS02);
			break;

		case Prescalar_1024:
			SET_BIT(TCCR0, CS00);
			CLEAR_BIT(TCCR0, CS01);
			SET_BIT(TCCR0, CS02);
			break;

		case extclk_FallingEdge:
			CLEAR_BIT(TCCR0, CS00);
			SET_BIT(TCCR0, CS01);
			SET_BIT(TCCR0, CS02);
			break;

		case extclk_risingEdge:
			SET_BIT(TCCR0, CS00);
			SET_BIT(TCCR0, CS01);
			SET_BIT(TCCR0, CS02);
			break;

		default: break;
		}
}



void OC_ValueInit(u8 value)
{
	if(value > 255 || value<0)
	{
		return;
	}
	else
	{
	OCR0 = value;
	}
}



void Timer_IntEnable(u8 mode)
{
	switch(mode)
	{
	case compareMatch:
		SET_BIT(TIMSK, OCIE0);
		CLEAR_BIT(TIMSK, TOIE0);
		break;

	case overflow:
		CLEAR_BIT(TIMSK, OCIE0);
		SET_BIT(TIMSK, TOIE0);
		break;

	default: break;
	}
}

