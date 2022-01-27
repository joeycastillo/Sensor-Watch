/*
 * MIT License
 *
 * Copyright (c) 2022 Joey Castillo
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

#ifndef _WATCH_SPI_H_INCLUDED
#define _WATCH_SPI_H_INCLUDED
////< @file watch_spi.h

#include "watch.h"

/** @addtogroup spi SPI Controller Driver
  * @brief This section covers functions related to the SAM L22's built-in SPI driver, including
  *        configuring the SPI bus and writing to / reading from devices.
  */
/// @{
/** @brief Enables the SPI peripheral. Call this before attempting to interface with SPI devices.
  */
void watch_enable_spi(void);

/** @brief Disables the SPI peripheral.
  */
void watch_disable_spi(void);

/** @brief Writes a series of values to a device on the SPI bus.
  * @param buf A series of unsigned bytes; the data you wish to transmit.
  * @param length The number of bytes in buf that you wish to send.
  * @note This function does not manage the chip select pin (usually A3).
  */
bool watch_spi_write(const uint8_t *buf, uint16_t length);

/** @brief Reads a series of values from a device on the SPI bus.
  * @param buf Storage for the incoming bytes; on return, it will contain the received data.
  * @param length The number of bytes that you wish to receive.
  * @note This function does not manage the chip select pin (usually A3).
  */
bool watch_spi_read(uint8_t *buf, uint16_t length);

/** @brief Reads a series of values from a device on the SPI bus.
  * @param buf Storage for the incoming bytes; on return, it will contain the received data.
  * @param length The number of bytes that you wish to receive.
  * @note This function does not manage the chip select pin (usually A3).
  */
bool watch_spi_transfer(const uint8_t *data_out, uint8_t *data_in, uint16_t length);

/// @}
#endif
