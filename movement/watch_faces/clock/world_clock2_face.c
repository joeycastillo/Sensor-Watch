/*
 * MIT License
 *
 * Copyright (c) 2023 Konrad Rieck
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
#include <string.h>
#include "world_clock2_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "watch_utility.h"

static bool refresh_face;

/* Simple macros for navigation */
#define FORWARD             +1
#define BACKWARD            -1

/* Activate refresh of time */
#define REFRESH_TIME        0xffffffff

/* List of all time zone names */
const char *zone_names[] = {
    "UTC",	//  0 :   0:00:00 (UTC)
    "CET",	//  1 :   1:00:00 (Central European Time)
    "SAST",	//  2 :   2:00:00 (South African Standard Time)
    "ARST",	//  3 :   3:00:00 (Arabia Standard Time)
    "IRST",	//  4 :   3:30:00 (Iran Standard Time)
    "GET",	//  5 :   4:00:00 (Georgia Standard Time)
    "AFT",	//  6 :   4:30:00 (Afghanistan Time)
    "PKT",	//  7 :   5:00:00 (Pakistan Standard Time)
    "IST",	//  8 :   5:30:00 (Indian Standard Time)
    "NPT",	//  9 :   5:45:00 (Nepal Time)
    "KGT",	// 10 :   6:00:00 (Kyrgyzstan time)
    "MYST",	// 11 :   6:30:00 (Myanmar Time)
    "THA",	// 12 :   7:00:00 (Thailand Standard Time)
    "CST",	// 13 :   8:00:00 (China Standard Time, Australian Western Standard Time)
    "ACWS",	// 14 :   8:45:00 (Australian Central Western Standard Time)
    "JST",	// 15 :   9:00:00 (Japan Standard Time, Korea Standard Time)
    "ACST",	// 16 :   9:30:00 (Australian Central Standard Time)
    "AEST",	// 17 :  10:00:00 (Australian Eastern Standard Time)
    "LHST",	// 18 :  10:30:00 (Lord Howe Standard Time)
    "SBT",	// 19 :  11:00:00 (Solomon Islands Time)
    "NZST",	// 20 :  12:00:00 (New Zealand Standard Time)
    "CHAS",	// 21 :  12:45:00 (Chatham Standard Time)
    "TOT",	// 22 :  13:00:00 (Tonga Time)
    "CHAD",	// 23 :  13:45:00 (Chatham Daylight Time)
    "LINT",	// 24 :  14:00:00 (Line Islands Time)
    "BIT",	// 25 : -12:00:00 (Baker Island Time)
    "NUT",	// 26 : -11:00:00 (Niue Time)
    "HST",	// 27 : -10:00:00 (Hawaii-Aleutian Standard Time)
    "MART",	// 28 :  -9:30:00 (Marquesas Islands Time)
    "AKST",	// 29 :  -9:00:00 (Alaska Standard Time)
    "PST",	// 30 :  -8:00:00 (Pacific Standard Time)
    "MST",	// 31 :  -7:00:00 (Mountain Standard Time)
    "CST",	// 32 :  -6:00:00 (Central Standard Time)
    "EST",	// 33 :  -5:00:00 (Eastern Standard Time)
    "VET",	// 34 :  -4:30:00 (Venezuelan Standard Time)
    "AST",	// 35 :  -4:00:00 (Atlantic Standard Time)
    "NST",	// 36 :  -3:30:00 (Newfoundland Standard Time)
    "BRT",	// 37 :  -3:00:00 (Brasilia Time)
    "NDT",	// 38 :  -2:30:00 (Newfoundland Daylight Time)
    "FNT",	// 39 :  -2:00:00 (Fernando de Noronha Time)
    "AZOT",	// 40 :  -1:00:00 (Azores Standard Time)
};

/* Modulo function */
static inline unsigned int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}

/* Find the next selected time zone */
static inline uint8_t find_selected_zone(world_clock2_state_t *state, int direction)
{
    uint8_t i = state->current_zone;

    do {
	i = mod(i + direction, NUM_TIME_ZONES);
	/* Could not find a selected zone. Return UTC */
	if (i == state->current_zone) {
	    return 0;
	}
    } while (!state->zones[i].selected);

    return i;
}

/* Beep when zone is enabled. An octave up */
static void beep_enable() {
    watch_buzzer_play_note(BUZZER_NOTE_G7, 50);
    watch_buzzer_play_note(BUZZER_NOTE_REST, 75);
    watch_buzzer_play_note(BUZZER_NOTE_C8, 75);
}

