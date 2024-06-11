/*
 * MIT License
 *
 * Copyright (c) 2024 Klingon Jane, based on Andreas Nebinger's simple clock bin led face
 * Copyright (c) 2023 Andreas Nebinger, based on Joey Castillo's simple clock face
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

// Emulator only: need time() to seed the random number generator.
#if __EMSCRIPTEN__
#include <time.h>
#endif

#include <stdlib.h>
#include <string.h>
#include "binary_clock_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "watch_private_display.h"

#define BINARY_DISPLAY_MODES 4

static void _update_alarm_indicator(bool settings_alarm_enabled, binary_clock_state_t *state) {
    state->alarm_enabled = settings_alarm_enabled;
    if (state->alarm_enabled) watch_set_indicator(WATCH_INDICATOR_SIGNAL);
    else watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
}

static void build_binary_string(binary_clock_state_t *state, uint8_t dec_value, uint8_t right_index, uint8_t iterations) {
	uint8_t cur_index;
	uint8_t i;
	uint8_t my_value;
	my_value = dec_value;
	cur_index = right_index;
	// Build string right to left on character-wise basis.
	for ( i = 0; i < iterations; i++ )
	{
		if (my_value%2 == 0){
			state->binary_string[cur_index]='0';
			if (cur_index == 2) state->binary_string[cur_index]=' ';	// Difficult location on display, use "-" instead of 0, or space.
		} else {
			state->binary_string[cur_index]='1';
		}
		my_value = my_value / 2;
		cur_index--;
	}
	state->binary_string[10] = (char) 0;  	// Ensure null terminated.
}

static void _display_left_aligned(uint8_t value) {
    if (value >= 10) {
        watch_display_character('0' + value / 10, 4);
        watch_display_character('0' + value % 10, 5);
    } else {
        watch_display_character('0' + value, 4);
        watch_display_character(' ', 5);
    }
}

static int gen_rand_value(uint16_t choices) {
    // Emulator: use rand. Hardware: use arc4random.
	uint8_t rand_value;
    #if __EMSCRIPTEN__
    rand_value = rand() % choices;
    #else
    rand_value = arc4random_uniform(choices);
    #endif
	return rand_value;
}
	
void binary_clock_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(binary_clock_state_t));
        memset(*context_ptr, 0, sizeof(binary_clock_state_t));
        binary_clock_state_t *state = (binary_clock_state_t *)*context_ptr;
        state->watch_face_index = watch_face_index;
    }
    // Emulator only: Seed random number generator
    #if __EMSCRIPTEN__
    srand(time(NULL));
    #endif
}

void binary_clock_face_activate(movement_settings_t *settings, void *context) {
    binary_clock_state_t *state = (binary_clock_state_t *)context;

    if (watch_tick_animation_is_running()) watch_stop_tick_animation();

    if (settings->bit.clock_mode_24h) watch_set_indicator(WATCH_INDICATOR_24H);

    // handle chime indicator
    if (state->signal_enabled) watch_set_indicator(WATCH_INDICATOR_BELL);
    else watch_clear_indicator(WATCH_INDICATOR_BELL);

    // show alarm indicator if there is an active alarm
    _update_alarm_indicator(settings->bit.alarm_enabled, state);

	state->display_mode = 2;	// Start with binary clock face.
    if (state->display_mode<2) watch_set_colon();

    // this ensures that none of the timestamp fields will match, so we can re-render them all.
    state->previous_date_time = 0xFFFFFFFF;
}

bool binary_clock_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    binary_clock_state_t *state = (binary_clock_state_t *)context;
    char buf[11];
    uint8_t pos;

    watch_date_time date_time;
    uint32_t previous_date_time;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
        case EVENT_LOW_ENERGY_UPDATE:
            date_time = watch_rtc_get_date_time();
			uint8_t disp_seconds;
			if (state->display_mode != 1) {
				disp_seconds = date_time.unit.second;
			} else {
				disp_seconds = gen_rand_value(100);
			}
            if (state->flashing_state > 0) {
                if (state->ticks) {
                    state->ticks--;
                } else {
                    
                    if (state->flashing_state & 64) {
                        // start led on for current bit
                        state->flashing_state &= 63;
                        state->ticks = (state->flashing_value & 1 ? 7 : 1);
                        movement_illuminate_led();
                    } else {
                        // indicate first or switch to next bit
                        watch_set_led_off();
                        if ((state->flashing_state & 128) == 0) state->flashing_value = state->flashing_value >> 1;
                        if (state->flashing_value || (state->flashing_state & 128)) {
                            state->flashing_state &= 127;
                            state->flashing_state |= 64;
                            state->ticks = 6;
                        } else if (state->flashing_state & 1) {
                            // transition to minutes
                            state->flashing_state = 2 + 128;
                            state->flashing_value = date_time.unit.minute;
                            _display_left_aligned(state->flashing_value);
                            state->ticks = 9;
                        } else {
                            // end flashing
                            state->flashing_state = 0;
                            state->previous_date_time = 0xFFFFFFFF;
                            movement_request_tick_frequency(1);
                            watch_set_colon();
                        }
                    }
                }
            } else {
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

				// We have 4 modes to support.  Happily the original simple watch face and the random seconds watch face
				// are nearly identical.  We do that here....
				
				if (state->display_mode <= 1 ) {

					if ((date_time.reg >> 6) == (previous_date_time >> 6) && event.event_type != EVENT_LOW_ENERGY_UPDATE) {
						// everything before seconds is the same, don't waste cycles setting those segments.
						watch_display_character_lp_seconds('0' + disp_seconds / 10, 8);
						watch_display_character_lp_seconds('0' + disp_seconds % 10, 9);
						break;
					} else if ((date_time.reg >> 12) == (previous_date_time >> 12) && event.event_type != EVENT_LOW_ENERGY_UPDATE) {
						// everything before minutes is the same.
						pos = 6;
						sprintf(buf, "%02d%02d", date_time.unit.minute, disp_seconds);
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
							sprintf(buf, "%s%2d%2d%02d%02d", watch_utility_get_weekday(date_time), date_time.unit.day, date_time.unit.hour, date_time.unit.minute, disp_seconds);
						}
					}
					watch_display_string(buf, pos);
					// handle alarm indicator
					if (state->alarm_enabled != settings->bit.alarm_enabled) _update_alarm_indicator(settings->bit.alarm_enabled, state);
				} else if ( state->display_mode == 2 ) {
					// Display binary hours on top row, binary minutes on bottom row
					// Must use 12 hour format in this mode to fit in 4 characters
					date_time.unit.hour %= 12;
					if (date_time.unit.hour == 0) date_time.unit.hour = 12;
					build_binary_string(state, date_time.unit.hour, 3, 4);
					build_binary_string(state, date_time.unit.minute, 9, 6);					
					watch_display_string(state->binary_string, 0);
				} else {
					// Display binary minutes on top row, binary seconds on bottom row
					// Will use watch indicators on top row to represent leftmost 0s and 1s
					if ((date_time.reg >> 6) == (previous_date_time >> 6) && event.event_type != EVENT_LOW_ENERGY_UPDATE) {
						// everything before seconds is the same, don't waste cycles setting those segments.
						// Just redo binary seconds
						build_binary_string(state, date_time.unit.second, 9, 6);
					} else {
						// Do all minutes and seconds
						// Leftmost 2 digits of minutes represented by indicators SIGNAL and BELL.
						watch_clear_all_indicators ( );
						watch_set_indicator ( WATCH_INDICATOR_PM );
						watch_set_indicator ( WATCH_INDICATOR_24H );
						if ( date_time.unit.minute >= 32 ) watch_set_indicator ( WATCH_INDICATOR_SIGNAL );
						if ( date_time.unit.minute & 16 ) watch_set_indicator ( WATCH_INDICATOR_BELL );
						// Build least significant 4 binary digits into binary string.
						build_binary_string(state, date_time.unit.minute, 3, 4 );
						// Add binary seconds
						build_binary_string(state, date_time.unit.second, 9, 6);
					}
					watch_display_string(state->binary_string, 0);
				}
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            state->signal_enabled = !state->signal_enabled;
            if (state->signal_enabled) watch_set_indicator(WATCH_INDICATOR_BELL);
            else watch_clear_indicator(WATCH_INDICATOR_BELL);
            break;
        case EVENT_ALARM_BUTTON_DOWN:
			state->display_mode += 1;
			if (state->display_mode >= BINARY_DISPLAY_MODES )
			{
				state->display_mode = 0;
				watch_clear_all_indicators ( );
			}
			if (state->display_mode <= 1 ) watch_set_colon();
			else watch_clear_colon();
            state->previous_date_time = 0xFFFFFFFF;			
			break;
        case EVENT_BACKGROUND_TASK:
            // uncomment this line to snap back to the clock face when the hour signal sounds:
            // movement_move_to_face(state->watch_face_index);
            movement_play_signal();
            break;
        case EVENT_LIGHT_LONG_PRESS:
            if (state->flashing_state == 0) {
                date_time = watch_rtc_get_date_time();
                state->flashing_state = 1 + 128;
                state->ticks = 4;
                if (!settings->bit.clock_mode_24h) {
                    date_time.unit.hour %= 12;
                    if (date_time.unit.hour == 0) date_time.unit.hour = 12;
                }
                watch_display_string("      ", 4);
                _display_left_aligned(date_time.unit.hour);
                state->flashing_value = date_time.unit.hour > 12 ? date_time.unit.hour - 12 : date_time.unit.hour;
                watch_set_led_off();
                watch_clear_colon();
                movement_request_tick_frequency(8);
            }
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void binary_clock_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

bool binary_clock_face_wants_background_task(movement_settings_t *settings, void *context) {
    (void) settings;
    binary_clock_state_t *state = (binary_clock_state_t *)context;
    if (!state->signal_enabled) return false;

    watch_date_time date_time = watch_rtc_get_date_time();

    return date_time.unit.minute == 0;
}
