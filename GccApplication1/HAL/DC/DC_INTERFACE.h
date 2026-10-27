/*
 * DC_INTERFACE.h
 *
 * Created: 10/16/2026 5:00:24 PM
 *  Author: reman
 */ 


#pragma once
#include "../../LIB/STD_TYPE.h"

#define DCMOTOR_CW   0
#define DCMOTOR_CCW  1

u8 DCMOTOR_Init(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2);
u8 DCMOTOR_RotateDirection1(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2);
u8 DCMOTOR_RotateDirection2(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2);
u8 DCMOTOR_Stop(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2);
u8 DCMOTOR_Move(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2, u8 Copy_u8Direction);