/* Beep when zone id disable. An octave down */
static void beep_disable() {
    watch_buzzer_play_note(BUZZER_NOTE_C8, 50);
    watch_buzzer_play_note(BUZZER_NOTE_REST, 75);
    watch_buzzer_play_note(BUZZER_NOTE_G7, 75);
}

void world_clock2_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr)
{
    (void) settings;
    (void) watch_face_index;

    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(world_clock2_state_t));
        memset(*context_ptr, 0, sizeof(world_clock2_state_t));

        /* Start in settings mode */
        world_clock2_state_t *state = (world_clock2_state_t *) * context_ptr;
        state->current_mode = WORLD_CLOCK2_MODE_SETTINGS;
    }
}

void world_clock2_face_activate(movement_settings_t *settings, void *context)
{
    (void) settings;
    world_clock2_state_t *state = (world_clock2_state_t *) context;

    if (watch_tick_animation_is_running())
        watch_stop_tick_animation();

    switch (state->current_mode) {
        case WORLD_CLOCK2_MODE_DISPLAY:
            /* Normal tick frequency */
            movement_request_tick_frequency(1);
            break;
        case WORLD_CLOCK2_MODE_SETTINGS:
            /* Faster frequency for blinking effect */
            movement_request_tick_frequency(4);
            break;
    }
    refresh_face = true;
}

static bool mode_display(movement_event_t event, movement_settings_t *settings, world_clock2_state_t *state)
{
    char buf[11];
    uint8_t pos;

    uint32_t timestamp;
    uint32_t previous_date_time;
    watch_date_time date_time;

    switch (event.event_type) {
	case EVENT_ACTIVATE:
	case EVENT_TICK:
	case EVENT_LOW_ENERGY_UPDATE:
	    /* Update indicators and colon on refresh */
	    if (refresh_face) {
		watch_clear_indicator(WATCH_INDICATOR_SIGNAL);
		watch_set_colon();
                if (settings->bit.clock_mode_24h)
                    watch_set_indicator(WATCH_INDICATOR_24H);

                state->previous_date_time = REFRESH_TIME;
                refresh_face = false;
            }

            /* Determine current time at time zone and store date/time */
	    date_time = watch_rtc_get_date_time();
	    timestamp = watch_utility_date_time_to_unix_time(date_time, movement_timezone_offsets[settings->bit.time_zone] * 60);
	    date_time = watch_utility_date_time_from_unix_time(timestamp, movement_timezone_offsets[state->current_zone] * 60);
	    previous_date_time = state->previous_date_time;
	    state->previous_date_time = date_time.reg;

	    if ((date_time.reg >> 6) == (previous_date_time >> 6) && event.event_type != EVENT_LOW_ENERGY_UPDATE) {
                /* Everything before seconds is the same, don't waste cycles setting those segments. */
		pos = 8;
		sprintf(buf, "%02d", date_time.unit.second);
	    } else if ((date_time.reg >> 12) == (previous_date_time >> 12) && event.event_type != EVENT_LOW_ENERGY_UPDATE) {
		/* Everything before minutes is the same. */
		pos = 6;
		sprintf(buf, "%02d%02d", date_time.unit.minute, date_time.unit.second);
	    } else {
		/* Other stuff changed; Let's do it all. */
		if (!settings->bit.clock_mode_24h) {
		    /* If we are in 12 hour mode, do some cleanup. */
		    if (date_time.unit.hour < 12) {
			watch_clear_indicator(WATCH_INDICATOR_PM);
		    } else {
			watch_set_indicator(WATCH_INDICATOR_PM);
		    }
		    date_time.unit.hour %= 12;
		    if (date_time.unit.hour == 0)
			date_time.unit.hour = 12;
		}

		pos = 0;
		if (event.event_type == EVENT_LOW_ENERGY_UPDATE) {
		    if (!watch_tick_animation_is_running())
			watch_start_tick_animation(500);

		    sprintf(buf, "%.2s%2d%2d%02d  ",
                            zone_names[state->current_zone],
                            date_time.unit.day,
                            date_time.unit.hour,
                            date_time.unit.minute);
		} else {
		    sprintf(buf, "%.2s%2d%2d%02d%02d",
			    zone_names[state->current_zone],
                            date_time.unit.day,
                            date_time.unit.hour,
                            date_time.unit.minute,
                            date_time.unit.second);
		}
	    }
	    watch_display_string(buf, pos);
	    break;
	case EVENT_ALARM_BUTTON_UP:
	    state->current_zone = find_selected_zone(state, FORWARD);
            state->previous_date_time = REFRESH_TIME;
	    break;
	case EVENT_LIGHT_BUTTON_DOWN:
	    /* Do nothing. */
	    break;
	case EVENT_LIGHT_BUTTON_UP:
	    state->current_zone = find_selected_zone(state, BACKWARD);
            state->previous_date_time = REFRESH_TIME;
	    break;
	case EVENT_LIGHT_LONG_PRESS:
	    movement_illuminate_led();
	    break;
	case EVENT_ALARM_LONG_PRESS:
	    /* Switch to settings mode */
	    state->current_mode = WORLD_CLOCK2_MODE_SETTINGS;
	    refresh_face = true;
            movement_request_tick_frequency(1);

            if (settings->bit.button_should_sound)
                watch_buzzer_play_note(BUZZER_NOTE_C8, 50);
	    break;
        case EVENT_MODE_BUTTON_UP:
            /* Reset frequency and move to next face */
            movement_request_tick_frequency(1);
            movement_move_to_next_face();
            break;
	default:
	    return movement_default_loop_handler(event, settings);
    }

    return true;
}

