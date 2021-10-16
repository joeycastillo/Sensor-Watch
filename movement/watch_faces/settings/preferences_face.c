#include <stdlib.h>
#include "preferences_face.h"
#include "watch.h"

#define PREFERENCES_FACE_NUM_PREFEFENCES (5)
const char preferences_face_titles[PREFERENCES_FACE_NUM_PREFEFENCES][11] = {"CL        ", "Bt  Beep  ", "SC        ", "Lt   grn  ", "Lt   red  "};

void preferences_face_setup(movement_settings_t *settings, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) *context_ptr = malloc(sizeof(uint8_t));
}

void preferences_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    *((uint8_t *)context) = 0;
    movement_request_tick_frequency(4); // we need to manually blink some pixels
}

bool preferences_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    printf("preferences_face_loop\n");
    uint8_t current_page = *((uint8_t *)context);
    switch (event.event_type) {
        case EVENT_MODE_BUTTON_UP:
            watch_set_led_off();
            movement_move_to_next_face();
            return false;
        case EVENT_LIGHT_BUTTON_UP:
            current_page = (current_page + 1) % PREFERENCES_FACE_NUM_PREFEFENCES;
            *((uint8_t *)context) = current_page;
            break;
        case EVENT_ALARM_BUTTON_UP:
            switch (current_page) {
                case 0:
                    settings->bit.clock_mode_24h = !(settings->bit.clock_mode_24h);
                    break;
                case 1:
                    settings->bit.button_should_sound = !(settings->bit.button_should_sound);
                    break;
                case 2:
                    settings->bit.le_inactivity_interval = settings->bit.le_inactivity_interval + 1;
                    break;
                case 3:
                    settings->bit.led_green_color = settings->bit.led_green_color + 1;
                    break;
                case 4:
                    settings->bit.led_red_color = settings->bit.led_red_color + 1;
                    break;
            }
            break;
        default:
            break;
    }

    watch_display_string((char *)preferences_face_titles[current_page], 0);

    if (event.subsecond % 2) return current_page <= 2;
    char buf[3];
    switch (current_page) {
        case 0:
            if (settings->bit.clock_mode_24h) watch_display_string("24h", 4);
            else watch_display_string("12h", 4);
            break;
        case 1:
            if (settings->bit.button_should_sound) watch_display_string("y", 9);
            else watch_display_string("n", 9);
            break;
        case 2:
            switch (settings->bit.le_inactivity_interval) {
                case 0:
                    watch_display_string(" never", 4);
                    break;
                case 1:
                    watch_display_string("1 hour", 4);
                    break;
                case 2:
                    watch_display_string("2 hour", 4);
                    break;
                case 3:
                    watch_display_string("6 hour", 4);
                    break;
                case 4:
                    watch_display_string("12 hr", 4);
                    break;
                case 5:
                    watch_display_string(" 1 day", 4);
                    break;
                case 6:
                    watch_display_string(" 2 day", 4);
                    break;
                case 7:
                    watch_display_string(" 7 day", 4);
                    break;
            }
            break;
        case 3:
            sprintf(buf, "%2d", settings->bit.led_green_color);
            watch_display_string(buf, 8);
            break;
        case 4:
            sprintf(buf, "%2d", settings->bit.led_red_color);
            watch_display_string(buf, 8);
            break;
    }

    if (current_page > 2) {
        watch_set_led_color(settings->bit.led_red_color ? (0xF | settings->bit.led_red_color << 4) : 0,
                            settings->bit.led_green_color ? (0xF | settings->bit.led_green_color << 4) : 0);
        return false;
    }

    watch_set_led_off();
    return true;
}

void preferences_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    watch_set_led_off();
    movement_request_tick_frequency(1);
}
