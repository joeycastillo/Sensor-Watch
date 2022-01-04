#include <stdlib.h>
#include <string.h>
#include "stopwatch_face.h"
#include "watch.h"

void stopwatch_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) *context_ptr = malloc(sizeof(stopwatch_state_t));
}

void stopwatch_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    memset(context, 0, sizeof(stopwatch_state_t));
}

bool stopwatch_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;

    stopwatch_state_t *stopwatch_state = (stopwatch_state_t *)context;
    char buf[14];

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            watch_set_colon();
            stopwatch_state->running = false;
            watch_display_string("st 00000", 0);
            break;
        case EVENT_TICK:
            if (stopwatch_state->running) {
                stopwatch_state->seconds++;
                if (stopwatch_state->seconds == 60) {
                    stopwatch_state->minutes++;
                    stopwatch_state->seconds = 0;
                }
                if (stopwatch_state->minutes == 60) {
                    stopwatch_state->hours++;
                    stopwatch_state->minutes = 0;
                }
            }

            sprintf(buf, "st%2d%02d%02d", stopwatch_state->hours, stopwatch_state->minutes, stopwatch_state->seconds);
            watch_display_string(buf, 0);
            break;
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            movement_illuminate_led();
            if (!stopwatch_state->running) {
                stopwatch_state->seconds = 0;
                stopwatch_state->minutes = 0;
                stopwatch_state->hours = 0;
                watch_display_string("st 00000", 0);
            }
            break;
        case EVENT_ALARM_BUTTON_DOWN:
            stopwatch_state->running = !stopwatch_state->running;
            break;
        case EVENT_TIMEOUT:
            // explicitly ignore the timeout event so we stay on screen
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            stopwatch_state->running = false;
            watch_set_indicator(WATCH_INDICATOR_BELL);
            break;
        default:
            break;
    }

    return true;
}

void stopwatch_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}