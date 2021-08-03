/*
 * Copyright (c) 2021, Joey Castillo
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

//-----------------------------------------------------------------------------
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "saml22.h"
#include "hal_init.h"
#include "peripheral_clk_config.h"
#include "hal_gpio.h"
#include "atmel_start_pins.h"
#include "watch.h"
#include "app.h"

//-----------------------------------------------------------------------------
HAL_GPIO_PIN(UART_TX,   B, 0)

//-----------------------------------------------------------------------------
static void uart_init(uint32_t baud) {
    uint64_t br = (uint64_t)65536 * (CONF_CPU_FREQUENCY - 16 * baud) / CONF_CPU_FREQUENCY;

    HAL_GPIO_UART_TX_out();
    HAL_GPIO_UART_TX_pmuxen(HAL_GPIO_PMUX_C);

    MCLK->APBCMASK.reg |= MCLK_APBCMASK_SERCOM3;

    GCLK->PCHCTRL[SERCOM3_GCLK_ID_CORE].reg = GCLK_PCHCTRL_GEN(0) | GCLK_PCHCTRL_CHEN;
    while (0 == (GCLK->PCHCTRL[SERCOM3_GCLK_ID_CORE].reg & GCLK_PCHCTRL_CHEN));

    SERCOM3->USART.CTRLA.reg =
        SERCOM_USART_CTRLA_DORD | SERCOM_USART_CTRLA_MODE(1/*USART_INT_CLK*/) |
        SERCOM_USART_CTRLA_RXPO(0/*PAD0*/) | SERCOM_USART_CTRLA_TXPO(1/*PAD2*/);

    SERCOM3->USART.CTRLB.reg = SERCOM_USART_CTRLB_RXEN | SERCOM_USART_CTRLB_TXEN |
        SERCOM_USART_CTRLB_CHSIZE(0/*8 bits*/);

    SERCOM3->USART.BAUD.reg = (uint16_t)br;

    SERCOM3->USART.CTRLA.reg |= SERCOM_USART_CTRLA_ENABLE;
}

//-----------------------------------------------------------------------------
void uart_putc(char c) {
    while (!(SERCOM3->USART.INTFLAG.reg & SERCOM_USART_INTFLAG_DRE));
    SERCOM3->USART.DATA.reg = c;
}

//-----------------------------------------------------------------------------
void uart_puts(char *s) {
    while (*s) uart_putc(*s++);
}

int main(void) {
    // Temporary, for debugging.
    uart_init(115200);

    // ASF code. Initialize the MCU with configuration options from Atmel Studio.
    init_mcu();

    // User code. Give the app a chance to initialize its data structures and state.
    app_init();

    // If the RTC is already enabled, we're either waking from BACKUP mode or a reset.
    // Ideally we should check if the TAMPER or CMP0 (alarm) flags are set.
    if (watch_rtc_is_enabled()) {
        // User code. Give the application a chance to restore state from backup registers.
        app_wake_from_deep_sleep();

        // disable the tamper interrupt and clear the tamper bit
        hri_rtcmode0_clear_INTEN_TAMPER_bit(RTC);
        hri_rtcmode0_clear_interrupt_TAMPER_bit(RTC);
    }

    // Watch library code. Set initial parameters for the device and enable the RTC.
    watch_init();

    // User code. Give the app a chance to enable and set up peripherals.
    app_setup();

    while (1) {
        bool can_sleep = app_loop();
        if (can_sleep) {
            app_prepare_for_sleep();
            sleep(4);
            app_wake_from_sleep();
        }
    }

    return 0;
}
