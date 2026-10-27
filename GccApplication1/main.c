/*
 * GccApplication1.c
 *
 * Created: 10/18/2026 4:41:41 PM
 * Author : reman
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "mcal/DIO/interface.h"
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPE.h"
#include "HAL/IR/IR_interface.h"
#include "HAL/DC/DC_INTERFACE.h"
#include "HAL/SSD/INTERFACE.h"

#define SEVSEG_DATA_PORT    DIO_u8PORTA
#define SEVSEG_PWR_PORT     DIO_u8PORTB
#define SEVSEG_PWR_PIN      DIO_u8PIN0

#define RED_LED_PORT        DIO_u8PORTB
#define RED_LED_PIN         DIO_u8PIN1

#define MOTOR_PORT          DIO_u8PORTC
#define MOTOR_PIN1          DIO_u8PIN0
#define MOTOR_PIN2          DIO_u8PIN1

#define IR_ENTRANCE_PORT    DIO_u8PORTD
#define IR_ENTRANCE_PIN     DIO_u8PIN2

#define IR_EXIT_PORT        DIO_u8PORTD
#define IR_EXIT_PIN         DIO_u8PIN3

#define MAX_CAPACITY        4

int main(void)
{
	
	SEVSEG_Init(SEVSEG_DATA_PORT, SEVSEG_PWR_PORT, SEVSEG_PWR_PIN);

	
	DIO_u8SetPinDirection(RED_LED_PORT, RED_LED_PIN, DIO_u8OUTPUT);
	DIO_u8SetPinValue(RED_LED_PORT, RED_LED_PIN, DIO_u8PIN_LOW);

	
	DCMOTOR_Init(MOTOR_PORT, MOTOR_PIN1, MOTOR_PIN2);
	DCMOTOR_Stop(MOTOR_PORT, MOTOR_PIN1, MOTOR_PIN2);

	
	IRSensor_Configuration ir_entrance = {IR_ENTRANCE_PORT, IR_ENTRANCE_PIN};
	IRSensor_Configuration ir_exit     = {IR_EXIT_PORT, IR_EXIT_PIN};
	IRSensor_voidInit(&ir_entrance);
	IRSensor_voidInit(&ir_exit);

	u8 cars_count = 0;

	
	SEVSEG_DicplayNumber(SEVSEG_DATA_PORT, SEVSEG_PWR_PORT, SEVSEG_PWR_PIN, cars_count, SEVSEG_u8COMMON_CATHOD);
    
    while (1) 
    {
	    if (cars_count >= MAX_CAPACITY)
	    {
		    DIO_u8SetPinValue(RED_LED_PORT, RED_LED_PIN, DIO_u8PIN_HIGH);
	    }
	    else
	    {
		    DIO_u8SetPinValue(RED_LED_PORT, RED_LED_PIN, DIO_u8PIN_LOW);
	    }

	    
	    if (IRSensor_u8Read(&ir_entrance) == 0)
	    {
		   
		    if (cars_count < MAX_CAPACITY)
		    {
			   
			    DCMOTOR_Move(MOTOR_PORT, MOTOR_PIN1, MOTOR_PIN2, DCMOTOR_CCW);
			    _delay_ms(150);
			    DCMOTOR_Stop(MOTOR_PORT, MOTOR_PIN1, MOTOR_PIN2);

			    cars_count++;
			    SEVSEG_DicplayNumber(SEVSEG_DATA_PORT, SEVSEG_PWR_PORT, SEVSEG_PWR_PIN, cars_count, SEVSEG_u8COMMON_CATHOD);

                _delay_ms(2000);
				
				DCMOTOR_Move(MOTOR_PORT, MOTOR_PIN1, MOTOR_PIN2, DCMOTOR_CW);
				_delay_ms(150);
				DCMOTOR_Stop(MOTOR_PORT, MOTOR_PIN1, MOTOR_PIN2);
			   
			    while (IRSensor_u8Read(&ir_entrance) == 0);
				_delay_ms(2000);
		    }
	    }

	   
	    if (IRSensor_u8Read(&ir_exit) == 0)
	    {
		    
		    if (cars_count > 0)
		    {
			  
			    DCMOTOR_Move(MOTOR_PORT, MOTOR_PIN1, MOTOR_PIN2, DCMOTOR_CCW);
			    _delay_ms(150);
			    DCMOTOR_Stop(MOTOR_PORT, MOTOR_PIN1, MOTOR_PIN2);

			    cars_count--;
			    SEVSEG_DicplayNumber(SEVSEG_DATA_PORT, SEVSEG_PWR_PORT, SEVSEG_PWR_PIN, cars_count, SEVSEG_u8COMMON_CATHOD);

                _delay_ms(2000);
				
				 DCMOTOR_Move(MOTOR_PORT, MOTOR_PIN1, MOTOR_PIN2, DCMOTOR_CW);
				 _delay_ms(150);
				 DCMOTOR_Stop(MOTOR_PORT, MOTOR_PIN1, MOTOR_PIN2);
				
			   
			    while (IRSensor_u8Read(&ir_exit) == 0);
				_delay_ms(2000);
		    }
	    }
	}
	return 0;
	
}

