/*
 * application.h
 *
 * Created: 9/14/2022 10:47:48 AM
 *  Author: Ali Mohamed Taima
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

// Including led and button modules from lower layer
#include "../ECUAL/LED/led.h"
#include "../ECUAL/Button/button.h"

// enum for traffic light colors
typedef enum EN_button_color_t
{
	RED, YELLOW, GREEN
	}EN_button_color_t;
// enum for mode
typedef enum EN_mode_t
{
	NORMAL, PEDESTRIAN
	}EN_mode_t;
typedef enum EN_interrupt_state_t
{
	INTERRUPT_ON, INTERRUPT_OFF
	}EN_interrupt_state_t;
// Function prototypes


void App_init(void);
void App_start(void);
void pedestrian_mode(void);
void GreenLED(void);
void RedLED(void);
void YellowLED(void);
void PedestrianMode(void);
void TurnOffLEDs(void);
#endif /* APPLICATION_H_ */