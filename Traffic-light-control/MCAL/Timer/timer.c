/*
 * timer.c
 *
 * Created: 9/14/2022 5:35:24 PM
 *  Author: Ali Mohamed Taima
 */
#include "timer.h"
void TIMER_init(void)
{
    // 1. set timer mode to normal mode
    TCCR0 = 0X00; // Normal mode
    // 2. Set timer initial value to 0
    TCNT0 = 0x00;
}
void TIMER_start(uint16_t preScalar, uint32_t number_of_overflow)
{
    uint32_t overflowCounter = 0;
    switch (preScalar)
    {
    case 1:
        TCCR0 |= (1 << 0); // set pin0
        break;
    case 8:
        TCCR0 |= (1 << 1); // set pin1
        break;
    case 64:
        TCCR0 |= 3; // set pin0 and pin1
        break;
    case 256:
        TCCR0 |= (1 << 2); // set pin2
        break;
    case 1024:
        TCCR0 |= 5; // set pin0 and pin2
        break;
    default:
        // Error handling
        break;
    }
    // Repeated number of overflow times
    while (overflowCounter < number_of_overflow)
    {
        // wait the overflow flat to be set
        while ((TIFR & (1 << 0)) == 0);
        // Clear the overflow flag
        TIFR |= (1 << 0);
        overflowCounter++;
    }
}
void TIMER_stop(void)
{
    // Timer stop
    TCCR0 = 0x00;
}
void delay_512ms(void)
{
	TIMER_start(8, 250);
	TIMER_stop();
}
void delay_5s(void)
{
	TIMER_start(256, 77);
	TIMER_stop();
}
