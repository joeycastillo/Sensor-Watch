#include <stdlib.h>
#include <string.h>
#include "character_set_face.h"
#include "watch.h"

void character_set_face_setup(movement_settings_t *settings, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) *context_ptr = malloc(sizeof(char));
}

void character_set_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    char *c = (char *)context;
    *c = '@';
}

bool character_set_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    char *c = (char *)context;
    char buf[11];
    switch (event.event_type) {
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            movement_illuminate_led();
            break;
        case EVENT_ALARM_BUTTON_UP:
            *c = (*c) + 1;
            if (*c & 0x80) *c = ' ';
            // fall through
        case EVENT_ACTIVATE:
            sprintf(buf, "%c%c%c%c%c%c%c%c%c%c", *c, *c, *c, *c, *c, *c, *c, *c, *c, *c);
            watch_display_string(buf, 0);
            break;
        case EVENT_TICK:
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        default:
            break;
    }

    return true;
}

void character_set_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