static bool mode_settings(movement_event_t event, movement_settings_t *settings, world_clock2_state_t *state)
{
    char buf[11];
    int8_t hours, minutes;
    uint8_t zone;
    div_t result;

    switch (event.event_type) {
	case EVENT_ACTIVATE:
	case EVENT_TICK:
	case EVENT_LOW_ENERGY_UPDATE:
            /* Update indicator and colon on refresh */
            if (refresh_face) {
                watch_clear_colon();
                watch_clear_indicator(WATCH_INDICATOR_24H);
                watch_clear_indicator(WATCH_INDICATOR_PM);
                refresh_face = false;
            }
	    result = div(movement_timezone_offsets[state->current_zone], 60);
	    hours = result.quot;
	    minutes = result.rem;

	    /*
	     * Display time zone. The range of the parameters is reduced
	     * to avoid accidentally overflowing the buffer and to suppress
	     * corresponding compiler warnings.
	     */
	    sprintf(buf, "%.2s%2d %c%02d%02d",
                    zone_names[state->current_zone],
                    state->current_zone % 100,
                    hours < 0 ? '-' : '+',
                    abs(hours) % 24,
		    abs(minutes) % 60);

            /* Let the zone number blink */
            if (event.subsecond % 2)
                buf[2] = buf[3] = ' ';

	    if (state->zones[state->current_zone].selected)
		watch_set_indicator(WATCH_INDICATOR_SIGNAL);
	    else
		watch_clear_indicator(WATCH_INDICATOR_SIGNAL);

	    watch_display_string(buf, 0);
	    break;
	case EVENT_ALARM_BUTTON_UP:
	    state->current_zone = mod(state->current_zone + FORWARD, NUM_TIME_ZONES);
	    break;
	case EVENT_LIGHT_BUTTON_UP:
	    state->current_zone = mod(state->current_zone + BACKWARD, NUM_TIME_ZONES);
	    break;
	case EVENT_LIGHT_BUTTON_DOWN:
	    /* Do nothing */
	    break;
	case EVENT_ALARM_LONG_PRESS:
	    /* Find next selected zone */
	    if (!state->zones[state->current_zone].selected)
		state->current_zone = find_selected_zone(state, FORWARD);

	    /* Switch to display mode */
	    state->current_mode = WORLD_CLOCK2_MODE_DISPLAY;
	    refresh_face = true;
            movement_request_tick_frequency(1);

            if (settings->bit.button_should_sound)
                watch_buzzer_play_note(BUZZER_NOTE_C8, 50);
	    break;
	case EVENT_LIGHT_LONG_PRESS:
	    /* Toggle selection of current zone */
	    zone = state->current_zone;
	    state->zones[zone].selected = !state->zones[zone].selected;

            if (settings->bit.button_should_sound) {
                if (state->zones[zone].selected) {
                    beep_enable();
                } else {
                    beep_disable();
                }
            }
            break;
        case EVENT_MODE_BUTTON_UP:
            /* Reset frequency and move to next face */
            movement_request_tick_frequency(1);
            movement_move_to_next_face();
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

bool world_clock2_face_loop(movement_event_t event, movement_settings_t *settings, void *context)
{
    world_clock2_state_t *state = (world_clock2_state_t *) context;
    switch (state->current_mode) {
	case WORLD_CLOCK2_MODE_DISPLAY:
	    return mode_display(event, settings, state);
	case WORLD_CLOCK2_MODE_SETTINGS:
	    return mode_settings(event, settings, state);
    }
    return false;
}

void world_clock2_face_resign(movement_settings_t *settings, void *context)
{
    (void) settings;
    (void) context;
}
