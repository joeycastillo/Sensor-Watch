#ifndef BEATS_FACE_H_
#define BEATS_FACE_H_

#include "movement.h"

float clock2beats(uint16_t, uint16_t, uint16_t, uint16_t, int16_t);
void beats_face_setup(movement_settings_t *settings, void ** context_ptr);
void beats_face_activate(movement_settings_t *settings, void *context);
bool beats_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void beats_face_resign(movement_settings_t *settings, void *context);

static const watch_face_t beats_face = {
    beats_face_setup,
    beats_face_activate,
    beats_face_loop,
    beats_face_resign,
    NULL
};

#endif // BEATS_FACE_H_