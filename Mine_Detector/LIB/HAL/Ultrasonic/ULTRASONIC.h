#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "avr/io.h"
#include "avr/delay.h"
#include "avr/interrupt.h"
#include "../../MCAL/DIO/DIO_CFG.h"
#include "../../MCAL/DIO/DIO.h"


#define TRIG	PIN_0
#define ECHO	PIN_2


u32 Ultrasonic();

#endif
