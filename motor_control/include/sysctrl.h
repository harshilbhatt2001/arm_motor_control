/*
 * sysctrl.h
 *
 * Created: 19-03-2021 22:53:51
 *  Author: harsh
 */ 


#ifndef SYSCTRL_H_
#define SYSCTRL_H_

#include "protected_io.h"

// TODO: Sleep mode config

/**
 * Initialize sysctrl interface
 */
static inline int8_t sysctrl_init()
{
    // Set system clock and prescaler according to configuration
    protected_write_io((void *)&CLKPR, 1 << CLKPCE, (0 << CLKPS3) | (0 << CLKPS2) | (0 << CLKPS1) | (0 << CLKPS0));
	
	MCUCR = (0 << PUD) | (0 << SM1) | (0 << SE) | (0 << SM0);
}



#endif /* SYSCTRL_H_ */