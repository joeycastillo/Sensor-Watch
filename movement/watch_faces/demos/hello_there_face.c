#include <stdlib.h>
#include <string.h>
#include "hello_there_face.h"
#include "watch.h"

void hello_there_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(hello_there_state_t));
        memset(*context_ptr, 0, sizeof(hello_there_state_t));
    }
}

void hello_there_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    hello_there_state_t *state = (hello_there_state_t *)context;
    state->current_word = 0;
    state->animating = true;
}

bool hello_there_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    hello_there_state_t *state = (hello_there_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
            if (state->animating) {
                if (state->current_word == 0) watch_display_string("Hello ", 4);
                else watch_display_string(" there", 4);
                state->current_word = (state->current_word + 1) % 2;
            }
            break;
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_UP:
            movement_illuminate_led();
            break;
        case EVENT_ALARM_BUTTON_UP:
            state->animating = !state->animating;   
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
        default:
            break;
    }

    return true;
}

void hello_there_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
