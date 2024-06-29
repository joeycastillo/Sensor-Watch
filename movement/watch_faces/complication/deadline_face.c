/*
 * MIT License
 *
 * Copyright (c) 2023-2024 Konrad Rieck
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to the
 * following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT
 * OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/*
 * # Deadline Face
 * 
 * This is a watch face for tracking deadlines.  It draws inspiration from
 * other watch faces of the project but focuses on keeping track of
 * deadlines.  You can enter and monitor up to four different deadlines by
 * providing their respective date and time.  The face has two modes:
 * *running mode* and *settings mode*.
 *
 * ## Running Mode
 * 
 * When the watch face is activated, it defaults to running mode.  The top
 * right corner shows the current deadline number, and the main display
 * presents the time left until the deadline.  The format of the display
 * varies depending on the remaining time.
 *
 * - When less than a day is left, the display shows the remaining hours,
 *   minutes, and seconds in the form `HH:MM:SS`.
 * 
 * - When less than a month is left, the display shows the remaining days
 *   and hours in the form `DD:HH` with the unit `dy` for days.
 * 
 * - When less than a year is left, the display shows the remaining months
 *   and days in the form `MM:DD` with the unit `mo` for months.
 * 
 * - When more than a year is left, the years and months are displayed in
 *   the form `YY:MM` with the unit `yr` for years.
 * 
 * - When a deadline has passed in the last 24 hours, the display shows
 *   `over` to indicate that the deadline has just recently been reached.
 * 
 * - When no deadline is set for a particular slot, or if a deadline has
 *   already passed by more than 24 hours, `--:--` is displayed.
 * 
 * The user can navigate in running mode using the following buttons:
 * 
 * - The *alarm button* moves the next deadline.  There are currently four
 *   slots available for deadlines.  When the last slot has been reached,
 *   pressing the button moves to the first slot.
 *
 * - A *long press* on the *alarm button* activates settings mode and
 *   enables configuring the currently selected deadline.
 * 
 * - A *long press* on the *light button* activates a deadline alarm.  The 
 *   bell icon is displayed, and the alarm will ring upon reaching any of
 *   the deadlines set.  It is important to note that the watch will not 
 *   enter low-energy sleep mode while the alarm is enabled.
 *
 *
 * ## Settings Mode
 * 
 * In settings mode, the currently selected slot for a deadline can be
 * configured by providing the date and the time.  Like running mode, the
 * top right corner of the display indicates the current deadline number. 
 * The main display shows the date and, on the next page, the time to be
 * configured.
 *
 * The user can use the following buttons in settings mode.
 *
 * - The *light button* navigates through the different date and time
 *   settings, going from year, month, day, hour, to minute.  The selected
 *   position is blinking.
 *
 * - A *long press* on the light button resets the date and time to the next
 *   day at midnight.  This is the default deadline.
 *
 * - The *alarm button* increments the currently selected position.  A *long
 *   press* on the *alarm button* changes the value faster.
 *
 * - The *mode button* exists setting mode and returns to *running mode*. 
 *   Here the selected deadline slot can be changed.
 *
 */

#include <stdlib.h>
#include <string.h>
#include "deadline_face.h"
#include "watch.h"
#include "watch_utility.h"

#define SETTINGS_NUM (5)
const char settings_titles[SETTINGS_NUM][3] = { "YR", "MO", "DA", "HR", "M1" };

/* Local functions */
static void _running_init(movement_settings_t *settings, deadline_state_t *state);
static bool _running_loop(movement_event_t event, movement_settings_t *settings, void *context);
static void _running_display(movement_event_t event, movement_settings_t *settings, deadline_state_t *state);
static void _setting_init(movement_settings_t *settings, deadline_state_t *state);
static bool _setting_loop(movement_event_t event, movement_settings_t *settings, void *context);
static void _setting_display(movement_event_t event, movement_settings_t *settings, deadline_state_t *state, watch_date_time date);

