#ifndef PREFERENCES_FACE_H_
#define PREFERENCES_FACE_H_

#include "movement.h"

void preferences_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void preferences_face_activate(movement_settings_t *settings, void *context);
bool preferences_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void preferences_face_resign(movement_settings_t *settings, void *context);

static const watch_face_t preferences_face = {
    preferences_face_setup,
    preferences_face_activate,
    preferences_face_loop,
    preferences_face_resign,
    NULL
};

#endif // PREFERENCES_FACE_H_