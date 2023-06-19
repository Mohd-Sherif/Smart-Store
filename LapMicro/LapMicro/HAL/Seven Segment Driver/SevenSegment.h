/*
 * SevenSegment.h
 *
 * Created: 3/19/2023 11:50:03 AM
 *  Author: Afrotto
 */ 


#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

#include "../../MCAL/DIO Driver/Dio.h"
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

/*
Function Name        : seven_seg_BCD_init
Function Returns     : void
Function Arguments   : uint8_t portName
Function Description : initiate a 1/2 port.
*/
void seven_seg_BCD_init(uint8_T portName,uint8_T half);

/*
Function Name        : WriteSevenSegmentBCD
Function Returns     : void
Function Arguments   : uint8_T portName,uint8_T dir,uint8_T value
Function Description : write a 1/2 port.
*/
void WriteSevenSegmentBCD(uint8_T portName,uint8_T dir,uint8_T value);
#endif /* SEVENSEGMENT_H_ */