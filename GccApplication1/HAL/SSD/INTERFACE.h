/*
 * INTERFACE.h
 *
 * Created: 10/15/2026 4:55:24 PM
 *  Author: reman
 */ 

#pragma once


#define SEVSEG_u8COMMON_CATHOD 0
#define SEVSEG_u8COMMON_ANODE 1

u8 SEVSEG_Init(u8 copy_u8DataPort , u8 copy_u8PowerPort,u8 copy_u8PowerPin);
u8 SEVSEG_DicplayNumber(u8 copy_u8DataPort, u8 copy_u8PowerPort,u8 copy_u8PowerPin, u8 copy_u8Number, u8 copy_u8Type);


