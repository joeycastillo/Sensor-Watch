/*
 * MIT License
 *
 * Copyright (c) 2023 Ekaitz Zarraga <ekaitz@elenq.tech>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <stdlib.h>
#include <string.h>
#include "couch_to_5k_face.h"

// They go: Warmup, Run, Walk, Run, Walk, Run, Walk ... , End (0)
// Time is defined in seconds
// Maybe do /10 to reduce memory usage?
// (i don't want to use floats)

// uint16_t C25K_WEEK_TEST[] = {10, 10, 10, 0};
uint16_t C25K_WEEK_1[]   = {300, 60, 90, 60, 90, 60, 90, 60, 90, 60, 90, 60,
    90, 60, 90, 60, 90, 0};
uint16_t C25K_WEEK_2[]   = {300, 90, 120, 90, 120, 90, 120, 90, 120, 90, 120,
    90, 120, 0};
uint16_t C25K_WEEK_3[]   = {300, 90, 90, 180, 180, 90, 90, 180, 180, 0};
uint16_t C25K_WEEK_4[]   = {300, 180, 90, 300, 150, 180, 90, 300, 0};
uint16_t C25K_WEEK_5_1[] = {300, 300, 180, 300, 180, 300, 0 };
uint16_t C25K_WEEK_5_2[] = {300, 480, 300, 480 , 0};
uint16_t C25K_WEEK_5_3[] = {300, 1200, 0};
uint16_t C25K_WEEK_6_1[] = {300, 300, 180, 480, 180, 300, 0 };
uint16_t C25K_WEEK_6_2[] = {300, 600, 180, 600 , 0};
uint16_t C25K_WEEK_6_3[] = {300, 1500, 0};
uint16_t C25K_WEEK_7[]   = {300, 1500, 0};
uint16_t C25K_WEEK_8[]   = {300, 1680, 0};
uint16_t C25K_WEEK_9[]   = {300, 1800, 0};


#define C25K_SESSIONS_LENGTH 3*9
uint16_t *C25K_SESSIONS[C25K_SESSIONS_LENGTH];

static inline bool _finished(couch_to_5k_state_t *state){
    return state->exercise_type == C25K_FINISHED;
}
static inline bool _cleared(couch_to_5k_state_t *state){
    return state->timer == C25K_SESSIONS[state->session][0]
        && state->exercise == 0;
}
static inline void _next_session(couch_to_5k_state_t *state){
    if (++state->session >= C25K_SESSIONS_LENGTH){
        state->session = 0;
    }
}

static inline void _assign_exercise_type(couch_to_5k_state_t *state){
    if (state->exercise == 0){
        state->exercise_type = C25K_WARMUP;
    } else if (state->exercise % 2 == 1){
        state->exercise_type = C25K_RUN;
    } else {
        state->exercise_type = C25K_WALK;
    }
}

static void _next_exercise(couch_to_5k_state_t *state){
    state->exercise++;
    state->timer = C25K_SESSIONS[state->session][state->exercise];
    // If the new timer starts in zero, it's finished
    if (state->timer == 0){
        movement_play_alarm_beeps(7, BUZZER_NOTE_C8);
        state->exercise_type = C25K_FINISHED;
        return;
    }
    movement_play_alarm_beeps(4, BUZZER_NOTE_A7);
    _assign_exercise_type(state);
}

static void _init_session(couch_to_5k_state_t *state){
    state->exercise = 0; // Restart exercise counter
    state->timer = C25K_SESSIONS[state->session][state->exercise];
    _assign_exercise_type(state);
}

static char *_exercise_type_to_str(exercise_type_t t){
    switch (t){
        case C25K_WARMUP:
            return "WU";
        case C25K_RUN:
            return "RU";
        case C25K_WALK:
            return "WA";
        case C25K_FINISHED:
            return "--";
        default:
            return "  ";
    }
}
static void _display(couch_to_5k_state_t *state, char *buf){
    // TODO only repaint needed parts
    uint8_t seconds = state->timer % 60;
    sprintf(buf, "%s%2d%2d%02d%02d",
            _exercise_type_to_str(state->exercise_type),
            (state->session + 1) % 100,
            ((state->timer - seconds) / 60) % 100,
            seconds,
            (state->exercise + 1) % 100);
    watch_display_string(buf, 0);
}


void couch_to_5k_face_setup(movement_settings_t *settings, uint8_t
                          watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(couch_to_5k_state_t));
        memset(*context_ptr, 0, sizeof(couch_to_5k_state_t));
        // Do any one-time tasks in here; the inside of this conditional
        // happens only at boot.
        // C25K_SESSIONS[0]  = C25K_WEEK_TEST;
        C25K_SESSIONS[0]  = C25K_WEEK_1;
        C25K_SESSIONS[1]  = C25K_WEEK_1;
        C25K_SESSIONS[2]  = C25K_WEEK_1;
        C25K_SESSIONS[3]  = C25K_WEEK_2;
        C25K_SESSIONS[4]  = C25K_WEEK_2;
        C25K_SESSIONS[5]  = C25K_WEEK_2;
        C25K_SESSIONS[6]  = C25K_WEEK_3;
        C25K_SESSIONS[7]  = C25K_WEEK_3;
        C25K_SESSIONS[8]  = C25K_WEEK_3;
        C25K_SESSIONS[9]  = C25K_WEEK_4;
        C25K_SESSIONS[10] = C25K_WEEK_4;
        C25K_SESSIONS[11] = C25K_WEEK_4;
        C25K_SESSIONS[12] = C25K_WEEK_5_1;
        C25K_SESSIONS[13] = C25K_WEEK_5_2;
        C25K_SESSIONS[14] = C25K_WEEK_5_3;
        C25K_SESSIONS[15] = C25K_WEEK_6_1;
        C25K_SESSIONS[16] = C25K_WEEK_6_2;
        C25K_SESSIONS[17] = C25K_WEEK_6_3;
        C25K_SESSIONS[18] = C25K_WEEK_7;
        C25K_SESSIONS[19] = C25K_WEEK_7;
        C25K_SESSIONS[20] = C25K_WEEK_7;
        C25K_SESSIONS[21] = C25K_WEEK_8;
        C25K_SESSIONS[22] = C25K_WEEK_8;
        C25K_SESSIONS[23] = C25K_WEEK_8;
        C25K_SESSIONS[24] = C25K_WEEK_9;
        C25K_SESSIONS[25] = C25K_WEEK_9;
        C25K_SESSIONS[26] = C25K_WEEK_9;
    }
    // Do any pin or peripheral setup here; this will be called whenever the
    // watch wakes from deep sleep.
}

void couch_to_5k_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    // Handle any tasks related to your watch face coming on screen.
    watch_set_colon();
}


bool couch_to_5k_face_loop(movement_event_t event, movement_settings_t *settings,
                         void *context) {
    couch_to_5k_state_t *state = (couch_to_5k_state_t *)context;
    static char buf[11];
    static bool paused = true;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            movement_request_tick_frequency(1);
            _init_session(state);
            paused = true;
            _display(state, buf);
            break;
        case EVENT_TICK:
            if ( !paused && !_finished(state) ) {
                if (state->timer == 0){
                    _next_exercise(state);
                } else {
                    state->timer--;
                }
            }
            _display(state, buf);
            break;
        case EVENT_LIGHT_BUTTON_UP:
            // This is the next-exercise / reset button.

            // When finished move to the next session and leave it paused
            if ( _finished(state) ){
                _next_session(state);
                _init_session(state);
                paused = true;
                break;
            }
            // When paused and cleared move to next, when only paused, clear
            if ( paused ) {
                if ( _cleared(state) ){
                    _next_session(state);
                }
                _init_session(state);
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            if (settings->bit.button_should_sound) {
                watch_buzzer_play_note(BUZZER_NOTE_C8, 50);
            }
            paused = !paused;
            break;
        case EVENT_TIMEOUT:
            // Your watch face will receive this event after a period of
            // inactivity. If it makes sense to resign,
            movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            // If you did not resign in EVENT_TIMEOUT, you can use this event
            // to update the display once a minute. Avoid displaying
            // fast-updating values like seconds, since the display won't
            // update again for 60 seconds. You should also consider starting
            // the tick animation, to show the wearer that this is sleep mode:
            // watch_start_tick_animation(500);
            break;
        default:
            // Movement's default loop handler will step in for any cases you
            // don't handle above:
            // * EVENT_LIGHT_BUTTON_DOWN lights the LED
            // * EVENT_MODE_BUTTON_UP moves to the next watch face in the list
            // * EVENT_MODE_LONG_PRESS returns to the first watch face (or
            // skips to the secondary watch face, if configured)
            // You can override any of these behaviors by adding a case for
            // these events to this switch statement.
            return movement_default_loop_handler(event, settings);
    }

    // return true if the watch can enter standby mode. Generally speaking, you
    // should always return true.
    // Exceptions:
    //  * If you are displaying a color using the low-level watch_set_led_color
    //  function, you should return false.
    //  * If you are sounding the buzzer using the low-level
    //  watch_set_buzzer_on function, you should return false.
    // Note that if you are driving the LED or buzzer using Movement functions
    // like movement_illuminate_led or movement_play_alarm, you can still
    // return true. This guidance only applies to the low-level watch_
    // functions.
    return true;
}

void couch_to_5k_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

