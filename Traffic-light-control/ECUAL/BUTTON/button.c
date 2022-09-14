/*
 * button.c
 *
 * Created: 9/14/2022 10:46:55 AM
 *  Author: Ali Mohamed Taima
 */ 
#include "button.h"

//initialize
void Button_init(EN_port_t buttonPort, EN_pin_t buttonPin) // Button is an input device
{
	DIO_init(buttonPort, buttonPin, IN);
}

// get button status
void Button_get_state(EN_port_t buttonPort, EN_pin_t buttonPin, uint8_t *value)
{
	DIO_read(buttonPort, buttonPin, value);
}