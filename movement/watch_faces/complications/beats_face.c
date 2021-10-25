#include <stdlib.h>
#include <string.h>
#include "beats_face.h"
#include "watch.h"

const uint8_t UTC_OFFSET = 4; // set to your current UTC offset to see correct beats time
const uint8_t BEAT_REFRESH_FREQUENCY = 8;

void beats_face_setup(movement_settings_t *settings, void ** context_ptr) {
    (void) settings;
    (void) context_ptr;
}

void beats_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    movement_request_tick_frequency(BEAT_REFRESH_FREQUENCY);
}

bool beats_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    char buf[14];
    float beats;

    watch_date_time date_time;
    switch (event.event_type) {
        case EVENT_TICK:
            date_time = watch_rtc_get_date_time();
            beats = clock2beats(date_time.unit.hour, date_time.unit.minute, date_time.unit.second, event.subsecond, UTC_OFFSET);
            sprintf(buf, "bt  %6.0f", beats * 100);

            watch_display_string(buf, 0);
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            date_time = watch_rtc_get_date_time();
            beats = clock2beats(date_time.unit.hour, date_time.unit.minute, date_time.unit.second, event.subsecond, UTC_OFFSET);
            sprintf(buf, "bt  %4d  ", (int)beats);

            watch_display_string(buf, 0);
            break;
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            movement_illuminate_led();
            break;
        case EVENT_ALARM_BUTTON_DOWN:
        case EVENT_ALARM_BUTTON_UP:
        case EVENT_ALARM_LONG_PRESS:
        default:
            break;
    }

    return true;
}

void beats_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    movement_request_tick_frequency(1);
}

float clock2beats(uint16_t hours, uint16_t minutes, uint16_t seconds, uint16_t subseconds, int16_t utc_offset) {
    float beats = seconds + ((float)subseconds / (float)BEAT_REFRESH_FREQUENCY);
    beats += 60 * minutes;
    beats += (float)hours * 60 * 60;
    beats += (utc_offset + 1) * 60 * 60; // offset from utc + 1 since beats in in UTC+1

    beats /= 86.4; // convert to beats
    while(beats > 1000) beats -= 1000; // beats %= 1000 but for a float

    return beats;
}