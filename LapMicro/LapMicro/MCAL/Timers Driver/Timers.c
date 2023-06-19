/*
 * Timers.c
 *
 * Created: 9/2/2022 9:23:50 PM
 *  Author: lenovo
 */ 

#include "Timers.h"
//prescaling =256
//F_CPU=1MHZ
void delay_ms(uint32_T T_delay)
{
	uint32_T counter_overFlows=0;
	//1.choose the Normal Mode
	TCCR0=0x00;
	uint8_T initialVal=0;
	uint32_T numberOfoverflows=0;
    float T_maxdelay=0;
	float T_tick=0.256;
	T_maxdelay=256*T_tick;
	if (T_delay>T_maxdelay)
	{
		numberOfoverflows=(T_delay/T_maxdelay);
		initialVal=256-((T_delay/T_tick)/numberOfoverflows);
		
		TCNT0=initialVal;//2.set initial value for timer
		//3.start timing by select prescaling from TCCR0 reg
		TCCR0|=(1<<2);
		while(counter_overFlows<=numberOfoverflows)
		{
			while(READ_BIT(TIFR,0)==0);
			//clear overflow flag
			TIFR|=(1<<0);
			counter_overFlows++;
		}
		counter_overFlows=0;
		//stop timer
		TCCR0=0x00;
	}
	else if(T_delay<T_maxdelay)
	{
		initialVal=(T_maxdelay-T_delay)/T_tick;
		TCNT0=initialVal;//2.set initial value for timer
		//3.start timing by select prescaling from TCCR0 reg
		TCCR0|=(1<<2);
		while(READ_BIT(TIFR,0)==0);
		//clear overflow flag
		TIFR|=(1<<0);
		//stop timer
		TCCR0=0x00;
	}
	else
	{
		TCNT0=0x00;
		//3.start timing by select prescaling from TCCR0 reg
		TCCR0|=(1<<2);
		while(READ_BIT(TIFR,0)==0);
		//clear overflow flag
		TIFR|=(1<<0);
		//stop timer
		TCCR0=0x00;
	}
	
}
void generate_signal_on_oc0(unsigned int freq)
{
	setPinDirection('b',3,OUTPUT);//1. set direction of pin is out put
	TCCR0|=(1<<3); //2.choosing mode of timing  (CTC mode)
	TCCR0|=(1<<4); //3.toggle pin every compare match COM00
	OCR0=(3906.25/freq)-1;
	//4.start timing by select prescaling 256
	TCCR0|=(1<<2);
	while(READ_BIT(TIFR,1)==0);
	//clear overflow flag
	TIFR|=(1<<0);
}
void wave_PWM_mode(float Dutycycle)
{
	if (Dutycycle<1)
	{
		volatile double PRESCALER=256.0000;
		volatile double F_CPU=1000.0000;
		
	volatile double T_overFlow_in_ms=0,T_ON_in_ms=0;
	T_overFlow_in_ms=256 *(PRESCALER/F_CPU);//65.536msec
	T_ON_in_ms=Dutycycle*T_overFlow_in_ms;
	
	//1.set pin output
	setPinDirection('b',3,OUTPUT);
	//2.select fast pwm mode 
	TCCR0|=(1<<3);
	TCCR0|=(1<<6);
	//3.set COM01:0=2 in pwm mode clear oco on compare match set on bottom
	// 3.set COM01:0=3 in pwm mode set oco on compare match clear at bottom
	TCCR0|=(1<<5);//2
	//4.put value on ocr
	 OCR0=(unsigned int)((T_ON_in_ms)/(PRESCALER/F_CPU));
	 //4.start timing by select prescaling 256
	 TCCR0|=(1<<2);
	 while(READ_BIT(TIFR,1)==0);
	 //clear overflow flag
	 TIFR|=(1<<1);
	}

}
