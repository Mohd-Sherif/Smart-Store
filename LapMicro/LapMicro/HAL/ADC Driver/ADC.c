/*
 * ADC.c
 *
 * Created: 9/5/2022 4:14:50 AM
 *  Author: lenovo
 */ 
#include "ADC.h"
/*
	Function Name        : ADC_Init
	Function Returns     : void
	Function Arguments   : void
    Function Description : initiate the ADC 
*/
void ADC_Init(void)
{
	SET_BIT(ADMUX,6);//1.select source of vref (external source 5 v)
	SET_BIT(ADCSRA,7);//2.enable ADC
	SET_BIT(ADCSRA,2);//3.select prescalar 16 1MHZ/16=62500
}
/*
	Function Name        : read_ADC_data
	Function Returns     : uint16_t
	Function Arguments   : void
    Function Description : read data registers on adc
*/
uint16_T read_ADC_data()
{
	uint16_T data=0;
	//ADLAR=0 BY DEFAULT
	//1.START CONV 
	SET_BIT(ADCSRA,6);
	while(READ_BIT(ADCSRA,4)==0);//2.stay in your position till ADIF become 1
	SET_BIT(ADCSRA,4);//3.clear ADIF
	data=ADCL;
	data|=(ADCH<<8);
	return data;

}