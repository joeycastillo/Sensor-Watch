/*
 * MIT License
 *
 * Copyright (c) 2022 Andreas Nebinger
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

#include <stdlib.h>
#include <string.h>

#include "interval_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "watch_private_display.h"
#include "watch_buzzer.h"

typedef enum {
    interval_setting_0_timer_idx,
    interval_setting_1_clear_yn,
    interval_setting_2_warmup_minutes,
    interval_setting_3_warmup_seconds,
    interval_setting_4_work_minutes,
    interval_setting_5_work_seconds,
    interval_setting_6_work_rounds,
    interval_setting_7_break_minutes,
    interval_setting_8_break_seconds,
    interval_setting_9_full_rounds,
    interval_setting_10_cooldown_minutes,
    interval_setting_11_cooldown_seconds,
    interval_setting_max
} interval_setting_idx_t;

#define INTERVAL_FACE_STATE_DEFAULT "IT"    // Interval Timer
#define INTERVAL_FACE_STATE_WARMUP "PR"     // PRepare / warm up
#define INTERVAL_FACE_STATE_WORK "WO"       // WOrk
#define INTERVAL_FACE_STATE_BREAK "BR"      // BReak
#define INTERVAL_FACE_STATE_COOLDOWN "CD"   // CoolDown

// Define some default timer settings. Each timer is described in an array like this: 
//      1. warm-up seconds,
//      2. work time (seconds/minutes)
//      3. break time (seconds/minutes)
//      4. full rounds (0 = no limit)
//      5. cooldown seconds
// Work time and break time: positive number = seconds, negative number = minutes
static const int8_t _default_timers[6][5] = {{0, 40, 20, 0, 0},
                                            {0, 45, 15, 0, 0},
                                            {10, 20, 10, 8, 10},
                                            {0, 35, 0, 0, 0},
                                            {0, -25, -5, 0, 0},
                                            {0, -20, -5, 0, 0}};

static const uint8_t _intro_segdata[4][2] = {{1, 8}, {0, 8}, {0, 7}, {1, 7}};
static const uint8_t _blink_idx[] = {3, 9, 4, 6, 4, 6, 8, 4, 6, 8, 4, 6};
static const uint8_t _setting_page_idx[] = {1, 0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4};
static const int8_t _sound_seq_warmup[] = {BUZZER_NOTE_F6, 8, BUZZER_NOTE_REST, 1, -2, 3, 0};
static const int8_t _sound_seq_work[] = {BUZZER_NOTE_F6, 8, BUZZER_NOTE_REST, 1, -2, 2, BUZZER_NOTE_C7, 24, 0};
static const int8_t _sound_seq_break[] = {BUZZER_NOTE_B6, 15, BUZZER_NOTE_REST, 1, -2, 1, BUZZER_NOTE_B6, 16, 0};
static const int8_t _sound_seq_cooldown[] = {BUZZER_NOTE_C7, 15, BUZZER_NOTE_REST, 1, -2, 1, BUZZER_NOTE_C7, 24, 0};
static const int8_t _sound_seq_finish[] = {BUZZER_NOTE_C7, 6, BUZZER_NOTE_E7, 6, BUZZER_NOTE_G7, 6, BUZZER_NOTE_C8, 18, 0};

static interval_setting_idx_t _setting_idx;
static int8_t _ticks;
static bool _erase_timer_flag;
static uint32_t _target_ts;
static uint32_t _now_ts;
static uint32_t _paused_ts;
static uint8_t _timer_work_round;
static uint8_t _timer_full_round;
static uint8_t _timer_run_state;

static inline void _inc_uint8(uint8_t *value, uint8_t step, uint8_t max) {
    *value += step;
    if (*value >= max) *value = 0;
}

static uint32_t _get_now_ts() {
    // returns the current date time as unix timestamp
    watch_date_time now = watch_rtc_get_date_time();
    return watch_utility_date_time_to_unix_time(now, 0);
}

static inline void _button_beep(movement_settings_t *settings) {
    // play a beep as confirmation for a button press (if applicable)
    if (settings->bit.button_should_sound) watch_buzzer_play_note(BUZZER_NOTE_C7, 50);
}

static void _timer_write_info(interval_face_state_t *state, char *buf, uint8_t timer_page) {
    // fill display string with requested timer information
    switch (timer_page) {
    case 0:
        // clear timer?
        sprintf(buf, "%2s %1dCLEARn", INTERVAL_FACE_STATE_DEFAULT, state->timer_idx + 1);
        if (_erase_timer_flag) buf[9] = 'y';
        watch_clear_colon();
        break;
    case 1:
        // warmup time info
        sprintf(buf, "%2s %1d%02d%02d  ", INTERVAL_FACE_STATE_WARMUP, state->timer_idx + 1, 
            state->timer[state->timer_idx].warmup_minutes, 
            state->timer[state->timer_idx].warmup_seconds);
        break;
    case 2:
        // work interval info
        sprintf(buf, "%2s %1d%02d%02d%2d", INTERVAL_FACE_STATE_WORK, state->timer_idx + 1, 
            state->timer[state->timer_idx].work_minutes, 
            state->timer[state->timer_idx].work_seconds,
            state->timer[state->timer_idx].work_rounds);
        break;
    case 3:
        // break interval info
        sprintf(buf, "%2s %1d%02d%02d%2d", INTERVAL_FACE_STATE_BREAK, state->timer_idx + 1, 
            state->timer[state->timer_idx].break_minutes, 
            state->timer[state->timer_idx].break_seconds,
            state->timer[state->timer_idx].full_rounds);
        if (!state->timer[state->timer_idx].full_rounds) buf[9] = '-';
        break;
    case 4:
        // cooldown time info
        sprintf(buf, "%2s %1d%02d%02d  ", INTERVAL_FACE_STATE_COOLDOWN ,state->timer_idx + 1, 
            state->timer[state->timer_idx].cooldown_minutes, 
            state->timer[state->timer_idx].cooldown_seconds);
        break;
    default:
        break;
    }
}

static void _face_draw(interval_face_state_t *state, uint8_t subsecond) {
    // draws current face state
    if (!state->is_active) return;
    char buf[14];
    buf[0] = 0;
    uint8_t tmp;
    if (state->face_state == interval_state_waiting && _ticks >= 0) {
        // play info slideshow for current timer
        int8_t ticks = _ticks % 12;
        if (ticks == 0) {
            if ((state->timer[state->timer_idx].warmup_minutes + state->timer[state->timer_idx].warmup_seconds) == 0) {
                // skip warmup info if there is none for this timer
                ticks = 3;
                _ticks += 3;
            }
        }
        tmp = ticks / 3 + 1;
        _timer_write_info(state, buf, tmp);
        // don't show '1 round' when displaying workout time to avoid detail overload
        if (tmp == 2 && state->timer[state->timer_idx].work_rounds == 1) buf[9] = ' ';
        // blink colon
        if (subsecond % 2 == 0 && _ticks < 24) watch_clear_colon();
        else watch_set_colon();
    } else if (state->face_state == interval_state_setting) {
        if (_setting_idx == interval_setting_0_timer_idx) {
            if ((state->timer[state->timer_idx].warmup_minutes + state->timer[state->timer_idx].warmup_seconds) == 0)
                tmp = 1;
            else
                tmp = 2;
        } else {
            tmp = _setting_page_idx[_setting_idx];
        }
        _timer_write_info(state, buf, tmp);
        // blink at cursor position
        if (subsecond % 2 && _ticks != -2) {
            buf[_blink_idx[_setting_idx]] = ' ';
            if (_blink_idx[_setting_idx] % 2 == 0) buf[_blink_idx[_setting_idx] + 1] = ' ';
        }
        // show lap indicator only when rounds are set
        if (_setting_idx == interval_setting_6_work_rounds || _setting_idx == interval_setting_9_full_rounds)
            watch_set_indicator(WATCH_INDICATOR_LAP);
        else 
            watch_clear_indicator(WATCH_INDICATOR_LAP);
    } else if (state->face_state == interval_state_running || state->face_state == interval_state_pausing) {
        tmp = _timer_full_round;
        switch (_timer_run_state) {
        case 0:
            sprintf(buf, INTERVAL_FACE_STATE_WARMUP);
            break;
        case 1:
            sprintf(buf, INTERVAL_FACE_STATE_WORK);
            if (state->timer[state->timer_idx].work_rounds > 1) tmp = _timer_work_round;
            break;
        case 2:
            sprintf(buf, INTERVAL_FACE_STATE_BREAK);
            break;
        case 3:
            sprintf(buf, INTERVAL_FACE_STATE_COOLDOWN);
            break;
        default:
            break;
        }
        div_t delta;
        
        if (state->face_state == interval_state_pausing) {
            // pausing
            delta = div(_target_ts - _paused_ts, 60);
            // blink the bell icon
            if (_now_ts % 2) watch_set_indicator(WATCH_INDICATOR_BELL);
            else watch_clear_indicator(WATCH_INDICATOR_BELL);
        } else
            // running
            delta = div(_target_ts - _now_ts, 60);
        sprintf(&buf[2], " %1d%02d%02d%2d", state->timer_idx + 1, delta.quot, delta.rem, tmp + 1);
    }
    // write out to lcd
    if (buf[0]) {
        watch_display_character(buf[0], 0);
        watch_display_character(buf[1], 1);
        // set the bar for the i-like symbol on position 2
        watch_set_pixel(2, 9);
        // display the rest of the string
        watch_display_string(&buf[3], 3);
    }
}

static void _initiate_setting(interval_face_state_t *state, uint8_t subsecond) {
    state->face_state = interval_state_setting;
    _setting_idx = interval_setting_0_timer_idx;
    _ticks = 0;
    _erase_timer_flag = false;
    watch_set_colon();
    movement_request_tick_frequency(4);
    _face_draw(state, subsecond);
}

static void _resume_setting(interval_face_state_t *state, uint8_t subsecond) {
    state->face_state = interval_state_waiting;
    _ticks = 0;
    _face_draw(state, subsecond);
    movement_request_tick_frequency(2);
    watch_clear_indicator(WATCH_INDICATOR_LAP);
}

static void _abort_quick_ticks() {
    if (_ticks == -2) {
        _ticks = -1;
        movement_request_tick_frequency(4);
    }
}

static void _handle_alarm_button(interval_face_state_t *state) {
    // handles the alarm button press and alters the corresponding timer settings
    switch (_setting_idx) {
    case interval_setting_0_timer_idx:
        _inc_uint8(&state->timer_idx, 1, INTERVAL_TIMERS);
        _erase_timer_flag = false;
        break;
    case interval_setting_1_clear_yn:
        _erase_timer_flag ^= 1;
        break;
    case interval_setting_2_warmup_minutes:
        _inc_uint8(&state->timer[state->timer_idx].warmup_minutes, 1, 60);
        break;
    case interval_setting_3_warmup_seconds:
        _inc_uint8(&state->timer[state->timer_idx].warmup_seconds, 5, 60);
        break;
    case interval_setting_4_work_minutes:
        _inc_uint8(&state->timer[state->timer_idx].work_minutes, 1, 60);
        if (state->timer[state->timer_idx].work_rounds == 0) state->timer[state->timer_idx].work_rounds = 1;
        break;
    case interval_setting_5_work_seconds:
        _inc_uint8(&state->timer[state->timer_idx].work_seconds, 5, 60);
        if (state->timer[state->timer_idx].work_rounds == 0) state->timer[state->timer_idx].work_rounds = 1;
        break;
    case interval_setting_6_work_rounds:
        _inc_uint8(&state->timer[state->timer_idx].work_rounds, 1, 100);
        break;
    case interval_setting_7_break_minutes:
        _inc_uint8(&state->timer[state->timer_idx].break_minutes, 1, 60);
        break;
    case interval_setting_8_break_seconds:
        _inc_uint8(&state->timer[state->timer_idx].break_seconds, 5, 60);
        break;
    case interval_setting_9_full_rounds:
        _inc_uint8(&state->timer[state->timer_idx].full_rounds, 1, 100);
        break;
    case interval_setting_10_cooldown_minutes:
        _inc_uint8(&state->timer[state->timer_idx].cooldown_minutes, 1, 60);
        break;
    case interval_setting_11_cooldown_seconds:
        _inc_uint8(&state->timer[state->timer_idx].cooldown_seconds, 5, 60);
        break;
    default:
        break;
    }
}

static void _set_next_timestamp(interval_face_state_t *state) {
    // set next timestamp for the running timer, set background task and pay sound sequence
    uint16_t delta = 0;
    int8_t *sound_seq;
    interval_timer_setting_t timer = state->timer[state->timer_idx];
    switch (_timer_run_state) {
    case 0:
        delta = timer.warmup_minutes * 60 + timer.warmup_seconds;
        sound_seq = (int8_t *)_sound_seq_warmup;
        break;
    case 1:
        delta = timer.work_minutes * 60 + timer.work_seconds;
        sound_seq = (int8_t *)_sound_seq_work;
        break;
    case 2:
        delta = timer.break_minutes * 60 + timer.break_seconds;
        sound_seq = (int8_t *)_sound_seq_break;
        break;
    case 3:
        delta = timer.cooldown_minutes * 60 + timer.cooldown_seconds;
        sound_seq = (int8_t *)_sound_seq_cooldown;
        break;
    default:
        sound_seq = NULL;
        break;
    }
    // failsafe
    if (delta <= 0) delta = 1;
    _target_ts += delta;
    // schedule next background task
    watch_date_time target_dt = watch_utility_date_time_from_unix_time(_target_ts, 0);
    movement_schedule_background_task_for_face(state->face_idx, target_dt);
    // play sound
    watch_buzzer_play_sequence(sound_seq, NULL);
}

static inline bool _is_timer_empty(interval_timer_setting_t *timer) {
    // checks if a timer is empty
    return (timer->warmup_minutes + timer->warmup_seconds 
        + timer->work_minutes + timer->work_seconds 
        + timer->break_minutes + timer->break_seconds
        + timer->cooldown_minutes + timer->cooldown_seconds == 0);
}

static void _init_timer_info(interval_face_state_t *state) {
    state->face_state = interval_state_waiting;
    _ticks = 0;
    if (state->is_active) movement_request_tick_frequency(2);
}

static void _abort_running_timer() {
    _timer_work_round = _timer_full_round = 0;
    _timer_run_state = 0;
    movement_cancel_background_task();
    watch_clear_indicator(WATCH_INDICATOR_BELL);
    watch_buzzer_play_note(BUZZER_NOTE_C8, 100);
}

static void _resume_paused_timer(interval_face_state_t *state) {
    // resume paused timer
    _now_ts = _get_now_ts();
    _target_ts += _now_ts - _paused_ts;
    watch_date_time target_dt = watch_utility_date_time_from_unix_time(_target_ts, 0);
    movement_schedule_background_task_for_face(state->face_idx, target_dt);
    state->face_state = interval_state_running;
    watch_set_indicator(WATCH_INDICATOR_BELL);
}

void interval_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr) {
    (void) settings;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(interval_face_state_t));
        interval_face_state_t *state = (interval_face_state_t *)*context_ptr;
        memset(*context_ptr, 0, sizeof(interval_face_state_t));
        state->face_idx = watch_face_index;
        // somehow the memset above doesn't to the trick. So set the state explicitly
        state->face_state = interval_state_waiting;
        for (uint8_t i = 0; i < INTERVAL_TIMERS; i++) state->timer[i].work_rounds = 1;
        // set up default timers
        for (uint8_t i = 0; i < 6; i++) {
            state->timer[i].warmup_seconds = _default_timers[i][0];
            if (_default_timers[i][1] < 0) state->timer[i].work_minutes = -_default_timers[i][1];
            else state->timer[i].work_seconds = _default_timers[i][1];
            state->timer[i].work_rounds = 1;
            if (_default_timers[i][2] < 0) state->timer[i].break_minutes = -_default_timers[i][2];
            else state->timer[i].break_seconds = _default_timers[i][2];
            state->timer[i].full_rounds = _default_timers[i][3];
            state->timer[i].cooldown_seconds = _default_timers[i][4];
        }
    }
}

void interval_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    interval_face_state_t *state = (interval_face_state_t *)context;
    _erase_timer_flag = false;
    state->is_active = true;
    if (state->face_state <= interval_state_waiting) {
        // initiate the intro loop
        state->face_state = interval_state_intro;
        _ticks = 0;
        movement_request_tick_frequency(8);
    } else watch_set_colon();
}

void interval_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    interval_face_state_t *state = (interval_face_state_t *)context;
    if (state->face_state <= interval_state_setting) state->face_state = interval_state_waiting;
    watch_set_led_off();
    movement_request_tick_frequency(1);
    state->is_active = false;
}

bool interval_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    interval_face_state_t *state = (interval_face_state_t *)context;
    interval_timer_setting_t *timer = &state->timer[state->timer_idx];

    switch (event.event_type) {
    case EVENT_TICK:
        if (state->face_state == interval_state_intro) {
            // play intro animation so the wearer knows the face
            if (_ticks == 4) {
                // transition to default view of current interval slot
                watch_set_colon();
                _init_timer_info(state);
                _face_draw(state, event.subsecond);
                break;
            } 
            watch_set_pixel(_intro_segdata[_ticks][0], _intro_segdata[_ticks][1]);
            _ticks++;
        } else if (state->face_state == interval_state_waiting && _ticks >= 0) {
            // play information slideshow for current interval timer
            _ticks++;
            if ((_ticks % 12 == 9) && (timer->cooldown_minutes + timer->cooldown_seconds == 0)) _ticks += 3;
            if (_ticks > 24) _ticks = -1;
            else _face_draw(state, event.subsecond);
        } else if (state->face_state == interval_state_setting) {
            if (_ticks == -2) {
                // fast counting
                _handle_alarm_button(state);
            }
            _face_draw(state, event.subsecond);
        } else if (state->face_state == interval_state_running || state->face_state == interval_state_pausing) {
            _now_ts = _get_now_ts();
            _face_draw(state, event.subsecond);
        }
        break;
    case EVENT_ACTIVATE:
        watch_display_string(INTERVAL_FACE_STATE_DEFAULT, 0);
        if (state->face_state) _face_draw(state, event.subsecond);
        break;
    case EVENT_LIGHT_BUTTON_UP:
        if (state->face_state == interval_state_setting) {
            if (_setting_idx == interval_setting_0_timer_idx) {
                // skip clear page if timer is empty
                if (_is_timer_empty(timer)) _setting_idx = interval_setting_1_clear_yn;
            } else if (_setting_idx == interval_setting_1_clear_yn) {
                watch_set_colon();
                if (_erase_timer_flag) {
                    // clear the current timer
                    memset((void *)timer, 0, sizeof(interval_timer_setting_t));
                    // play a short beep as confirmation
                    watch_buzzer_play_note(BUZZER_NOTE_C8, 70);
                }
            } else if (_setting_idx == interval_setting_9_full_rounds && !timer->full_rounds) {
                // skip cooldown if full rounds are not limited
                _setting_idx = interval_setting_11_cooldown_seconds;
            }
            _setting_idx += 1;
            if (_setting_idx == interval_setting_max) {
                // we have done a full settings circle: resume setting
                _resume_setting(state, event.subsecond);
            } else 
                _face_draw(state, event.subsecond);
        } else {
            movement_illuminate_led();
        }
        break;
    case EVENT_LIGHT_LONG_PRESS:
        _button_beep(settings);
        if (state->face_state == interval_state_setting) {
            _resume_setting(state, event.subsecond);
        } else {
            if (state->face_state >= interval_state_running ) _abort_running_timer();
            _initiate_setting(state, event.subsecond);
        }
        break;
    case EVENT_ALARM_BUTTON_UP:
        switch (state->face_state) {
        case interval_state_waiting:
            // cycle through timers
            _inc_uint8(&state->timer_idx, 1, INTERVAL_TIMERS);
            _ticks = 0;
            _face_draw(state, event.subsecond);
            break;
        case interval_state_setting:
            // alter timer settings
            _abort_quick_ticks();
            _handle_alarm_button(state);
            break;
        case interval_state_running:
            // pause timer
            _button_beep(settings);
            _paused_ts = _get_now_ts();
            state->face_state = interval_state_pausing;
            movement_cancel_background_task();
            _face_draw(state, event.subsecond);
            break;
        case interval_state_pausing:
            // resume paused timer
            _button_beep(settings);
            _resume_paused_timer(state);
            _face_draw(state, event.subsecond);
            break;
        default:
            break;
        }
        break;
    case EVENT_ALARM_LONG_PRESS:
        if (state->face_state == interval_state_setting && _setting_idx != interval_setting_1_clear_yn) {
            // initiate quick counting
            _ticks = -2;
            movement_request_tick_frequency(8);
            break;
        } else if (state->face_state <= interval_state_waiting) {
            if (_is_timer_empty(timer)) {
                // jump back to timer #1
                _button_beep(settings);
                state->timer_idx = 0;
                _init_timer_info(state);
            } else {
                // set initial state and start timer
                _timer_work_round = _timer_full_round = 0;
                if (timer->warmup_minutes + timer->warmup_seconds) _timer_run_state = 0;
                else if (timer->work_minutes + timer->work_seconds) _timer_run_state = 1;
                else if (timer->break_minutes + timer->break_seconds) _timer_run_state = 2;
                else if (timer->cooldown_minutes + timer->cooldown_seconds) _timer_run_state = 3;
                movement_request_tick_frequency(1);
                _now_ts = _get_now_ts();
                _target_ts = _now_ts;
                _set_next_timestamp(state);
                state->face_state = interval_state_running;
                watch_set_indicator(WATCH_INDICATOR_BELL);
                watch_set_colon();
            }
        } else if (state->face_state == interval_state_running) {
            // stop the timer
            _abort_running_timer();
            _init_timer_info(state);
        } else if (state->face_state == interval_state_pausing) {
            // resume paused timer
            _button_beep(settings);
            _resume_paused_timer(state);
        }
        _face_draw(state, event.subsecond);
        break;
    case EVENT_ALARM_LONG_UP:
        _abort_quick_ticks();
        break;
    case EVENT_BACKGROUND_TASK:
        // find the next timestamp or end the timer
        if (_timer_run_state == 0) {
            // warmup finished
            if (timer->work_minutes + timer->work_seconds) _timer_run_state = 1;
            else if (timer->break_minutes + timer->break_seconds) _timer_run_state = 2;
            else if (timer->cooldown_minutes + timer->cooldown_seconds) _timer_run_state = 3;
            else _timer_run_state = 4;
        } else if (_timer_run_state == 1) {
            // work finished
            _timer_work_round++;
            if (_timer_work_round == timer->work_rounds) {
                _timer_work_round = 0;
                if (timer->break_minutes + timer->break_seconds && (timer->full_rounds == 0 
                    || (timer->full_rounds && _timer_full_round + 1 < timer->full_rounds))) _timer_run_state = 2;
                else {
                    _timer_full_round++;
                    if (timer->full_rounds && _timer_full_round == timer->full_rounds) {
                        if (timer->cooldown_minutes + timer->cooldown_seconds) _timer_run_state = 3;
                        else _timer_run_state = 4;
                    } else _timer_run_state = 1;
                }
            }
        } else if (_timer_run_state == 2) {
            // break finished
            _timer_full_round++;
            _timer_work_round = 0;
            if (timer->full_rounds && _timer_full_round == timer->full_rounds) {
                if (timer->cooldown_minutes + timer->cooldown_seconds) _timer_run_state = 3;
                else _timer_run_state = 4;
                _timer_full_round--;
            } else {
                if (timer->work_minutes + timer->work_seconds) _timer_run_state = 1;
            }
        } else if (_timer_run_state == 3)
            // cooldown finished
            _timer_run_state = 4;
        // set next timestamp or play final sound sequence
        if (_timer_run_state < 4) {
            // transition to next timer phase
            _set_next_timestamp(state);
        } else {
            // timer has finished
            state->face_state = interval_state_waiting;
            _init_timer_info(state);
            _face_draw(state, event.subsecond);
            watch_buzzer_play_sequence((int8_t *)_sound_seq_finish, NULL);
        }
        break;
    case EVENT_TIMEOUT:
        if (state->face_state != interval_state_running) movement_move_to_face(0);
        break;
    case EVENT_LIGHT_BUTTON_DOWN:
        // don't light up every time light is hit
        break;
    default:
        movement_default_loop_handler(event, settings);
        break;
    }
    return true;
}
