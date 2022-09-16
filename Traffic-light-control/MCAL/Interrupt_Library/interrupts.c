/*
 * interrupts.c
 *
 * Created: 9/16/2022 10:42:19 AM
 *  Author: Ali Mohamed Taima
 */ 
#include "interrupts.h"
void interrupt_rising_init(void)
{
	/*
		Description: this function initialize external interrupt 0 and its sense to rising edge
		inputs: none
		outputs: none
		return: none
	*/
	// 1. Enable global interrupt(setting bit 7 in status register to 1
	sei();
	// 2. Choosing the external interrupt snese (sense on the rising edge)
	MCUCR |= (1 << 0) | (1 << 1);
	// 3.Enable External interrupt 0(INT0)
	GICR |= (1 << 6);
	
}
