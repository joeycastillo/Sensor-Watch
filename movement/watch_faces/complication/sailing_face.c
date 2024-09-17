/*
 * MIT License
 *
 * Copyright (c) 2023 Jan H. Voigt
 * Copyright (c) 2022 Wesley Ellis
 * Copyright (c) 2022 Niclas Hoyer
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
#include "sailing_face.h"
#include "watch.h"
#include "watch_utility.h"

#define sl_SELECTIONS 6
#define DEFAULT_MINUTES { 5,4,1,0,0,0 }

static inline int32_t get_tz_offset(movement_settings_t *settings) {
    return movement_timezone_offsets[settings->bit.time_zone] * 60;
}

static int lap = 0;
bool ringflag = false;
int8_t double_beep[] = {BUZZER_NOTE_C8, 4, BUZZER_NOTE_REST, 5, BUZZER_NOTE_C8, 5, 0};
int8_t single_beep[] = {BUZZER_NOTE_C8, 4, 0};
int8_t long_beep[] = {BUZZER_NOTE_C8, 40, 0};
int beepseconds[] = {600, 540, 480, 420, 360, 300, 240, 180, 120, 60, 30, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; //seconds before start that can trigger the buzzer. Every whole minute, 30s before start & 10s countdown.
int beepseconds_size = sizeof(beepseconds) / sizeof(int);
int beepflag = 0;
int alarmflag = 3;

static void reset(sailing_state_t *state) {
    state->index = 0;
    state->mode = sl_waiting;
    movement_cancel_background_task();
    watch_clear_indicator(WATCH_INDICATOR_LAP);
    beepflag = 0;
    ringflag = false;
}

static void counting(sailing_state_t *state) {
    state->mode = sl_counting;  
    movement_cancel_background_task();
    watch_set_indicator(WATCH_INDICATOR_LAP);
}

static void draw(sailing_state_t *state, uint8_t subsecond, movement_settings_t *settings) {
    (void) settings;

    char tmp[24];
    char buf[16];

    uint32_t delta;
    div_t result;
    uint8_t hrs, min, sec;

    switch (state->mode) {
        case sl_running:
            if (state->now_ts > state->target_ts) {
                delta = 0;
                counting(state); //in case buttons are pressed while sound is played (esp. in the last 10s), the timing of ring might be thrown off. Beep stops and the switch to counting doesn't occur. temporary fix/safety net. 
            } else {
                delta = state->target_ts - state->now_ts;
            }
            result = div(delta, 60);
            min = result.quot;
            sec = result.rem;

            if (min > 0) {
                sprintf(buf, "SA1L  %2d%02d", min, sec);
            } else {
                sprintf(buf, "SA1L  %2d  ", sec);
            }
            break;
        case sl_waiting:
            sprintf(buf, "SA1L  %2d%02d", state->minutes[0], 0);
            break;
        case sl_setting:
            // this sprintf to a larger tmp is to guarantee that no buffer overflows
            // occur here (and to squelch the corresponding compiler warning)
            if (state->minutes[0] == 10) { //print 10 vertically.
                sprintf(tmp, "SA1L %1d%1d%1d%1d%1d",
                    state->minutes[1],
                    state->minutes[2],
                    state->minutes[3],
                    state->minutes[4],
                    state->minutes[5]
                );
                memcpy(buf, tmp, sizeof(buf));
                if (subsecond % 2) {
                    buf[4 + state->selection] = ' ';
                }
                watch_display_string(buf, 0);
                if (!(subsecond % 2) || state->selection != 0) {
                    watch_set_pixel(0, 18);
                    watch_set_pixel(0, 19);
                    watch_set_pixel(1, 18);
                    watch_set_pixel(1, 19);
                }
                return;
            }
            sprintf(tmp, "SA1L%1d%1d%1d%1d%1d%1d",
                state->minutes[0],
                state->minutes[1],
                state->minutes[2],
                state->minutes[3],
                state->minutes[4],
                state->minutes[5]
            );
            memcpy(buf, tmp, sizeof(buf));
            if (subsecond % 2) {
                buf[4 + state->selection] = ' ';
            }
            break;
        case sl_counting:
            delta = state->now_ts - state->target_ts;
            if (state->now_ts <= state->target_ts) {
                sprintf(buf, "SA1L  %2d  ", 0);
            }
            else {
                result = div(delta, 3600);
                hrs = result.quot;
                delta -= 60*hrs;
                result = div(delta, 60);
                min = result.quot;
                sec = result.rem;
                sprintf(buf, "SL%2d%2d%02d%02d", lap, hrs, min, sec);//implement counting
                if (hrs > 23) {
                    reset(state);
                }
            }
            break;
    }
    watch_display_string(buf, 0);
}

static void ring(sailing_state_t *state, movement_settings_t *settings) {    
// if ring is called in background (while on another face), a button press can interrupt and cancel the execution.
// To reduce the probability of cancelling all future alarms, the new alarm is set as soon as possible after calling ring.
    movement_cancel_background_task();
    if (beepflag + 1 == beepseconds_size) { //equivalent to (beepflag + 1 == sizeof(beepseconds) / sizeof(int)) but without needing to divide here => quicker
        if (alarmflag != 0){
            watch_buzzer_play_sequence(long_beep, NULL);
        }
        movement_cancel_background_task();
        counting(state);
        return;
    }
    state->nextbeep_ts = state->target_ts - beepseconds[beepflag+1];
    watch_date_time target_dt = watch_utility_date_time_from_unix_time(state->nextbeep_ts, get_tz_offset(settings));
    movement_schedule_background_task_for_face(state->watch_face_index, target_dt);
//background task is set, now we have time to play the tune. If this is cancelled accidentally, the next alarm will still ring. Sound is implemented non-blocking, so that neither buttons nor display output are compromised.
    for (int i = 0; i < 5; i++) {
        if (beepseconds[beepflag] == 60 * state->minutes[i]) {
            if (alarmflag > 1) {
                watch_buzzer_play_sequence((int8_t *)double_beep, NULL);
            }   
            ringflag = true;           
        }
    }
    if (!ringflag) {
        if (alarmflag == 3) {
            watch_buzzer_play_sequence((int8_t *)single_beep, NULL);
        }
    }
    ringflag = false;
    beepflag++;
}

static void start(sailing_state_t *state, movement_settings_t *settings) {//gets called by starting / switching to next signal
    while (beepseconds[beepflag] < state->minutes[state->index]*60) {
        state->index++;
    }
    while (beepseconds[beepflag] > state->minutes[state->index]*60) {
        beepflag++;
    }
    if (state->index > 5 || state->minutes[state->index] == 0) {
        watch_date_time now = watch_rtc_get_date_time();
        state->now_ts = watch_utility_date_time_to_unix_time(now, get_tz_offset(settings));
        state->target_ts = state->now_ts;
        if (alarmflag != 0){
            watch_buzzer_play_sequence(long_beep, NULL);
        }
        counting(state);
        return;
    }
    movement_request_tick_frequency(1); //synchronises tick with the moment the button was pressed. Solves 1s offset between sound and display, solves up to +-0.5s offset between button action and display.
    state->mode = sl_running;
    watch_date_time now = watch_rtc_get_date_time();
    state->now_ts = watch_utility_date_time_to_unix_time(now, get_tz_offset(settings));
    state->target_ts = watch_utility_offset_timestamp(state->now_ts, 0, state->minutes[state->index], 0);
    ring(state, settings);
}

static void settings_increment(sailing_state_t *state) {
    state->minutes[state->selection] += 1;
    uint8_t max = 11;
    if (state->selection > 0) {
        max = state->minutes[state->selection-1];
    }
    if (state->minutes[state->selection] >= max) {
        state->minutes[state->selection] = 0;
    }
    // ensure that minutes are decreasing
    if (state->selection < 5) {
        for (uint8_t i = 0; i < 5; i++) {
            if (state->minutes[i+1] >= state->minutes[i]) {
                if (state->minutes[i] > 0) {
                    state->minutes[i+1] = state->minutes[i] - 1;
                } else {
                    state->minutes[i+1] = 0;
                }
            }
        }
    }
    return;
}

void sailing_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(sailing_state_t));
        sailing_state_t *state = (sailing_state_t *)*context_ptr;
        memset(*context_ptr, 0, sizeof(sailing_state_t));
        static const uint8_t default_minutes[6] = DEFAULT_MINUTES;
        memcpy(&state->minutes, default_minutes, sizeof(default_minutes));
        state->watch_face_index = watch_face_index;
    }
}

void sailing_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    sailing_state_t *state = (sailing_state_t *)context;
    if(state->mode == sl_running) {
        watch_date_time now = watch_rtc_get_date_time();
        state->now_ts = watch_utility_date_time_to_unix_time(now, get_tz_offset(settings));
    }
    if(state->mode == sl_counting) {
        watch_date_time now = watch_rtc_get_date_time();
        state->now_ts = watch_utility_date_time_to_unix_time(now, get_tz_offset(settings));
        watch_set_indicator(WATCH_INDICATOR_LAP);
    }
    switch (alarmflag) {
        case 0: //no sound
            watch_clear_indicator(WATCH_INDICATOR_BELL);
            watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
            break;
        case 1: //sound at start only
            watch_set_indicator(WATCH_INDICATOR_BELL);
            watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
            break;
        case 2: //sound at set minutes
            watch_clear_indicator(WATCH_INDICATOR_BELL);
            watch_set_indicator(WATCH_INDICATOR_SIGNAL);
            break;
        case 3: //sound at every minute, 30s, 10-0s
            watch_set_indicator(WATCH_INDICATOR_BELL);
            watch_set_indicator(WATCH_INDICATOR_SIGNAL);
            break;
    }
}


bool sailing_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    sailing_state_t *state = (sailing_state_t *)context;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
            draw(state, event.subsecond, settings);
            break;
        case EVENT_TICK:
            if (state->mode == sl_running || state->mode == sl_counting) {
                state->now_ts++;
            }
            draw(state, event.subsecond, settings);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if (state->mode == sl_running) {
                reset(state);
            }
            if (state->mode == sl_counting) {
                reset(state);
            }
            if (state->mode == sl_setting) {
                if (alarmflag == 3) {
                    alarmflag = 0;
                }
                else {
                    alarmflag++;
                }
                switch (alarmflag) {
                    case 0: //no sound
                        watch_clear_indicator(WATCH_INDICATOR_BELL);
                        watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
                        break;
                    case 1: //sound at start only
                        watch_set_indicator(WATCH_INDICATOR_BELL);
                        watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
                        break;
                    case 2: //sound at set minutes
                        watch_clear_indicator(WATCH_INDICATOR_BELL);
                        watch_set_indicator(WATCH_INDICATOR_SIGNAL);
                        break;
                    case 3: //sound at every minute, 30s, 10-0s
                        watch_set_indicator(WATCH_INDICATOR_BELL);
                        watch_set_indicator(WATCH_INDICATOR_SIGNAL);
                        break;
                }
            }
            break;
        case EVENT_LIGHT_BUTTON_UP:
            switch(state->mode) {
                case sl_running:
                    movement_illuminate_led();
                    break;
                case sl_waiting:
                    state->mode = sl_setting;
                    movement_request_tick_frequency(4);
                    break;
                case sl_setting:
                    state->selection++;
                    if(state->selection >= sl_SELECTIONS) {
                        state->selection = 0;
                        state->mode = sl_waiting;
                        movement_request_tick_frequency(1);
                    }
                    break;
                case sl_counting:
                    movement_illuminate_led();
                    break;
            }
            draw(state, event.subsecond, settings);
            break;
        case EVENT_ALARM_BUTTON_UP:
            switch(state->mode) {
                case sl_running:
                    start(state, settings);
                    break;
                case sl_waiting:
                    start(state, settings);
                    break;
                case sl_setting:
                    settings_increment(state);
                    break;
                case sl_counting:
                    //implement lap counting up to 39
                    if (lap <39){
                        lap++;
                    }
                    break;
            }
            draw(state, event.subsecond, settings);
            break;
        case EVENT_BACKGROUND_TASK:
            ring(state, settings);
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (state->mode == sl_setting) {
                    static const uint8_t default_minutes[6] = DEFAULT_MINUTES;
                    memcpy(&state->minutes, default_minutes, sizeof(default_minutes));
                    state->index = 0;
                    draw(state, event.subsecond, settings);
                    break;
            }
            if (state->mode == sl_counting) {
                lap = 0;
            }
            break;
        case EVENT_TIMEOUT:
            if (state->mode != sl_running && state->mode != sl_counting) {
                movement_move_to_face(0);
            }
            break;
        case EVENT_LOW_ENERGY_UPDATE:
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

void sailing_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    sailing_state_t *state = (sailing_state_t *)context;
    if (state->mode == sl_setting) {
        state->selection = 0;
        state->mode = sl_waiting;
    }
}
