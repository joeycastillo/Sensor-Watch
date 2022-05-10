/*
 * MIT License
 *
 * Copyright (c) 2022 Joey Castillo
 *
 * Ported from MIT-licensed code from CircuitPython
 * Copyright (c) 2016, 2017 Scott Shawcroft for Adafruit Industries
 *
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

#include "watch.h"

#define CMD_READ_JEDEC_ID 0x9f
#define CMD_READ_DATA 0x03
#define CMD_FAST_READ_DATA 0x0B
#define CMD_SECTOR_ERASE 0x20
// #define CMD_SECTOR_ERASE CMD_READ_JEDEC_ID
#define CMD_CHIP_ERASE 0xC7
// #define CMD_CHIP_ERASE CMD_READ_JEDEC_ID
#define CMD_DISABLE_WRITE 0x04
#define CMD_ENABLE_WRITE 0x06
#define CMD_PAGE_PROGRAM 0x02
// #define CMD_PAGE_PROGRAM CMD_READ_JEDEC_ID
#define CMD_READ_STATUS 0x05
#define CMD_READ_STATUS2 0x35
#define CMD_WRITE_STATUS_BYTE1 0x01
#define CMD_WRITE_STATUS_BYTE2 0x31
#define CMD_DUAL_READ 0x3b
#define CMD_QUAD_READ 0x6b
#define CMD_ENABLE_RESET 0x66
#define CMD_RESET 0x99
#define CMD_WAKE 0xab

bool spi_flash_command(uint8_t command);
bool spi_flash_read_command(uint8_t command, uint8_t *response, uint32_t length);
bool spi_flash_write_command(uint8_t command, uint8_t *data, uint32_t length);
bool spi_flash_sector_command(uint8_t command, uint32_t address);
bool spi_flash_write_data(uint32_t address, uint8_t *data, uint32_t data_length);
bool spi_flash_read_data(uint32_t address, uint8_t *data, uint32_t data_length);
void spi_flash_init(void);
