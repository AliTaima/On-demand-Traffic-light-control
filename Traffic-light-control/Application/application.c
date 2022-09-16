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
EN_mode_t mode = NORMAL;
EN_button_color_t color;

void App_start(void)
{
	while (1)
	{
		if(mode == NORMAL)
		{
			// turn on cars' Red LED for 5 s and pedestrian's Green LED will be on
			LED_on(LED_C_RED_PORT, LED_C_RED_PIN);
			LED_on(LED_P_GREEN_PORT, LED_P_GREEN_PIN);
			LED_off(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
			LED_off(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
			delay_5s();
			// Turn on cars' Yellow led for 5 s and pedestrian's Yellow LED will be on
			LED_off(LED_C_RED_PORT, LED_C_RED_PIN);
			LED_off(LED_P_GREEN_PORT, LED_P_GREEN_PIN);
			LED_on(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
			LED_on(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
			LED_off(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
			delay_5s();
			// Turn on cars' Green led for 5 s and pedestrian's Red LED will be on
			LED_off(LED_C_RED_PORT, LED_C_RED_PIN);
			LED_off(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
			LED_off(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
			LED_on(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
			LED_on(LED_P_RED_PORT, LED_P_RED_PIN);
			delay_5s();
			LED_off(LED_P_RED_PORT, LED_P_RED_PIN);
			
		}
		else if (mode == PEDESTRIAN)
		{
			
			// turn off all cars' LEDs
			LED_off(LED_C_RED_PORT, LED_C_RED_PIN);
			LED_off(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
			LED_off(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
			// turn off all pedestrian's LEDs
			LED_off(LED_P_RED_PORT, LED_P_RED_PIN);
			LED_off(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
			LED_off(LED_P_GREEN_PORT, LED_P_GREEN_PIN);
			//Applying pedestrian mode according to cars' LEDs
			if (color == RED)
			{
				LED_on(LED_C_RED_PORT, LED_C_RED_PIN);
				LED_on(LED_P_GREEN_PORT, LED_P_GREEN_PIN);
				delay_5s();
				
			}
			else if (color == GREEN)
			{
				LED_on(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
				LED_on(LED_P_RED_PORT, LED_P_RED_PIN);
				delay_5s();
				LED_off(LED_P_RED_PORT, LED_P_RED_PIN);
				LED_on(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
				LED_on(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
				delay_5s();
				LED_off(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
				LED_off(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
				LED_off(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
				LED_on(LED_C_RED_PORT, LED_C_RED_PIN);
				LED_on(LED_P_GREEN_PORT, LED_P_GREEN_PIN);
				delay_5s();
				
				
			}
			else if (color == YELLOW)
			{
				LED_on(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
				LED_on(LED_P_RED_PORT, LED_P_RED_PIN);
				delay_5s();
				LED_off(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
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
			// cars' Red LED will be off
			LED_off(LED_C_RED_PORT, LED_C_RED_PIN);
			// both Yellow LEDs will be on
			LED_on(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
			LED_on(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);	
			delay_5s();
			// The pedestrian's GREEN LED will be off 	
			LED_off(LED_P_GREEN_PORT, LED_P_GREEN_PIN);	
			// both Yellow LEDs will be off
			LED_off(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
			LED_off(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
			// both the pedestrian Red LED and the cars' Green LED will be on
			LED_on(LED_P_RED_PORT, LED_P_RED_PIN);
			LED_on(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
			delay_5s();	
			// both the pedestrian Red LED and the cars' Green LED will be off
			LED_off(LED_P_RED_PORT, LED_P_RED_PIN);
			LED_off(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
			mode = NORMAL;
			
		}
		
	}
}
ISR(EXT_INT_0)
{
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
	mode = PEDESTRIAN;
}
