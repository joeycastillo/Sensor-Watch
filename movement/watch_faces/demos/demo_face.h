#ifndef DEMO_FACE_H_
#define DEMO_FACE_H_

#include "movement.h"

void demo_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void demo_face_activate(movement_settings_t *settings, void *context);
bool demo_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void demo_face_resign(movement_settings_t *settings, void *context);

static const watch_face_t demo_face = {
    demo_face_setup,
    demo_face_activate,
    demo_face_loop,
    demo_face_resign,
    NULL
};

#endif // DEMO_FACE_H_