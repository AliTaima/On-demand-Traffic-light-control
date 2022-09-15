/*
 * DIO.h
 *
 * Created: 9/14/2022 10:45:18 AM
 *  Author: Ali Mohamed Taima
 */

#ifndef DIO_H_
#define DIO_H_

// include register header
#include "../../Utilities/registers.h"

// include interrupt header
#include "../Interrupt_Library/interrupts.h"
/************************************************************************/
/* define helpful macros                                               */
/************************************************************************/
// set pin macro(make PIN_NO = 1)
#define SET_PIN(X, PIN_NO) X |= (1 << PIN_NO)
// clear pin macro(make PIN_NO = 0)
#define CLR_PIN(X, PIN_NO) X &= ~(1 << PIN_NO)
// toggle pin macro(make PIN_NO = 0 then PIN_NO = 1 and so on...)
#define TOGGLE_PIN(X, PIN_NO) X ^= (1 << PIN_NO)
// get status of the pin(read pin) to see it high or low(X--> the value, Y--> the PIN_name)for example(*value, PINA, PIN4)
#define GET_STATE(X, Y, PIN_NO) X = (Y & (1 << PIN_NO)) >> PIN_NO
/************************************************************************/
/*							Typedefs						            */
/************************************************************************/
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
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

// all driver function prototypes

void DIO_init(EN_port_t portNumber, EN_pin_t pinNumber, EN_direction_t direction); // Initialize dio direction

void DIO_write(EN_port_t portNumber, EN_pin_t pinNumber, EN_value_t value); // write data to dio

void DIO_toggle(EN_port_t portNumber, EN_pin_t pinNumber); // toggle dio

void DIO_read(EN_port_t portNumber, EN_pin_t pinNumber, uint8_t *value); // read dio

#endif /* DIO_H_ */