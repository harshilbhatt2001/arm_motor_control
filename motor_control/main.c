/*
 * main.c
 *
 * Created: 3/14/2021 2:45:26 PM
 *  Author: harsh
 */ 


/************************************************************************/
/* TODO: SS setup for USI module                                        */
/************************************************************************/

#include "include/system.h"
#include "Config/spi_usi_driver.h"
#include "avr/io.h"
#include "avr/interrupt.h"

#define SPIMODE 0

int main(void)
{
    system_init();
    spiX_initslave(SPIMODE);
    sei();
    while(1)
    {
		TransmitByte(spiX_get());
    }
}