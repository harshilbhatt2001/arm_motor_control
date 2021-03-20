/*
 * system.h
 *
 * Created: 17-03-2021 21:37:22
 *  Author: harsh
 */ 



#ifndef SYSTEM_INCLUDED
#define SYSTEM_INCLUDED

#include <xc.h>
#include "port.h"
#include "protected_io.h"
#ifdef __cplusplus
extern "C" {
#endif

#define MCU_RESET_CAUSE_POR (1 << PORF)
#define MCU_RESET_CAUSE_EXT (1 << EXTRF)
#define MCU_RESET_CAUSE_BOR (1 << BORF)
#define MCU_RESET_CAUSE_WDT (1 << WDRF)

static inline void mcu_init(void)
{
    /* On AVR devices all peripherals are enabled from power on reset, this
     * disables all peripherals to save power. Driver shall enable
     * peripheral if used */

    PRR = (1 << PRUSI) | (1 << PRUSART) | (1 << PRTIM0) | (1 << PRTIM1);

    /* Set all pins to low power mode */
    PORTA_set_port_dir(0xff, PORT_DIR_OFF);
    PORTB_set_port_dir(0xff, PORT_DIR_OFF);
    PORTD_set_port_dir(0xff, PORT_DIR_OFF);
}

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_INCLUDED */
