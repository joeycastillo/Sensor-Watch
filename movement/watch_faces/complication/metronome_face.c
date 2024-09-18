/*
 * MIT License
 *
 * Copyright (c) 2023 Austin Teets
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
#include "metronome_face.h"
#include "watch.h"

static const int8_t _sound_seq_start[] = {BUZZER_NOTE_C8, 2, 0};
static const int8_t _sound_seq_beat[] = {BUZZER_NOTE_C6, 2, 0};

void metronome_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(metronome_state_t));
        memset(*context_ptr, 0, sizeof(metronome_state_t));
    }
}

void metronome_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    metronome_state_t *state = (metronome_state_t *)context;
    movement_request_tick_frequency(2);
    if (state->bpm == 0) {
        state->count = 4;
        state->bpm = 120;
        state->soundOn = true;
    }
    state->mode = metWait;
    state->correction = 0;
    state->setCur = hundred;
}

static void _metronome_face_update_lcd(metronome_state_t *state) {
    char buf[11];
    if (state->soundOn) {
        watch_set_indicator(WATCH_INDICATOR_BELL);
    } else {
        watch_clear_indicator(WATCH_INDICATOR_BELL);
    }
    sprintf(buf, "MN %d %03d%s", state->count, state->bpm, "bp");
    watch_display_string(buf, 0);
}

static void _metronome_start_stop(metronome_state_t *state) {
    if (state->mode != metRun) {
        movement_request_tick_frequency(64);
        state->mode = metRun;
        watch_clear_display();
        double ticks = 3840.0 / (double)state->bpm;
        state->tick = (int) ticks;
        state->curTick = (int) ticks;
        state->halfBeat = (int)(state->tick/2);
        state->curCorrection = ticks - state->tick;
        state->correction = ticks - state->tick;
        state->curBeat = 1;
    } else {
        state->mode = metWait;
        movement_request_tick_frequency(2);
        _metronome_face_update_lcd(state);
    }
}

static void _metronome_tick_beat(metronome_state_t *state) {
    char buf[11];
    if (state->soundOn) {
        if (state->curBeat == 1) {
            watch_buzzer_play_sequence((int8_t *)_sound_seq_start, NULL);
        } else {
            watch_buzzer_play_sequence((int8_t *)_sound_seq_beat, NULL);
        }
    }
    sprintf(buf, "MN %d %03d%s", state->count, state->bpm, "bp");    
    watch_display_string(buf, 0);
}

static void _metronome_event_tick(uint8_t subsecond, metronome_state_t *state) {
    (void) subsecond;

    if (state->curCorrection >= 1) {
        state->curCorrection -= 1;
        state->curTick -= 1;
    }
    int diff = state->curTick - state->tick;
    if(diff == 0) {
        _metronome_tick_beat(state);
        state->curTick = 0;
        state->curCorrection += state->correction;
        if (state->curBeat < state->count ) {
            state->curBeat += 1;
        } else {
            state->curBeat = 1;
        }
    } else {
        if (state->curTick == state->halfBeat)  {
            watch_clear_display();
        }
        state->curTick += 1;
    }
}

static void _metronome_setting_tick(uint8_t subsecond, metronome_state_t *state) {
    char buf[13];
    sprintf(buf, "MN %d %03d%s", state->count, state->bpm, "bp"); 
    if (subsecond%2 == 0) {
        switch (state->setCur) {
            case hundred:
                buf[5] = ' ';
                break;
            case ten:
                buf[6] = ' ';
                break;
            case one:
                buf[7] = ' ';
                break;
            case count:
                buf[3] = ' ';
                break;
            case alarm:
                break;
        }
    }
    if (state->setCur == alarm) {
        sprintf(buf, "MN  8eep%s", state->soundOn ? "On" : " -");
    }
    if (state->soundOn) {
        watch_set_indicator(WATCH_INDICATOR_BELL);
    } else {
        watch_clear_indicator(WATCH_INDICATOR_BELL);
    }
    watch_display_string(buf, 0);
}

static void _metronome_update_setting(metronome_state_t *state) {
    char buf[13];
    switch (state->setCur) {
        case hundred:
            if (state->bpm < 100) {
                state->bpm += 100;
            } else {
                state->bpm -= 100;
            }
            break;
        case ten:
            if ((state->bpm / 10) % 10 < 9) {
                state->bpm += 10;
            } else {
                state->bpm -= 90;
            }
            break;
        case one:
            if (state->bpm%10 < 9) {
                state->bpm += 1;
            } else {
                state->bpm -= 9;
            }
            break;
        case count:
            if (state->count < 9) {
                state->count += 1;
            } else {
                state->count = 2;
            }
            break;
        case alarm:
            state->soundOn = !state->soundOn;
            break;
    }
    sprintf(buf, "MN %d %03d%s", state->count % 10, state->bpm, "bp"); 
    if (state->setCur == alarm) {
        sprintf(buf, "MN  8eep%s", state->soundOn ? "On" : " -");
    }
    if (state->soundOn) {
        watch_set_indicator(WATCH_INDICATOR_BELL);
    } else {
        watch_clear_indicator(WATCH_INDICATOR_BELL);
    }
    watch_display_string(buf, 0);
}

bool metronome_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    metronome_state_t *state = (metronome_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            _metronome_face_update_lcd(state);
            break;
        case EVENT_TICK:
            if (state->mode == metRun){
                _metronome_event_tick(event.subsecond, state);
            } else if (state->mode == setMenu) {
                _metronome_setting_tick(event.subsecond, state);
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            if (state->mode == setMenu) {
                _metronome_update_setting(state);
            } else {
                _metronome_start_stop(state);
            }
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            if (state->mode == setMenu) {
                if (state->setCur < alarm) {
                    state->setCur += 1;
                } else {
                    state->setCur = hundred;
                }
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (state->mode != metRun && state->mode != setMenu) {
                movement_request_tick_frequency(2);
                state->mode = setMenu;
                _metronome_face_update_lcd(state);
            } else if (state->mode == setMenu) {
                state->mode = metWait;
                _metronome_face_update_lcd(state);
            }
            break;
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_TIMEOUT:
            if (state->mode != metRun) {
                movement_move_to_face(0);
            }
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }
    return true;
}

void metronome_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

