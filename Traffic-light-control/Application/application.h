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

// Function prototypes

void App_init(void);
void App_start(void);



#endif /* APPLICATION_H_ */