/*
 * uart_interrupt.c
 *
 * Created: 20-03-2021 17:24:19
 *  Author: harsh
 */ 

#include "Config/uart_driver.h"
#include <xc.h>

// Static variables
static unsigned char UART_RxBuf[UART_RX_BUFFER_SIZE];
static volatile unsigned char UART_RxHead;
static volatile unsigned char UART_RxTail;
static unsigned char UART_TxBuf[UART_TX_BUFFER_SIZE];
static volatile unsigned char UART_TxHead;
static volatile unsigned char UART_TxTail;

void UART_init(unsigned char ubrr_val)
{
    unsigned char x;

    // Set baud rate
	UBRRH = (unsigned char)(ubrr_val >> 8);
	UBRRL = (unsigned char)ubrr_val;
	
	// Enable UART Receiver and Transmitter
	UCSRB = ((1 << RXEN) | (1 << TXEN) | (1 << RXCIE));

	// Flush Receive buffer
	x = 0;

	UART_RxTail = x;
	UART_RxHead = x;
    UART_TxTail = x;
    UART_TxHead = x;
}

/**
 * UART_TX_interrupt
 */
ISR(USART_UDRE_vect)
{
    unsigned char tmptail;

    // If data not transmitted, transmit data
    if (UART_TxHead != UART_TxTail)
    {
        tmptail = (UART_TxTail + 1) & UART_TX_BUFFER_MASK;
        UART_TxTail = tmptail;
        UDR = UART_TxBuf[tmptail];
    }
    else
    {
        // Disable UDRE interrupt
        UCSRB &= ~(1 << UDRIE);
    }
}

// TODO: ReceiveByte function

/**
 * Transmit one Byte of data
 * @param data
 */
void TransmitByte(unsigned char data)
{
    unsigned char tmphead;

    tmphead = (UART_TxHead + 1) & UART_TX_BUFFER_MASK;
    while (tmphead == UART_TxTail);
    UART_TxBuf[tmphead] = data;
    UART_TxHead = tmphead;
    // Enable UDRE interrupt
    UDR |= (1 << UDRIE);
}