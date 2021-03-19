/*
 * spi_usi_driver.h
 *
 * Created: 19-03-2021 14:41:15
 *  Author: harsh
 */ 


#ifndef SPI_USI_DRIVER_H_
#define SPI_USI_DRIVER_H_

#include <xc.h>

/*
 * USI port and pin definitions
 */
#define USI_OUT_REG PORTB       // USI port output register
#define USI_IN_REG PINB         // USI port input register
#define USI_DIR_REG DDRB        // USI port direction register
#define USI_CLOCK_PIN PB7       // USI clock IO pin
#define USI_DATAIN_PIN PB5      // USI data in IO pin
#define USI_DATAOUT_PIN PB6     // USI data in IO pin

/*
 * Speed Configuration:
 * Bits per second = CPUSPEED / PRESCALER / (COMPAREVALUE+1) /2
 * Maximum = CPUSPEED / 64
 */
#define TC0_PRESCALER_VALUE 256 // Must be 1, 8, 64, 256, 1024
#define TC0_COMPARE_VALUE 1     // Must be 0 to 255. Minimum 31 with prescaler CLK/1

/*
 * Prescaler values converted to bit settings
 */
#if TC0_PRESCALER_VALUE == 1
#define TCO_PS_SETTINGS (1 << CS00)
#elif TC0_PRESCALER_VALUE == 8
#define TC0_PS_SETTINGS (1 << CS01)
#elif TC0_PRESCALER_VALUE == 64
#define TC0_PS_SETTING (1 << CS01) | (1 << CS00)
#elif TC0_PRESCALER_VALUE == 256
#define TC0_PS_SETTING (1 << CS02)
#elif TC0_PRESCALER_VALUE == 1024
#define TC0_PS_SETTING (1 << CS02) | (1 << CS00)
#else
#error Invalid T/C0 prescaler setting.
#endif

/**
 * Driver status bit structure
 */
struct usidriverStatus_t {
    unsigned char masterMode : 1;           // True if in master mode
    unsigned char transferComplete : 1;     // True when transfer complete
    unsigned char writeCollision : 1;       // True if put attempted during transfer
};

#endif /* SPI_USI_DRIVER_H_ */