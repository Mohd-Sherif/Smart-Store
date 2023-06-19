/*
 * LapMicro.c
 *
 * Created: 3/20/2023 8:55:54 AM
 */ 

//#include "std_macros.h"
#include "registers.h"
//#include "Database.h"
#include <string.h>

#include "../LapMicro/HAL/Button Driver/Button.h"
//#include "../LapMicro/HAL/Seven Segment Driver/SevenSegment.h"
#include "../LapMicro/HAL/LCD Driver/LCD.h"
//#include "../LapMicro/HAL/LED Driver/Led.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h> 
#include "../LapMicro/MCAL/USART Driver/USART.h"
#include "MCAL/SpiDriver/SPI.h"
#include "../../Config.h"
volatile char x;
volatile char barcode[10][10];
volatile static int i=0;
volatile char z=0;

volatile int testArray[2] = {200, 201};
 
int main(void)
{
	sei();
	LCD_init('c');
	UART_init(9600);
	
	GICR |= (1 << INT0);
	MCUCR |= (1 << ISC01);
	
	ButtonInit('D', 2);
	connectPullup('D', 2);
	
	SPI_Master_init();
	
	while (1)
	{
		
		//x=UART_receiveData();
		//LCD_send_char(x,'c');
	}
}
ISR (USART_UDRE_vect)
{
	
}
ISR (USART_RXC_vect)
{
	x = UDR;
		barcode[i][z]=x;
	z++;
	if (z==BAR_CODE_LENGTH)
	i++;
	if (i==ITEMS_COUNT) i=0;
}
ISR(INT0_vect){
	SPI_Master_Transmit_char(START_MESSAGE);
	_delay_ms(300);
	/*
	SPI_Master_Transmit_char(barcode[0][0]);
	_delay_ms(500);
	SPI_Master_Transmit_char(END_MESSAGE);
	*/
	/*
	for (int i = 0;i<ITEMS_COUNT;i++)
	{
		for (int j = 0;j<BAR_CODE_LENGTH;j++)
		{
			SPI_Master_Transmit_char(barcode[i][j]);
		}
	}
	*/
	//SPI_Master_Transmit_String("CDG55564d");
	//testArray[0] = (int)(barcode[0][0]-48)*100 + (int)(barcode[1][1]-48)*10 + (int)(barcode[2][2]-48);
	//testArray[1] = (int)(barcode[3][3]-48)*100 + (int)(barcode[4][4]-48)*10 + (int)(barcode[5][5]-48);
	SPI_Master_Transmit_char(testArray[0]);
	SPI_Master_Transmit_char(testArray[1]);
	SPI_Master_Transmit_char(END_MESSAGE);
}


