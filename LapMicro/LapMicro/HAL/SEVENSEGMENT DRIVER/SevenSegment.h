/*
 * SevenSegment.h
 *
 * Created: 3/19/2023 11:50:03 AM
 *  Author: Afrotto
 */ 


#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

#include "c:\users\afrotto\Documents\Atmel Studio\7.0\My first project\My first project\MCAL\Dio Driver\Dio.h"
/*
Function Name        : sevenSegmentInit
Function Returns     : void
Function Arguments   : uint8_t portName
Function Description : Initialize Seven Segment.
*/
void sevenSegmentInit(uint8_T portName);
/*
Function Name        : WriteSevenSegment
Function Returns     : void
Function Arguments   : uint8_t portName,uint8_T number
Function Description : write a number on Seven Segment.
*/
void WriteSevenSegment(uint8_T portName,uint8_T number);



#endif /* SEVENSEGMENT_H_ */