/* Utility functions */
static void _background_alarm_play(movement_settings_t *settings, deadline_state_t *state);
static void _background_alarm_schedule(movement_settings_t *settings, deadline_state_t *state);
static void _background_alarm_cancel(movement_settings_t *settings, deadline_state_t *state);
static void _increment_date(movement_settings_t *settings, deadline_state_t *state, watch_date_time date_time);
static inline int32_t _get_tz_offset(movement_settings_t *settings);
static inline void _change_tick_freq(uint8_t freq, deadline_state_t *state);
static inline bool _is_leap(int16_t y);
static inline int _days_in_month(int16_t mpnth, int16_t y);
static inline unsigned int _mod(int a, int b);
static inline void _beep_button(movement_settings_t *settings);
static inline void _beep_enable(movement_settings_t *settings);
static inline void _beep_disable(movement_settings_t *settings);
static inline void _reset_deadline(movement_settings_t *settings, deadline_state_t *state);

/* Check for leap year */
static inline bool _is_leap(int16_t y)
{
    y += 1900;
    return !(y % 4) && ((y % 100) || !(y % 400));
}

/* Modulo function */
static inline unsigned int _mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}

/* Return days in month */
static inline int _days_in_month(int16_t month, int16_t year)
{
    uint8_t days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    month = _mod(month - 1, 12);

    if (month == 1 && _is_leap(year)) {
        return days[month] + 1;
    } else {
        return days[month];
    }
}

/* Return time zone offset */
static inline int32_t _get_tz_offset(movement_settings_t *settings)
{
    return movement_timezone_offsets[settings->bit.time_zone] * 60;
}

/* Beep for a button press*/
static inline void _beep_button(movement_settings_t *settings)
{
    // Play a beep as confirmation for a button press (if applicable)
    if (!settings->bit.button_should_sound)
        return;

    watch_buzzer_play_note(BUZZER_NOTE_C7, 50);
}

/* Beep for entering settings */
static inline void _beep_enable(movement_settings_t *settings)
{
    if (!settings->bit.button_should_sound)
        return;

    watch_buzzer_play_note(BUZZER_NOTE_G7, 50);
    watch_buzzer_play_note(BUZZER_NOTE_REST, 75);
    watch_buzzer_play_note(BUZZER_NOTE_C8, 75);
}

/* Beep for leaving settings */
static inline void _beep_disable(movement_settings_t *settings)
{
    if (!settings->bit.button_should_sound)
        return;

    watch_buzzer_play_note(BUZZER_NOTE_C8, 50);
    watch_buzzer_play_note(BUZZER_NOTE_REST, 75);
    watch_buzzer_play_note(BUZZER_NOTE_G7, 75);
}

/* Change tick frequency */
static inline void _change_tick_freq(uint8_t freq, deadline_state_t *state)
{
    if (state->tick_freq != freq) {
        movement_request_tick_frequency(freq);
        state->tick_freq = freq;
    }
}

/* Determine index of closest deadline */
static uint8_t _closest_deadline(movement_settings_t *settings, deadline_state_t *state)
{
    watch_date_time now = watch_rtc_get_date_time();
    uint32_t now_ts = watch_utility_date_time_to_unix_time(now, _get_tz_offset(settings));
    uint32_t min_ts = UINT32_MAX;
    uint8_t min_index = 0;

    for (uint8_t i = 0; i < DEADLINE_FACE_DATES; i++) {
        if (state->deadlines[i] < now_ts || state->deadlines[i] > min_ts)
            continue;
        min_ts = state->deadlines[i];
        min_index = i;
    }

    return min_index;
}

/* Play background alarm */
static void _background_alarm_play(movement_settings_t *settings, deadline_state_t *state)
{
    (void) settings;

    /* Use the default alarm from movement and move to foreground */
    if (state->alarm_enabled) {
        movement_play_alarm();
        movement_move_to_face(state->face_idx);
    }
}

/* Schedule background alarm */
static void _background_alarm_schedule(movement_settings_t *settings, deadline_state_t *state)
{
    /* We simply re-use the scheduling in the background task */
    deadline_face_wants_background_task(settings, state);
}

/* Cancel background alarm */
static void _background_alarm_cancel(movement_settings_t *settings, deadline_state_t *state)
{
    (void) settings;

    movement_cancel_background_task_for_face(state->face_idx);
}

