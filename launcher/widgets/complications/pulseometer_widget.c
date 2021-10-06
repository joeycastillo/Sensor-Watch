#include <stdlib.h>
#include <string.h>
#include "pulseometer_widget.h"
#include "watch.h"

void pulseometer_widget_setup(LauncherSettings *settings, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) *context_ptr = malloc(sizeof(PulsometerState));
}

void pulseometer_widget_activate(LauncherSettings *settings, void *context) {
    (void) settings;
    memset(context, 0, sizeof(PulsometerState));
}

bool pulseometer_widget_loop(LauncherEvent event, LauncherSettings *settings, void *context) {
    printf("pulseometer_widget_loop\n");
    (void) settings;
    PulsometerState *pulsometer_state = (PulsometerState *)context;
    char buf[14];
    // starts at index 15
    const uint8_t pulse_lookup[] = {240, 225, 212, 200, 189, 180, 171, 164, 157, 150, 144, 138, 133, 129, 124, 120, 116, 113, 109, 106, 103, 100, 97, 95, 92, 90, 88, 86, 84, 82, 80, 78, 77, 75, 73, 72, 71, 69, 68, 67, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 55, 54, 53, 52, 51, 51, 50, 49, 49, 48, 47, 47, 46, 46, 45, 44, 44, 43, 43, 42, 42, 41, 41, 40, 40, 40};
    switch (event.event_type) {
        case EVENT_TICK:
            if (pulsometer_state->pulse == 0 && !pulsometer_state->measuring) {
                switch (pulsometer_state->ticks % 5) {
                    case 0:
                        watch_display_string("  Hold  ", 2);
                        break;
                    case 1:
                        watch_display_string(" Alarn", 4);
                        break;
                    case 2:
                        watch_display_string("+   Count ", 0);
                        break;
                    case 3:
                        watch_display_string("  30Beats ", 0);
                        break;
                    case 4:
                        watch_clear_display();
                        break;
                }
                pulsometer_state->ticks++;
            } else {
                if (pulsometer_state->ticks < 15) {
                    watch_display_string("        Lo", 0);
                } else if (pulsometer_state->ticks > 91) {
                    watch_display_string("        Hi", 0);
                } else {
                    if (pulsometer_state->measuring) pulsometer_state->pulse = pulse_lookup[pulsometer_state->ticks - 15];
                    sprintf(buf, "    %-3dbpn", pulsometer_state->pulse);
                    watch_display_string(buf, 0);
                }
                if (pulsometer_state->measuring) pulsometer_state->ticks++;
            }
            return false;
        case EVENT_MODE_BUTTON_UP:
            launcher_move_to_next_widget();
            return false;
        case EVENT_LIGHT_BUTTON_UP:
            launcher_illuminate_led();
            break;
        case EVENT_ALARM_BUTTON_DOWN:
            pulsometer_state->ticks = 0;
            pulsometer_state->measuring = true;
            launcher_request_tick_frequency(2);
            break;
        case EVENT_ALARM_BUTTON_UP:
        case EVENT_ALARM_LONG_PRESS:
            pulsometer_state->measuring = false;
            launcher_request_tick_frequency(1);
            break;
        default:
            break;
    }

    return true;
}

void pulseometer_widget_resign(LauncherSettings *settings, void *context) {
    (void) settings;
    (void) context;
}
