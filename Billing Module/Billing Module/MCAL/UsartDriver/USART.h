/*
 * USART.h
 *
 * Created: 24-Aug-22 11:58:57 PM
 *  Author: Mohamed Sherif
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "../StandardMacrosHeader/std_macros.h"

#ifndef USART_H_
#define USART_H_

void USART_vinit(unsigned long baud);
void USART_vsend_data(char data);
char USART_u8receive_data();
void USART_vsend_string(char*ptr);

#endif /* USART_H_ */