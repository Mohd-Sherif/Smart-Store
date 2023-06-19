/*
 * std_macros.h
 *
 * Created: 8/31/2022 5:27:21 AM
 *  Author: lenovo
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_
#define INPUT 0
#define OUTPUT 1
#define HIGH 1
#define LOW 0
#define UPPER 1
#define LOWER 0
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
#define REGISTER_SIZE 8
#define SET_BIT(reg,bit) reg|=(1<<bit)
#define CLR_BIT(reg,bit) reg&=(~(1<<bit))
#define TOG_BIT(reg,bit) reg^=(1<<bit)
#define READ_BIT(reg,bit) ((reg&(1<<bit))>>bit)


#endif /* STD_MACROS_H_ */