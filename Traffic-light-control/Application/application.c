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
	// 4. initialize timer
	TIMER_init();
}
// To store the mode
EN_mode_t mode = NORMAL;
EN_button_color_t color;
EN_interrupt_state_t interrupt_state = INTERRUPT_OFF;
void App_start(void)
{
	while (1)
	{
		if (mode == NORMAL)
		{
			TurnOffLEDs();
			// turn on cars' Red LED for 5 s and pedestrian's Green LED will be on
			LED_on(LED_C_RED_PORT, LED_C_RED_PIN);
			LED_on(LED_P_GREEN_PORT, LED_P_GREEN_PIN);
			LED_off(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
			LED_off(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
			delay_5s();
			// check if interrupt is or not to run pedestrian mode
			if (interrupt_state == INTERRUPT_ON)
			{
				continue;
			}
			// Turn on cars' Yellow led for 5 s and pedestrian's Yellow LED will be on
			LED_off(LED_C_RED_PORT, LED_C_RED_PIN);
			LED_off(LED_P_GREEN_PORT, LED_P_GREEN_PIN);
			LED_off(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
			LED_on(LED_P_RED_PORT, LED_P_RED_PIN);
			toggle_LED_5s(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
			// check if interrupt is or not to run pedestrian mode
			if (interrupt_state == INTERRUPT_ON)
			{
				continue;
			}
			// Turn on cars' Green led for 5 s and pedestrian's Red LED will be on
			LED_off(LED_P_RED_PORT, LED_P_RED_PIN);
			LED_off(LED_C_RED_PORT, LED_C_RED_PIN);
			LED_off(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
			LED_on(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
			toggle_LED_5s(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
		}
		else if (mode == PEDESTRIAN)
		{
			PedestrianMode();
		}
	}
}
ISR(EXT_INT_0)
{
	if (interrupt_state == INTERRUPT_OFF)
	{
		uint8_t value;
		DIO_read(LED_C_RED_PORT, LED_C_RED_PIN, &value);
		if (value)
		{
			color = RED;
		}
		else
		{
			DIO_read(LED_C_GREEN_PORT, LED_C_GREEN_PIN, &value);
			if (value)
			{

				color = GREEN;
			}
			else
			{
				color = YELLOW;
			}
		}
		// set mode to pedestrian mode
		mode = PEDESTRIAN;
		interrupt_state = INTERRUPT_ON;
	}
}

void PedestrianMode(void)
{
	TurnOffLEDs();
	// Applying pedestrian mode according to cars' LEDs
	if (color == RED)
	{
		RedLED();
	}
	else if (color == GREEN)
	{
		GreenLED();
	}
	else if (color == YELLOW)
	{
		YellowLED();
	}
	// cars' Red LED will be off
	LED_off(LED_C_RED_PORT, LED_C_RED_PIN);
	// both Yellow LEDs will be on
	toggle_2_LEDs_5s(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN, LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
	// The pedestrian's GREEN LED will be off
	LED_off(LED_P_GREEN_PORT, LED_P_GREEN_PIN);
	// both Yellow LEDs will be off
	LED_off(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
	LED_off(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
	// both the pedestrian Red LED and the cars' Green LED will be on
	LED_on(LED_P_RED_PORT, LED_P_RED_PIN);
	LED_on(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
	delay_5s();
	interrupt_state = INTERRUPT_OFF;
	mode = NORMAL;
}
void TurnOffLEDs(void)
{
	// turn off all cars' LEDs
	LED_off(LED_C_RED_PORT, LED_C_RED_PIN);
	LED_off(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
	LED_off(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
	// turn off all pedestrian's LEDs
	LED_off(LED_P_RED_PORT, LED_P_RED_PIN);
	LED_off(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
	LED_off(LED_P_GREEN_PORT, LED_P_GREEN_PIN);
}

void GreenLED(void)
{
	LED_on(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
	LED_on(LED_P_RED_PORT, LED_P_RED_PIN);
	delay_5s();
	LED_off(LED_P_RED_PORT, LED_P_RED_PIN);
	toggle_2_LEDs_5s(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN, LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
	LED_off(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
	LED_off(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
	LED_off(LED_C_GREEN_PORT, LED_C_GREEN_PIN);
	LED_on(LED_C_RED_PORT, LED_C_RED_PIN);
	LED_on(LED_P_GREEN_PORT, LED_P_GREEN_PIN);
	delay_5s();
}
void RedLED(void)
{
	LED_on(LED_C_RED_PORT, LED_C_RED_PIN);
	LED_on(LED_P_GREEN_PORT, LED_P_GREEN_PIN);
	delay_5s();
}
void YellowLED(void)
{
	LED_on(LED_P_RED_PORT, LED_P_RED_PIN);
	toggle_LED_5s(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
	LED_off(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
	LED_off(LED_P_RED_PORT, LED_P_RED_PIN);
	toggle_2_LEDs_5s(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN, LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
	LED_off(LED_P_YELLOW_PORT, LED_P_YELLOW_PIN);
	LED_off(LED_C_YELLOW_PORT, LED_C_YELLOW_PIN);
	LED_on(LED_C_RED_PORT, LED_C_RED_PIN);
	LED_on(LED_P_GREEN_PORT, LED_P_GREEN_PIN);
	delay_5s();
}
void toggle_2_LEDs_5s(EN_port_t ledPort1, EN_pin_t ledPin1, EN_port_t ledPort2, EN_pin_t ledPin2)
{
	uint32_t overflowCounter = 0;

	TCCR0 |= (1 << 2); // set pin2, 256 prescalar
	// Repeated number of overflow times
	while (overflowCounter < 77)
	{
		// wait the overflow flat to be set
		while ((TIFR & (1 << 0)) == 0)
			;
		// Clear the overflow flag
		TIFR |= (1 << 0);
		if (overflowCounter % 6 == 0)
		{
			LED_toggle(ledPort1, ledPin1);
			LED_toggle(ledPort2, ledPin2);
		}
		overflowCounter++;
	}
}
void toggle_LED_5s(EN_port_t ledPort, EN_pin_t ledPin)
{
	uint32_t overflowCounter = 0;

	TCCR0 |= (1 << 2); // set pin2, 256 prescalar
	// Repeated number of overflow times
	while (overflowCounter < 77)
	{
		// wait the overflow flat to be set
		while ((TIFR & (1 << 0)) == 0)
		;
		// Clear the overflow flag
		TIFR |= (1 << 0);
		if (overflowCounter % 6 == 0)
		{
			LED_toggle(ledPort, ledPin);
		}
		overflowCounter++;
	}
}