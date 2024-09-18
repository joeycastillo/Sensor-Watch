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
#include "watch_private_buzzer.h"
#include "watch_main_loop.h"

#include <emscripten.h>
#include <emscripten/html5.h>

static bool buzzer_enabled = false;
static uint32_t buzzer_period;

void cb_watch_buzzer_seq(void *userData);

static uint16_t _seq_position;
static int8_t _tone_ticks, _repeat_counter;
static long _em_interval_id = 0;
static int8_t *_sequence;
static void (*_cb_finished)(void);

static inline void _em_interval_stop() {
    emscripten_clear_interval(_em_interval_id);
    _em_interval_id = 0;
}

void watch_buzzer_play_sequence(int8_t *note_sequence, void (*callback_on_end)(void)) {
    if (_em_interval_id) _em_interval_stop();
    watch_set_buzzer_off();
    _sequence = note_sequence;
    _cb_finished = callback_on_end;
    _seq_position = 0;
    _tone_ticks = 0;
    _repeat_counter = -1;
    // prepare buzzer
    watch_enable_buzzer();
    // initiate 64 hz callback
    _em_interval_id = emscripten_set_interval(cb_watch_buzzer_seq, (double)(1000/64), (void *)NULL);
}

void cb_watch_buzzer_seq(void *userData) {
    // callback for reading the note sequence
    (void) userData;
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
            if (note == BUZZER_NOTE_REST) {
                watch_set_buzzer_off();
            } else {
                watch_set_buzzer_period(NotePeriods[note]);
                watch_set_buzzer_on();
            }
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
    if (_em_interval_id) _em_interval_stop();
    watch_set_buzzer_off();
}

void watch_enable_buzzer(void) {
    buzzer_enabled = true;
    buzzer_period = NotePeriods[BUZZER_NOTE_A4];

    EM_ASM({
        Module['audioContext'] = new (window.AudioContext || window.webkitAudioContext)();
    });
}

void watch_set_buzzer_period(uint32_t period) {
    if (!buzzer_enabled) return;
    buzzer_period = period;
}

void watch_disable_buzzer(void) {
    buzzer_enabled = false;
    buzzer_period = NotePeriods[BUZZER_NOTE_A4];

    EM_ASM({
        if (Module['audioContext']) {
            Module['audioContext'].close();
            Module['audioContext'] = null;
        }
    });
}

void watch_set_buzzer_on(void) {
    if (!buzzer_enabled) return;

    EM_ASM({
        const audioContext = Module['audioContext'];
        if (!audioContext) return;

        if (!(audioContext._oscillator && audioContext._gain)) {
            const oscillator = audioContext.createOscillator();
            const gain = audioContext.createGain();
            oscillator.type = 'triangle';
            oscillator.connect(gain);
            gain.connect(audioContext.destination);
            oscillator.start(0);

            audioContext._oscillator = oscillator;
            audioContext._gain = gain;
        }

        audioContext._oscillator.frequency.value = 1e6/$0;
        audioContext._gain.gain.value = volumeGain;
    }, buzzer_period);
}

void watch_set_buzzer_off(void) {
    if (!buzzer_enabled) return;

    EM_ASM({
        const audioContext = Module['audioContext'];
        if (audioContext && audioContext._gain) {
            audioContext._gain.gain.value = 0;
        }
    });
}

void watch_buzzer_play_note(BuzzerNote note, uint16_t duration_ms) {
    if (note == BUZZER_NOTE_REST) {
        watch_set_buzzer_off();
    } else {
        watch_set_buzzer_period(NotePeriods[note]);
        watch_set_buzzer_on();
    }

    main_loop_sleep(duration_ms);
    watch_set_buzzer_off();
}
