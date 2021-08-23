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
////< @file watch_uart.h

/** @addtogroup debug Debug UART
  * @brief This section covers functions related to the debug UART, available on
  *        pin D1 of the 9-pin connector.
  * @todo Refactor this as a USB CDC so that folks can debug over USB.
  */
/// @{
/** @brief Initializes the debug UART.
  * @param baud The baud rate
  */
void watch_enable_debug_uart(uint32_t baud);

/** @brief Outputs a single character on the debug UART.
  * @param c The character you wish to output.
  */
void watch_debug_putc(char c);

/** @brief Outputs a string on the debug UART.
  * @param s A null-terminated string.
  */
void watch_debug_puts(char *s);
/// @}
