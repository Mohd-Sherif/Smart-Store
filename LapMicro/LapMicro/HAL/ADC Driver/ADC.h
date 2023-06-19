/*
 * ADC.h
 *
 * Created: 9/5/2022 4:15:13 AM
 *  Author: lenovo
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "../../MCAL/DIO Driver/Dio.h"
/*
	Function Name        : ADC_Init
	Function Returns     : void
	Function Arguments   : void
    Function Description : initiate the ADC 
*/
void ADC_Init(void);
/*
	Function Name        : read_ADC_data
	Function Returns     : uint16_t
	Function Arguments   : void
    Function Description : read data registers on adc
*/
uint16_T read_ADC_data();
#endif /* ADC_H_ */