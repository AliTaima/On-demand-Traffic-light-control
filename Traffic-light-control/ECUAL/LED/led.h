/*
 * LED.h
 *
 * Created: 9/14/2022 10:46:22 AM
 *  Author: Ali Mohamed Taima
 */

#ifndef LED_H_
#define LED_H_
/************************************************************************/
/* Led driver in upper layer, so we include DIO driver(from low layer) inside it */
/************************************************************************/
#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/Timer/timer.h"

/************************************************************************/
/*					3LEDs for cars										*/
/************************************************************************/
// define led1 port and pin
#define LED_C_1_PORT PORT_A
#define LED_C_1_PIN PIN0
// define led2 port and pin
#define LED_C_2_PORT PORT_A
#define LED_C_2_PIN PIN1
// define led3 port and pin
#define LED_C_3_PORT PORT_A
#define LED_C_3_PIN PIN2

/************************************************************************/
/*					3LEDs for pedestrians                               */
/************************************************************************/
// define led1 port and pin
#define LED_P_1_PORT PORT_A
#define LED_P_1_PIN PIN0
// define led2 port and pin
#define LED_P_2_PORT PORT_A
#define LED_P_2_PIN PIN3
// define led3 port and pin
#define LED_P_3_PORT PORT_A
#define LED_P_3_PIN PIN7

// functions prototypes
void LED_init(EN_port_t ledPort, EN_pin_t ledPin);
void LED_on(EN_port_t ledPort, EN_pin_t ledPin);
void LED_off(EN_port_t ledPort, EN_pin_t ledPin);
void LED_toggle(EN_port_t ledPort, EN_pin_t ledPin);

#endif /* LED_H_ */