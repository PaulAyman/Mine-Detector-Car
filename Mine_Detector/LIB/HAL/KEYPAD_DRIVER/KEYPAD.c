#include "../../UTILS/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/DIO/DIO_CFG.h"
#include "KEYPAD.h"
#include "KEYPAD_CFG.h"

u8 KEYPAD_VALUES[4][4]=
{
	{'1','2','3','+'},
	{'4','5','6','-'},
	{'7','8','9','*'},
	{'%','0','=','/'}
};

//keypad initialization
void KEYPAD_Init(void){
	//COLs
	SetPinDir(KEYPAD_PORT,COL_0,OUTPUT);
	SetPinDir(KEYPAD_PORT,COL_1,OUTPUT);
	SetPinDir(KEYPAD_PORT,COL_2,OUTPUT);
	SetPinDir(KEYPAD_PORT,COL_3,OUTPUT);
	
	SetPinValue(KEYPAD_PORT,COL_0,HIGH);
	SetPinValue(KEYPAD_PORT,COL_1,HIGH);
	SetPinValue(KEYPAD_PORT,COL_2,HIGH);
	SetPinValue(KEYPAD_PORT,COL_3,HIGH);
	
	//ROWs
	SetPinDir(KEYPAD_PORT,ROW_0,INPUT);
	SetPinDir(KEYPAD_PORT,ROW_1,INPUT);
	SetPinDir(KEYPAD_PORT,ROW_2,INPUT);
	SetPinDir(KEYPAD_PORT,ROW_3,INPUT);
	
	//Pull Up Resistors
	SetPinValue(KEYPAD_PORT,ROW_0,HIGH);
	SetPinValue(KEYPAD_PORT,ROW_1,HIGH);
	SetPinValue(KEYPAD_PORT,ROW_2,HIGH);
	SetPinValue(KEYPAD_PORT,ROW_3,HIGH);
}

//keypad getting value
u8 KEYPAD_GetValue(void){
	u8 value=NOT_PRESSED,Col_Counter,Row_Counter;
	for(Col_Counter=COL_0; Col_Counter<=COL_3;Col_Counter++){
		SetPinValue(KEYPAD_PORT,Col_Counter,LOW);
		for(Row_Counter=ROW_0; Row_Counter<=ROW_3;Row_Counter++){
			if(ReadPinValue(KEYPAD_PORT,Row_Counter)==PRESSED){
				while(ReadPinValue(KEYPAD_PORT,Row_Counter)==PRESSED);
				value=KEYPAD_VALUES[Row_Counter-ROW_0][Col_Counter];
				SetPinValue(KEYPAD_PORT,Col_Counter,HIGH);
				return value;
			}
		}
		SetPinValue(KEYPAD_PORT,Col_Counter,HIGH);
	}
	return value;
}
