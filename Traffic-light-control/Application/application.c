/*
 * application.c
 *
 * Created: 9/14/2022 10:48:01 AM
 *  Author: Ali Mohamed Taima
 */
#include "application.h"
void App_init(void)
{
	// 1.  Set direction of LEDs to output
	// 1.1 cars' LEDs
	LED_init(LED_C_RED_PORT, LED_C_RED_PIN);
	LED_init(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
	LED_init(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
	// 1.2 Pedestrians' LEDs
	LED_init(LED_P_RED_PORT, LED_P_RED_PIN);
	LED_init(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
	LED_init(LED_P_GREEN_PORT, LED_P_GREEN_PIN);
	// 2. Set direction of BUTTON  to input
	Button_init(EXT_INT_BUTTON_PORT, EXT_INT_BUTTON_PIN);
	// 3. initialize external interrupt 1
	interrupt_rising_init();
	TIMER_init();
}

void App_start(void)
{
	while (1)
	{

		LED_on(LED_C_RED_PORT, LED_C_RED_PIN);
		LED_off(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
		LED_off(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
		delay_5s();
		LED_off(LED_C_RED_PORT, LED_C_RED_PIN);
		LED_on(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
		LED_off(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
		delay_5s();
		// delay_5s_toggle(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
		LED_off(LED_C_RED_PORT, LED_C_RED_PIN);
		LED_off(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
		LED_on(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
		delay_5s();
	}
}
ISR(EXT_INT_0)
{
	pedestrain_mode();
	TIMER_stop();
}
void pedestrain_mode(void)
{
	EN_button_color_t color;
	uint8_t value;
	DIO_read(LED_C_RED_PORT, LED_C_RED_PIN, &value);
	if (value)
	{
		color = RED;
	}
	else
	{
		DIO_read(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN, &value);
		if (value)
		{

			color = YELLOW;
		}
		else
		{
			color = GREEN;
		}
	}
	// turn off all cars' LEDs
	LED_off(LED_C_RED_PORT, LED_C_RED_PIN);
	LED_off(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
	LED_off(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
	// Applying pedestrian mode according to cars' LEDs
	if (color == RED)
	{
		LED_on(LED_P_GREEN_PORT, LED_P_GREEN_PIN);
		LED_on(LED_C_RED_PORT, LED_C_RED_PIN);
		delay_5s();
	}
	else if (color == GREEN || color == YELLOW)
	{
		LED_on(LED_P_RED_PORT, LED_P_RED_PIN);
		delay_5s();
		LED_off(LED_P_RED_PORT, LED_P_RED_PIN);
		LED_on(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
		LED_on(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
		delay_5s();
		LED_off(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
		LED_off(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
		LED_on(LED_C_RED_PORT, LED_C_RED_PIN);
		LED_on(LED_P_GREEN_PORT, LED_P_GREEN_PIN);
		delay_5s();
	}
	
}
