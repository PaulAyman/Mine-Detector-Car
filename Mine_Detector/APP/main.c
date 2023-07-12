
#include "avr/delay.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#include "../LIB/MCAL/DIO/DIO.h"
#include "../LIB/MCAL/DIO/DIO_CFG.h"
#include "../LIB/HAL/DCMOTOR/DCMOTOR.h"
#include "../LIB/HAL/LCD_DRIVER/LCD.h"
#include "../LIB/HAL/LCD_DRIVER/LCD_CFG.h"
#include "../LIB/MCAL/INTERRUPT/INTERRUPT.h"
#include "../LIB/MCAL/INTERRUPT/INTERRUPT_CFG.h"
#include "../LIB/MCAL/Timer0/Timer0.h"
#include "../LIB/HAL/Ultrasonic/ULTRASONIC.h"

void Receive();

static volatile u16 time=0; //Stores the count from TCNT1
static volatile u16 flag=0;	//Check the status of ECHO pin

int main()
{
	LCD_vInit();
	INT0_Enable();
	SET_CALLBACK(Receive, Ex_INT0);
	u16 distance=0; //Stores the distance (time/58)cm
	sei();
	SET_BIT(DDRD,TRIG);//TRIG PD0 as output
	CLEAR_BIT(DDRD,ECHO);//ECHO PD2 as input
	while(1)
	{
			SET_BIT(PORTD,TRIG);//Set TRIG PD0 High
			_delay_us(15);
			CLEAR_BIT(PORTD,TRIG);//Set TRIG PD0 LOW
			distance=time/58;
			LCD_IntToStr(distance);
//		motor_Forward();
//
//		if(Ultrasonic() <= 4)			//safety <= 4cm
//		{
//			motor_STOP();
//			motor_Backward();
//			motor_Right();
//		}
//


	}
}
void Receive(){
	if (flag == 0){ // ECHO state is HIGH (sending)
		SET_BIT(TCCR1B,CS10); //No prescaling (start timer1)
		flag=1;
	}
	else{ // ECHO state is LOW (receiving)
		CLEAR_BIT(TCCR1B,CS10); //stop timer1
		time=TCNT1; //store the TCNT1 value
		TCNT1=0;	//reset TCNT1 value
		flag=0;		//reset flag so that the value is received
	}
}
