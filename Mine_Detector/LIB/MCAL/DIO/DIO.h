#ifndef DIO_H
#define DIO_H
#include "../../UTILS/STD_TYPES.h"
#include "../../UTILS/BIT_MATH.h"

void SetPinDir(u8 PORT_NAME, u8 PIN_NUMBER, u8 PIN_DIR); //pin direction
void SetPinValue(u8 PORT_NAME, u8 PIN_NUMBER, u8 PIN_VALUE); //pin value
u8 ReadPinValue(u8 PORT_NAME, u8 PIN_NUMBER);//read pin
void SetGroupDir(u8 PORT_NAME, u8 GROUP_DIR);//group direction
void SetGroupValue(u8 PORT_NAME, u8 GROUP_VALUE);//group value
void ToggleGroupValue(u8 PORT_NAME);//Toggle group value
u8 ReadGroupValue(u8 PORT_NAME);//read group
#endif
