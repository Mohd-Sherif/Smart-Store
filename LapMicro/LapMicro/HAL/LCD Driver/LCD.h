#ifndef LCD_H_
#define LCD_H
#include "../../std_macros.h"
#define F_CPU 8000000UL
#include "util/delay.h"
#include "LCD_config.h"
#define EN 0
#define RS 1
#define RW 2
#define FOUR_BIT 0x28
#define EIGHT_BIT 0x38
#define CURSOR_ON_DISPLAY_ON 0x0F 
#define CLR_SCREEN 0x01 
#define ENTRY_MODE 0x06   //moveCursor to right when write and not shift the screen
#define RETURN_HOME 0x02 //return to 1st row & 1st column 
#define CURSOR_OR_DISP_shift 0x14//14

/*
	Function Name        : LCD_init
	Function Returns     : void
	Function Arguments   : void
     Function Description : initialization of LCD   
*/
void LCD_init(u8 portName);
/*
	Function Name        : sendPulse
	Function Returns     : void
	Function Arguments   : void
     Function Description : send pulses to EN pin   
*/
void sendPulse();
/*
	Function Name        : sendCMD
	Function Returns     : void
	Function Arguments   : uint8_t cmd
     Function Description : send commands
*/
void sendCMD(u8 cmd,u8 portName);
void write_high_nibble(u8 portName,u8 cmd);
/*
	Function Name        : LCD_send_char
	Function Returns     : void
	Function Arguments   : uint8_t data ,uint8_t portName
     Function Description : send data
*/
void LCD_send_char(u8 data,u8 portName);
/*
	Function Name        : LCD_send_strin
	Function Returns     : void
	Function Arguments   : char *data
     Function Description : send String data
*/
void LCD_send_string(u8 *data,u8 portName);
/*
Function Name        : LCD_CLR_Screen
Function Returns     : void
Function Arguments   : void
Function Description : clear screen
*/
void LCD_CLR_Screen(u8 portName);
/*
Function Name        : moveCursor
Function Returns     : void
Function Arguments   : uint8_t row,uint8_t column,uint8_t portName
Function Description : moveCursor
*/
void moveCursor(u8 row,u8 column,u8 portName);
#endif /* LCD_H_ */



