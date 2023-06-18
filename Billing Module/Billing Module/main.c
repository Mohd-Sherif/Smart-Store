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

int main(void)
{
    USART_vinit(9600);
    LCD_vinit();
    while (1) 
    {
    }
}

