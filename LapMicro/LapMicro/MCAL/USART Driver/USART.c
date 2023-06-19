/*
 * USART.c
 *
 * Created: 9/16/2022 7:43:02 PM
 *  Author: lenovo
 */ 
#include "USART.h"
/*
Function Name        : UART_init
Function Returns     : void
Function Arguments   : void
Function Description : initialization UART protocol.
*/
void UART_init(unsigned long long baudRate)
{
	unsigned short Baud_prescale=((8000000UL/(baudRate*16UL))-1);
	//fosc=1MHZ 
	//1.select BAUD rate & UBBRH & UBBRL
	
	//URSEL bit 7 in UBBRH must be zero when writing in UBBRH 
	UBRRH=(Baud_prescale>>8);
	UBRRL=Baud_prescale;
	
	//3.enable receiving and transmitting
	//SET_BIT(UCSRB,3);//trans
	//SET_BIT(UCSRB,4);//receive
	UCSRB|=(1<<3)|(1<<4);
	//4.choose normal or double speed
	//choose double
	//SET_BIT(UCSRA,1);
	//Enable interruot bits for recieving and sending
	UCSRB|=(1<<6)|(1<<7);
	//5.choose number of data bits  , parity stop from UCSRC
	//8 data bits , 1 stop bit , no parity
	//SET_BIT(UCSRC,1);//8 bit data
	//SET_BIT(UCSRC,2);//8 bit data
	UCSRC=(1<<7)|(1<<1)|(1<<2);
    //7 to select control register not UBBRL as they have same address
}
void UART_sendData(u8 data)
{
	//1.wait for transmit buffer to be empty
	while(READ_BIT(UCSRA,5)==0);//UDRE
	//2.put data in UDR reg
	UDR=data;
}
u8 UART_receiveData(void)
{
	//1.wait for receiving buffer to be filled with data
	while(READ_BIT(UCSRA,7)==0);
	//2.receive data from udr
	return UDR;
}
void UART_sendString(u8 *ptr)
{
	while (*ptr !='\0')
	{
		UART_sendData(*ptr);
		ptr++;
		//delay_ms(100);
	}
}