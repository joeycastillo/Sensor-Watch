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

/** @addtogroup debug Debug UART
  * @brief This section covers functions related to the debug UART, available on
  *        pin D1 of the 9-pin connector.
  * @warning These functions were used early on in development, before the TinyUSB
  *          CDC was implemented. You can now print debug messages to the USB console
  *          using printf, rendering this bit irrelevant. These methods will likely
  *          be refactored out in the future, in favor of a more full-featured UART
  *          on the nine-pin connector.
  **/
/// @{
/** @brief Initializes the debug UART.
  * @param baud The baud rate
  */
__attribute__((deprecated("Use printf to log debug messages over USB.")))
void watch_enable_debug_uart(uint32_t baud);

/** @brief Outputs a single character on the debug UART.
  * @param c The character you wish to output.
  */
__attribute__((deprecated("Use printf to log debug messages over USB.")))
void watch_debug_putc(char c);

/** @brief Outputs a string on the debug UART.
  * @param s A null-terminated string.
  */
__attribute__((deprecated("Use printf to log debug messages over USB.")))
void watch_debug_puts(char *s);
/// @}
#endif
