/*
 * Dio.h
 *
 * Created: 8/31/2022 5:42:11 AM
 *  Author: lenovo
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../registers.h"
#include "../../std_macros.h"
/*
Function Name        : DIO_setPINDir
Function Returns     : void
Function Arguments   : uint8_t portName,uint8_t pinNumber,uint8_t direction
Function Description : Set the direction of the given pin in the given port (direction 0 = input : 1 = output)
*/

void setPinDirection(u8 portName,u8 pinNumber ,u8 direction);
/*
Function Name        : writePin
Function Returns     : void
Function Arguments   : uint8_t portName,uint8_t pinNumber,uint8_t outputValue
Function Description : Set the value of the given pin in the given port (outputValue 0 = low : 1 = high)
*/
void writePin(u8 portName ,u8 pinNumber , u8 outputValue);
/*
Function Name        : readPin
Function Returns     : uint8_t
Function Arguments   : uint8_t portName,uint8_t pinNumber
Function Description : Returns 1 if the value of the given pin is high and zero if the value is low
*/
u8 readPin(u8 portName,u8 pinNumber);
/*
Function Name        : togglePin
Function Returns     : void
Function Arguments   : uint8_t portName,uint8_t pinNumber
Function Description : Reverse the value of the given pin in the given port.
*/
void toggPin(u8 portName,u8 pinNumber);
/*
Function Name        : setPortDirection
Function Returns     : void
Function Arguments   : uint8_t portName,uint8_t direction
Function Description : set the direction of whole port .
*/
void setPortDirection(u8 portName,u8 direction);
/*
Function Name        : setPort
Function Returns     : void
Function Arguments   : uint8_t portName,uint8_t portValue
Function Description : Write the value to all port pins.
*/
void setPort(u8 portName,u8 value);
/*
Function Name        : readPort
Function Returns     : uint8_t
Function Arguments   : uint8_t portName
Function Description : read the value of the port .
*/
u8 readPort(u8 portName);

/*
Function Name        : writeLowNibble
Function Returns     : void
Function Arguments   : uint8_t portName,uint8_T value
Function Description : Write Lower part of port.
*/
void writeLowNibble(u8 portName ,u8 value);
/*
Function Name        : writeHighNibble
Function Returns     : void
Function Arguments   : uint8_t portName,uint8_T value
Function Description : Write Higher part of port.
*/
void writeHighNibble(u8 portName,u8 value);
#endif /* DIO_H_ */