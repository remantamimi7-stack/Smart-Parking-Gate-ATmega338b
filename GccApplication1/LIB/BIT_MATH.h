/*
 * NEW_ITEM.h
 *
 * Created: 10/10/2026 5:02:41 PM
 *  Author: reman
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR, BITNO) ((VAR)|= (1<<(BITNO)))

#define CLR_BIT(VAR, BITNO) ((VAR)&= ~(1<<(BITNO)))

#define TOG_BIT(VAR, BITNO) ((VAR)^= (1<<(BITNO)))

#define GET_BIT(VAR, BITNO) (((VAR) >> (BITNO)) &0X01)




#endif /* BIT_MATH_H_ */