#include "../../UTILS/STD_TYPES.h"
#include "../../UTILS/BIT_MATH.h"
#include "DIO_CFG.h"
#include "DIO.h"
#include "avr/io.h"


//pin direction
void SetPinDir(u8 PORT_NAME, u8 PIN_NUMBER, u8 PIN_DIR){
	if(PIN_DIR == OUTPUT){
		switch(PORT_NAME){
			case GROUP_A:
			SET_BIT(DDRA,PIN_NUMBER);
			break;
			case GROUP_B:
			SET_BIT(DDRB,PIN_NUMBER);
			break;
			case GROUP_C:
			SET_BIT(DDRC,PIN_NUMBER);
			break;
			case GROUP_D:
			SET_BIT(DDRD,PIN_NUMBER);
			break;
			default:
			break;
	}}
		else{
			switch(PORT_NAME){
				case GROUP_A:
			CLEAR_BIT(DDRA,PIN_NUMBER);
			break;
			case GROUP_B:
			CLEAR_BIT(DDRB,PIN_NUMBER);
			break;
			case GROUP_C:
			CLEAR_BIT(DDRC,PIN_NUMBER);
			break;
			case GROUP_D:
			CLEAR_BIT(DDRD,PIN_NUMBER);
			break;
			default:
			break;
			}
		}
	}

//pin value
void SetPinValue(u8 PORT_NAME, u8 PIN_NUMBER, u8 PIN_VALUE){
	if(PIN_VALUE == HIGH){
		switch(PORT_NAME){
			case GROUP_A:
			SET_BIT(PORTA,PIN_NUMBER);
			break;
			case GROUP_B:
			SET_BIT(PORTB,PIN_NUMBER);
			break;
			case GROUP_C:
			SET_BIT(PORTC,PIN_NUMBER);
			break;
			case GROUP_D:
			SET_BIT(PORTD,PIN_NUMBER);
			break;
			default:
			break;
		}}
		else{
			switch(PORT_NAME){
			case GROUP_A:
			CLEAR_BIT(PORTA,PIN_NUMBER);
			break;
			case GROUP_B:
			CLEAR_BIT(PORTB,PIN_NUMBER);
			break;
			case GROUP_C:
			CLEAR_BIT(PORTC,PIN_NUMBER);
			break;
			case GROUP_D:
			CLEAR_BIT(PORTD,PIN_NUMBER);
			break;
			default:
			break;
			}
		}
	}
	
	
//read pin
u8 ReadPinValue(u8 PORT_NAME, u8 PIN_NUMBER)
{
u8 value;
switch(PORT_NAME){
	case GROUP_A:
			value = READ_BIT(PINA,PIN_NUMBER);
			break;
			case GROUP_B:
			value = READ_BIT(PINB,PIN_NUMBER);
			break;
			case GROUP_C:
			value = READ_BIT(PINC,PIN_NUMBER);
			break;
			case GROUP_D:
			value=READ_BIT(PIND,PIN_NUMBER);
			break;
			default:
			break;
}
return value;	
}

//group direction
void SetGroupDir(u8 PORT_NAME,u8 GROUP_DIR){
		switch(PORT_NAME){
			case GROUP_A:
			DDRA=GROUP_DIR;
			break;
			case GROUP_B:
			DDRB=GROUP_DIR;
			break;
			case GROUP_C:
			DDRC=GROUP_DIR;
			break;
			case GROUP_D:
			DDRD=GROUP_DIR;
			break;
			default:
			break;
		}
}

//group value
void SetGroupValue(u8 PORT_NAME, u8 GROUP_VALUE){
		switch(PORT_NAME){
			case GROUP_A:
			PORTA=GROUP_VALUE;
			break;
			case GROUP_B:
			PORTB=GROUP_VALUE;
			break;
			case GROUP_C:
			PORTC=GROUP_VALUE;
			break;
			case GROUP_D:
			PORTD=GROUP_VALUE;
			break;
			default:
			break;
		}
		}

//Toggle group value
void ToggleGroupValue(u8 PORT_NAME){
	switch(PORT_NAME){
				case GROUP_A:
				TOGGLE_BIT(PORTA,PIN_0);
				TOGGLE_BIT(PORTA,PIN_1);
				TOGGLE_BIT(PORTA,PIN_2);
				TOGGLE_BIT(PORTA,PIN_3);
				TOGGLE_BIT(PORTA,PIN_4);
				TOGGLE_BIT(PORTA,PIN_5);
				TOGGLE_BIT(PORTA,PIN_6);
				TOGGLE_BIT(PORTA,PIN_7);
				break;
				case GROUP_B:
					TOGGLE_BIT(PORTB,PIN_0);
					TOGGLE_BIT(PORTB,PIN_1);
					TOGGLE_BIT(PORTB,PIN_2);
					TOGGLE_BIT(PORTB,PIN_3);
					TOGGLE_BIT(PORTB,PIN_4);
					TOGGLE_BIT(PORTB,PIN_5);
					TOGGLE_BIT(PORTB,PIN_6);
					TOGGLE_BIT(PORTB,PIN_7);
				break;
				case GROUP_C:
					TOGGLE_BIT(PORTC,PIN_0);
					TOGGLE_BIT(PORTC,PIN_1);
					TOGGLE_BIT(PORTC,PIN_2);
					TOGGLE_BIT(PORTC,PIN_3);
					TOGGLE_BIT(PORTC,PIN_4);
					TOGGLE_BIT(PORTC,PIN_5);
					TOGGLE_BIT(PORTC,PIN_6);
					TOGGLE_BIT(PORTC,PIN_7);
				break;
				case GROUP_D:
					TOGGLE_BIT(PORTD,PIN_0);
					TOGGLE_BIT(PORTD,PIN_1);
					TOGGLE_BIT(PORTD,PIN_2);
					TOGGLE_BIT(PORTD,PIN_3);
					TOGGLE_BIT(PORTD,PIN_4);
					TOGGLE_BIT(PORTD,PIN_5);
					TOGGLE_BIT(PORTD,PIN_6);
					TOGGLE_BIT(PORTD,PIN_7);
				break;
				default:
				break;
			}
}
//read group
u8 ReadGroupValue(u8 PORT_NAME){
	u8 value;
switch(PORT_NAME){
	case GROUP_A:
			value = PINA;
			break;
			case GROUP_B:
			value = PINB;
			break;
			case GROUP_C:
			value = PINC;
			break;
			case GROUP_D:
			value = PIND;
			break;
			default:
			break;
}
return value;
}	
