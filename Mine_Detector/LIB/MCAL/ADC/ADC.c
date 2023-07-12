/*
 * ADC.c
 *
 *  Created on: Sep 5, 2022
 *      Author: DELL
 */
#include "../DIO/DIO.h"
#include "../DIO/DIO_CFG.h"
#include "avr/io.h"
#include "ADC.h"

//ADC Initialization
void ADC_VoidInit(void)
{
#if ADC_VOLTAGE == ADC_AREF_INT

	SET_BIT(ADMUX,PIN_7);
	SET_BIT(ADMUX,PIN_6);

#elif ADC_VOLTAGE == ADC_AREF_EXT

	CLEAR_BIT(ADMUX,PIN_7);
	CLEAR_BIT(ADMUX,PIN_6);

#elif ADC_VOLTAGE == ADC_AVCC

	CLEAR_BIT(ADMUX,PIN_7);
	SET_BIT(ADMUX,PIN_6);

#endif

	ADMUX=(ADMUX & 0xE0) | (ADC_CHANNEL & 0x1F); // BIT Masking

	SET_BIT(ADCSRA,PIN_7);

#if ADC_INT_MODE == ADC_DISABLE_INT
	CLEAR_BIT(ADCSRA,PIN_3);

#elif ADC_INT_MODE == ADC_ENABLE_INT

	SET_BIT(ADCSRA,PIN_3);

#endif

#if ADC_PRESCALER == ADC_PRE_128
	SET_BIT(ADCSRA,PIN_2);
	SET_BIT(ADCSRA,PIN_1);
	SET_BIT(ADCSRA,PIN_0);

#elif ADC_PRESCALER == ADC_PRE_64
	SET_BIT(ADCSRA,PIN_2);
	SET_BIT(ADCSRA,PIN_1);
	CLEAR_BIT(ADCSRA,PIN_0);

#elif ADC_PRESCALER == ADC_PRE_32
	SET_BIT(ADCSRA,PIN_2);
	CLEAR_BIT(ADCSRA,PIN_1);
	SET_BIT(ADCSRA,PIN_0);

#elif ADC_PRESCALER == ADC_PRE_16
	SET_BIT(ADCSRA,PIN_2);
	CLEAR_BIT(ADCSRA,PIN_1);
	CLEAR_BIT(ADCSRA,PIN_0);

#elif ADC_PRESCALER == ADC_PRE_8
	CLEAR_BIT(ADCSRA,PIN_2);
	SET_BIT(ADCSRA,PIN_1);
	SET_BIT(ADCSRA,PIN_0);

#elif ADC_PRESCALER == ADC_PRE_4
	CLEAR_BIT(ADCSRA,PIN_2);
	SET_BIT(ADCSRA,PIN_1);
	CLEAR_BIT(ADCSRA,PIN_0);

#elif ADC_PRESCALER == ADC_PRE_2
	CLEAR_BIT(ADCSRA,PIN_2);
	CLEAR_BIT(ADCSRA,PIN_1);
	CLEAR_BIT(ADCSRA,PIN_0);

#endif
}

//Start Conversion
void ADC_VoidStartConversion(void){
SET_BIT(ADCSRA,PIN_6);
}

//Read Data
u16 ADC_u16ReadData(u8 ADC_u8CopyChannelId){
	ADMUX=(ADMUX & 0xE0) | (ADC_u8CopyChannelId & 0x1F); // BIT Masking

	ADC_VoidStartConversion();

#if ADC_INT_MODE == ADC_DISABLE_INT

	while (READ_BIT(ADCSRA,PIN_4)==0);
	SET_BIT(ADCSRA,PIN_4); //Clear Flag by setting flag

#elif ADC_INT_MODE == ADC_ENABLE_INT
#endif
	return ADC;
}
