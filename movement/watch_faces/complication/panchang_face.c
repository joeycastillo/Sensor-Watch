/*
 * MIT License
 *
 * Copyright (c) 2023 Navaneeth Bhardwaj
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
#include "panchang_face.h"
#include "plib.h"
#include "watch_utility.h"


//Offsets in minutes from 6AM
static uint16_t rahu_kalam_offsets [7] = {
    (60+30),   //Monday 	07:30 AM to 09:00 AM
    (9*60),    //Tuesday 	03:00 PM to 04:30 PM
    (6*60),    //Wednesday 12:00 PM to 01:30 PM
    (7*60+30), //Thursday 	01:30 PM to 03:00 PM
    (4*60+30), //Friday 	10:30 AM to 12:00 PM
    (3*60),    //Saturday 	09:00 AM to 10:30 AM
    (10*60+30) //Sunday    04:30 PM to 06:00 PM
};

void panchang_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(panchang_state_t));
        memset(*context_ptr, 0, sizeof(panchang_state_t));
        // Do any one-time tasks in here; the inside of this conditional happens only at boot.
    }
    // Do any pin or peripheral setup here; this will be called whenever the watch wakes from deep sleep.
}

void panchang_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    panchang_state_t *state = (panchang_state_t *)context;

    // Handle any tasks related to your watch face coming on screen.
}

static void show_panchang(watch_date_time date_time, uint16_t tz_offset)
{
    struct panchanga pdata;
    int dd, mm, yy;
    float hr, zhr;


    date_time = watch_rtc_get_date_time();

    // date_time.unit.year = 3;
    // date_time.unit.month = 3;
    // date_time.unit.day = 6;
    // date_time.unit.hour = 23;
    // date_time.unit.minute = 51;

    hr = date_time.unit.hour;
    hr += date_time.unit.minute/60.0;
    char buf[12] = {0};
    dd = date_time.unit.day;
    mm = date_time.unit.month;
    yy = WATCH_RTC_REFERENCE_YEAR + date_time.unit.year;
    zhr = tz_offset/60.0;

    // Calculate Panchanga
	calculate_panchanga(dd, mm, yy, hr, zhr, &pdata);
	// calculate_panchanga(7, 3, 2023, 21, 5.5, &pdata);
    strncpy(buf, pdata.dpaksha, 2);
    switch(pdata.tithi) {
        case 15: strncpy(buf+2, " P", 2); break;
        case 30: strncpy(buf+2, " A", 2); break;
        default:
            if(pdata.tithi>15)
                pdata.tithi -= 15;
            sprintf(buf+2, "%2d", pdata.tithi);
            break;
    }
    strncpy(buf+4, pdata.dnakshatra, 6);
    printf("Panchang of %d-%d-%d-%f: %s\n",dd,mm,yy,hr, buf);
    watch_display_string(buf, 0);
    // watch_display_string("CR 5Pushya", 0);
}

static void show_rahu_kalam(watch_date_time date_time)
{
    uint8_t weekday = watch_utility_get_iso8601_weekday_number(date_time.unit.year+WATCH_RTC_REFERENCE_YEAR, date_time.unit.month, date_time.unit.day) - 1;
    //All representations are in minutes
    uint16_t sunrise = 6*60; //TODO: Get actual sunrise time for the day
    uint16_t rahu_kalam_start = rahu_kalam_offsets[weekday] + sunrise;
    uint16_t rahu_kalam_end = rahu_kalam_start + 90;
    char buf[12] = {0};

    printf("Rahu kalam for %d is %d to %d\n", weekday, rahu_kalam_start, rahu_kalam_end);

    sprintf(buf, "rt%2d%2d%2d%2d", rahu_kalam_end/60, rahu_kalam_start/60, rahu_kalam_start%60, rahu_kalam_end%60);
    watch_display_string(buf, 0);

}

bool panchang_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    panchang_state_t *state = (panchang_state_t *)context;
    watch_date_time date_time;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            // Show your initial UI here.
            printf("Panchang Activate\n");
            date_time = watch_rtc_get_date_time();
            show_panchang(date_time, movement_timezone_offsets[settings->bit.time_zone]);
            break;
        case EVENT_TICK:
            // If needed, update your display here.
            break;
        case EVENT_LIGHT_BUTTON_UP:
            // You can use the Light button for your own purposes. Note that by default, Movement will also
            // illuminate the LED in response to EVENT_LIGHT_BUTTON_DOWN; to suppress that behavior, add an
            // empty case for EVENT_LIGHT_BUTTON_DOWN.
            break;
        case EVENT_ALARM_BUTTON_UP:
            // Just in case you have need for another button.
            date_time = watch_rtc_get_date_time();
            show_rahu_kalam(date_time);
            break;
        case EVENT_TIMEOUT:
            // Your watch face will receive this event after a period of inactivity. If it makes sense to resign,
            // you may uncomment this line to move back to the first watch face in the list:
            // movement_move_to_face(0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            // If you did not resign in EVENT_TIMEOUT, you can use this event to update the display once a minute.
            // Avoid displaying fast-updating values like seconds, since the display won't update again for 60 seconds.
            // You should also consider starting the tick animation, to show the wearer that this is sleep mode:
            // watch_start_tick_animation(500);
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

void panchang_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

