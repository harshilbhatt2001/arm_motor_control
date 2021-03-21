/*
 * ext_interrupt_driver.c
 *
 * Created: 21-03-2021 20:14:39
 *  Author: harsh
 */ 

#include "include/ext_interrupt_driver.h"
#include <xc.h>

/**
 * This configures external interrupt to sense change on either
 * rising edge, falling edge, both edges or low level to rise
 * an interrut change
 * @param INT_NO
 * @param INT_MODE
 */
void Configure_Interrupt(uint8_t INT_NO, uint8_t INT_MODE)
{
    switch (INT_NO) {
        case 0:
            switch (INT_MODE) {
                case 0:
                    MCUCR = (MCUCR & (~(1 << ISC01 | 1 << ISC00))) | (0 << ISC01 | 0 << ISC00);
                    break;
				case 1:
					MCUCR = (MCUCR & (~(1 << ISC01 | 1 << ISC00))) | (0 << ISC01 | 1 << ISC00);
					break;
				case 2:
				    MCUCR = (MCUCR & (~(1 << ISC01 | 1 << ISC00))) | (1 << ISC01 | 0 << ISC00);
					break;
				case 3:                    
					MCUCR = (MCUCR & (~(1 << ISC01 | 1 << ISC00))) | (1 << ISC01 | 1 << ISC00);
                    break;
				default:
					break;
            }
			break;
		case 1:
            switch (INT_MODE) {
                case 0:
                    MCUCR = (MCUCR & (~(1 << ISC11 | 1 << ISC10))) | (0 << ISC11 | 0 << ISC10);
                    break;
                case 1:
                    MCUCR = (MCUCR & (~(1 << ISC11 | 1 << ISC10))) | (0 << ISC11 | 1 << ISC10);
                    break;
                case 2:
                    MCUCR = (MCUCR & (~(1 << ISC11 | 1 << ISC10))) | (1 << ISC11 | 0 << ISC10);
                    break;
                case 3:
                    MCUCR = (MCUCR & (~(1 << ISC11 | 1 << ISC10))) | (1 << ISC11 | 1 << ISC10);
                    break;
                default:
                    break;
            }
        default:
            break;
    }
}

/**
 * Enable external interrupt
 * @param INT_NO
 */
void Enable_Interrupt(uint8_t INT_NO)
{
    switch (INT_NO) {
        case 0:
			GIMSK |= (1 << INT0);
			break;
		case 1:
			GIMSK |= (1 << INT1);
			break;
		default:
			break;	             
    }
}

/**
 * TODO: enable external pin change interrupt
 * @param INT_NO
 */
void Enable_PcInterrupt(uint8_t INT_NO)
{
    __asm("NOP");
}

/**
 * This function disables external interrupt
 * @param INT_NO
 */
void Disable_Interrupt(uint8_t INT_NO)
{
    switch (INT_NO) {
        case 0:
			GIMSK &= ~(1 << INT0);
            break;
        case 1:
			GIMSK &= ~(1 << INT1);
            break;
        default:
            break;
    }
}

/**
 * TODO: disable external pin change interrupt
 * @param INT_NO
 */
void Disable_PcInterrupt(uint8_t INT_NO)
{
    __asm("NOP");
}