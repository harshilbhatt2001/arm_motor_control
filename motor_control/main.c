/*
 * main.c
 *
 * Created: 3/14/2021 2:45:26 PM
 *  Author: harsh
 */ 


/************************************************************************/
/* TODO
	1. Receive data from Mega with USI module
	2. Data receive interrupt on USI
	3. Transmit data in ISR via USART module 
                                                                        */
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