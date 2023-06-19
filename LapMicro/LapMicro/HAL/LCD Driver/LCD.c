/*
 * LCD.c
 *
 * Created: 9/8/2022 10:48:53 AM
 *  Author: lenovo
 */ 
#include "LCD.h"
void write_high_nibble(uint8_T portName,uint8_T cmd)//xxxx xxxx
{
	cmd&=0xf0;//xxxx0000
	setPortDirection(portName,0xf0);
	writePin(portName,4,LOW);
	writePin(portName,5,LOW);
	writePin(portName,6,LOW);
	writePin(portName,7,LOW);
	switch(portName)
	{
		case 'a':
		case 'A':
		PORTA^=cmd;
		break;
		case 'b':
		case 'B':
		PORTB^=cmd;
		break;
		case 'c':
		case 'C':
		PORTC^=cmd;
		break;
		case 'd':
		case 'D':
		PORTD^=cmd;
		break;
		default:
		break;
	}
	
}
void sendPulse()
{
	writePin('b',EN,HIGH);
	_delay_ms(2);
	writePin('b',EN,LOW);
	_delay_ms(2);
}
void LCD_init(uint8_T portName)
{
	_delay_ms(200);
	#ifdef eight_bits_mode
	setPortDirection(portName,0xff);
	setPinDirection('b',EN,OUTPUT);
	setPinDirection('b',RS,OUTPUT);
	sendCMD(EIGHT_BIT,portName);
	_delay_ms(1);
	sendCMD(CURSOR_ON_DISPLAY_ON,portName);
	_delay_ms(1);
	sendCMD(CLR_SCREEN,portName);
	_delay_ms(10);
	sendCMD(ENTRY_MODE,portName);
	_delay_ms(1);
	#endif
	#ifdef four_bits_mode
	setPinDirection(portName,4,OUTPUT);
	setPinDirection(portName,5,OUTPUT);
	setPinDirection(portName,6,OUTPUT);
	setPinDirection(portName,7,OUTPUT);
	setPinDirection('b',EN,OUTPUT);
	setPinDirection('b',RS,OUTPUT);
	sendCMD(RETURN_HOME,portName);
	_delay_ms(10);
	sendCMD(FOUR_BIT,portName);
	_delay_ms(1);
	sendCMD(CURSOR_ON_DISPLAY_ON,portName);
	_delay_ms(1);
	sendCMD(CLR_SCREEN,portName);
	_delay_ms(10);
	sendCMD(ENTRY_MODE,portName);
	_delay_ms(1);
	#endif
}
void sendCMD(uint8_T cmd,uint8_T portName)
{
	#ifdef eight_bits_mode
	setPort(portName,cmd);
	writePin('b',RS,LOW);//for command
	sendPulse();
	#endif
	#ifdef four_bits_mode
	write_high_nibble(portName,cmd>>4);
	writePin(portName,RS,LOW);
	sendPulse();
	write_high_nibble(portName,cmd);
	writePin(portName,RS,LOW);
	sendPulse();
	_delay_ms(1);
	#endif
}
void LCD_send_char(uint8_T data,uint8_T portName)
{
	#ifdef eight_bits_mode
	setPort(portName,data);
	writePin('b',RS,HIGH);
	sendPulse();
	#endif
	#ifdef four_bits_mode
	write_high_nibble(portName,data>>4);
	writePin('b',RS,HIGH);
	sendPulse();
	write_high_nibble(portName,data);
	writePin('b',RS,HIGH);
	sendPulse();
	_delay_ms(1);
	#endif
}
void LCD_send_string(uint8_T *data,uint8_T portName)
{
	while((*data)!='\0')
	{
		LCD_send_char(*data,portName);
		data++;
	}
}
void LCD_CLR_Screen(uint8_T portName)
{
	sendCMD(CLR_SCREEN,portName);
	_delay_ms(10);
}
void moveCursor(uint8_T row,uint8_T column,uint8_T portName)
{
	uint8_T data=0;
	if (row<1 ||row>2 ||column>16 ||column<1 )
	{
		data=0x80;//first row & first column
	}
	else if(row==1)
	{
		data=0x80+column-1;
	}
	else if(row==2)
	{
		data=0xc0+column-1;
	}
	sendCMD(data,portName);
	_delay_ms(1);
}