#ifndef LCD_H
#define LCD_H
#include "../../UTILS/STD_TYPES.h"

//LCD Initialization
void LCD_vInit(void);
//Sending Commands
void LCD_vSendCMD(u8 cmd);
//Sending Data
void LCD_vSendData(u8 data);
//Display String
void LCD_DispalyStr(u8 Str[]);
//Go to row & column
void LCD_Go_To_Row_Col(u8 row , u8 col);
//Display string (row,column)
void LCD_DisplayStr_Row_Col(u8 Str[] ,u8 row , u8 col);
//integer to string
void LCD_IntToStr(u8 num);
#endif
