/*
 * MIT License
 *
 * Copyright (c) 2023 Hieu Nguyen / @cheehieu
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
#include "proposal_face.h"

#define WATCHFACE_TITLE "  " // blank title in weekday digits

// State tick frequency in Hz
#define TICK_FREQ_NAME 2
#define TICK_FREQ_PROPOSAL 1
#define TICK_FREQ_RESPONSE 2
#define TICK_FREQ_REACTION 1

#define WORD_DEATH " DEath"
#define WORD_LOVERS "Lovers"
#define WORD_BOWSER "Bou sr" // Needs extra segments for "W" in append_segments_for_bowser()
#define WORD_MARIO "n&ario"
#define WORD_PEACH " PEACH"

static char words_name[][7] = {
    WORD_PEACH,
    "ES    ",
    WORD_PEACH,
    "  ES  ",
    WORD_PEACH,
    "    ES",
};

static char words_proposal[][7] = {
    "W  LL ", // Needs extra segments for "Wi" in append_segments_for_will()
    "   You",
    "n&arry",
    "n&E ? ",
};

static char words_response[][7] = {
    " Y  no",
    " Y  no",
};

static char words_reaction_yes[][7] = {
    WORD_LOVERS,
    WORD_PEACH,
    WORD_BOWSER,
};

static char words_reaction_no[][7] = {
    WORD_DEATH,
    "  2   ",
    WORD_MARIO,
};

#define NUM_WORDS_NAME (sizeof(words_name) / sizeof(*words_name))
#define NUM_WORDS_PROPOSAL (sizeof(words_proposal) / sizeof(*words_proposal))
#define NUM_WORDS_RESPONSE (sizeof(words_response) / sizeof(*words_response))
#define NUM_WORDS_REACTION_Y (sizeof(words_reaction_yes) / sizeof(*words_reaction_yes))
#define NUM_WORDS_REACTION_N (sizeof(words_reaction_no) / sizeof(*words_reaction_no))

void proposal_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(proposal_state_t));
        memset(*context_ptr, 0, sizeof(proposal_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void proposal_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    proposal_state_t *state = (proposal_state_t *)context;

    // Handle any tasks related to your watch face coming on screen.
    // watch_display_string(WATCHFACE_TITLE, 0);
    movement_request_tick_frequency(TICK_FREQ_NAME);
    state->current_state = STATE_NAME;
    state->word_index = 0;
    state->proposal_response = false;
}

// Modify display string with extra segments for "WiLL"
// https://joeycastillo.github.io/Sensor-Watch-Documentation/segmap
static void append_segments_for_will(proposal_state_t *state) {
    if (state->current_state == STATE_PROPOSAL && state->word_index == 0) {
        watch_set_pixel(1, 20); // partial right half of "W" in clock hours
        watch_set_pixel(2, 21); // partial right half of "W" in clock hours
        watch_set_pixel(1, 22); // "i" in clock minutes
    }
}

// Modify display string with extra segments for "Bowser"
static void append_segments_for_bowser(proposal_state_t *state) {
    if (state->current_state == STATE_REACTION && state->word_index == 2 && state->proposal_response == true) {
        watch_set_pixel(1, 1); // partial right half of "W" in clock minutes
        watch_set_pixel(2, 10); // partial right half of "W" in clock minutes
    }
}

// Display a word from the buffer depending on the state
static void display_word(proposal_state_t *state) {
    char buf[11];
    switch (state->current_state) {
        case STATE_NAME:
            sprintf(buf, "    %s", words_name[state->word_index]);
            break;
        case STATE_PROPOSAL:
            sprintf(buf, "    %s", words_proposal[state->word_index]);
            break;
        case STATE_RESPONSE:
            sprintf(buf, "    %s", words_response[state->word_index]);
            break;
        case STATE_REACTION:
            if (state->proposal_response) {
                sprintf(buf, "    %s", words_reaction_yes[state->word_index]);
            } else {
                sprintf(buf, "    %s", words_reaction_no[state->word_index]);
            }
            break;
        default:
            sprintf(buf, "    %s", words_name[state->word_index]);
            break;
    }
    watch_display_string(buf, 0);

    // If needed, modify display string with extra segments
    append_segments_for_will(state);
    append_segments_for_bowser(state);
}

// Play Mario one-up sound effect
static void song_mario_one_up (void) {
    const BuzzerNote notes[] = {
        BUZZER_NOTE_E5,
        BUZZER_NOTE_G5,
        BUZZER_NOTE_E6,
        BUZZER_NOTE_C6,
        BUZZER_NOTE_D6,
        BUZZER_NOTE_G6,
    };
    const uint16_t durations[] = {
        150,
        150,
        150,
        150,
        150,
        150,
    };
    for(size_t i = 0, count = sizeof(notes) / sizeof(notes[0]); i < count; i++) {
        watch_buzzer_play_note(notes[i], durations[i]);
    }
}

// Play Mario death sound effect
static void song_mario_death (void) {
    const BuzzerNote notes[] = {
        BUZZER_NOTE_C5,
        BUZZER_NOTE_C5SHARP_D5FLAT,
        BUZZER_NOTE_D5,
        BUZZER_NOTE_REST,
        BUZZER_NOTE_B4,
        BUZZER_NOTE_F5,
        BUZZER_NOTE_REST,
        BUZZER_NOTE_F5,
        BUZZER_NOTE_REST,
        BUZZER_NOTE_F5,
        BUZZER_NOTE_E5,
        BUZZER_NOTE_D5,
        BUZZER_NOTE_C5,
        BUZZER_NOTE_E4,
        BUZZER_NOTE_REST,
        BUZZER_NOTE_E4,
        BUZZER_NOTE_C4,
    };
    const uint16_t durations[] = {
        40,
        40,
        80,
        600,
        150,
        150,
        150,
        150,
        25,
        250,
        250,
        250,
        150,
        150,
        150,
        150,
        150,
    };
    for(size_t i = 0, count = sizeof(notes) / sizeof(notes[0]); i < count; i++) {
        watch_buzzer_play_note(notes[i], durations[i]);
    }
}

// Handles state management
bool proposal_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    proposal_state_t *state = (proposal_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            display_word(state);
            break;
        case EVENT_TICK:
            switch (state->current_state) {
                case STATE_NAME:
                    if (state->word_index < NUM_WORDS_NAME) {
                        display_word(state);
                        state->word_index = state->word_index + 1;
                    } else {
                        // Prepare for transition to STATE_PROPOSAL
                        movement_request_tick_frequency(TICK_FREQ_PROPOSAL);
                        state->current_state = STATE_PROPOSAL;
                        state->word_index = 0;
                    }
                    break;
                case STATE_PROPOSAL:
                    if (state->word_index < NUM_WORDS_PROPOSAL) {
                        display_word(state);
                        state->word_index = state->word_index + 1;
                    } else {
                        // Prepare for transition to STATE_RESPONSE
                        movement_request_tick_frequency(TICK_FREQ_RESPONSE);
                        state->current_state = STATE_RESPONSE;
                        state->word_index = 0;
                    }
                    break;
                case STATE_RESPONSE:
                    display_word(state);
                    state->word_index = (state->word_index + 1) % NUM_WORDS_RESPONSE;

                    // Toggle bell indicator on each EVENT_TICK while awaiting button press
                    if (state->word_index % 2 == 0) {
                        watch_set_indicator(WATCH_INDICATOR_BELL);
                    } else {
                        watch_clear_indicator(WATCH_INDICATOR_BELL);
                    }
                    break;
                case STATE_REACTION:
                    display_word(state);

                    // Blink LED and play song
                    if (state->word_index % NUM_WORDS_REACTION_Y == 0) {
                        if (state->proposal_response) {
                            watch_set_led_green();
                            movement_illuminate_led();
                            song_mario_one_up();
                        } else {
                            watch_set_led_red();
                            movement_illuminate_led();
                            song_mario_death();
                        }
                    } else {
                        watch_set_led_off();
                    }

                    // Loop over response words
                    if (state->proposal_response) {
                        state->word_index = (state->word_index + 1) % NUM_WORDS_REACTION_Y;
                    } else {
                        state->word_index = (state->word_index + 1) % NUM_WORDS_REACTION_N;
                    }

                    // return false; // return false to prevent standby mode?
                    break;
                default:
                    break;
            }
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            // Button is only functional for a YES response
            if (state->current_state == STATE_RESPONSE) {
                state->proposal_response = true;

                // Prepare for transition to STATE_REACTION
                watch_clear_all_indicators();
                movement_request_tick_frequency(TICK_FREQ_REACTION);
                state->current_state = STATE_REACTION;
                state->word_index = 0;
            }
            break;
        case EVENT_ALARM_BUTTON_DOWN:
            // Button is only functional for a NO response
            if (state->current_state == STATE_RESPONSE) {
                state->proposal_response = false;

                // Prepare for transition to STATE_REACTION
                watch_clear_all_indicators();
                movement_request_tick_frequency(TICK_FREQ_REACTION);
                state->current_state = STATE_REACTION;
                state->word_index = 0;
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            // Reset back to name state
            watch_set_led_off();
            watch_clear_all_indicators();
            movement_request_tick_frequency(TICK_FREQ_NAME);
            state->current_state = STATE_NAME;
            state->word_index = 0;
            break;
        case EVENT_TIMEOUT:
            // Your watch face will receive this event after a period of inactivity. If it makes sense to resign,
            // you may uncomment this line to move back to the first watch face in the list:
            movement_move_to_face(0);
            break;
        default:
            // Movement's default loop handler will step in for any cases you don't handle above:
            // * EVENT_LIGHT_BUTTON_DOWN lights the LED
            // * EVENT_MODE_BUTTON_UP moves to the next watch face in the list
            // * EVENT_MODE_LONG_PRESS returns to the first watch face (or skips to the secondary watch face, if configured)
            // You can override any of these behaviors by adding a case for these events to this switch statement.
            return movement_default_loop_handler(event, settings);
    }

    // return true if the watch can enter standby mode. Generally speaking, you should always return true.
    // Exceptions:
    //  * If you are displaying a color using the low-level watch_set_led_color function, you should return false.
    //  * If you are sounding the buzzer using the low-level watch_set_buzzer_on function, you should return false.
    // Note that if you are driving the LED or buzzer using Movement functions like movement_illuminate_led or
    // movement_play_alarm, you can still return true. This guidance only applies to the low-level watch_ functions.
    return true;
}

void proposal_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
    watch_set_led_off();
}
