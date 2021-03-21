/*
 * ext_interrupt_driver.h
 *
 * Created: 21-03-2021 20:17:44
 *  Author: harsh
 */ 


#ifndef EXT_INTERRUPT_DRIVER_H_
#define EXT_INTERRUPT_DRIVER_H_

#include "avr/io.h"

/**
 * Macro to assign integer value for each INT interrupt
 */
#define INTR0 0
#define INTR1 1

/**
 * Macros to assign integer value for each INT sense configuration
 */
#define LEVEL 0
#define EDGE 1
#define FALLING 2
#define RISING 3

/**
 * TODO: Macros to assign an integer value for each pin change interrupt
 */

void Configure_Interrupt(uint8_t INT_NO, uint8_t INT_MODE);
void Enable_Interrupt(uint8_t INT_NO);
void Enable_PcInterrupt(uint8_t PCINT_NO);
void Disable_Interrupt(uint8_t INT_NO);
void Disable_PcInterrupt(uint8_t INT_NO);

#endif /* EXT_INTERRUPT_DRIVER_H_ */