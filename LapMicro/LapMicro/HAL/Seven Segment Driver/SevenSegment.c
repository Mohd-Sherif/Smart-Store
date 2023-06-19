/*
 * SevenSegment.c
 *
 * Created: 3/19/2023 11:49:41 AM
 */ 
#include "SevenSegment.h"
void sevenSegmentInit(uint8_T portName)
{
	setPortDirection(portName,OUTPUT);
}
void WriteSevenSegment(uint8_T portName,uint8_T number)
{
	uint8_T arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
		//{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f}; cathode
		//{0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90}; anode
		setPort(portName,arr[number]);
}
void seven_seg_BCD_init(uint8_T portName,uint8_T half)
{
	if(half==UPPER)
	{
		setPinDirection(portName,0,OUTPUT);
		setPinDirection(portName,1,OUTPUT);
		setPinDirection(portName,2,OUTPUT);
		setPinDirection(portName,3,OUTPUT);
	}
	else if (half==LOWER)
	{
		setPinDirection(portName,4,OUTPUT);
		setPinDirection(portName,5,OUTPUT);
		setPinDirection(portName,6,OUTPUT);
		setPinDirection(portName,7,OUTPUT);
	}
}
void WriteSevenSegmentBCD(uint8_T portName,uint8_T dir,uint8_T value)
{
	if(dir==UPPER)
	writeLowNibble(portName,value);
	else if (dir==LOWER)
	writeHighNibble(portName,value);
}
