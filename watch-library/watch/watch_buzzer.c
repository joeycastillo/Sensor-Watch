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

 inline void watch_enable_buzzer() {
    PWM_1_init();
}

inline void watch_set_buzzer_period(uint32_t period) {
    pwm_set_parameters(&PWM_1, period, period / 2);
}

inline void watch_set_buzzer_on() {
	pwm_enable(&PWM_1);
}

inline void watch_set_buzzer_off() {
	pwm_disable(&PWM_1);
}

const uint16_t NotePeriods[108] = {31047, 29301, 27649, 26079, 24617, 23224, 21923, 20683, 19515, 18418, 17377, 16399, 15477, 14603, 13780, 13004, 12272, 11580, 10926, 10311, 9730, 9181, 8664, 8175, 7714, 7280, 6869, 6483, 6117, 5772, 5447, 5140, 4850, 4577, 4319, 4076, 3846, 3629, 3425, 3232, 3050, 2878, 2715, 2562, 2418, 2282, 2153, 2032, 1917, 1809, 1707, 1611, 1520, 1435, 1354, 1277, 1205, 1137, 1073, 1013, 956, 902, 851, 803, 758, 715, 675, 637, 601, 567, 535, 505, 476, 450, 424, 400, 378, 357, 336, 317, 300, 283, 267, 252, 238, 224, 212, 200, 188, 178, 168, 158, 149, 141, 133, 125, 118, 112, 105, 99, 94, 89, 84, 79, 74, 70, 66, 63};

void watch_buzzer_play_note(BuzzerNote note, uint16_t duration_ms) {
    if (note == BUZZER_NOTE_REST) {
        watch_set_buzzer_off();
    } else {
        pwm_set_parameters(&PWM_1, NotePeriods[note], NotePeriods[note] / 2);
        watch_set_buzzer_on();
    }
    delay_ms(duration_ms);
    watch_set_buzzer_off();
}
