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
// Function prototypes

void App_init(void);
void App_start(void);
void pedestrain_mode(void);


#endif /* APPLICATION_H_ */