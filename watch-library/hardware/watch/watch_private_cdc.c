/*
 * MIT License
 *
 * Copyright (c) 2020 Joey Castillo
 * Copyright (c) 2023 Edward Shin
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

#include "watch_private_cdc.h"

#include <stddef.h>

#include "watch_utility.h"
#include "tusb.h"

/*
 * Implement a circular buffer for the USB CDC Serial read buffer.
 * The size of the buffer must be a power of two for this circular buffer
 * implementation to work.
 */

// Size of the circular buffer. Must be a power of two.
#define CDC_WRITE_BUF_SZ  (1024)
// Macro function to perform modular arithmetic on an index.
// eg. (63 + 2) & (64 - 1) -> 1
#define CDC_WRITE_BUF_IDX(x)  ((x) & (CDC_WRITE_BUF_SZ - 1))
static char s_write_buf[CDC_WRITE_BUF_SZ] = {0};
static size_t s_write_buf_pos = 0;
static size_t s_write_buf_len = 0;

#define CDC_READ_BUF_SZ  (256)
#define CDC_READ_BUF_IDX(x)  ((x) & (CDC_READ_BUF_SZ - 1))
static char s_read_buf[CDC_READ_BUF_SZ] = {0};
static size_t s_read_buf_pos = 0;
static size_t s_read_buf_len = 0;

// Mask TC1 interrupts, preventing calls to cdc_task()
static inline void prv_critical_section_enter(void) {
    NVIC_DisableIRQ(TC1_IRQn);
}

// Unmask TC1 interrupts, allowing calls to cdc_task()
static inline void prv_critical_section_exit(void) {
    NVIC_EnableIRQ(TC1_IRQn);
}

int _write(int file, char *ptr, int len) {
    (void) file;

    if (ptr == NULL || len <= 0) {
        return -1;
    }

    int bytes_written = 0;

    prv_critical_section_enter();

    for (int i = 0; i < len; i++) {
        s_write_buf[s_write_buf_pos] = ptr[i];
        s_write_buf_pos = CDC_WRITE_BUF_IDX(s_write_buf_pos + 1);
        if (s_write_buf_len < CDC_WRITE_BUF_SZ) {
            s_write_buf_len++;
        }
        bytes_written++;
    }

    prv_critical_section_exit();

    return bytes_written;
}

int _read(int file, char *ptr, int len) {
    (void) file;

    prv_critical_section_enter();

    if (ptr == NULL || len <= 0 || s_read_buf_len == 0) {
        prv_critical_section_exit();
        return -1;
    }

    // Clamp to the length of the read buffer
    if ((size_t) len > s_read_buf_len) {
        len = s_read_buf_len;
    }

    // Calculate the start of the circular buffer, and iterate from there
    const size_t start_pos = CDC_READ_BUF_IDX(s_read_buf_pos - len);
    for (size_t i = 0; i < (size_t) len; i++) {
        const size_t idx = CDC_READ_BUF_IDX(start_pos + i);
        ptr[i] = s_read_buf[idx];
        s_read_buf[idx] = 0;
    }

    // Update circular buffer position and length
    s_read_buf_len -= len;
    s_read_buf_pos = CDC_READ_BUF_IDX(s_read_buf_pos - len);

    prv_critical_section_exit();

    return len;
}

static void prv_handle_reads(void) {
    while (tud_cdc_available()) {
        int c = tud_cdc_read_char();
        if (c < 0) {
            continue;
        }
        s_read_buf[s_read_buf_pos] = c;
        s_read_buf_pos = CDC_READ_BUF_IDX(s_read_buf_pos + 1);
        if (s_read_buf_len < CDC_READ_BUF_SZ) {
            s_read_buf_len++;
        }
    }
}

static void prv_handle_writes(void) {
    if (s_write_buf_len > 0) {
        const size_t start_pos =
            CDC_WRITE_BUF_IDX(s_write_buf_pos - s_write_buf_len);
        for (size_t i = 0; i < (size_t) s_write_buf_len; i++) {
            const size_t idx = CDC_WRITE_BUF_IDX(start_pos + i);
            if (tud_cdc_available() > 0) {
                // If we receive data while doing a large write, we need to
                // fully service it before continuing to write, or the
                // stack will crash.
                prv_handle_reads();
            }
            if (tud_cdc_write_available()) {
                tud_cdc_write(&s_write_buf[idx], 1);
            }
            s_write_buf[idx] = 0;
            s_write_buf_len--;
        }
        tud_cdc_write_flush();
    }
}

void cdc_task(void) {
    prv_handle_reads();
    prv_handle_writes();
}
