#include <stdlib.h>
#include <string.h>
#include "demo_face.h"
#include "watch.h"

typedef enum {
    DEMO_FACE_HELLO = 0,
    DEMO_FACE_TIME,
    DEMO_FACE_WORLD_TIME,
    DEMO_FACE_BEATS,
    DEMO_FACE_TEMP_F,
    DEMO_FACE_TEMP_C,
    DEMO_FACE_BATTERY_VOLTAGE,
    DEMO_FACE_NUM_FACES
} demo_face_index_t;

void demo_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(demo_face_index_t));
        memset(*context_ptr, 0, sizeof(demo_face_index_t));
    }
}

void demo_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    movement_request_tick_frequency(0);
    // ensure the watch never enters low energy mode
    settings->bit.le_interval = 0;
}

bool demo_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    demo_face_index_t *screen = (demo_face_index_t *)context;
    switch (event.event_type) {
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            movement_illuminate_led();
            break;
        case EVENT_ALARM_BUTTON_UP:
            *screen = ((*screen) + 1) % DEMO_FACE_NUM_FACES;
            // fall through
        case EVENT_ACTIVATE:
            switch (*screen) {
                case DEMO_FACE_HELLO:
                    watch_display_string("    Hello ", 0);
                    watch_clear_colon();
                    break;
                case DEMO_FACE_TIME:
                    watch_display_string("TH 6101036", 0);
                    watch_set_colon();
                    break;
                case DEMO_FACE_WORLD_TIME:
                    watch_display_string("MT 6 81036", 0);
                    break;
                case DEMO_FACE_BEATS:
                    watch_display_string("bt   64125", 0);
                    watch_clear_colon();
                    break;
                case DEMO_FACE_TEMP_F:
                    watch_display_string("TE  72.1#F", 0);
                    break;
                case DEMO_FACE_TEMP_C:
                    watch_display_string("TE  22.3#C", 0);
                    break;
                case DEMO_FACE_BATTERY_VOLTAGE:
                    watch_display_string("BA  2.97 V", 0);
                    break;
                case DEMO_FACE_NUM_FACES:
                    // we won't get here, but silence the warning
                    break;
            }
            break;
        case EVENT_TIMEOUT:
            // ignore timeout
            break;
        default:
            break;
    }

    return true;
}

void demo_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    movement_request_tick_frequency(1);
}
