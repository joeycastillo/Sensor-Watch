#include <stdlib.h>
#include "simple_clock_face.h"
#include "watch.h"

void simple_clock_face_setup(movement_settings_t *settings, void ** context_ptr) {
    (void) settings;
    // the only context we need is the timestamp of the previous tick.
    if (*context_ptr == NULL) *context_ptr = malloc(sizeof(uint32_t));
}

void simple_clock_face_activate(movement_settings_t *settings, void *context) {
    if (settings->bit.clock_mode_24h) {
        watch_set_indicator(WATCH_INDICATOR_24H);
    }
    watch_set_colon();
    // this ensures that none of the timestamp fields will match, so we can re-render them all.
    *((uint32_t *)context) = 0xFFFFFFFF;
}

bool simple_clock_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    printf("simple_clock_face_loop\n");
    const char weekdays[7][3] = {"SA", "SU", "MO", "TU", "WE", "TH", "FR"};
    char buf[11];
    uint8_t pos;

    watch_date_time date_time;
    uint32_t previous_date_time;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
        case EVENT_LOW_POWER_TICK:
            date_time = watch_rtc_get_date_time();
            previous_date_time = *((uint32_t *)context);
            *((uint32_t *)context) = date_time.reg;

            if (date_time.reg >> 6 == previous_date_time >> 6 && event.event_type != EVENT_LOW_POWER_TICK) {
                // everything before seconds is the same, don't waste cycles setting those segments.
                pos = 8;
                sprintf(buf, "%02d", date_time.unit.second);
            } else if (date_time.reg >> 12 == previous_date_time >> 12 && event.event_type != EVENT_LOW_POWER_TICK) {
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
                if (event.event_type == EVENT_LOW_POWER_TICK) {
                    sprintf(buf, "%s%2d%2d%02d  ", weekdays[simple_clock_face_get_weekday(date_time.unit.year, date_time.unit.month, date_time.unit.day)], date_time.unit.day, date_time.unit.hour, date_time.unit.minute);
                } else {
                    sprintf(buf, "%s%2d%2d%02d%02d", weekdays[simple_clock_face_get_weekday(date_time.unit.year, date_time.unit.month, date_time.unit.day)], date_time.unit.day, date_time.unit.hour, date_time.unit.minute, date_time.unit.second);
                }
            }
            watch_display_string(buf, pos);
            break;
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            return false;
        case EVENT_LIGHT_BUTTON_UP:
            movement_illuminate_led();
            break;
        case EVENT_ALARM_BUTTON_UP:
            break;
        default:
            break;
    }

    return true;
}

void simple_clock_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

uint8_t simple_clock_face_get_weekday(uint16_t year, uint16_t month, uint16_t day) {
    year += 20;
    if (month <= 2) {
        month += 12;
        year--;
    }
    return (day + 13 * (month + 1) / 5 + year + year / 4 + 525) % 7;
}
