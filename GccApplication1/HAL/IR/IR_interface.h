/*
 * IR_interface.h
 *
 * Created: 10/16/2026 5:12:41 PM
 *  Author: reman
 */ 


#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_

#include "../../LIB/STD_TYPE.h"

typedef struct
{
	u8 Port;
	u8 Pin;
} IRSensor_Configuration;

void IRSensor_voidInit(IRSensor_Configuration *sensor);
u8   IRSensor_u8Read(IRSensor_Configuration *sensor);




#endif /* IR_INTERFACE_H_ */