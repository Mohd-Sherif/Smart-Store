/*
 * USART.c
 *
 * Created: 24-Aug-22 11:58:41 PM
 *  Author: Mohamed Sherif
 */ 

#include "USART.h"

void USART_vinit(unsigned long baud){
	//Choose baud rate
	unsigned short UBRR=(F_CPU/16*baud)-1;
	UBRRH=(unsigned char)(UBRR>>8);
	UBRRL=(unsigned char)UBRR;
	//Enable USART Sender and Receiver
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	//Choose data length, parity and stop bits from UCSRC
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1); //Default: 8bit data, 1 stop bit and no parity bits
	_delay_ms(300);
}

void USART_vsend_data(char data){
	while(READ_BIT(UCSRA,UDRE)==0); //Wait UDR transmit buffer be empty
	UDR=data; //Put data to UDR transmit buffer to transmit
}

char USART_u8receive_data(){
	while(READ_BIT(UCSRA,RXC)==0); //Wait for UDR receive buffer to be filled with data
	return UDR; //Receive data from UDR receive buffer
}

void USART_vsend_string(char*ptr){
	while(*ptr!=0){
		USART_vsend_data(*ptr);
		ptr++;
		_delay_ms(100);
	}
}
