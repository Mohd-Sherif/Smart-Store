/*
 * USART.h
 *
 * Created: 9/16/2022 7:43:22 PM
 *  Author: lenovo
 */ 

#include "../Dio Driver/Dio.h"
//#include "../TIMERS/Timers.h"

/*
Function Name        : UART_init
Function Returns     : void
Function Arguments   : void
Function Description : initialization UART protocol.
*/
void UART_init(unsigned long long baudRate);
/*
Function Name        : UART_sendData
Function Returns     : void
Function Arguments   : uint8_T data
Function Description : send Data from mc1 to mc2.
*/
void UART_sendData(u8 data);
/*
Function Name        : UART_recieveData
Function Returns     : uint8_T data
Function Arguments   : void
Function Description : receive Data from mc2.
*/
u8 UART_receiveData(void);
/*
Function Name        : UART_sendString
Function Returns     : void
Function Arguments   : uint8_T *ptr
Function Description : send String.
*/
void UART_sendString(u8 *ptr);
#ifndef USART_H_
#define USART_H_





#endif /* USART_H_ */