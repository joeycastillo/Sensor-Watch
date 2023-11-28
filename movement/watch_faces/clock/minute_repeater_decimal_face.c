/*
 * MIT License
 *
 * Copyright (c) 2023 Jonas Termeau - original repetition_minute_face
 * Copyright (c) 2023 Brian Blakley - modified minute_repeater_decimal_face
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

/*
 * This face, minute_repeater_decimal_face, is a modification of the original 
 * repetition_minute_face by Jonas Termeau.
 * 
 * This version was created by BrianBinFL to use a decimal minute repeater pattern 
 * (hours, tens, and minutes) instead of the traditional pattern (hours, quarters, 
 * minutes).
 *
 * Also 500ms delays were added after the hours segment and after the tens segment
 * to make it easier for the user to realize that the counting for the current 
 * segment has ended.
 *
 */
 
#include <stdlib.h>
#include "minute_repeater_decimal_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "watch_private_display.h"

void mrd_play_hour_chime(void) {
        watch_buzzer_play_note(BUZZER_NOTE_C6, 75);
        watch_buzzer_play_note(BUZZER_NOTE_REST, 500);
}

void mrd_play_tens_chime(void) {
        watch_buzzer_play_note(BUZZER_NOTE_E6, 75);
        watch_buzzer_play_note(BUZZER_NOTE_REST, 150);
        watch_buzzer_play_note(BUZZER_NOTE_C6, 75);
        watch_buzzer_play_note(BUZZER_NOTE_REST, 750);
}

void mrd_play_minute_chime(void) {
        watch_buzzer_play_note(BUZZER_NOTE_E6, 75);
        watch_buzzer_play_note(BUZZER_NOTE_REST, 500);
}

static void _update_alarm_indicator(bool settings_alarm_enabled, minute_repeater_decimal_state_t *state) {
    state->alarm_enabled = settings_alarm_enabled;
    if (state->alarm_enabled) watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    else watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
}

void minute_repeater_decimal_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(minute_repeater_decimal_state_t));
        minute_repeater_decimal_state_t *state = (minute_repeater_decimal_state_t *)*context_ptr;
        state->signal_enabled = false;
        state->watch_face_index = watch_face_index;
    }
}

void minute_repeater_decimal_face_activate(movement_settings_t *settings, void *context) {
    minute_repeater_decimal_state_t *state = (minute_repeater_decimal_state_t *)context;

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

bool minute_repeater_decimal_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    minute_repeater_decimal_state_t *state = (minute_repeater_decimal_state_t *)context;
    char buf[11];
    uint8_t pos;

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
            movement_play_signal();
            break;
        case EVENT_LIGHT_LONG_UP:
            /*
             * Howdy neighbors, this is the actual complication. Like an actual
             * (very expensive) watch with a repetition minute complication it's
             * boring at 00:00 or 1:00 and very quite musical at 23:59 or 12:59.
             */

            date_time = watch_rtc_get_date_time();
            
            
            int hours = date_time.unit.hour;
            int tens = date_time.unit.minute / 10;
            int minutes = date_time.unit.minute % 10;

            // chiming hours
            if (!settings->bit.clock_mode_24h) {
                hours = date_time.unit.hour % 12;                
                if (hours == 0) hours = 12;
            }
            if (hours > 0) {
                int count = 0;
                for(count = hours; count > 0; --count) {          
                    mrd_play_hour_chime();
                }
                // do a little pause before proceeding to tens
                watch_buzzer_play_note(BUZZER_NOTE_REST, 500);
            }

            // chiming tens (if needed)
            if (tens > 0) {
                int count = 0;
                for(count = tens; count > 0; --count) {          
                    mrd_play_tens_chime();
                }
                // do a little pause before proceeding to minutes
                watch_buzzer_play_note(BUZZER_NOTE_REST, 500);
            }

            // chiming minutes (if needed)
            if (minutes > 0) {
                int count = 0;
                for(count = minutes; count > 0; --count) {          
                    mrd_play_minute_chime();
                }
            }
           
            break; 
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void minute_repeater_decimal_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

bool minute_repeater_decimal_face_wants_background_task(movement_settings_t *settings, void *context) {
    (void) settings;
    minute_repeater_decimal_state_t *state = (minute_repeater_decimal_state_t *)context;
    if (!state->signal_enabled) return false;

    watch_date_time date_time = watch_rtc_get_date_time();

    return date_time.unit.minute == 0;
}
