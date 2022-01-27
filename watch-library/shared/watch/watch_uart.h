/*
 * MIT License
 *
 * Copyright (c) 2020 Joey Castillo
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef _WATCH_UART_H_INCLUDED
#define _WATCH_UART_H_INCLUDED
////< @file watch_uart.h

#include "watch.h"

/** @addtogroup debug UART
  * @brief This section covers functions related to the UART peripheral.
  **/
/// @{

/** @brief Initializes the debug UART.
  * @param tx_pin The pin the watch will use to transmit, or 0 for a receive-only UART.
  *               If specified, must be either A2 or A4.
  * @param rx_pin The pin the watch will use to receive, or 0 for a transmit-only UART.
  *               If specified, must be A1, A2, A3 or A4 (pin A0 cannot receive UART data).
  * @param baud The baud rate for the UART. A typical value is 19200.
  */
void watch_enable_uart(const uint8_t tx_pin, const uint8_t rx_pin, uint32_t baud);

/** @brief Transmits a string of bytes on the UART's TX pin.
  * @param s A null-terminated string containing the bytes you wish to transmit.
  */
void watch_uart_puts(char *s);

/** @brief Receives a single byte from the UART's RX pin.
  * @return the received byte.
  * @note This method will block until a byte is received!
  */
char watch_uart_getc(void);

// Begin deprecated functions:

/** @brief Initializes the debug UART.
  * @param baud The baud rate
  */
__attribute__((deprecated("Use watch_enable_uart to enable the UART.")))
void watch_enable_debug_uart(uint32_t baud);

/** @brief Outputs a single character on the debug UART.
  * @param c The character you wish to output.
  */
__attribute__((deprecated("Use watch_uart_puts to print to the UART, or printf to log debug messages over USB.")))
void watch_debug_putc(char c);

/** @brief Outputs a string on the debug UART.
  * @param s A null-terminated string.
  */
__attribute__((deprecated("Use watch_uart_puts to print to the UART, or printf to log debug messages over USB.")))
void watch_debug_puts(char *s);
/// @}
#endif
