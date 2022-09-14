/*
 * interrupts.h
 *
 * Created: 9/14/2022 10:45:40 AM
 *  Author: Ali Mohamed Taima
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

/************************************************************************/
/*						 Interrupts vectors                            */
/************************************************************************/
// External Interrupt vectors

// External interrupt request 0
#define EXT_INT_0 __vector_1
// External interrupt request 1
#define EXT_INT_1 __vector_2
// External interrupt request 2
#define EXT_INT_2 __vector_3

// Set global interrupts, set the I-bit in status register to 1
#define  sei() __asm__ __volatile__ ("sei" ::: "memory")

// Clear Global interrupts, set the I-bit in status register to 0
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

// ISR defition
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal, used));\
void INT_VECT(void)



#endif /* INTERRUPTS_H_ */