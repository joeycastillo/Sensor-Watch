#ifndef PULSOMETER_FACE_H_
#define PULSOMETER_FACE_H_

#include "movement.h"

typedef struct {
    bool measuring;
    int16_t pulse;
    int16_t ticks;
} PulsometerState;

void pulsometer_face_setup(movement_settings_t *settings, void ** context_ptr);
void pulsometer_face_activate(movement_settings_t *settings, void *context);
bool pulsometer_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void pulsometer_face_resign(movement_settings_t *settings, void *context);

static const watch_face_t pulsometer_face = {
    pulsometer_face_setup,
    pulsometer_face_activate,
    pulsometer_face_loop,
    pulsometer_face_resign,
    NULL
};

#endif // PULSOMETER_FACE_H_