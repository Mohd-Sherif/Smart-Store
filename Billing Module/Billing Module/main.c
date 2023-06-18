/*
 * Billing Module.c
 *
 * Created: 18-Jun-23 5:44:08 PM
 * Author : Mohamed Sherif
 */ 

#include "MCAL/StandardMacrosHeader/std_macros.h"
#include "MCAL/DioDriver/DIO.h"
#include "MCAL/UsartDriver/USART.h"
#include "HAL/LcdDriver/LCD.h"
#include "../../ProductsDB/Database.h"

#define START_MESSAGE 0xcf
#define END_MESSAGE 0x0f
#define ITEMS_COUNT 10
#define BAR_CODE_LENGTH 8

void receiving();
void calculatingCost();
void printCost();

volatile unsigned char receivedProducts[ITEMS_COUNT][BAR_CODE_LENGTH], received = 0, found = 0;
volatile unsigned int totalCost;

int main(void)
{
    USART_vinit(9600);
    LCD_vinit();
	LCD_vsend_string(" Welcome To Our ");
	LCD_vmove_cursor(2,1);
	LCD_vsend_string("   Smart Store  ");
    while (1) 
    {
		if(USART_u8receive_data() == START_MESSAGE){
			totalCost = 0;
			LCD_vCLR_screen();
			LCD_vsend_string("Reading Products");
			LCD_vmove_cursor(2,1);
			LCD_vsend_string("Please Wait...");
			receiving();
			LCD_vCLR_screen();
			LCD_vsend_string("Calculating cost");
			LCD_vmove_cursor(2,1);
			LCD_vsend_string("Please Wait...");
			_delay_ms(500);
			calculatingCost();
			printCost();
			LCD_vCLR_screen();
			LCD_vsend_string("Thanks for");
			LCD_vmove_cursor(2,1);
			LCD_vsend_string("your visit");
			_delay_ms(500);
			LCD_vCLR_screen();
			LCD_vsend_string(" Welcome To Our ");
			LCD_vmove_cursor(2,1);
			LCD_vsend_string("   Smart Store  ");
		}
    }
}

void receiving(){
	for(int i=0;i<ITEMS_COUNT;i++){
		for(int j=0;j<BAR_CODE_LENGTH;j++){
			received = USART_u8receive_data();
			if(received == END_MESSAGE){
				return;
			}
			receivedProducts[i][j] = received;
		}
	}
}

void calculatingCost(){
	for(int i=0;i<ITEMS_COUNT;i++){
		found = 0;
		for(int j=0;j<BAR_CODE_LENGTH;j++){
			if(receivedProducts[i][j] != products[i].barcode[j]){
				break;
			}
			found++;
		}
		if(found == BAR_CODE_LENGTH){
			totalCost += products[i].price;
		}
	}
}

void printCost(){
	LCD_vCLR_screen();
	LCD_vsend_string("Total Cost=");
	totalCost = totalCost % 1000;
	if(totalCost<10){
		LCD_vsend_char((char)(totalCost));
	}
	else if(totalCost<100){
		LCD_vsend_char((char)(totalCost/10));
		LCD_vsend_char((char)(totalCost%10));
	}
	else{
		LCD_vsend_char((char)(totalCost/100));
		LCD_vsend_char((char)(totalCost/10));
		LCD_vsend_char((char)(totalCost%10));
	}
	_delay_ms(1000);
}
