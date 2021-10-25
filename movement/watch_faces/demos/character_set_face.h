#ifndef CHARACTER_SET_FACE_H_
#define CHARACTER_SET_FACE_H_

#include "movement.h"

void character_set_face_setup(movement_settings_t *settings, void ** context_ptr);
void character_set_face_activate(movement_settings_t *settings, void *context);
bool character_set_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void character_set_face_resign(movement_settings_t *settings, void *context);

static const watch_face_t character_set_face = {
    character_set_face_setup,
    character_set_face_activate,
    character_set_face_loop,
    character_set_face_resign,
    NULL
};

#endif // CHARACTER_SET_FACE_H_