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

#include "watch_slcd.h"
#include "watch_private_display.h"
#include "hpl_slcd_config.h"

#include <emscripten.h>

 //////////////////////////////////////////////////////////////////////////////////////////
// Segmented Display

void watch_enable_display(void) {
    watch_clear_display();
}

void watch_set_pixel(uint8_t com, uint8_t seg) {
    EM_ASM({
        document.querySelectorAll("[data-com='" + $0 + "'][data-seg='" + $1 + "']")
            .forEach(function(e) {
                e.style.opacity = 1;
            });
    }, com, seg);
}

void watch_clear_pixel(uint8_t com, uint8_t seg) {
    EM_ASM({
        document.querySelectorAll("[data-com='" + $0 + "'][data-seg='" + $1 + "']")
            .forEach(function(e) {
                e.style.opacity = 0;
            });
    }, com, seg);
}

void watch_clear_display(void) {
    EM_ASM({
        document.querySelectorAll("[data-com][data-seg]")
            .forEach(function(e) {
                e.style.opacity = 0;
            });
    });
}

void watch_start_character_blink(char character, uint32_t duration) {
    // SLCD->CTRLD.bit.FC0EN = 0;
    // _sync_slcd();
    // 
    // if (duration <= SLCD_FC_BYPASS_MAX_MS) {
    //     SLCD->FC0.reg = SLCD_FC0_PB | ((duration / (1000 / SLCD_FRAME_FREQUENCY)) - 1);
    // } else {
    //     SLCD->FC0.reg = (((duration / (1000 / SLCD_FRAME_FREQUENCY)) / 8 - 1));
    // }
    // SLCD->CTRLD.bit.FC0EN = 1;

    watch_display_character(character, 7);
    watch_clear_pixel(2, 10); // clear segment B of position 7 since it can't blink

    // SLCD->CTRLD.bit.BLINK = 0;
    // SLCD->CTRLA.bit.ENABLE = 0;
    // _sync_slcd();

    // SLCD->BCFG.bit.BSS0 = 0x07;
    // SLCD->BCFG.bit.BSS1 = 0x07;

    // SLCD->CTRLD.bit.BLINK = 1;
    // _sync_slcd();
    // SLCD->CTRLA.bit.ENABLE = 1;
    // _sync_slcd();
}

void watch_stop_blink(void) {
    // SLCD->CTRLD.bit.FC0EN = 0;
    // SLCD->CTRLD.bit.BLINK = 0;
}

void watch_start_tick_animation(uint32_t duration) {
    watch_display_character(' ', 8);
    const uint32_t segs[] = { SLCD_SEGID(0, 2)};
    // TODO: (a2) hook to UI
    // slcd_sync_start_animation(&SEGMENT_LCD_0, segs, 1, duration);
}

bool watch_tick_animation_is_running(void) {
    // return hri_slcd_get_CTRLD_CSREN_bit(SLCD);
    return false;
}

void watch_stop_tick_animation(void) {
    const uint32_t segs[] = { SLCD_SEGID(0, 2)};
    // slcd_sync_stop_animation(&SEGMENT_LCD_0, segs, 1);
    watch_display_character(' ', 8);
}
