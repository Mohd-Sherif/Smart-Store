/*
 * Timers.h
 *
 * Created: 9/2/2022 9:24:17 PM
 *  Author: lenovo
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_
#include "../Dio Driver/Dio.h"
/*
	Function Name        : delay_ms
	Function Returns     : void
	Function Arguments   : uint32_t T_delay
     Function Description : make delay in m sec in Normal mode   
*/
void delay_ms(unsigned int T_delay);
/*
	Function Name        : generate_signal_on_oc0
	Function Returns     : void
	Function Arguments   : unsigned int freq
     Function Description : generate signal on CTC mode on oc0 pin depending on freq of T ON   
*/
void generate_signal_on_oc0(unsigned int freq);
/*
	Function Name        : wave_PWM_mode
	Function Returns     : void
	Function Arguments   : float Dutycycle
    Function Description : generate signal on fastPWM mode on oc0 pin depending on Dutycycle   
*/
void wave_PWM_mode(float Dutycycle);



#endif /* TIMERS_H_ */