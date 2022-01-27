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

#include "watch_uart.h"
#include <string.h>

struct usart_sync_descriptor USART_0;
struct io_descriptor *uart_io;

void watch_enable_uart(const uint8_t tx_pin, const uint8_t rx_pin, uint32_t baud) {
    SERCOM_USART_CTRLA_Type ctrla;
    SERCOM_USART_CTRLB_Type ctrlb;
    ctrla.reg = SERCOM_USART_CTRLA_DORD | SERCOM_USART_CTRLA_MODE(1);
    ctrlb.reg = SERCOM_USART_CTRLB_CHSIZE(0);

    MCLK->APBCMASK.reg |= MCLK_APBCMASK_SERCOM3;
    GCLK->PCHCTRL[SERCOM3_GCLK_ID_CORE].reg = GCLK_PCHCTRL_GEN(0) | GCLK_PCHCTRL_CHEN;

    while (0 == (GCLK->PCHCTRL[SERCOM3_GCLK_ID_CORE].reg & GCLK_PCHCTRL_CHEN)) {
        // wait
    }

	usart_sync_init(&USART_0, SERCOM3, (void *)NULL);

    SERCOM3->USART.CTRLA.reg &= ~SERCOM_USART_CTRLA_ENABLE;

    switch (tx_pin) {
        case A2:
            gpio_set_pin_direction(tx_pin, GPIO_DIRECTION_OUT);
            gpio_set_pin_function(tx_pin, PINMUX_PB02C_SERCOM3_PAD0);
            ctrla.reg |= SERCOM_USART_CTRLA_TXPO(0);
            ctrlb.reg |= SERCOM_USART_CTRLB_TXEN;
            break;
        case A4:
            gpio_set_pin_direction(tx_pin, GPIO_DIRECTION_OUT);
            gpio_set_pin_function(tx_pin, PINMUX_PB00C_SERCOM3_PAD2);
            ctrla.reg |= SERCOM_USART_CTRLA_TXPO(1);
            ctrlb.reg |= SERCOM_USART_CTRLB_TXEN;
            break;
        default:
            break;
    }

    switch (rx_pin) {
        case A1:
            gpio_set_pin_direction(rx_pin, GPIO_DIRECTION_IN);
            gpio_set_pin_function(rx_pin, PINMUX_PB01C_SERCOM3_PAD3);
            ctrla.reg |= SERCOM_USART_CTRLA_RXPO(3);
            ctrlb.reg |= SERCOM_USART_CTRLB_RXEN;
            break;
        case A2:
            gpio_set_pin_direction(rx_pin, GPIO_DIRECTION_IN);
            gpio_set_pin_function(rx_pin, PINMUX_PB02C_SERCOM3_PAD0);
            ctrla.reg |= SERCOM_USART_CTRLA_RXPO(0);
            ctrlb.reg |= SERCOM_USART_CTRLB_RXEN;
            break;
        case A3:
            gpio_set_pin_direction(rx_pin, GPIO_DIRECTION_IN);
            gpio_set_pin_function(rx_pin, PINMUX_PB03C_SERCOM3_PAD1);
            ctrla.reg |= SERCOM_USART_CTRLA_RXPO(1);
            ctrlb.reg |= SERCOM_USART_CTRLB_RXEN;
            break;
        case A4:
            gpio_set_pin_direction(rx_pin, GPIO_DIRECTION_IN);
            gpio_set_pin_function(rx_pin, PINMUX_PB00C_SERCOM3_PAD2);
            ctrla.reg |= SERCOM_USART_CTRLA_RXPO(2);
            ctrlb.reg |= SERCOM_USART_CTRLB_RXEN;
            break;
        default:
            break;
    }
    SERCOM3->USART.CTRLA.reg = ctrla.reg;
    SERCOM3->USART.CTRLB.reg = ctrlb.reg;

    if (hri_usbdevice_get_CTRLA_ENABLE_bit(USB)) {
        uint64_t br = 65536 - ((65536 * 16.0f * baud) / 8000000);
        SERCOM3->USART.BAUD.reg = (uint16_t)br;
    } else {
        uint64_t br = 65536 - ((65536 * 16.0f * baud) / 4000000);
        SERCOM3->USART.BAUD.reg = (uint16_t)br;
    }

    SERCOM3->USART.CTRLA.reg |= SERCOM_USART_CTRLA_ENABLE;

	usart_sync_enable(&USART_0);
    usart_sync_get_io_descriptor(&USART_0, &uart_io);
}

void watch_uart_puts(char *s) {
	io_write(uart_io, (uint8_t *)s, strlen(s));
}

char watch_uart_getc(void) {
    uint8_t retval;
    io_read(uart_io, &retval, 1);
    return retval;
}

// Begin deprecated functions

 /*
 * UART methods are Copyright (c) 2014-2017, Alex Taradov <alex@taradov.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "peripheral_clk_config.h"

void watch_enable_debug_uart(uint32_t baud) {
    uint64_t br = (uint64_t)65536 * ((CONF_CPU_FREQUENCY * 4) - 16 * baud) / (CONF_CPU_FREQUENCY * 4);

    gpio_set_pin_direction(A2, GPIO_DIRECTION_OUT);
    gpio_set_pin_function(A2, PINMUX_PB02C_SERCOM3_PAD0);

    MCLK->APBCMASK.reg |= MCLK_APBCMASK_SERCOM3;

    GCLK->PCHCTRL[SERCOM3_GCLK_ID_CORE].reg = GCLK_PCHCTRL_GEN(0) | GCLK_PCHCTRL_CHEN;
    while (0 == (GCLK->PCHCTRL[SERCOM3_GCLK_ID_CORE].reg & GCLK_PCHCTRL_CHEN));

    SERCOM3->USART.CTRLA.reg =
        SERCOM_USART_CTRLA_DORD | SERCOM_USART_CTRLA_MODE(1/*USART_INT_CLK*/) |
        SERCOM_USART_CTRLA_RXPO(1/*PAD1*/) | SERCOM_USART_CTRLA_TXPO(0/*PAD0*/);

    SERCOM3->USART.CTRLB.reg = SERCOM_USART_CTRLB_RXEN | SERCOM_USART_CTRLB_TXEN |
        SERCOM_USART_CTRLB_CHSIZE(0/*8 bits*/);

    SERCOM3->USART.BAUD.reg = (uint16_t)br;

    SERCOM3->USART.CTRLA.reg |= SERCOM_USART_CTRLA_ENABLE;
}

void watch_debug_putc(char c) {
    while (!(SERCOM3->USART.INTFLAG.reg & SERCOM_USART_INTFLAG_DRE));
    SERCOM3->USART.DATA.reg = c;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
void watch_debug_puts(char *s) {
    while (*s) watch_debug_putc(*s++);
}
#pragma GCC diagnostic pop
