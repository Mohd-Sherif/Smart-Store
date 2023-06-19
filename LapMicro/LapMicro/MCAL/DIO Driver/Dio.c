/*
 * Dio.c
 *
 * Created: 8/31/2022 5:58:45 AM
 *  Author: lenovo
 */ 
#include "Dio.h"


/*
Function Name        : DIO_setPINDir
Function Returns     : void
Function Arguments   : uint8_t portName,uint8_t pinNumber,uint8_t direction
Function Description : Set the direction of the given pin in the given port (direction 0 = input : 1 = output)
*/

void setPinDirection(uint8_T portName,uint8_T pinNumber ,uint8_T direction)
{
	switch(portName)
	{
		case 'a':
		case 'A':
		if (direction==OUTPUT)
		{
			SET_BIT(DDRA,pinNumber);
		}
		else
		{
			CLR_BIT(DDRA,pinNumber);
		}
		break;
		case 'b':
		case 'B':
		if (direction==OUTPUT)
		{
			SET_BIT(DDRB,pinNumber);
		}
		else
		{
			CLR_BIT(DDRB,pinNumber);
		}
		break;
		case 'c':
		case 'C':
		if (direction==OUTPUT)
		{
			SET_BIT(DDRC,pinNumber);
		}
		else
		{
			CLR_BIT(DDRC,pinNumber);
		}
		break;
		case 'd':
		case 'D':
		if (direction==OUTPUT)
		{
			SET_BIT(DDRD,pinNumber);
		}
		else
		{
			CLR_BIT(DDRD,pinNumber);
		}
		break;
		default:
		break;
	}
}
/*
Function Name        : writePin
Function Returns     : void
Function Arguments   : uint8_t portName,uint8_t pinNumber,uint8_t outputValue
Function Description : Set the value of the given pin in the given port (outputValue 0 = low : 1 = high)
*/
void writePin(uint8_T portName ,uint8_T pinNumber , uint8_T outputValue)
{
	switch(portName)
	{
		case 'a':
		case 'A':
		if (outputValue==HIGH)
		{
			SET_BIT(PORTA,pinNumber);
		}
		else
		{
			CLR_BIT(PORTA,pinNumber);
		}
		break;
		case 'b':
		case 'B':
		if (outputValue==HIGH)
		{
			SET_BIT(PORTB,pinNumber);
		}
		else
		{
			CLR_BIT(PORTB,pinNumber);
		}
		break;
		case 'c':
		case 'C':
		if (outputValue==HIGH)
		{
			SET_BIT(PORTC,pinNumber);
		}
		else
		{
			CLR_BIT(PORTC,pinNumber);
		}
		break;
		case 'd':
		case 'D':
		if (outputValue==HIGH)
		{
			SET_BIT(PORTD,pinNumber);
		}
		else
		{
			CLR_BIT(PORTD,pinNumber);
		}
		break;
		default:
		break;
	}
}
/*
Function Name        : readPin
Function Returns     : uint8_t
Function Arguments   : uint8_t portName,uint8_t pinNumber
Function Description : Returns 1 if the value of the given pin is high and zero if the value is low
*/
uint8_T readPin(uint8_T portName,uint8_T pinNumber)
{
	uint8_T readVal=0;
	switch(portName)
	{
		case 'a':
		case 'A':
		readVal=READ_BIT(PINA,pinNumber);
		break;
		case 'b':
		case 'B':
		readVal=READ_BIT(PINB,pinNumber);
		break;
		case 'c':
		case 'C':
		readVal=READ_BIT(PINC,pinNumber);
		break;
		case 'd':
		case 'D':
		readVal=READ_BIT(PIND,pinNumber);
		break;
		default:
		break;
	}
	return readVal;
}
/*
Function Name        : togglePin
Function Returns     : void
Function Arguments   : uint8_t portName,uint8_t pinNumber
Function Description : Reverse the value of the given pin in the given port.
*/
void toggPin(uint8_T portName,uint8_T pinNumber)
{
	switch(portName)
	{
		case 'a':
		case 'A':
		TOG_BIT(PORTA,pinNumber);
		break;
		case 'b':
		case 'B':
		TOG_BIT(PORTB,pinNumber);
		break;
		case 'c':
		case 'C':
		TOG_BIT(PORTC,pinNumber);
		break;
		case 'd':
		case 'D':
		TOG_BIT(PORTD,pinNumber);
		break;
		default:
		break;
	}
}
/*
Function Name        : setPortDirection
Function Returns     : void
Function Arguments   : uint8_t portName,uint8_t direction
Function Description : set the direction of whole port .
*/
void setPortDirection(uint8_T portName,uint8_T direction)
{
	switch(portName)
	{
		case 'a':
		case 'A':
		if (direction==OUTPUT)
		{
			DDRA=0xff;
		}
		else
		{
			DDRA=0x00;
		}
		break;
		case 'b':
		case 'B':
		if (direction==OUTPUT)
		{
			DDRB=0xff;
		}
		else
		{
			DDRB=0x00;
		}
		break;
		case 'c':
		case 'C':
		if (direction==OUTPUT)
		{
			DDRC=0xff;
		}
		else
		{
			DDRC=0x00;
		}
		break;
		case 'd':
		case 'D':
		if (direction==OUTPUT)
		{
			DDRD=0xff;
		}
		else
		{
			DDRD=0x00;
		}
		break;
		default:
		break;
	}
	
}
/*
Function Name        : setPort
Function Returns     : void
Function Arguments   : uint8_t portName,uint8_t portValue
Function Description : Write the value to all port pins.
*/
void setPort(uint8_T portName,uint8_T value)
{
	switch(portName)
	{
		case 'a':
		case 'A':
		PORTA=value;
		break;
		case 'b':
		case 'B':
		PORTB=value;
		break;
		case 'c':
		case 'C':
		PORTC=value;
		break;
		case 'd':
		case 'D':
		PORTD=value;
		break;
		default:
		break;
	}
}
/*
Function Name        : readPort
Function Returns     : uint8_t
Function Arguments   : uint8_t portName
Function Description : read the value of the port .
*/
uint8_T readPort(uint8_T portName)
{
	uint8_T readVal=0;
	switch(portName)
	{
		case 'a':
		case 'A':
		readVal=PINA;
		break;
		case 'b':
		case 'B':
		readVal=PINB;
		break;
		case 'c':
		case 'C':
		readVal=PINC;
		break;
		case 'd':
		case 'D':
		readVal=PIND;
		break;
		default:
		break;
	}
	return readVal;
}
void writeHighNibble(uint8_T portName ,uint8_T value) // 4 5 6 7
{
	value<<=4;
	switch (portName)
	{
		case 'A':
		case 'a':
		PORTA&=0x0f;
		PORTA|=value;
		break;
		case 'b':
		case 'B':
		PORTB&=0x0f;
		PORTB|=value;
		break;
		case 'c':
		case 'C':
		PORTC&=0x0f;
		PORTC|=value;
		break;
		case 'd':
		case 'D':
		PORTD&=0x0f;
		PORTD|=value;
		break;
	}
}
void writeLowNibble(uint8_T portName,uint8_T value)
{
	value&=0x0f;
	switch(portName)
	{
		case 'A':
		case 'a':
		PORTA&=0xf0;
		PORTA|=value;
		break;
		case 'b':
		case 'B':
		PORTB&=0xf0;
		PORTB|=value;
		break;
		case 'C':
		case 'c':
		PORTC&=0xf0;
		PORTC|=value;
		break;
		case 'D':
		case 'd':
		PORTD&=0xf0;
		PORTD|=value;
		break;
	}
}