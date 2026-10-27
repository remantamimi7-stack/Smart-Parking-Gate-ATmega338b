/*
 * DC_PROGRAM.c
 *
 * Created: 10/16/2026 5:00:44 PM
 *  Author: reman
 */ 
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/interface.h"
#include "DC_INTERFACE.h"

u8 DCMOTOR_Init(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2)
{
	u8 local_u8Error1 = DIO_u8SetPinDirection(Copy_u8Port, Copy_u8Pin1, 1);
	u8 local_u8Error2 = DIO_u8SetPinDirection(Copy_u8Port, Copy_u8Pin2, 1);
	return local_u8Error1 || local_u8Error2;
}

u8 DCMOTOR_RotateDirection1(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2)
{
	u8 local_u8Error1 = DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin1, 1);
	u8 local_u8Error2 = DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin2, 0);
	return local_u8Error1 || local_u8Error2;
}

u8 DCMOTOR_RotateDirection2(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2)
{
	u8 local_u8Error1 = DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin1, 0);
	u8 local_u8Error2 = DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin2, 1);
	return local_u8Error1 || local_u8Error2;
}

u8 DCMOTOR_Stop(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2)
{
	u8 local_u8Error1 = DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin1, 0);
	u8 local_u8Error2 = DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin2, 0);
	return local_u8Error1 || local_u8Error2;
}

//lab 3
u8 DCMOTOR_Move(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2, u8 Copy_u8Direction)
{
	u8 local_u8Error;

	switch (Copy_u8Direction)
	{
		case DCMOTOR_CW:
		local_u8Error = DCMOTOR_RotateDirection1(Copy_u8Port, Copy_u8Pin1, Copy_u8Pin2);
		break;
		case DCMOTOR_CCW:
		local_u8Error = DCMOTOR_RotateDirection2(Copy_u8Port, Copy_u8Pin1, Copy_u8Pin2);
		break;
		default:
		local_u8Error = 1;  
		break;
	}

	return local_u8Error;
}