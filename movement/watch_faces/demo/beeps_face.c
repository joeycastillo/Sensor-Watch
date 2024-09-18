/*
 * MIT License
 *
 * Copyright (c) 2024 Wesley
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
#include "beeps_face.h"

void beeps_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(beeps_state_t));
        memset(*context_ptr, 0, sizeof(beeps_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
}

void beeps_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

static void _beep_face_update_lcd(beeps_state_t *state) {
    char buf[11];
    const char buzzernote[][7] = {"   5500", "   5827", "   6174","   6541","   6930","   7342","   7778","   8241","   8731","   9250","   9800","  10383","  11000","  11654","  12347","  13081","  13859","  14683","  15556","  16481","  17461","  18500","  19600","  20765","  22000","  23308","  24694","  26163","  27718","  29366","  31113","  32963","  34923","  36999","  39200","  41530","  44000","  46616","  49388","  52325","  55437","  58733","  62225","  65925","  69846","  73999","  78399","  83061","  88000","  93233","  98777"," 104650"," 110873"," 117466"," 124451"," 131851"," 139691"," 147998"," 156798"," 166122"," 176000"," 186466"," 197553"," 209300"," 221746"," 234932"," 248902"," 263702"," 279383"," 295996"," 313596"," 332244"," 352000"," 372931"," 395107"," 418601"," 443492"," 469863"," 497803"," 527404"," 558765"," 591991"," 627193"," 664488"," 704000"," 745862"," 790213"};
    sprintf(buf, "HZ %s", buzzernote[state->frequency]);
    watch_display_string(buf, 0);
}

bool beeps_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    beeps_state_t *state = (beeps_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            _beep_face_update_lcd(state);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            state->frequency = (state->frequency + 1) % 87;
            _beep_face_update_lcd(state);
            break;
        case EVENT_ALARM_BUTTON_DOWN:
            if (state->frequency == 0) {
                watch_buzzer_play_note(BUZZER_NOTE_A1, 500);
            } else if (state->frequency == 1) {
                watch_buzzer_play_note(BUZZER_NOTE_A1SHARP_B1FLAT, 500);
            } else if (state->frequency == 2) {
                watch_buzzer_play_note(BUZZER_NOTE_B1, 500);
            } else if (state->frequency == 3) {
                watch_buzzer_play_note(BUZZER_NOTE_C2, 500);
            } else if (state->frequency == 4) {
                watch_buzzer_play_note(BUZZER_NOTE_C2SHARP_D2FLAT, 500);
            } else if (state->frequency == 5) {
                watch_buzzer_play_note(BUZZER_NOTE_D2, 500);
            } else if (state->frequency == 6) {
                watch_buzzer_play_note(BUZZER_NOTE_D2SHARP_E2FLAT, 500);
            } else if (state->frequency == 7) {
                watch_buzzer_play_note(BUZZER_NOTE_E2, 500);
            } else if (state->frequency == 8) {
                watch_buzzer_play_note(BUZZER_NOTE_F2, 500);
            } else if (state->frequency == 9) {
                watch_buzzer_play_note(BUZZER_NOTE_F2SHARP_G2FLAT, 500);
            } else if (state->frequency == 10) {
                watch_buzzer_play_note(BUZZER_NOTE_G2, 500);
            } else if (state->frequency == 11) {
                watch_buzzer_play_note(BUZZER_NOTE_G2SHARP_A2FLAT, 500);
            } else if (state->frequency == 12) {
                watch_buzzer_play_note(BUZZER_NOTE_A2, 500);
            } else if (state->frequency == 13) {
                watch_buzzer_play_note(BUZZER_NOTE_A2SHARP_B2FLAT, 500);
            } else if (state->frequency == 14) {
                watch_buzzer_play_note(BUZZER_NOTE_B2, 500);
            } else if (state->frequency == 15) {
                watch_buzzer_play_note(BUZZER_NOTE_C3, 500);
            } else if (state->frequency == 16) {
                watch_buzzer_play_note(BUZZER_NOTE_C3SHARP_D3FLAT, 500);
            } else if (state->frequency == 17) {
                watch_buzzer_play_note(BUZZER_NOTE_D3, 500);
            } else if (state->frequency == 18) {
                watch_buzzer_play_note(BUZZER_NOTE_D3SHARP_E3FLAT, 500);
            } else if (state->frequency == 19) {
                watch_buzzer_play_note(BUZZER_NOTE_E3, 500);
            } else if (state->frequency == 20) {
                watch_buzzer_play_note(BUZZER_NOTE_F3, 500);
            } else if (state->frequency == 21) {
                watch_buzzer_play_note(BUZZER_NOTE_F3SHARP_G3FLAT, 500);
            } else if (state->frequency == 22) {
                watch_buzzer_play_note(BUZZER_NOTE_G3, 500);
            } else if (state->frequency == 23) {
                watch_buzzer_play_note(BUZZER_NOTE_G3SHARP_A3FLAT, 500);
            } else if (state->frequency == 24) {
                watch_buzzer_play_note(BUZZER_NOTE_A3, 500);
            } else if (state->frequency == 25) {
                watch_buzzer_play_note(BUZZER_NOTE_A3SHARP_B3FLAT, 500);
            } else if (state->frequency == 26) {
                watch_buzzer_play_note(BUZZER_NOTE_B3, 500);
            } else if (state->frequency == 27) {
                watch_buzzer_play_note(BUZZER_NOTE_C4, 500);
            } else if (state->frequency == 28) {
                watch_buzzer_play_note(BUZZER_NOTE_C4SHARP_D4FLAT, 500);
            } else if (state->frequency == 29) {
                watch_buzzer_play_note(BUZZER_NOTE_D4, 500);
            } else if (state->frequency == 30) {
                watch_buzzer_play_note(BUZZER_NOTE_D4SHARP_E4FLAT, 500);
            } else if (state->frequency == 31) {
                watch_buzzer_play_note(BUZZER_NOTE_E4, 500);
            } else if (state->frequency == 32) {
                watch_buzzer_play_note(BUZZER_NOTE_F4, 500);
            } else if (state->frequency == 33) {
                watch_buzzer_play_note(BUZZER_NOTE_F4SHARP_G4FLAT, 500);
            } else if (state->frequency == 34) {
                watch_buzzer_play_note(BUZZER_NOTE_G4, 500);
            } else if (state->frequency == 35) {
                watch_buzzer_play_note(BUZZER_NOTE_G4SHARP_A4FLAT, 500);
            } else if (state->frequency == 36) {
                watch_buzzer_play_note(BUZZER_NOTE_A4, 500);
            } else if (state->frequency == 37) {
                watch_buzzer_play_note(BUZZER_NOTE_A4SHARP_B4FLAT, 500);
            } else if (state->frequency == 38) {
                watch_buzzer_play_note(BUZZER_NOTE_B4, 500);
            } else if (state->frequency == 39) {
                watch_buzzer_play_note(BUZZER_NOTE_C5, 500);
            } else if (state->frequency == 40) {
                watch_buzzer_play_note(BUZZER_NOTE_C5SHARP_D5FLAT, 500);
            } else if (state->frequency == 41) {
                watch_buzzer_play_note(BUZZER_NOTE_D5, 500);
            } else if (state->frequency == 42) {
                watch_buzzer_play_note(BUZZER_NOTE_D5SHARP_E5FLAT, 500);
            } else if (state->frequency == 43) {
                watch_buzzer_play_note(BUZZER_NOTE_E5, 500);
            } else if (state->frequency == 44) {
                watch_buzzer_play_note(BUZZER_NOTE_F5, 500);
            } else if (state->frequency == 45) {
                watch_buzzer_play_note(BUZZER_NOTE_F5SHARP_G5FLAT, 500);
            } else if (state->frequency == 46) {
                watch_buzzer_play_note(BUZZER_NOTE_G5, 500);
            } else if (state->frequency == 47) {
                watch_buzzer_play_note(BUZZER_NOTE_G5SHARP_A5FLAT, 500);
            } else if (state->frequency == 48) {
                watch_buzzer_play_note(BUZZER_NOTE_A5, 500);
            } else if (state->frequency == 49) {
                watch_buzzer_play_note(BUZZER_NOTE_A5SHARP_B5FLAT, 500);
            } else if (state->frequency == 50) {
                watch_buzzer_play_note(BUZZER_NOTE_B5, 500);
            } else if (state->frequency == 51) {
                watch_buzzer_play_note(BUZZER_NOTE_C6, 500);
            } else if (state->frequency == 52) {
                watch_buzzer_play_note(BUZZER_NOTE_C6SHARP_D6FLAT, 500);
            } else if (state->frequency == 53) {
                watch_buzzer_play_note(BUZZER_NOTE_D6, 500);
            } else if (state->frequency == 54) {
                watch_buzzer_play_note(BUZZER_NOTE_D6SHARP_E6FLAT, 500);
            } else if (state->frequency == 55) {
                watch_buzzer_play_note(BUZZER_NOTE_E6, 500);
            } else if (state->frequency == 56) {
                watch_buzzer_play_note(BUZZER_NOTE_F6, 500);
            } else if (state->frequency == 57) {
                watch_buzzer_play_note(BUZZER_NOTE_F6SHARP_G6FLAT, 500);
            } else if (state->frequency == 58) {
                watch_buzzer_play_note(BUZZER_NOTE_G6, 500);
            } else if (state->frequency == 59) {
                watch_buzzer_play_note(BUZZER_NOTE_G6SHARP_A6FLAT, 500);
            } else if (state->frequency == 60) {
                watch_buzzer_play_note(BUZZER_NOTE_A6, 500);
            } else if (state->frequency == 61) {
                watch_buzzer_play_note(BUZZER_NOTE_A6SHARP_B6FLAT, 500);
            } else if (state->frequency == 62) {
                watch_buzzer_play_note(BUZZER_NOTE_B6, 500);
            } else if (state->frequency == 63) {
                watch_buzzer_play_note(BUZZER_NOTE_C7, 500);
            } else if (state->frequency == 64) {
                watch_buzzer_play_note(BUZZER_NOTE_C7SHARP_D7FLAT, 500);
            } else if (state->frequency == 65) {
                watch_buzzer_play_note(BUZZER_NOTE_D7, 500);
            } else if (state->frequency == 66) {
                watch_buzzer_play_note(BUZZER_NOTE_D7SHARP_E7FLAT, 500);
            } else if (state->frequency == 67) {
                watch_buzzer_play_note(BUZZER_NOTE_E7, 500);
            } else if (state->frequency == 68) {
                watch_buzzer_play_note(BUZZER_NOTE_F7, 500);
            } else if (state->frequency == 69) {
                watch_buzzer_play_note(BUZZER_NOTE_F7SHARP_G7FLAT, 500);
            } else if (state->frequency == 70) {
                watch_buzzer_play_note(BUZZER_NOTE_G7, 500);
            } else if (state->frequency == 71) {
                watch_buzzer_play_note(BUZZER_NOTE_G7SHARP_A7FLAT, 500);
            } else if (state->frequency == 72) {
                watch_buzzer_play_note(BUZZER_NOTE_A7, 500);
            } else if (state->frequency == 73) {
                watch_buzzer_play_note(BUZZER_NOTE_A7SHARP_B7FLAT, 500);
            } else if (state->frequency == 74) {
                watch_buzzer_play_note(BUZZER_NOTE_B7, 500);
            } else if (state->frequency == 75) {
                watch_buzzer_play_note(BUZZER_NOTE_C8, 500);
            } else if (state->frequency == 76) {
                watch_buzzer_play_note(BUZZER_NOTE_C8SHARP_D8FLAT, 500);
            } else if (state->frequency == 77) {
                watch_buzzer_play_note(BUZZER_NOTE_D8, 500);
            } else if (state->frequency == 78) {
                watch_buzzer_play_note(BUZZER_NOTE_D8SHARP_E8FLAT, 500);
            } else if (state->frequency == 79) {
                watch_buzzer_play_note(BUZZER_NOTE_E8, 500);
            } else if (state->frequency == 80) {
                watch_buzzer_play_note(BUZZER_NOTE_F8, 500);
            } else if (state->frequency == 81) {
                watch_buzzer_play_note(BUZZER_NOTE_F8SHARP_G8FLAT, 500);
            } else if (state->frequency == 82) {
                watch_buzzer_play_note(BUZZER_NOTE_G8, 500);
            } else if (state->frequency == 83) {
                watch_buzzer_play_note(BUZZER_NOTE_G8SHARP_A8FLAT, 500);
            } else if (state->frequency == 84) {
                watch_buzzer_play_note(BUZZER_NOTE_A8, 500);
            } else if (state->frequency == 85) {
                watch_buzzer_play_note(BUZZER_NOTE_A8SHARP_B8FLAT, 500);
            } else if (state->frequency == 86) {
                watch_buzzer_play_note(BUZZER_NOTE_B8, 500);
            }
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }
    return true;
}

void beeps_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

