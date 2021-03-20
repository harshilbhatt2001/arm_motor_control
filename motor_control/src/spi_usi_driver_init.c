/*
 * spi_usi_driver_init.c
 *
 * Created: 19-03-2021 23:18:05
 *  Author: harsh
 */ 

#include "../include/spi_usi_driver_init.h"
#include "../include/system.h"

void system_init()
{
    mcu_init();

    // TODO: Port setting according to UART

    sysctrl_init();
}