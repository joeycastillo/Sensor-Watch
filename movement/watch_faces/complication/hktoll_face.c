/*
 * MIT License
 *
 * Copyright (c) 2024 alanho
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
#include "hktoll_face.h"
#include "watch_utility.h"
#include "watch_private_display.h"

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

void hktoll_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void **context_ptr)
{
    (void)settings;
    (void)watch_face_index;
    if (*context_ptr == NULL)
    {
        *context_ptr = malloc(sizeof(hktoll_state_t));
        memset(*context_ptr, 0, sizeof(hktoll_state_t));
    }
}

void hktoll_face_activate(movement_settings_t *settings, void *context)
{
    (void) settings;
    (void) context;
}

const char tunnel_names[3] = {'C', 'W', 'E'};
const uint8_t toll_schemes[2][3] = {{20, 40, 30}, {20, 60, 30}}; // non-peak, peak, normal
const uint8_t toll_holiday[2] = {20, 25};
const uint8_t tunnel_index_to_toll_scheme[3] = {0, 1, 0};

bool hktoll_face_loop(movement_event_t event, movement_settings_t *settings, void *context)
{
    char buf[4];
    uint8_t toll;
    watch_date_time date_time = watch_rtc_get_date_time();
    hktoll_state_t *state = (hktoll_state_t *)context;

    switch (event.event_type)
    {
    case EVENT_ACTIVATE:
        state->public_holiday = hktoll_is_likely_public_holiday(date_time);
        break;
    case EVENT_ALARM_LONG_PRESS:
        state->public_holiday = !(state->public_holiday);
        break;
    case EVENT_ALARM_BUTTON_UP:
        state->tunnel_index = (state->tunnel_index + 1) % 3;
        break;
    case EVENT_TICK:
        break;
    case EVENT_TIMEOUT:
        movement_move_to_face(0);
        return true;
        break;
    default:
        return movement_default_loop_handler(event, settings);
    }

    watch_display_character((state->public_holiday ? 'H' : ' '), 3);

    // display tunnel name
    watch_display_character(tunnel_names[state->tunnel_index], 0);

    toll = state->public_holiday ? hktoll_get_toll_for_holiday(date_time) : hktoll_get_toll_for_normal_day(date_time, state->tunnel_index);

    sprintf(buf, "%02d", toll);
    watch_display_string(buf, 6);

    return true;
}

void hktoll_face_resign(movement_settings_t *settings, void *context)
{
    (void)settings;
    (void)context;
}

bool hktoll_is_likely_public_holiday(watch_date_time date_time)
{
    // Check if the day is a Sunday
    if (watch_utility_get_iso8601_weekday_number(date_time.unit.year + WATCH_RTC_REFERENCE_YEAR, date_time.unit.month, date_time.unit.day) == 7)
    {
        return true;
    }

    // best effort, not exhaustive. these are fixed dates holiday
    // user can always long press alarm button to switch to holiday mode
    static const uint8_t known_public_holidays[6][2] = {
        {1, 1},   // New Year's Day
        {5, 1},   // Labour Day
        {7, 1},   // HKSAR Day
        {10, 1},  // National Day
        {12, 25}, // Christmas
        {12, 26}  // Boxing Day
    };

    // Check if current date matches any known public holiday
    uint8_t month = date_time.unit.month;
    uint8_t day = date_time.unit.day;

    for (uint8_t i = 0; i < 6; i++)
    {
        if (month < known_public_holidays[i][0])
            break; // Early exit if past current month
        if (month == known_public_holidays[i][0] && day == known_public_holidays[i][1])
            return true;
    }

    return false;
}

uint8_t hktoll_get_toll_for_holiday(watch_date_time date_time)
{
    uint8_t holiday_toll_normal = toll_holiday[0];
    uint8_t holiday_toll_peak = toll_holiday[1];

    // Convert time to minutes since midnight for easier comparison
    uint16_t minutes = date_time.unit.hour * 60 + date_time.unit.minute;

    // Before 10:11 (611 minutes)
    if (minutes < 611)
    {
        return holiday_toll_normal;
    }
    // 10:11-10:14 transition period
    else if (minutes < 615)
    {
        // round up to nearest even
        return holiday_toll_peak - (((615 - minutes) + 1) & ~1);
    }
    // 10:15-19:15 peak period (615-1155 minutes)
    else if (minutes < 1155)
    {
        return holiday_toll_peak;
    }
    // 19:15-19:18 transition period
    else if (minutes < 1159)
    {
        return holiday_toll_peak - (((minutes - 1155) + 2) & ~1); // round up to next even 0 > 2, 1 > 2, 2 > 4, 3 > 4
    }
    // After 19:19
    else
    {
        return holiday_toll_normal;
    }
}

uint8_t hktoll_get_toll_for_normal_day(watch_date_time date_time, tunnel_index_t tunnel_index)
{
    uint16_t minutes = date_time.unit.hour * 60 + date_time.unit.minute;
    const uint8_t *scheme = toll_schemes[tunnel_index_to_toll_scheme[tunnel_index]];

    // 7:30am
    if (minutes < 450)
    {
        return scheme[0]; // non-peak
    }
    else if (minutes < 615)
    { // 10:15am
        return MIN(scheme[1], (scheme[0] + (((minutes - 450) / 2) + 1) * 2));
    }
    else if (minutes < 990)
    { // 16:30
        return MAX(scheme[2], (scheme[1] - (((minutes - 615) / 2) + 1) * 2));
    }
    else if (minutes < 1140)
    { // 19:00
        return MIN(scheme[1], (scheme[2] + (((minutes - 990) / 2) + 1) * 2));
    }
    else
    {
        return MAX(scheme[0], (scheme[1] - (((minutes - 1140) / 2) + 1) * 2));
    }
}
