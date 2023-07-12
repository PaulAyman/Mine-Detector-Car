#include "../../UTILS/BIT_MATH.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../UTILS/STD_TYPES.h"
#include "LCD_CFG.h"
#include "LCD.h"
#include "avr/delay.h"

//LCD Initialization
void LCD_vInit(void){
	
	SetGroupDir(LCD_DATA_PORT,0xFF);
	SetPinDir(LCD_CTRL_PORT,RS_PIN,OUTPUT);
	SetPinDir(LCD_CTRL_PORT,RW_PIN,OUTPUT);
	SetPinDir(LCD_CTRL_PORT,EN_PIN,OUTPUT);
	_delay_ms(50);
	LCD_vSendCMD(TWO_LINE_LCD_EIGHT_BIT_MODE);
	_delay_ms(50);
	LCD_vSendCMD(CURSOR_ON);
	_delay_ms(50);
	LCD_vSendCMD(CLEAR_COMMAND);
	_delay_ms(50);
	
}

//Sending Commands
void LCD_vSendCMD(u8 cmd){
	
	SetPinValue(LCD_CTRL_PORT,RS_PIN,LOW);
	SetPinValue(LCD_CTRL_PORT,RW_PIN,LOW);
	SetPinValue(LCD_CTRL_PORT,EN_PIN,LOW);
	_delay_ms(50);
	SetPinValue(LCD_CTRL_PORT,EN_PIN,HIGH);
	_delay_ms(50);
	SetGroupValue(LCD_DATA_PORT,cmd);
	_delay_ms(50);
	SetPinValue(LCD_CTRL_PORT,EN_PIN,LOW);
	_delay_ms(50);
//	SetPinValue(LCD_CTRL_PORT,EN_PIN,HIGH);
//	_delay_ms(50);
	
}

//Sending Data
void LCD_vSendData(u8 data){
	SetPinValue(LCD_CTRL_PORT,RS_PIN,HIGH);
	SetPinValue(LCD_CTRL_PORT,RW_PIN,LOW);
	SetPinValue(LCD_CTRL_PORT,EN_PIN,LOW);
	_delay_ms(50);
	SetPinValue(LCD_CTRL_PORT,EN_PIN,HIGH);
	_delay_ms(50);
	SetGroupValue(LCD_DATA_PORT,data);
	_delay_ms(50);
	SetPinValue(LCD_CTRL_PORT,EN_PIN,LOW);
	_delay_ms(50);
//	SetPinValue(LCD_CTRL_PORT,EN_PIN,HIGH);
//	_delay_ms(50);
}
//Display String
void LCD_DispalyStr(u8 Str[]){
	for(u8 i=0;Str[i]!='\0';++i){
		LCD_vSendData(Str[i]);
	}
}
//Go to row & column
void LCD_Go_To_Row_Col(u8 row , u8 col){
	u8 address;
	switch(row){
	case LCD_ROW_0:
		address=row+col;
		LCD_vSendCMD(address|SET_CURSOR_LOCATION);
		break;
	case LCD_ROW_1:
		address=row+col;
			LCD_vSendCMD(address|SET_CURSOR_LOCATION);
			break;
	}
}
//Display string (row,column)
void LCD_DisplayStr_Row_Col(u8 Str[] ,u8 row , u8 col){
	LCD_Go_To_Row_Col(row ,col);
	LCD_DispalyStr(Str);
}
//integer to string
void LCD_IntToStr(u8 num){
 u8 temp=num,No_Of_Digits=1;
 while(temp!=0)
 {
	 No_Of_Digits*=10;
	 temp/=10;

 }
 No_Of_Digits/=10;
 while(num!=0){
	 switch((num/No_Of_Digits)){
	 case 0:
		 LCD_vSendData('0');
		 break;
	 case 1:
	 		 LCD_vSendData('1');
	 		 break;
	 case 2:
	 		 LCD_vSendData('2');
	 		 break;
	 case 3:
	 		 LCD_vSendData('3');
	 		 break;
	 case 4:
	 		 LCD_vSendData('4');
	 		 break;
	 case 5:
	 		 LCD_vSendData('5');
	 		 break;
	 case 6:
	 		 LCD_vSendData('6');
	 		 break;
	 case 7:
	 		 LCD_vSendData('7');
	 		 break;
	 case 8:
	 		 LCD_vSendData('8');
	 		 break;
	 case 9:
	 		 LCD_vSendData('9');
	 		 break;
	 }
	num%=No_Of_Digits;
	No_Of_Digits/=10;
 }
 return;
}