/* Reset deadline to tomorrow */
static inline void _reset_deadline(movement_settings_t *settings, deadline_state_t *state)
{
    /* Get current time and reset hours/minutes/seconds */
    watch_date_time date_time = watch_rtc_get_date_time();
    date_time.unit.second = 0;
    date_time.unit.minute = 0;
    date_time.unit.hour = 0;

    /* Add 24 hours to obtain first second of tomorrow */
    uint32_t ts = watch_utility_date_time_to_unix_time(date_time, _get_tz_offset(settings));
    ts += 24 * 60 * 60;

    state->deadlines[state->current_index] = ts;
}

/* Increment date in settings mode. Function taken from `set_time_face.c` */
static void _increment_date(movement_settings_t *settings, deadline_state_t *state, watch_date_time date_time)
{
    const uint8_t days_in_month[12] = { 31, 28, 31, 30, 31, 30, 30, 31, 30, 31, 30, 31 };

    switch (state->current_page) {
        case 0:
            /* Only 10 years covered. Fix this sometime next decade */
            date_time.unit.year = ((date_time.unit.year % 10) + 1);
            break;
        case 1:
            date_time.unit.month = (date_time.unit.month % 12) + 1;
            break;
        case 2:
            date_time.unit.day = date_time.unit.day + 1;

            /* Check for leap years */
            int8_t days = days_in_month[date_time.unit.month - 1];
            if (date_time.unit.month == 2 && _is_leap(date_time.unit.year))
                days++;

            if (date_time.unit.day > days)
                date_time.unit.day = 1;
            break;
        case 3:
            date_time.unit.hour = (date_time.unit.hour + 1) % 24;
            break;
        case 4:
            date_time.unit.minute = (date_time.unit.minute + 1) % 60;
            break;
    }

    uint32_t ts = watch_utility_date_time_to_unix_time(date_time, _get_tz_offset(settings));
    state->deadlines[state->current_index] = ts;
}

/* Update display in running mode */
static void _running_display(movement_event_t event, movement_settings_t *settings, deadline_state_t *state)
{
    (void) event;
    (void) settings;

    /* Seconds, minutes, hours, days, months, years */
    int16_t unit[] = { 0, 0, 0, 0, 0, 0 };
    uint8_t i, range[] = { 60, 60, 24, 30, 12, 0 };
    char buf[16];

    /* Display indicators */
    if (state->alarm_enabled)
        watch_set_indicator(WATCH_INDICATOR_BELL);
    else
        watch_clear_indicator(WATCH_INDICATOR_BELL);

    watch_date_time now = watch_rtc_get_date_time();
    uint32_t now_ts = watch_utility_date_time_to_unix_time(now, _get_tz_offset(settings));

    /* Deadline expired */
    if (state->deadlines[state->current_index] < now_ts) {
        if (state->deadlines[state->current_index] + 24 * 60 * 60 > now_ts)
            sprintf(buf, "DL%2dOVER  ", state->current_index + 1);
        else
            sprintf(buf, "DL%2d----  ", state->current_index + 1);

        //watch_clear_indicator(WATCH_INDICATOR_BELL);
        watch_display_string(buf, 0);
        return;
    }

    /* Get date time structs */
    watch_date_time deadline = watch_utility_date_time_from_unix_time(state->deadlines[state->current_index], _get_tz_offset(settings)
        );

    /* Calculate naive difference of dates */
    unit[0] = deadline.unit.second - now.unit.second;
    unit[1] = deadline.unit.minute - now.unit.minute;
    unit[2] = deadline.unit.hour - now.unit.hour;
    unit[3] = deadline.unit.day - now.unit.day;
    unit[4] = deadline.unit.month - now.unit.month;
    unit[5] = deadline.unit.year - now.unit.year;

    /* Correct errors of naive difference */
    for (i = 0; i < 6; i++) {
        if (unit[i] < 0) {
            /* Correct remaining units */
            if (i == 3)
                unit[i] += _days_in_month(deadline.unit.month - 1, deadline.unit.year);
            else
                unit[i] += range[i];

            /* Carry over change to next unit if non-zero */
            if (i < 5 && unit[i + 1] != 0)
                unit[i + 1] -= 1;
        }
    }

    /* Set range */
    i = state->current_index + 1;
    if (unit[5] > 0) {
        /* years:months */
        sprintf(buf, "DL%2d%02d%02dYR", i, unit[5] % 100, unit[4] % 12);
    } else if (unit[4] > 0) {
        /* months:days */
        sprintf(buf, "DL%2d%02d%02dMO", i, (unit[5] * 12 + unit[4]) % 100, unit[3] % 32);
    } else if (unit[3] > 0) {
        /* days:hours */
        sprintf(buf, "DL%2d%02d%02ddY", i, unit[3] % 32, unit[2] % 24);
    } else {
        /* hours:minutes:seconds */
        sprintf(buf, "DL%2d%02d%02d%02d", i, unit[2] % 24, unit[1] % 60, unit[0] % 60);
    }
    watch_display_string(buf, 0);
}

