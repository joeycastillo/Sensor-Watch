/*
 * MIT License
 *
 * Copyright (c) 2023 Bernd Plontsch
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
#include "breathing_face.h"
#include "watch.h"

#define BREATHING_DEFAULT_SOUND_ON true
#define BREATHING_MIN_LENGTH 4
#define BREATHING_DEFAULT_LENGTH 4
#define BREATHING_MAX_LENGTH 10

typedef struct {
    uint8_t ticks;
    uint8_t count_seconds;
    bool sound_on;
} breathing_state_t;

static void beep_in (void);
static void beep_in_hold (void);
static void beep_out (void);
static void beep_out_hold (void);

void breathing_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    // These next two lines just silence the compiler warnings associated with unused parameters.
    // We have no use for the settings or the watch_face_index, so we make that explicit here.
    (void) settings;
    (void) watch_face_index;
    // At boot, context_ptr will be NULL indicating that we don't have anyplace to store our context.
    if (*context_ptr == NULL) {
        // in this case, we allocate an area of memory sufficient to store the stuff we need to track.
        *context_ptr = malloc(sizeof(breathing_state_t));
    }
}

void breathing_face_activate(movement_settings_t *settings, void *context) {
    // same as above: silence the warning, we don't need to check the settings.
    (void) settings;
    // we do however need to set some things in our context. Here we cast it to the correct type...
    breathing_state_t *state = (breathing_state_t *)context;
    // ...and set the initial state of our watch face.
    state->ticks = 0;
    state->count_seconds = BREATHING_DEFAULT_LENGTH;
    state->sound_on = BREATHING_DEFAULT_SOUND_ON;
}

const int NOTE_LENGTH = 80;

void beep_in (void) {
        const BuzzerNote notes[] = {
            BUZZER_NOTE_C4,
            BUZZER_NOTE_D4,
            BUZZER_NOTE_E4,
        };
        const uint16_t durations[] = {
            NOTE_LENGTH,
            NOTE_LENGTH,
            NOTE_LENGTH
        };
        for(size_t i = 0, count = sizeof(notes) / sizeof(notes[0]); i < count; i++) {
            watch_buzzer_play_note(notes[i], durations[i]);
        }
}

void beep_in_hold (void) {
        const BuzzerNote notes[] = {
            BUZZER_NOTE_E4,
            BUZZER_NOTE_REST,
            BUZZER_NOTE_E4,
        };
        const uint16_t durations[] = {
            NOTE_LENGTH,
            NOTE_LENGTH * 2,
            NOTE_LENGTH,
        };
        for(size_t i = 0, count = sizeof(notes) / sizeof(notes[0]); i < count; i++) {
            watch_buzzer_play_note(notes[i], durations[i]);
        }
}

void beep_out (void) {
        const BuzzerNote notes[] = {
            BUZZER_NOTE_E4,
            BUZZER_NOTE_D4,
            BUZZER_NOTE_C4,
        };
        const uint16_t durations[] = {
            NOTE_LENGTH,
            NOTE_LENGTH,
            NOTE_LENGTH,
        };
        for(size_t i = 0, count = sizeof(notes) / sizeof(notes[0]); i < count; i++) {
            watch_buzzer_play_note(notes[i], durations[i]);
        }
}

void beep_out_hold (void) {
        const BuzzerNote notes[] = {
            BUZZER_NOTE_C4,
            BUZZER_NOTE_REST * 2,
            BUZZER_NOTE_C4,
        };
        const uint16_t durations[] = {
            NOTE_LENGTH,
            NOTE_LENGTH,
            NOTE_LENGTH,
        };
        for(size_t i = 0, count = sizeof(notes) / sizeof(notes[0]); i < count; i++) {
            watch_buzzer_play_note(notes[i], durations[i]);
        }
}

bool breathing_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    breathing_state_t *state = (breathing_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:

            if (state->sound_on == true) {
                watch_set_indicator(WATCH_INDICATOR_BELL); 
            } else {
                watch_clear_indicator(WATCH_INDICATOR_BELL); 
            }

            char buf[9];

            if (state->ticks == 0) {
                sprintf(buf, "%2iBreath", state->count_seconds);
            } else {
                uint8_t count = state->count_seconds - (state->ticks % state->count_seconds);
                switch (state->ticks / state->count_seconds) {
                    case 0: sprintf(buf, "%2iIn  %2i", state->count_seconds, count); break;
                    case 1: sprintf(buf, "%2iHold%2i", state->count_seconds, count); break;
                    case 2: sprintf(buf, "%2iOu t%2i", state->count_seconds, count); break;
                    case 3: sprintf(buf, "%2iHold%2i", state->count_seconds, count); break;
                }
            }

            if (state->sound_on && state->ticks % state->count_seconds == 0) {
                switch (state->ticks / state->count_seconds) {
                    case 0: beep_in(); break;
                    case 1: beep_in_hold(); break;
                    case 2: beep_out(); break;
                    case 3: beep_out_hold(); break;
                }
            }

            watch_display_string(buf, 2);

            // and increment it so that it will update on the next tick.
            state->ticks = (state->ticks + 1) % (state->count_seconds * 4);

            break;
        case EVENT_ALARM_BUTTON_UP:
            state->sound_on = !state->sound_on;            
             if (state->sound_on == true) {
                watch_set_indicator(WATCH_INDICATOR_BELL); 
            } else {
                watch_clear_indicator(WATCH_INDICATOR_BELL); 
            }
            break;
        case EVENT_LIGHT_LONG_PRESS:
            {
                uint8_t stage = state->ticks / state->count_seconds;
                uint8_t num = state->ticks % state->count_seconds;
                if (state->count_seconds++ > BREATHING_MAX_LENGTH) {
                    state->count_seconds = BREATHING_MIN_LENGTH;
                    state->ticks = 0;
                } else {
                    state->ticks = (stage * state->count_seconds) + num;
                }
                break;
            }
        case EVENT_LOW_ENERGY_UPDATE:
            // This low energy mode update occurs once a minute, if the watch face is in the
            // foreground when Movement enters low energy mode. We have the option of supporting
            // this mode, but since our watch face animates once a second, the "Hello there" face
            // isn't very useful in this mode. So we choose not to support it. (continued below)
            break;
        case EVENT_TIMEOUT:
            // ... Instead, we respond to the timeout event. This event happens after a configurable
            // interval on screen (1-30 minutes). The watch will give us this event as a chance to
            // resign control if we want to, and in this case, we do.
            // This function will return the watch to the first screen (usually a simple clock),
            // and it will do it long before the watch enters low energy mode. This ensures we
            // won't be on screen, and thus opts us out of getting the EVENT_LOW_ENERGY_UPDATE above.
            
            // movement_move_to_face(0);
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void breathing_face_resign(movement_settings_t *settings, void *context) {
    // our watch face, like most watch faces, has nothing special to do when resigning.
    // watch faces that enable a peripheral or interact with a sensor may want to turn it off here.
    (void) settings;
    (void) context;
}
