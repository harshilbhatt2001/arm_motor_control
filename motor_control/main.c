/*
 * main.c
 *
 * Created: 3/14/2021 2:45:26 PM
 *  Author: harsh
 */ 


#include "include/system.h"
#include "Config/spi_usi_driver.h"
#include "avr/io.h"
#include "avr/interrupt.h"

#define SPIMODE 0

ISR(INT0_vect)
{
	TransmitByte(spiX_get());
}

int main(void)
{
    system_init();
    spiX_initslave(SPIMODE);
	Enable_Interrupt(INT0);
    sei();
    while(1)
    {
	
    }
}