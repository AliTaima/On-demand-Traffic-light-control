/*
 * types.h
 *
 * Created: 9/14/2022 10:48:49 AM
 *  Author: Ali Mohamed Taima
 */ 


#ifndef TYPES_H_
#define TYPES_H_
// Direction define
typedef enum EN_direction_t
{
	IN,
	OUT
} EN_direction_t;
// Value define
typedef enum EN_value_t
{
	LOW,
	HIGH
} EN_value_t;
// PINs define
typedef enum EN_pin_t
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
} EN_pin_t;
// PORT define
typedef enum EN_port_t
{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
} EN_port_t;

typedef unsigned char uint8_t;




#endif /* TYPES_H_ */