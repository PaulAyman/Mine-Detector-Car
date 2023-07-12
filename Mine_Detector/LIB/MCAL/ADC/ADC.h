/*
 * ADC.h
 *
 *  Created on: Sep 5, 2022
 *      Author: DELL
 */
#ifndef ADC_ADC_H_
#define ADC_ADC_H_
#include "../../UTILS/STD_TYPES.h"
#include "../../UTILS/BIT_MATH.h"
#include "ADC_CFG.h"
/************** ADC CONFIGURATIONS *************/
#define ADC_VOLTAGE    ADC_AREF_INT
#define ADC_CHANNEL    ADC_CH0
#define ADC_PRESCALER  ADC_PRE_64
#define ADC_INT_MODE   ADC_DISABLE_INT

/*************** FUNCTIONS PROTOTYPE ***********/

void ADC_VoidInit(void);

void ADC_VoidStartConversion(void);

u16 ADC_u16ReadData(u8 ADC_u8CopyChannelId);

#endif /* ADC_ADC_H_ */
