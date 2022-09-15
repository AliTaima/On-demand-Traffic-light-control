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
	LED_init(LED_C_1_PORT, LED_C_1_PIN);
	LED_init(LED_C_2_PORT, LED_C_2_PIN);
	LED_init(LED_C_3_PORT, LED_C_3_PIN);
	// 1.2 Pedestrians' LEDs
	LED_init(LED_P_1_PORT, LED_P_1_PIN);
	LED_init(LED_P_2_PORT, LED_P_2_PIN);
	LED_init(LED_P_3_PORT, LED_P_3_PIN);
	// 2. Set direction of BUTTON  to input
	Button_init(EXT_INT_BUTTON_PORT, EXT_INT_BUTTON_PIN);
	// 3. Enable global interrupt(setting bit 7 in status register to 1
	sei();
	// 4. Choosing the external interrupt snese (sense on the rising edge)
	MCUCR |= (1 << 0) | (1 << 1);
	// 5. Enable External interrupt 0(INT0)
	GICR |= (1 << 6);
	// 2. initialize timer
	TIMER_init();
}
EN_mode_t mode = NORMAL;

void App_start(void)
{	
	while (1)
	{
		if(mode == NORMAL)
		{
			LED_on(LED_C_1_PORT, LED_C_1_PIN);
			LED_off(LED_C_2_PORT, LED_C_2_PIN);
			LED_off(LED_C_3_PORT, LED_C_3_PIN);
			delay_5s();
			LED_off(LED_C_1_PORT, LED_C_1_PIN);
			LED_on(LED_C_2_PORT, LED_C_2_PIN);
			LED_off(LED_C_3_PORT, LED_C_3_PIN);
			delay_5s();
			// delay_5s_toggle(LED_C_2_PORT, LED_C_2_PIN);
			LED_off(LED_C_1_PORT, LED_C_1_PIN);
			LED_off(LED_C_2_PORT, LED_C_2_PIN);
			LED_on(LED_C_3_PORT, LED_C_3_PIN);
			delay_5s();
			LED_off(LED_C_1_PORT, LED_C_1_PIN);
			LED_off(LED_C_2_PORT, LED_C_2_PIN);
			LED_off(LED_C_3_PORT, LED_C_3_PIN);
			
		}
		else if (mode == PEDESTRAIN)
		{
			LED_on(LED_P_1_PORT, LED_P_1_PIN);
			LED_off(LED_P_2_PORT, LED_P_2_PIN);
			LED_off(LED_P_3_PORT, LED_P_3_PIN);
			delay_512ms();
			LED_off(LED_P_1_PORT, LED_P_1_PIN);
			LED_on(LED_P_2_PORT, LED_P_2_PIN);
			LED_off(LED_P_3_PORT, LED_P_3_PIN);
			delay_512ms();
			mode = NORMAL;
	
		}
		
	}
}
ISR(EXT_INT_0)
{
	mode = PEDESTRAIN;
}
/*
#define NUMBER_OF_LEDS 3


uint8_t led_number = 0;
void App_init(void)
{
	//1. set direction for button pin to input
	Button_init(EXT_INT_BUTTON_PORT, EXT_INT_BUTTON_PIN);
	//2. Set all LED bits to output
	LED_init(LED_C_1_PORT, LED_C_1_PIN);
	LED_init(LED_C_2_PORT, LED_C_2_PIN);
	LED_init(LED_C_3_PORT, LED_C_3_PIN);

	//3. Enable global interrupt(setting bit 7 in status register to 1
	sei();
	//4. Choosing the external interrupt sense (sense on the rising edge)
	MCUCR |= (1<<0) | (1<<1);
	//5. Enable External interrupt 0(INT0)
	GICR |= (1<<6);

}
void App_start(void)
{
	while(1)
	{
		switch(led_number)
		{
			case 0:
			LED_off(LED_C_1_PORT, LED_C_1_PIN);
			LED_off(LED_C_2_PORT, LED_C_2_PIN);
			LED_off(LED_C_3_PORT, LED_C_3_PIN);
			break;
			case 1:
			LED_on(LED_C_1_PORT, LED_C_1_PIN);
			break;
			case 2:
			LED_on(LED_C_2_PORT, LED_C_2_PIN);
			break;
			case 3:
			LED_on(LED_C_3_PORT, LED_C_3_PIN);
			break;
			default:
			// Nothing
			break;
		}

	}


}

ISR(EXT_INT_0)
{
	if(led_number < NUMBER_OF_LEDS)
	{
		led_number++;
	}
	else
	{
		led_number = 0;
	}
}*/