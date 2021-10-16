#ifndef PULSEOMETER_FACE_H_
#define PULSEOMETER_FACE_H_

#include "movement.h"

typedef struct {
    bool measuring;
    int16_t pulse;
    int16_t ticks;
} PulsometerState;

void pulseometer_face_setup(movement_settings_t *settings, void ** context_ptr);
void pulseometer_face_activate(movement_settings_t *settings, void *context);
bool pulseometer_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void pulseometer_face_resign(movement_settings_t *settings, void *context);

#define pulseometer_face { \
    pulseometer_face_setup, \
    pulseometer_face_activate, \
    pulseometer_face_loop, \
    pulseometer_face_resign, \
    NULL, \
}

#endif // PULSEOMETER_FACE_H_