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


int main(void)
{
    USART_vinit(9600);
    LCD_vinit();
    while (1) 
    {
    }
}

