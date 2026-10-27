/*
 * PROGRAM.c
 *
 * Created: 10/15/2026 4:55:48 PM
 *  Author: reman
 */ 
#include "../../LIB/STD_TYPE.h"
#include "INTERFACE.h"
static const u8 arr[10]={//common cathod
  0b00111111,
  0b00000110,
  0b01011011,
  0b01001111,
  0b01100110,
  0b01101101,
  0b01111101,
  0b00000111,
  0b01111111,
  0b01101111
};
u8 SEVSEG_Init(u8 copy_u8DataPort , u8 copy_u8PowerPort,u8 copy_u8PowerPin)
{
	u8 local_u8Error1 =DIO_u8SetPortDirection(copy_u8DataPort, 0xFF);
	u8 local_u8Error2 =DIO_u8SetPinDirection(copy_u8PowerPort , copy_u8PowerPin,1);
	return local_u8Error1 || local_u8Error2 ;
	
}
u8 SEVSEG_DicplayNumber(u8 copy_u8DataPort, u8 copy_u8PowerPort, u8 copy_u8PowerPin,u8 copy_u8Number, u8 copy_u8Type)
{
	// common cathode = 0 ,comman anode =1 
	
	if (copy_u8Number >9 || (copy_u8Type != SEVSEG_u8COMMON_ANODE && copy_u8Type != SEVSEG_u8COMMON_CATHOD))
	   return 1;
    u8 local_u8Error1 =DIO_u8SetPinValue(copy_u8PowerPort, copy_u8PowerPin,(copy_u8Type == SEVSEG_u8COMMON_ANODE)? 1:0 );
    u8 local_u8Error2 =DIO_u8SetPortValue(copy_u8DataPort ,(copy_u8Type == SEVSEG_u8COMMON_ANODE)? ~arr[copy_u8Number]:arr[copy_u8Number] );
	return local_u8Error1 || local_u8Error2;
}