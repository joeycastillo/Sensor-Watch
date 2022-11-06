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

void cb_watch_buzzer_seq(void);

static uint16_t _seq_position;
static int8_t _tone_ticks, _repeat_counter;
static int8_t *_sequence;
static void (*_cb_finished)(void);

static void _tcc_write_RUNSTDBY(bool value) {
    // enables or disables RUNSTDBY of the tcc
    hri_tcc_clear_CTRLA_ENABLE_bit(TCC0);
    hri_tcc_write_CTRLA_RUNSTDBY_bit(TCC0, value);
    hri_tcc_set_CTRLA_ENABLE_bit(TCC0);
    hri_tcc_wait_for_sync(TCC0, TCC_SYNCBUSY_ENABLE);
}

void watch_buzzer_play_sequence(int8_t *note_sequence, void (*callback_on_end)(void)) {
    watch_rtc_disable_periodic_callback(32);
    watch_set_buzzer_off();
    _sequence = note_sequence;
    _cb_finished = callback_on_end;
    _seq_position = 0;
    _tone_ticks = 0;
    _repeat_counter = -1;
    // prepare buzzer
    watch_enable_buzzer();
    // TCC should run in standby mode
    _tcc_write_RUNSTDBY(true);
    // register 32 hz callback
    watch_rtc_register_periodic_callback(cb_watch_buzzer_seq, 32);
}

void cb_watch_buzzer_seq(void) {
    // callback for reading the note sequence
    if (_tone_ticks == 0) {
        if (_sequence[_seq_position] < 0 && _sequence[_seq_position + 1]) {
            // repeat indicator found
            if (_repeat_counter == -1) {
                // first encounter: load repeat counter
                _repeat_counter = _sequence[_seq_position + 1];
            } else _repeat_counter--;
            if (_repeat_counter > 0)
                // rewind
                if (_seq_position > _sequence[_seq_position] * -2)
                    _seq_position += _sequence[_seq_position] * 2;
                else
                    _seq_position = 0;
            else {
                // continue
                _seq_position += 2;
                _repeat_counter = -1;
            }
        }
        if (_sequence[_seq_position] && _sequence[_seq_position + 1]) {
            // read note
            BuzzerNote note = _sequence[_seq_position];
            if (note != BUZZER_NOTE_REST) {
                hri_tcc_write_PERBUF_reg(TCC0, NotePeriods[note]);
                hri_tcc_write_CCBUF_reg(TCC0, WATCH_BUZZER_TCC_CHANNEL, NotePeriods[note] / 2);
                watch_set_buzzer_on();
            } else watch_set_buzzer_off();
            // set duration ticks and move to next tone
            _tone_ticks = _sequence[_seq_position + 1];
            _seq_position += 2;
        } else {
            // end the sequence
            watch_buzzer_abort_sequence();
            if (_cb_finished) _cb_finished();
        }
    } else _tone_ticks--;
}

void watch_buzzer_abort_sequence(void) {
    // ends/aborts the sequence
    watch_rtc_disable_periodic_callback(32);
    watch_set_buzzer_off();
    // disable standby mode for TCC
    _tcc_write_RUNSTDBY(false);
}

inline void watch_enable_buzzer(void) {
    if (!hri_tcc_get_CTRLA_reg(TCC0, TCC_CTRLA_ENABLE)) {
        _watch_enable_tcc();
    }
}

inline void watch_set_buzzer_period(uint32_t period) {
    hri_tcc_write_PERBUF_reg(TCC0, period);
}

void watch_disable_buzzer(void) {
    _watch_disable_tcc();
}

inline void watch_set_buzzer_on(void) {
    gpio_set_pin_direction(BUZZER, GPIO_DIRECTION_OUT);
    gpio_set_pin_function(BUZZER, WATCH_BUZZER_TCC_PINMUX);
}

inline void watch_set_buzzer_off(void) {
    gpio_set_pin_direction(BUZZER, GPIO_DIRECTION_OFF);
    gpio_set_pin_function(BUZZER, GPIO_PIN_FUNCTION_OFF);
}

void watch_buzzer_play_note(BuzzerNote note, uint16_t duration_ms) {
    if (note == BUZZER_NOTE_REST) {
        watch_set_buzzer_off();
    } else {
        hri_tcc_write_PERBUF_reg(TCC0, NotePeriods[note]);
        hri_tcc_write_CCBUF_reg(TCC0, WATCH_BUZZER_TCC_CHANNEL, NotePeriods[note] / 2);
        watch_set_buzzer_on();
    }
    delay_ms(duration_ms);
    watch_set_buzzer_off();
}
