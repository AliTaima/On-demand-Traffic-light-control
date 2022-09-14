/*
 * DIO.c
 *
 * Created: 9/14/2022 10:45:04 AM
 *  Author: Ali Mohamed Taima
 */ 
#include "dio.h"
void DIO_init(EN_port_t portNumber, EN_pin_t pinNumber, EN_direction_t direction)
{
	switch (portNumber)
	{
		case PORT_A:
			if (direction == IN)
			{
				CLR_PIN(DDRA, pinNumber); // input
			}
			else if (direction == OUT)
			{
				SET_PIN(DDRA, pinNumber); // output
			}
			else
			{
				// error handling
			}
			break;
		case PORT_B:
			if (direction == IN)
			{
				CLR_PIN(DDRB, pinNumber); // input
			}
			else if (direction == OUT)
			{
				SET_PIN(DDRB, pinNumber); // output
			}
			else
			{
				// error handling
			}
			break;
		case PORT_C:
			if (direction == IN)
			{
				CLR_PIN(DDRC, pinNumber); // input
			}
			else if (direction == OUT)
			{
				SET_PIN(DDRC, pinNumber); // output
			}
			else
			{
				// error handling
			}
			break;
		case PORT_D:
			if (direction == IN)
			{
				CLR_PIN(DDRD, pinNumber); // input
			}
			else if (direction == OUT)
			{
				SET_PIN(DDRD, pinNumber); // output
			}
			else
			{
				// error handling
			}
			break;
		default:
			break;
		// error handling
	}
}
void DIO_write(EN_port_t portNumber, EN_pin_t pinNumber, EN_value_t value)
{
	switch (portNumber)
	{
		case PORT_A:
			if (value == LOW)
			{
				CLR_PIN(PORTA, pinNumber); // write 0
			}
			else if (value == HIGH)
			{
				SET_PIN(PORTA, pinNumber); // write 1
			}
			else
			{
				// error handling
			}
			break;
		case PORT_B:
			if (value == LOW)
			{
				CLR_PIN(PORTB, pinNumber); // write 0
			}
			else if (value == HIGH)
			{
				SET_PIN(PORTB, pinNumber); // write 1
			}
			else
			{
				// error handling
			}
			break;
		case PORT_C:
			if (value == LOW)
			{
				CLR_PIN(PORTC, pinNumber); // write 0
			}
			else if (value == HIGH)
			{
				SET_PIN(PORTC, pinNumber); // write 1
			}
			else
			{
				// error handling
			}
			break;
		case PORT_D:
			if (value == LOW)
			{
				CLR_PIN(PORTD, pinNumber); // write 0
			}
			else if (value == HIGH)
			{
				SET_PIN(PORTD, pinNumber); // write 1
			}
			else
			{
				// error handling
			}
			break;
		default:
			break;
		// error handling
	}
}

void DIO_toggle(EN_port_t portNumber, EN_pin_t pinNumber)
{
	switch (portNumber)
	{
		case PORT_A:
			TOGGLE_PIN(PORTA, pinNumber);
			break;
		case PORT_B:
			TOGGLE_PIN(PORTB, pinNumber);
			break;
		case PORT_C:
			TOGGLE_PIN(PORTC, pinNumber);
			break;
		case PORT_D:
			TOGGLE_PIN(PORTD, pinNumber);
			break;
		default:
			// Error handling
			break;
	}
}

void DIO_read(EN_port_t portNumber, EN_pin_t pinNumber, uint8_t *value)
{
	switch (portNumber)
	{
		case PORT_A:
			GET_STATE(*value, PINA, pinNumber); // get state --> read bit
			break;
		case PORT_B:
			GET_STATE(*value, PINB, pinNumber); // get state --> read bit
			break;
		case PORT_C:
			GET_STATE(*value, PINC, pinNumber); // get state --> read bit
			break;
		case PORT_D:
			GET_STATE(*value, PIND, pinNumber); // get state --> read bit
			break;
		default:
			// Error handling
			break;
	}
}