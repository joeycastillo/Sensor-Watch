#include <stdlib.h>
#include "preferences_widget.h"
#include "watch.h"

#define PREFERENCES_WIDGET_NUM_PREFEFENCES (5)
const char preferences_widget_titles[PREFERENCES_WIDGET_NUM_PREFEFENCES][11] = {"CL", "Bt  Beep", "SC", "Lt   grn", "Lt   red"};

void preferences_widget_setup(LauncherSettings *settings, void ** context_ptr) {
    (void) settings;
    *context_ptr = malloc(sizeof(uint8_t));
}

void preferences_widget_activate(LauncherSettings *settings, void *context) {
    (void) settings;
    *((uint8_t *)context) = 0;
    launcher_request_tick_frequency(4); // we need to manually blink some pixels
}

void preferences_widget_loop(LauncherEvent event, LauncherSettings *settings, uint8_t subsecond, void *context) {
    (void) settings;
    (void) context;
    printf("preferences_widget_loop\n");
    uint8_t current_page = *((uint8_t *)context);
    switch (event) {
        case EVENT_MODE_BUTTON_UP:
            launcher_move_to_next_widget();
            return;
        case EVENT_LIGHT_BUTTON_UP:
            current_page = (current_page + 1) % PREFERENCES_WIDGET_NUM_PREFEFENCES;
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
                    settings->bit.screensaver_interval = settings->bit.screensaver_interval + 1;
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

    watch_clear_display();
    watch_display_string((char *)preferences_widget_titles[current_page], 0);
    if (current_page > 2) {
        // this is a hack, launcher should be able to illumate with a custom color.
        launcher_illuminate_led();
        watch_set_led_color(settings->bit.led_red_color ? (0xF | settings->bit.led_red_color << 4) : 0,
                            settings->bit.led_green_color ? (0xF | settings->bit.led_green_color << 4) : 0);
    } else {
        watch_set_led_off();
    }

    if (subsecond % 2) return;
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
            switch (settings->bit.screensaver_interval) {
                case 0:
                    watch_display_string("never", 4);
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
}

void preferences_widget_resign(LauncherSettings *settings, void *context) {
    (void) settings;
    (void) context;
    watch_set_led_off();
    launcher_request_tick_frequency(1);
}
