#include "../../UTILS/STD_TYPES.h"
#include "../../UTILS/BIT_MATH.h"
#include "../DIO/DIO.h"
#include "../DIO/DIO_CFG.h"
#include "avr/io.h"
#include "INTERRUPT.h"
#include "INTERRUPT_CFG.h"
#include "avr/interrupt.h"
#define NULL ((void*)0)
static volatile void (*G_Ptr_To_Func_INT0)(void)=NULL;
static volatile void (*G_Ptr_To_Func_INT1)(void)=NULL;
static volatile void (*G_Ptr_To_Func_INT2)(void)=NULL;

//Alternative to ISR for INIT0
void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	G_Ptr_To_Func_INT0();
}

//Alternative to ISR for INIT1
void __vector_2(void)__attribute__((signal));
void __vector_2(void)
{
	G_Ptr_To_Func_INT1();
}

//Alternative to ISR for INIT2
void __vector_3(void)__attribute__((signal));
void __vector_3(void)
{
	G_Ptr_To_Func_INT2();
}

//SET_CALLBACK
void SET_CALLBACK(void (*L_Ptr_To_Func)(void), u8 Ex_INT)
{
	switch(Ex_INT){
	case Ex_INT0:
		G_Ptr_To_Func_INT0=L_Ptr_To_Func;
		break;
	case Ex_INT1:
			G_Ptr_To_Func_INT1=L_Ptr_To_Func;
			break;
	case Ex_INT2:
			G_Ptr_To_Func_INT2=L_Ptr_To_Func;
			break;
}}

//INT0 Enable
void INT0_Enable(){
	CLEAR_BIT(SREG,PIN_7);//Disable GIE
	CLEAR_BIT(DDRD,INT0); //set PD2 as input
	SET_BIT(PORTD,INT0); //activate pull up for PD2
	SET_BIT(MCUCR,ISC00); //Any logical change on INT0 generates an interrupt request.
	SET_BIT(GICR,INT0); //Enable PIE for INT0
	SET_BIT(SREG,PIN_7);//Enable GIE
}

//INT1 Enable
void INT1_Enable(){
	CLEAR_BIT(SREG,PIN_7); //disable GIE
	CLEAR_BIT(DDRD,PIN_2); //set PD3 as input
	SET_BIT(PORTD,PIN_2); //activate pull up for PD3
	SET_BIT(MCUCR,PIN_3); //sense falling edge for INT1
	SET_BIT(GICR,PIN_7); //Enable PIE for INT1
	SET_BIT(SREG,PIN_7); //enable GIE
}

//INT2 Enable
void INT2_Enable(){
	CLEAR_BIT(SREG,PIN_7); //disable GIE
	CLEAR_BIT(DDRB,PIN_2); //set PB2 as input
	SET_BIT(PORTB,PIN_2); //activate pull up for PD3
	CLEAR_BIT(MCUCR,PIN_6); //sense falling edge for INT2
	SET_BIT(GICR,PIN_5); //Enable PIE for INT2
	SET_BIT(SREG,PIN_7); //enable GIE
}
