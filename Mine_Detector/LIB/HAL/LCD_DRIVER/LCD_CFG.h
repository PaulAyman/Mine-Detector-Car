#ifndef LCD_CFG_H
#define LCD_CFG_H
#include "../../MCAL/DIO/DIO_CFG.h"
/********* LCD COMMANDS *********/
#define CLEAR_COMMAND 0x01
#define TWO_LINE_LCD_EIGHT_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON  0x0F
#define SET_CURSOR_LOCATION 0x80

/************* LCD ROWS & COLUMNS ADDRESSES ***************/
#define LCD_ROW_0 0x00
#define LCD_ROW_1 0x40
#define LCD_ROW_2 0x10
#define LCD_ROW_3 0x50

#define LCD_COL_0  0x00
#define LCD_COL_1  0x01
#define LCD_COL_2  0x02
#define LCD_COL_3  0x03
#define LCD_COL_4  0x04
#define LCD_COL_5  0x05
#define LCD_COL_6  0x06
#define LCD_COL_7  0x07
#define LCD_COL_8  0x08
#define LCD_COL_9  0x09
#define LCD_COL_10 0x0A
#define LCD_COL_11 0x0B
#define LCD_COL_12 0x0C
#define LCD_COL_13 0x0D
#define LCD_COL_14 0x0E
#define LCD_COL_15 0x0F

/************* LCD PORTS ***************/
#define LCD_DATA_PORT GROUP_C
#define LCD_CTRL_PORT GROUP_D
#define RS_PIN PIN_0
#define RW_PIN PIN_1
#define EN_PIN PIN_2

#endif
