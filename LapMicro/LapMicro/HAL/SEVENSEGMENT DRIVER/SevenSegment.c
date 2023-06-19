/*
 * SevenSegment.c
 *
 * Created: 3/19/2023 11:49:41 AM
 */ 
#include "SevenSegment.h"
void sevenSegmentInit(uint8_T portName)
{
	setPortDirection(portName,0xff);
}
void WriteSevenSegment(uint8_T portName,uint8_T number)
{
	uint8_T arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
		setPort(portName,arr[number]);
}
