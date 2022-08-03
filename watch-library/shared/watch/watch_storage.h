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
#ifndef _WATCH_STORAGE_H_INCLUDED
#define _WATCH_STORAGE_H_INCLUDED
////< @file watch_storage.h

#include "watch.h"

#ifndef NVMCTRL_ROW_SIZE
#define NVMCTRL_ROW_SIZE 256
#endif
#ifndef NVMCTRL_PAGE_SIZE
#define NVMCTRL_PAGE_SIZE 64
#endif
#ifndef NVMCTRL_RWWEE_PAGES
#define NVMCTRL_RWWEE_PAGES 128
#endif

/** @addtogroup storage Flash Storage
  * @brief This section covers functions related to the SAM L22's 8 kilobyte EEPROM emulation area.
  * @details The SAM L22 inside Sensor Watch has a 256 kilobyte Flash memory array that can be
  *          programmed with whatever data we want. We use most of it to store the bootloader
  *          and the application code that runs on your wrist. The bootloader region is read-only,
  *          and the main application area is only writable by the bootloader (when you drag new
  *          code onto the WATCHBOOT drive). However! there's also a special 8 kilobyte region
  *          at the end of the Flash memory called the EEPROM Emulation Area. This EEPROM emulation
  *          area can be written or erased while the main Flash array is being read. This makes it
  *          super easy to work with, and useful for storing a small amount of non-volatile data that
  *          persists across reboots, even when power is lost.
  *          The functions in this section are very basic, and only cover reading and writing data
  *          in this area. The region is laid out as 32 rows consisting of 4 pages of 64 bytes.
  *          32*4*64 = 8192 bytes. The area can be written one page at a time, but it can only be
  *          erased one row at a time. You can read at arbitrary word-aligned offsets within a row.
  *
  *                 ┌──────────────┬──────────────┬──────────────┬──────────────┐
  *          Row 0  │   64 bytes   │   64 bytes   │   64 bytes   │   64 bytes   │
  *                 ├──────────────┼──────────────┼──────────────┼──────────────┤
  *          Row 1  │   64 bytes   │   64 bytes   │   64 bytes   │   64 bytes   │
  *                 ├──────────────┼──────────────┼──────────────┼──────────────┤
  *           ...   │              │              │              │              │
  *                 ├──────────────┼──────────────┼──────────────┼──────────────┤
  *          Row 31 │   64 bytes   │   64 bytes   │   64 bytes   │   64 bytes   │
  *                 └──────────────┴──────────────┴──────────────┴──────────────┘
  */
/// @{
/** @brief Reads a range of bytes from the storage area.
  * @param row The row you want to read.
  * @param offset The offset from the beginning of the row.
  * @param buffer A buffer of at least `size` bytes.
  * @param size The number of bytes you wish to read.
  */
bool watch_storage_read(uint32_t row, uint32_t offset, uint8_t *buffer, uint32_t size);

/** @brief Writes bytes to a page in the storage area. Note that the row should already be erased before writing.
  * @param row The row containing the page you want to write.
  * @param offset The offset from the beginning of the row. Must be a multiple of 64.
  * @param buffer The buffer containing the bytes you wish to set.
  * @param size The number of bytes you wish to write.
  */
bool watch_storage_write(uint32_t row, uint32_t offset, const uint8_t *buffer, uint32_t size);

/** @brief Erases a row in the storage area, setting all its bytes to 0xFF.
  * @param row The row you want to erase.
  */
bool watch_storage_erase(uint32_t row);

/** @brief Waits for any pending writes to complete.
  */
bool watch_storage_sync(void);
/// @}
#endif
