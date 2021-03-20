/*
 * system.c
 *
 * Created: 20-03-2021 17:52:16
 *  Author: harsh
 */ 

#include "../include/spi_usi_driver_init.h"
#include "../include/system.h"
#include "../Config/uart_driver.h"

void system_init()
{
	mcu_init();
	
	UART_init(UBRR_VAL);

	// TODO: Port setting according to UART

	sysctrl_init();
}