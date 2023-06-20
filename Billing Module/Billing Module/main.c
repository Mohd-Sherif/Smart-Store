/*
 * Billing Module.c
 *
 * Created: 18-Jun-23 5:44:08 PM
 * Author : Mohamed Sherif
 */ 

#include "MCAL/StandardMacrosHeader/std_macros.h"
#include "MCAL/DioDriver/DIO.h"
#include "MCAL/UsartDriver/USART.h"
#include "MCAL/SpiDriver/SPI.h"
#include "HAL/LcdDriver/LCD.h"
#include "../../ProductsDB/Database.h"
#include "../../Config.h"

int receiving();
void calculatingCost(int items);
void printCost();

volatile unsigned char receivedProducts[ITEMS_COUNT][BAR_CODE_LENGTH];
volatile unsigned int totalCost;
volatile unsigned int testArray[ITEMS_COUNT] = {200, 201};

int main(void)
{
	int items;
    LCD_vinit();
	//DIO_vsetport_dir('d',0xff);
	LCD_vsend_string(" Welcome To Our ");
	LCD_vmove_cursor(2,1);
	LCD_vsend_string("   Smart Store  ");
	//USART_vinit(9600);
	SPI_Slave_init();
    while (1) 
    {
		//if(USART_u8receive_data() == START_MESSAGE){
		if(SPI_Slave_Receive_char(DUMMY_DATA) == START_MESSAGE){
			totalCost = 0;
			LCD_vCLR_screen();
			LCD_vsend_string("Reading Products");
			LCD_vmove_cursor(2,1);
			LCD_vsend_string("Please Wait...");
			items = receiving();
			LCD_vCLR_screen();
			LCD_vsend_string("Calculating cost");
			LCD_vmove_cursor(2,1);
			LCD_vsend_string("Please Wait...");
			_delay_ms(500);
			calculatingCost(items);
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

int receiving(){
	unsigned char received;
	for(int i=0;i<ITEMS_COUNT;i++){
	//	for(int j=0;j<BAR_CODE_LENGTH;j++){
			//received = USART_u8receive_data();
			received = SPI_Slave_Receive_char(DUMMY_DATA);
			//_delay_ms(300);
			if(received == END_MESSAGE){
				return i+1;
			}
			receivedProducts[i][0] = received;
		//}
	}
	return ITEMS_COUNT;
}

void calculatingCost(int items){
//	int found;
	int idx;
	//int *ptr;
	for(int i=0;i<items;i++){
		//found = 0;
		//ptr = products[i].barcode;
		for(int j=0;j<4;j++){
			//if(receivedProducts[i][j] != ptr[j]){
			if(receivedProducts[i][0] == products[j].barcode){
				idx=j;
				break;
			}
			//found++;
		}
		//if(found == BAR_CODE_LENGTH){
			totalCost += products[idx].price - (products[idx].price * products[idx].offer);
	//	}
	}
	//DIO_vwriteport('d',totalCost);
}

void printCost(){
	LCD_vCLR_screen();
	LCD_vsend_string("Total Cost=");
	//totalCost = totalCost % 1000;
	if(totalCost<10){
		LCD_vsend_char((char)(totalCost)+48);
	}
	else if(totalCost<100){
		LCD_vsend_char((char)((totalCost/10)%10)+48);
		LCD_vsend_char((char)(totalCost%10)+48);
	}
	else{
		LCD_vsend_char((char)((totalCost/100)%10)+48);
		LCD_vsend_char((char)((totalCost/10)%10)+48);
		LCD_vsend_char((char)(totalCost%10)+48);
	}
	_delay_ms(1500);
}
