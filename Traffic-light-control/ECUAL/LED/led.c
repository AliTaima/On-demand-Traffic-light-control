/*
 * LED.c
 *
 * Created: 9/14/2022 10:46:35 AM
 *  Author: Ali Mohamed Taima
 */ 
#include "led.h"
void LED_init(EN_port_t ledPort, EN_pin_t ledPin)
{
	//let LED as output
	DIO_init(ledPort, ledPin, OUT);
}
void LED_on(EN_port_t ledPort, EN_pin_t ledPin)
{
	// write high on the LED
	DIO_write(ledPort, ledPin, HIGH);
}
void LED_off(EN_port_t ledPort, EN_pin_t ledPin)
{
	// write low on the LED
	DIO_write(ledPort, ledPin, LOW);
}
void LED_toggle(EN_port_t ledPort, EN_pin_t ledPin)
{
	// toggle the LED
	DIO_toggle(ledPort, ledPin);
}