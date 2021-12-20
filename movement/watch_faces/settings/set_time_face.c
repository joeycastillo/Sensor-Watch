#include <stdlib.h>
#include "set_time_face.h"
#include "watch.h"

#define SET_TIME_FACE_NUM_SETTINGS (7)
const char set_time_face_titles[SET_TIME_FACE_NUM_SETTINGS][3] = {"HR", "M1", "SE", "YR", "MO", "DA", "ZO"};

void set_time_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) *context_ptr = malloc(sizeof(uint8_t));
}

void set_time_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    *((uint8_t *)context) = 0;
    movement_request_tick_frequency(4);
}

bool set_time_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    uint8_t current_page = *((uint8_t *)context);
    const uint8_t days_in_month[12] = {31, 28, 31, 30, 31, 30, 30, 31, 30, 31, 30, 31};
    watch_date_time date_time = watch_rtc_get_date_time();

    switch (event.event_type) {
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            return false;
        case EVENT_LIGHT_BUTTON_UP:
            current_page = (current_page + 1) % SET_TIME_FACE_NUM_SETTINGS;
            *((uint8_t *)context) = current_page;
            break;
        case EVENT_ALARM_BUTTON_UP:
            switch (current_page) {
                case 0: // hour
                    date_time.unit.hour = (date_time.unit.hour + 1) % 24;
                    break;
                case 1: // minute
                    date_time.unit.minute = (date_time.unit.minute + 1) % 60;
                    break;
                case 2: // second
                    date_time.unit.second = 0;
                    break;
                case 3: // year
                    // only allow 2021-2030. fix this sometime next decade
                    date_time.unit.year = ((date_time.unit.year % 10) + 1);
                    break;
                case 4: // month
                    date_time.unit.month = (date_time.unit.month % 12) + 1;
                    break;
                case 5: // day
                    date_time.unit.day = date_time.unit.day + 1;
                    // can't set to the 29th on a leap year. if it's february 29, set to 11:59 on the 28th.
                    // and it should roll over.
                    if (date_time.unit.day > days_in_month[date_time.unit.month - 1]) {
                        date_time.unit.day = 1;
                    }
                    break;
                case 6: // time zone
                    settings->bit.time_zone++;
                    if (settings->bit.time_zone > 40) settings->bit.time_zone = 0;
                    break;
            }
            watch_rtc_set_date_time(date_time);
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        default:
            break;
    }

    char buf[11];
    if (current_page < 3) {
        watch_set_colon();
        if (settings->bit.clock_mode_24h) {
            watch_set_indicator(WATCH_INDICATOR_24H);
            sprintf(buf, "%s  %2d%02d%02d", set_time_face_titles[current_page], date_time.unit.hour, date_time.unit.minute, date_time.unit.second);
        } else {
            sprintf(buf, "%s  %2d%02d%02d", set_time_face_titles[current_page], (date_time.unit.hour % 12) ? (date_time.unit.hour % 12) : 12, date_time.unit.minute, date_time.unit.second);
            if (date_time.unit.hour > 12) watch_set_indicator(WATCH_INDICATOR_PM);
            else watch_clear_indicator(WATCH_INDICATOR_PM);
        }
    } else if (current_page < 6) {
        watch_clear_colon();
        watch_clear_indicator(WATCH_INDICATOR_24H);
        watch_clear_indicator(WATCH_INDICATOR_PM);
        sprintf(buf, "%s  %2d%02d%02d", set_time_face_titles[current_page], date_time.unit.year + 20, date_time.unit.month, date_time.unit.day);
    } else {
        if (event.subsecond % 2) {
            watch_clear_colon();
            sprintf(buf, "%s        ", set_time_face_titles[current_page]);
        } else {
            watch_set_colon();
            sprintf(buf, "%s %3d%02d  ", set_time_face_titles[current_page], (int8_t) (movement_timezone_offsets[settings->bit.time_zone] / 60), (int8_t) (movement_timezone_offsets[settings->bit.time_zone] % 60) * (movement_timezone_offsets[settings->bit.time_zone] < 0 ? -1 : 1));
        }
    }

    // blink up the parameter we're setting
    if (event.subsecond % 2) {
        switch (current_page) {
            case 0:
            case 3:
                buf[4] = buf[5] = ' ';
                break;
            case 1:
            case 4:
                buf[6] = buf[7] = ' ';
                break;
            case 2:
            case 5:
                buf[8] = buf[9] = ' ';
                break;
        }
    }

    watch_display_string(buf, 0);

    return true;
}

void set_time_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    watch_set_led_off();
    movement_request_tick_frequency(1);
    watch_store_backup_data(settings->reg, 0);
}
