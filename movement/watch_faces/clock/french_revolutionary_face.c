/*
 * MIT License
 *
 * Copyright (c) 2023 CarpeNoctem
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
#include "french_revolutionary_face.h"

void french_revolutionary_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(french_revolutionary_state_t));
        memset(*context_ptr, 0, sizeof(french_revolutionary_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
        french_revolutionary_state_t *state = (french_revolutionary_state_t *)*context_ptr;
        state->use_am_pm = false;
        state->show_seconds = true;
        state->display_type = 0;
        state->colon_set_after_splash = false;
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void french_revolutionary_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    french_revolutionary_state_t *state = (french_revolutionary_state_t *)context;

    // Handle any tasks related to your watch face coming on screen.
    state->colon_set_after_splash = false;
}

bool french_revolutionary_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    french_revolutionary_state_t *state = (french_revolutionary_state_t *)context;

    char buf[11];
    watch_date_time date_time;
    fr_decimal_time decimal_time;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Initial UI - Show a quick "splash screen"
            watch_clear_display();
            watch_display_string("FR  dECimL", 0);
            break;
        case EVENT_TICK:
        case EVENT_LOW_ENERGY_UPDATE:

            date_time = watch_rtc_get_date_time();

            decimal_time = get_decimal_time(&date_time);

            set_display_buffer(buf, state, &decimal_time, &date_time);

            // If we're in low-energy mode, don't write out the seconds. Also start the LE tick animation if it's not already going.
            if (event.event_type == EVENT_LOW_ENERGY_UPDATE) {
                buf[8] = ' ';
                buf[9] = ' ';
                if (!watch_tick_animation_is_running()) { watch_start_tick_animation(500); }
            }

            // Update the display with our decimal time
            watch_display_string(buf, 0);

            // Oh, and a one-off to set the colon after the "splash screen"
            if (!state->colon_set_after_splash) {
                watch_set_colon();
                state->colon_set_after_splash = true;
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            state->display_type += 1 ; // cycle through the display types
            if (state->display_type > 2) { state->display_type = 0; } // but return to 0 after 2
            break;
        case EVENT_ALARM_LONG_PRESS:
            // I originally had chiming on the decimal-hour enabled, and this would enable/disable that chime, just like on
            // the simple clock and decimal time faces. But because decimal seconds don't always line up with normal seconds,
            // I assume the (decimal-)hourly chime could sometimes be missed. Additionally, I need this button for other purposes,
            // now that I added seconds on/off toggle and upper normal-time with the ability to toggle that between 12/24hr format.
            state->show_seconds = !state->show_seconds;
            if (!state->show_seconds) { watch_display_string("  ", 8); }
            else { watch_display_string("--", 8); }
            break;
        case EVENT_LIGHT_LONG_PRESS:
            // In case anyone really wants that upper time in 12-hour format. I thought about using the global setting (settings->bit.clock_mode_24h)
            // for this preference, but thought someone who prefers 12-hour format normally, might prefer 24hr when compared to a 10hr decimal day,
            // so this is separate for now.
            state->use_am_pm = !state->use_am_pm;
            if (state->use_am_pm) {
                watch_clear_indicator(WATCH_INDICATOR_24H);
                date_time = watch_rtc_get_date_time();
                if (date_time.unit.hour < 12) { watch_clear_indicator(WATCH_INDICATOR_PM); }
                else { watch_set_indicator(WATCH_INDICATOR_PM); }
            } else {
                watch_clear_indicator(WATCH_INDICATOR_PM);
                watch_set_indicator(WATCH_INDICATOR_24H);
            }
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

void french_revolutionary_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

// Calculate decimal time from normal (24hr) time
fr_decimal_time get_decimal_time(watch_date_time *date_time) {
    uint32_t current_24hr_secs, current_decimal_seconds;
    fr_decimal_time decimal_time;
    // Current 24-hr time in seconds (There are 86400 of these in a day.)
    current_24hr_secs = date_time->unit.hour * 3600 + date_time->unit.minute * 60 + date_time->unit.second;

    // Current Decimal Time in seconds. There are 100000 seconds in a 10-hr decimal-time day.
    // current_decimal_seconds = current_24hr_seconds * 100000 / 86400, or = current_24_seconds * 1000 / 864;
    // By chopping the extra zeros off the end, we can use uint32 instead of uint64.
    current_decimal_seconds = current_24hr_secs * 1000 / 864;

    decimal_time.hour = current_decimal_seconds / 10000;
    // Remove the hours from total seconds and keep the remainder for below.
    current_decimal_seconds = current_decimal_seconds - decimal_time.hour * 10000;

    decimal_time.minute = current_decimal_seconds / 100;
    // Remove the minutes from total seconds and keep the remaining seconds
    // Note: I think I used an extra seconds variable here because sprintf or movement weren't liking a uint32...
    decimal_time.second = current_decimal_seconds - decimal_time.minute * 100;
    return decimal_time;
}

// Fills in the display buffer, depending on the currently-selected display option (and sub-options):
// - Decimal-time only
// - Decimal-time with date in top-right
// - Decimal-time with normal time in the top (minutes first, then hours, due to display limitations)
// TODO: There is some power-saving stuff that simple clock does here around not redrawing characters that haven't changed, but we're not doing that here.
//       I'll try to add that optimization could be added in a future commit.
void set_display_buffer(char *buf, french_revolutionary_state_t *state, fr_decimal_time *decimal_time, watch_date_time *date_time) {
    switch (state->display_type) {
                // Decimal time only
                case 0:
                    // Originally I had the day slot set to "FR" (French Revolutionary time), but my brain kept thinking "Friday" whenever I saw it,
                    // so I changed it to dT (Decimal Time) to avoid that confusion. Apologies to anyone who has the other decimal_time face and this one
                    // installed concurrently. Maybe the splash screen will help a little.
                    sprintf( buf, "dT  %2d%02d%02d", decimal_time->hour, decimal_time->minute, decimal_time->second );
                    watch_clear_indicator(WATCH_INDICATOR_PM);
                    watch_clear_indicator(WATCH_INDICATOR_24H);
                    break;
                // Decimal time and date
                case 1:
                    sprintf( buf, "dT%2d%2d%02d%02d",  date_time->unit.day, decimal_time->hour, decimal_time->minute, decimal_time->second );
                    watch_clear_indicator(WATCH_INDICATOR_PM);
                    watch_clear_indicator(WATCH_INDICATOR_24H);
                    break;
                // Decimal time on bottom, normal time above
                case 2:
                    if (state->use_am_pm) {
                        // if we are in 12 hour mode, do some cleanup.
                        watch_clear_indicator(WATCH_INDICATOR_24H);
                        if (date_time->unit.hour < 12) {
                            watch_clear_indicator(WATCH_INDICATOR_PM);
                        } else {
                            watch_set_indicator(WATCH_INDICATOR_PM);
                        }
                        date_time->unit.hour %= 12;
                        if (date_time->unit.hour == 0) date_time->unit.hour = 12;
                    } else {
                        watch_clear_indicator(WATCH_INDICATOR_PM);
                        watch_set_indicator(WATCH_INDICATOR_24H);
                    }
                    // Note, the date digits don't display a leading zero well, so we don't use it.
                    sprintf( buf, "%02d%2d%2d%02d%02d", date_time->unit.minute, date_time->unit.hour, decimal_time->hour, decimal_time->minute, decimal_time->second );
                    
                    // Make the second character of the Day area more readable
                    buf[1] = fix_character_one(buf[1]);
                    break;
            }
            // Finally, if show_seconds is disabled, trim those off.
            if (!state->show_seconds) {
                buf[8] = ' ';
                buf[9] = ' ';
            }
}

// Sadly, the second character of the Day field cannot show all numbers, so we make some replacements.
// See https://www.sensorwatch.net/docs/wig/display/#limitations-of-the-weekday-digits
char fix_character_one(char digit) {
    char return_char = digit; // We don't need to update this for 0, 1, 3, 7 and 8.
    switch(digit) {
        case '2':
            // Roman numeral / tally representation of 2
            return_char = '|'; // Thanks, Joey, for already having this in the character set.
            break;
        case '4':
            // Looks almost like a 4 - just missing the top-left segment.
            // 0b01000110
            return_char = '&'; // Slight hack - I want 0b01000110, but 0b01000100 is already in the character set and will do, since B and C segments are linked in this position.
            break;
        case '5':
            return_char = 'F'; // F for Five
            break;
        case '6':
            return_char = 'E'; // Looks almost like a 6 - just missing the bottom-right segment. Not super happy with it, but liked it best of the options I tried.
            break;
        case '9':
            return_char = 'N'; // N for Nine
            break;
    }
    return return_char;
}
