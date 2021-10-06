#include <stdlib.h>
#include <string.h>
#include "pulseometer_widget.h"
#include "watch.h"

#define PULSOMETER_WIDGET_FREQUENCY_FACTOR (4ul) // refresh rate will be 2 to this power Hz (0 for 1 Hz, 2 for 4 Hz, etc.)
#define PULSOMETER_WIDGET_FREQUENCY (1 << PULSOMETER_WIDGET_FREQUENCY_FACTOR)

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
                pulsometer_state->ticks = (pulsometer_state->ticks + 1) % 5;
            } else {
                if (pulsometer_state->measuring && pulsometer_state->ticks) {
                    pulsometer_state->pulse = (int16_t)((30.0 * ((float)(60 << PULSOMETER_WIDGET_FREQUENCY_FACTOR) / (float)pulsometer_state->ticks)) + 0.5);
                }
                if (pulsometer_state->pulse > 240) {
                    watch_display_string("        Hi", 0);
                } else if (pulsometer_state->pulse < 40) {
                    watch_display_string("        Lo", 0);
                } else {
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
            pulsometer_state->pulse = 0xFFFF;
            pulsometer_state->measuring = true;
            launcher_request_tick_frequency(PULSOMETER_WIDGET_FREQUENCY);
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