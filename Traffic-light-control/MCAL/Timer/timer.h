/*
 * timer.h
 *
 * Created: 9/14/2022 5:35:37 PM
 *  Author: Ali Mohamed Taima
 */

#ifndef TIMER_H_
#define TIMER_H_
#include "../DIO/dio.h"
// typedef EN_prescalar_t
// {

// }EN_prescalar_t;
// define number of overflows to get our delay
#define NUMBER_OF_OVERFLOW 20

void TIMER_init(void);
void TIMER_start(uint16_t preScalar, uint32_t number_of_overflow);
void TIMER_stop(void);
void delay_512ms(void);
void delay_5s(void);
void delay_5s_toggle(EN_port_t ledPort, EN_pin_t ledPin);


#endif /* TIMER_H_ */