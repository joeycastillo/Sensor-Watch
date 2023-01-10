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

#include "watch_buzzer.h"

 inline void watch_enable_buzzer(void) {
    if (!hri_tcc_get_CTRLA_reg(TCC0, TCC_CTRLA_ENABLE)) {
        _watch_enable_tcc();
    }
    gpio_set_pin_direction(BUZZER, GPIO_DIRECTION_OUT);
}
inline void watch_set_buzzer_period(uint32_t period) {
    hri_tcc_write_PERBUF_reg(TCC0, period);
    hri_tcc_write_CCBUF_reg(TCC0, WATCH_BUZZER_TCC_CHANNEL, period / 2);
}

void watch_disable_buzzer(void) {
    _watch_disable_tcc();
    watch_set_buzzer_off();
}

inline void watch_set_buzzer_on(void) {
    gpio_set_pin_direction(BUZZER, GPIO_DIRECTION_OUT);
    gpio_set_pin_function(BUZZER, WATCH_BUZZER_TCC_PINMUX);
}

inline void watch_set_buzzer_off(void) {
    gpio_set_pin_function(BUZZER, GPIO_PIN_FUNCTION_OFF);
    gpio_set_pin_level(BUZZER, true);
}

void watch_buzzer_play_note(BuzzerNote note, uint16_t duration_ms) {
    if (note == BUZZER_NOTE_REST) {
        watch_set_buzzer_off();
    } else {
        watch_set_buzzer_period(NotePeriods[note]);
        watch_set_buzzer_on();
    }
    delay_ms(duration_ms);
    watch_set_buzzer_off();
}
