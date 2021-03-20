/*
 * spi_usi_driver.c
 *
 * Created: 19-03-2021 14:04:08
 *  Author: harsh
 */ 

#include "Config/spi_usi_driver.h"

/**
 * Data input register buffer
 */
unsigned char storedUSIDR;

volatile struct usidriverStatus_t spiX_status; // The driver status bits

/**
 * TODO: Timer/Counter 0 Compare Match Interrupt Handler
 *
 * This is enabled when transferring in master mode.
 */

/**
 * USI Timer Overflow Interrupt Handler
 *
 * This handler disables the compare match interrupt if in master mode.
 * When the USI counter overflows, a byte has been transferred, and we have to
 * stop the timer tick.
 * For all modes, the USIDR contents are stored and flags updates
 */
//#pragma vector = USI_OVF_vect
//__interrupt void usiovf_handler
ISR(USI_OVERFLOW_vect)
{
    // TODO: Master must disable compare match interrupt
    // Update flags and clear USI counter
    USISR                        = (1 << USIOIF);
    spiX_status.transferComplete = 1;

    // Copy USIDR to buffer
    storedUSIDR = USIDR;
}

/*
 * TODO: Initialize USI as SPI master
 */

/**
 * Initialize USI as SPI slave
 * @param spimode   Must be 0 or 1
 */
void spiX_initslave(char spimode)
{
    // Configure port direction
    USI_DIR_REG |= (1 << USI_DATAOUT_PIN);                          // Output
    USI_DIR_REG &= ~(1 << USI_DATAIN_PIN) | (1 << USI_CLOCK_PIN);   // input
    USI_OUT_REG |= (1 << USI_DATAIN_PIN) | (1 << USI_CLOCK_PIN);    // pull-up

    // Configure USI to 3-wire SPI slave with overflow interrupt
    USICR = (1 << USIOIE) | (1 << USIWM0) | (1 << USICS1) | (spimode << USICS0);

    // Init driver status register
    spiX_status.masterMode = 0;
    spiX_status.transferComplete = 0;
    spiX_status.writeCollision = 0;

    storedUSIDR = 0;
}

/**
 * TODO: Put one byte on the bus
 * @param val
 * @return
 */
// char spiX_put(unsigned char val)
// {
//     NULL;
// }

unsigned char spiX_get()
{
    return storedUSIDR;
}

/**
 * Wait till transfer is complete
 */
void spiX_wait()
{
    do {
    }
    while (spiX_status.transferComplete == 0);
}