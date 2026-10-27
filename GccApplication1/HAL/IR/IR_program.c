/*
 * IR_program.c
 *
 * Created: 10/16/2026 5:13:02 PM
 *  Author: reman
 */ 
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/interface.h"

#include "IR_Interface.h"

void IRSensor_voidInit(IRSensor_Configuration *sensor)
{
	if (sensor != 0)
	{
		
		DIO_u8SetPinDirection(sensor->Port, sensor->Pin, 0);
	}
}

u8 IRSensor_u8Read(IRSensor_Configuration *sensor)
{
	u8 Sensor_Value = 1;  

	if (sensor != 0)
	{
		DIO_u8GetPinValue(sensor->Port, sensor->Pin, &Sensor_Value);
	}

	return Sensor_Value;
}