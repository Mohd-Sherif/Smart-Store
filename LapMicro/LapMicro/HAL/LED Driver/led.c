/*
 * led.c
 *
 * Created: 8/31/2022 10:21:45 PM
 *  Author: lenovo
 */ 
#include "Led.h"
/*
Function Name        : LED_Init
Function Returns     : void
Function Arguments   : uint8_t portName,uint8_t pinNumber
Function Description : Initialize the pin as an output pin to connect the led.
*/
void LED_Init(uint8_T portName,uint8_T pinNumber)
{
		setPinDirection(portName,pinNumber,OUTPUT);
}
/*
Function Name        : LED_TurnOn
Function Returns     : void
Function Arguments   : uint8_t portName,uint8_t pinNumber
Function Description : Turn on the led connected to the given pin and port.
*/
void LED_TurnOn(uint8_T portName,uint8_T pinNumber)
{
	writePin(portName,pinNumber,HIGH);
}
/*
Function Name        : LED_TurnOff
Function Returns     : void
Function Arguments   : uint8_t portName,uint8_t pinNumber
Function Description : Turn off the led connected to the given pin and port.
*/
void LED_TurnOff(uint8_T portName,uint8_T pinNumber)
{
	writePin(portName,pinNumber,LOW);
}
/*
Function Name        : LED_Toggle
Function Returns     : void
Function Arguments   : uint8_t portName,uint8_t pinNumber
Function Description : Toggle the led connected to the given pin and port.
*/
void LED_Toggle(uint8_T portName,uint8_T pinNumber)
{
	toggPin(portName,pinNumber);
}