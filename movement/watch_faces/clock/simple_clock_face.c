/*
 * MIT License
 *
 * Copyright (c) 2022 Joey Castillo
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
#include "simple_clock_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "watch_private_display.h"

// Defining the EASTER_EGG means that very long presses on 'ALARM' on this face
// show these words on the screen, and once the end is reached the watch display
// inverts. If EASTER_EGG is not defined, all of this code path is not included.
// If there's more than one string in the easter egg array, after completion
// the display will 'flip' all the characters. To undo this, start the easter
// egg again (but don't let it complete).
#define EASTER_EGG {"    SENSOR ", "    HACKED"}

#ifdef EASTER_EGG
static bool easter_egg_loop(movement_event_type_t event_type, uint8_t watch_face_index);
#endif

static void _update_alarm_indicator(bool settings_alarm_enabled, simple_clock_state_t *state) {
    state->alarm_enabled = settings_alarm_enabled;
    if (state->alarm_enabled) watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    else watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
}

void simple_clock_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(simple_clock_state_t));
        simple_clock_state_t *state = (simple_clock_state_t *)*context_ptr;
        state->signal_enabled = false;
        state->watch_face_index = watch_face_index;
    }
}

void simple_clock_face_activate(movement_settings_t *settings, void *context) {
    simple_clock_state_t *state = (simple_clock_state_t *)context;

    if (watch_tick_animation_is_running()) watch_stop_tick_animation();

    if (settings->bit.clock_mode_24h) watch_set_indicator(WATCH_INDICATOR_24H);

    // handle chime indicator
    if (state->signal_enabled) watch_set_indicator(WATCH_INDICATOR_BELL);
    else watch_clear_indicator(WATCH_INDICATOR_BELL);

    // show alarm indicator if there is an active alarm
    _update_alarm_indicator(settings->bit.alarm_enabled, state);

    watch_set_colon();

    // this ensures that none of the timestamp fields will match, so we can re-render them all.
    state->previous_date_time = 0xFFFFFFFF;
}

bool simple_clock_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    simple_clock_state_t *state = (simple_clock_state_t *)context;
    char buf[11];
    uint8_t pos;

    #ifdef EASTER_EGG
    // If easter egg mode is enabled, then first see if the easter
    // egg wants to do anything before our normal processing.
    if (easter_egg_loop(event.event_type, state->watch_face_index)) {
        // It's returned true. This means it's currently doing something weird
        // on the screen, so (a) we shouldn't pass to the normal logic and (b) the watch
        // shouldn't enter standby.
        return false;
    }
    #endif

    watch_date_time date_time;
    uint32_t previous_date_time;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
        case EVENT_LOW_ENERGY_UPDATE:
            date_time = watch_rtc_get_date_time();
            previous_date_time = state->previous_date_time;
            state->previous_date_time = date_time.reg;

            // check the battery voltage once a day...
            if (date_time.unit.day != state->last_battery_check) {
                state->last_battery_check = date_time.unit.day;
                watch_enable_adc();
                uint16_t voltage = watch_get_vcc_voltage();
                watch_disable_adc();
                // 2.2 volts will happen when the battery has maybe 5-10% remaining?
                // we can refine this later.
                state->battery_low = (voltage < 2200);
            }

            // ...and set the LAP indicator if low.
            if (state->battery_low) watch_set_indicator(WATCH_INDICATOR_LAP);

            if ((date_time.reg >> 6) == (previous_date_time >> 6) && event.event_type != EVENT_LOW_ENERGY_UPDATE) {
                // everything before seconds is the same, don't waste cycles setting those segments.
                watch_display_character_lp_seconds('0' + date_time.unit.second / 10, 8);
                watch_display_character_lp_seconds('0' + date_time.unit.second % 10, 9);
                break;
            } else if ((date_time.reg >> 12) == (previous_date_time >> 12) && event.event_type != EVENT_LOW_ENERGY_UPDATE) {
                // everything before minutes is the same.
                pos = 6;
                sprintf(buf, "%02d%02d", date_time.unit.minute, date_time.unit.second);
            } else {
                // other stuff changed; let's do it all.
                if (!settings->bit.clock_mode_24h) {
                    // if we are in 12 hour mode, do some cleanup.
                    if (date_time.unit.hour < 12) {
                        watch_clear_indicator(WATCH_INDICATOR_PM);
                    } else {
                        watch_set_indicator(WATCH_INDICATOR_PM);
                    }
                    date_time.unit.hour %= 12;
                    if (date_time.unit.hour == 0) date_time.unit.hour = 12;
                }
                pos = 0;
                if (event.event_type == EVENT_LOW_ENERGY_UPDATE) {
                    if (!watch_tick_animation_is_running()) watch_start_tick_animation(500);
                    sprintf(buf, "%s%2d%2d%02d  ", watch_utility_get_weekday(date_time), date_time.unit.day, date_time.unit.hour, date_time.unit.minute);
                } else {
                    sprintf(buf, "%s%2d%2d%02d%02d", watch_utility_get_weekday(date_time), date_time.unit.day, date_time.unit.hour, date_time.unit.minute, date_time.unit.second);
                }
            }
            watch_display_string(buf, pos);
            // handle alarm indicator
            if (state->alarm_enabled != settings->bit.alarm_enabled) _update_alarm_indicator(settings->bit.alarm_enabled, state);
            break;
        case EVENT_ALARM_LONG_PRESS:
            state->signal_enabled = !state->signal_enabled;
            if (state->signal_enabled) watch_set_indicator(WATCH_INDICATOR_BELL);
            else watch_clear_indicator(WATCH_INDICATOR_BELL);
            break;
        case EVENT_BACKGROUND_TASK:
            // uncomment this line to snap back to the clock face when the hour signal sounds:
            // movement_move_to_face(state->watch_face_index);
            if (watch_is_buzzer_or_led_enabled()) {
                // if we are in the foreground, we can just beep.
                movement_play_signal();
            } else {
                // if we were in the background, we need to enable the buzzer peripheral first,
                watch_enable_buzzer();
                // beep quickly (this call blocks for 275 ms),
                movement_play_signal();
                // and then turn the buzzer peripheral off again.
                watch_disable_buzzer();
            }
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void simple_clock_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

bool simple_clock_face_wants_background_task(movement_settings_t *settings, void *context) {
    (void) settings;
    simple_clock_state_t *state = (simple_clock_state_t *)context;
    if (!state->signal_enabled) return false;

    watch_date_time date_time = watch_rtc_get_date_time();

    return date_time.unit.minute == 0;
}

#ifdef EASTER_EGG

#define DISPLAY_WIDTH 10

static bool easter_egg_display_string_morph(char *old_string_arg, char *new_string_arg) {
    static char *old_string = NULL;
    static char *new_string = NULL;
    static uint8_t old_segdata[DISPLAY_WIDTH];
    static uint8_t new_segdata[DISPLAY_WIDTH];
    static size_t position = 0;
    size_t i;

    if (old_string_arg == NULL && new_string_arg == NULL) {
        old_string = new_string = NULL;
        return false;
    }

    if (old_string != old_string_arg) {
        position = 0;
        old_string = old_string_arg;
        for (i = 0; old_string[i] && i < DISPLAY_WIDTH; ++i) {
            old_segdata[i] = watch_convert_char_to_segdata(old_string[i], i);
        }
        for (; i < DISPLAY_WIDTH; ++i) {
            old_segdata[i] = watch_convert_char_to_segdata(' ', i);
        }
    }
    if (new_string != new_string_arg) {
        position = 0;
        new_string = new_string_arg;
        for (i = 0; new_string[i] && i < DISPLAY_WIDTH; ++i) {
            new_segdata[i] = watch_convert_char_to_segdata(new_string[i], i);
        }
        for (; i < DISPLAY_WIDTH; ++i) {
            new_segdata[i] = watch_convert_char_to_segdata(' ', i);
        }
    }

    // Make old_segdata approach new_segdata by the first bit we find.
    for (; position < DISPLAY_WIDTH; ++position) {
        if (old_segdata[position] == new_segdata[position]) {
            continue;
        }

        for (int bit_pos = 0; bit_pos < 8; ++bit_pos) {
            int bit = 1 << bit_pos;

            if ((old_segdata[position] & bit) != (new_segdata[position] & bit)) {
                old_segdata[position] ^= bit;
                watch_display_segment(position, bit_pos, old_segdata[position] & bit);
                // We only do one segment change. Call again to keep morphing.
                return true;
            }
        }
    }

    // This cleans up the extra tweaks that wouldn't have been done in the
    // segment map.
    watch_display_string(new_string, 0);
    return false;
}

static char *egg_states[] = EASTER_EGG;
static const size_t egg_states_length = sizeof(egg_states) / sizeof(egg_states[0]);
static const int32_t easter_egg_delay = 3;

static bool easter_egg_loop(movement_event_type_t event_type, uint8_t watch_face_index) {
    static int32_t egg_state_index = -1;
    static uint32_t alarm_button_down_time = 0;
    static bool morphing = false;

    if (alarm_button_down_time == 0 && event_type != EVENT_ALARM_BUTTON_DOWN) {
        // Nothing to do here folks. Avoid any unnecessary processing.
        return false;
    }

    watch_date_time date_time = watch_rtc_get_date_time();
    int32_t time_since_alarm_button = date_time.reg - alarm_button_down_time;

    switch (event_type) {
        case EVENT_ACTIVATE:
        case EVENT_LOW_ENERGY_UPDATE:
        case EVENT_ALARM_BUTTON_UP:
        case EVENT_ALARM_LONG_UP:
            // Either a button press ended, or we've somehow still got a button down
            // time after more interesting things have happened. Clean stuff up.
            if (egg_state_index != -1) {
                movement_move_to_face(watch_face_index);
                easter_egg_display_string_morph(NULL, NULL);
                egg_state_index = -1;
                morphing = false;
                movement_request_tick_frequency(1);
            }
            alarm_button_down_time = 0;
            break;
        case EVENT_ALARM_BUTTON_DOWN:
            alarm_button_down_time = date_time.reg;
            break;
        case EVENT_TICK:
            if (egg_state_index == -1) {
                if (time_since_alarm_button > easter_egg_delay) {
                    egg_state_index = 0;
                    watch_display_invert(false);
                    watch_clear_colon();
                    watch_clear_all_indicators();
                    watch_display_string(egg_states[egg_state_index], 0);
                }
            } else if (egg_state_index >= 0) {
                if (morphing) {
                    morphing = easter_egg_display_string_morph(egg_states[egg_state_index - 1], egg_states[egg_state_index]);
                    if (!morphing) { // Finished changing to new string.
                        movement_request_tick_frequency(1);

                        if (egg_state_index + 1 >= (int32_t)egg_states_length) {
                            // We've finished our animation after the final morph. Flip!
                            watch_display_invert(true);
                            // And display so people are immediately confused.
                            watch_display_string(egg_states[egg_state_index], 0);
                        }
                    }
                }

                if (egg_state_index + 1 < (int32_t)egg_states_length && time_since_alarm_button > easter_egg_delay * (egg_state_index + 2)) {
                    // In case we didn't finish the morph, set it here.
                    if (morphing) {
                      watch_display_string(egg_states[egg_state_index], 0);
                    }
                    egg_state_index += 1;
                    movement_request_tick_frequency(16);
                    morphing = true;
                }
            }
            break;
        default:
            break;
    }

    return egg_state_index != -1;
}
#endif // EASTER_EGG
