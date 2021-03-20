/*
 * uart_driver.h
 *
 * Created: 20-03-2021 17:27:08
 *  Author: harsh
 */ 


#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_

#include "avr/io.h"
#include "avr/interrupt.h"

#define UBRR_VAL 51
// UART Buffer Defines
#define UART_RX_BUFFER_SIZE 8
#define UART_TX_BUFFER_SIZE 8
#define UART_RX_BUFFER_MASK (UART_RX_BUFFER_SIZE - 1)
#define UART_TX_BUFFER_MASK (UART_TX_BUFFER_SIZE - 1)

void UART_init(unsigned char ubrr_val);
unsigned char ReceiveByte(void);
void TransmitByte(unsigned char data);

#endif /* UART_DRIVER_H_ */