/*
 * Button.c
 *
 * Created: 9/1/2022 12:27:23 AM
 *  Author: lenovo
 */ 
#include "Button.h"
/*
Function Name        : ButtonInit
Function Returns     : void
Function Arguments   : uint8_t portName,uint8_t pinNumber
Function Description : define the given pin in the given port as input pin
*/
void ButtonInit(uint8_T portName,uint8_T pinNumber)
{
	setPinDirection(portName,pinNumber,INPUT);
}
/*
Function Name        : ButtonRead
Function Returns     : uint8_t
Function Arguments   : uint8_t portName,uint8_t pinNumber
Function Description : Returns 0 or 1 depend on the status of the button(pressed or not) and the type of connection (pull up or pull down)
*/
uint8_T ButtonRead(uint8_T portName,uint8_T pinNumber)
{
	uint8_T readVal=0;
	readVal=readPin(portName,pinNumber);
	return readVal;
}
/*
	Function Name        : connectPullup
	Function Returns     : void
	Function Arguments   : uint8_t portName,uint8_t pinNumber
     Function Description : Connect and disconnect pull up resistor to the given pin at the given port 
*/
 void connectPullup(uint8_T portName,uint8_T pinNumber)
 {
	 switch (portName)
	 {
	 case 'a':
	 case 'A':
	 SET_BIT(PORTA,pinNumber);
	 //CLR_BIT(PINA,pinNumber);
	 	break;
	case 'b':
	case 'B':
	SET_BIT(PORTB,pinNumber);
	//CLR_BIT(PINB,pinNumber);
	   break;
	case 'c':
	case 'C':
	SET_BIT(PORTC,pinNumber);
	//CLR_BIT(PINC,pinNumber);
	 break;
	case 'd':
	case 'D':
	SET_BIT(PORTD,pinNumber);
	//CLR_BIT(PIND,pinNumber);
	break;
	default:
	break;
	 }
 }