/* Init running mode */
static void _running_init(movement_settings_t *settings, deadline_state_t *state)
{
    (void) settings;
    (void) state;

    watch_clear_indicator(WATCH_INDICATOR_24H);
    watch_clear_indicator(WATCH_INDICATOR_PM);
    watch_set_colon();

    /* Ensure 1Hz updates only */
    _change_tick_freq(1, state);
}

/* Loop of running mode */
static bool _running_loop(movement_event_t event, movement_settings_t *settings, void *context)
{
    deadline_state_t *state = (deadline_state_t *) context;

    if (event.event_type != EVENT_BACKGROUND_TASK)
        _running_display(event, settings, state);

    switch (event.event_type) {
        case EVENT_ALARM_BUTTON_UP:
            _beep_button(settings);
            state->current_index = (state->current_index + 1) % DEADLINE_FACE_DATES;
            _running_display(event, settings, state);
            break;
        case EVENT_ALARM_LONG_PRESS:
            _beep_enable(settings);
            _setting_init(settings, state);
            state->mode = DEADLINE_FACE_SETTING;
            break;
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            return false;
        case EVENT_LIGHT_BUTTON_DOWN:
            break;
        case EVENT_LIGHT_LONG_PRESS:
            _beep_button(settings);
            state->alarm_enabled = !state->alarm_enabled;
            if (state->alarm_enabled) {
                _background_alarm_schedule(settings, context);
            } else {
                _background_alarm_cancel(settings, context);
            }
            _running_display(event, settings, state);
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        case EVENT_BACKGROUND_TASK:
            _background_alarm_play(settings, state);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

/* Update display in settings mode */
static void _setting_display(movement_event_t event, movement_settings_t *settings, deadline_state_t *state, watch_date_time date_time)
{
    char buf[11];

    int i = state->current_index + 1;
    if (state->current_page > 2) {
        watch_set_colon();
        if (settings->bit.clock_mode_24h) {
            watch_set_indicator(WATCH_INDICATOR_24H);
            sprintf(buf, "%s%2d%2d%02d  ", settings_titles[state->current_page], i, date_time.unit.hour, date_time.unit.minute);
        } else {
            sprintf(buf, "%s%2d%2d%02d  ", settings_titles[state->current_page], i, (date_time.unit.hour % 12) ? (date_time.unit.hour % 12) : 12,
                    date_time.unit.minute);
            if (date_time.unit.hour < 12)
                watch_clear_indicator(WATCH_INDICATOR_PM);
            else
                watch_set_indicator(WATCH_INDICATOR_PM);
        }
    } else {
        watch_clear_colon();
        watch_clear_indicator(WATCH_INDICATOR_24H);
        watch_clear_indicator(WATCH_INDICATOR_PM);
        sprintf(buf, "%s%2d%2d%02d%02d", settings_titles[state->current_page], i, date_time.unit.year + 20, date_time.unit.month, date_time.unit.day);
    }

    /* Blink up the parameter we are setting */
    if (event.subsecond % 2) {
        switch (state->current_page) {
            case 0:
            case 3:
                buf[4] = buf[5] = ' ';
                break;
            case 1:
            case 4:
                buf[6] = buf[7] = ' ';
                break;
            case 2:
                buf[8] = buf[9] = ' ';
                break;
        }
    }

    watch_display_string(buf, 0);
}

/* Init setting mode */
static void _setting_init(movement_settings_t *settings, deadline_state_t *state)
{
    state->current_page = 0;

    /* Init fresh deadline to next day */
    if (state->deadlines[state->current_index] == 0) {
        _reset_deadline(settings, state);
    }

    /* Ensure 1Hz updates only */
    _change_tick_freq(1, state);
}

/* Loop of setting mode */
static bool _setting_loop(movement_event_t event, movement_settings_t *settings, void *context)
{
    deadline_state_t *state = (deadline_state_t *) context;
    watch_date_time date_time;
    date_time = watch_utility_date_time_from_unix_time(state->deadlines[state->current_index], _get_tz_offset(settings));

    if (event.event_type != EVENT_BACKGROUND_TASK)
        _setting_display(event, settings, state, date_time);

    switch (event.event_type) {
        case EVENT_TICK:
            if (state->tick_freq == 8) {
                if (watch_get_pin_level(BTN_ALARM)) {
                    _increment_date(settings, state, date_time);
                    _setting_display(event, settings, state, date_time);
                } else {
                    _change_tick_freq(4, state);
                }
            }
            break;
        case EVENT_ALARM_LONG_PRESS:
            _change_tick_freq(8, state);
            break;
        case EVENT_ALARM_LONG_UP:
            _change_tick_freq(4, state);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            _beep_button(settings);
            _reset_deadline(settings, state);
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            break;
        case EVENT_LIGHT_BUTTON_UP:
            state->current_page = (state->current_page + 1) % SETTINGS_NUM;
            _setting_display(event, settings, state, date_time);
            break;
        case EVENT_ALARM_BUTTON_UP:
            _change_tick_freq(4, state);
            _increment_date(settings, state, date_time);
            _setting_display(event, settings, state, date_time);
            break;
        case EVENT_TIMEOUT:
            _beep_button(settings);
            _background_alarm_schedule(settings, context);
            _change_tick_freq(1, state);
            state->mode = DEADLINE_FACE_RUNNING;
            movement_move_to_face(0);
            break;
        case EVENT_MODE_BUTTON_UP:
            _beep_disable(settings);
            _background_alarm_schedule(settings, context);
            _running_init(settings, state);
            _running_display(event, settings, state);
            state->mode = DEADLINE_FACE_RUNNING;
            break;
        case EVENT_BACKGROUND_TASK:
            _background_alarm_play(settings, state);
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

/* Setup face */
void deadline_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr)
{
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr != NULL)
        return; /* Skip setup if context available */

    /* Allocate state */
    *context_ptr = malloc(sizeof(deadline_state_t));
    memset(*context_ptr, 0, sizeof(deadline_state_t));

    /* Store face index for background tasks */
    deadline_state_t *state = (deadline_state_t *) *context_ptr;
    state->face_idx = watch_face_index;
}

/* Activate face */
void deadline_face_activate(movement_settings_t *settings, void *context)
{
    (void) settings;
    deadline_state_t *state = (deadline_state_t *) context;

    /* Set display options */
    _running_init(settings, state);
    state->mode = DEADLINE_FACE_RUNNING;
    state->current_index = _closest_deadline(settings, state);
}

/* Loop face */
bool deadline_face_loop(movement_event_t event, movement_settings_t *settings, void *context)
{
    (void) settings;
    deadline_state_t *state = (deadline_state_t *) context;
    switch (state->mode) {
        case DEADLINE_FACE_SETTING:
            _setting_loop(event, settings, context);
            break;
        default:
        case DEADLINE_FACE_RUNNING:
            _running_loop(event, settings, context);
            break;
    }

    return true;
}

/* Resign face */
void deadline_face_resign(movement_settings_t *settings, void *context)
{
    (void) settings;
    (void) context;
}

/* Want background task */
bool deadline_face_wants_background_task(movement_settings_t *settings, void *context)
{
    deadline_state_t *state = (deadline_state_t *) context;

    if (!state->alarm_enabled)
        return false;

    /* Determine closest deadline */
    watch_date_time now = watch_rtc_get_date_time();
    uint32_t now_ts = watch_utility_date_time_to_unix_time(now, _get_tz_offset(settings));
    uint32_t next_ts = state->deadlines[_closest_deadline(settings, state)];

    /* No active deadline */
    if (next_ts < now_ts)
        return false;

    /* No deadline within next 60 seconds */
    if (next_ts >= now_ts + 60)
        return false;

    /* Deadline within next minute. Let's set up an alarm */
    watch_date_time next = watch_utility_date_time_from_unix_time(next_ts, _get_tz_offset(settings));
    movement_request_wake();
    movement_schedule_background_task_for_face(state->face_idx, next);
    return false;
}
