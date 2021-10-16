#ifndef PULSEOMETER_FACE_H_
#define PULSEOMETER_FACE_H_

#include "movement.h"

typedef struct {
    bool measuring;
    int16_t pulse;
    int16_t ticks;
} PulsometerState;

void pulseometer_face_setup(LauncherSettings *settings, void ** context_ptr);
void pulseometer_face_activate(LauncherSettings *settings, void *context);
bool pulseometer_face_loop(LauncherEvent event, LauncherSettings *settings, void *context);
void pulseometer_face_resign(LauncherSettings *settings, void *context);

#define pulseometer_face { \
    pulseometer_face_setup, \
    pulseometer_face_activate, \
    pulseometer_face_loop, \
    pulseometer_face_resign, \
}

#endif // PULSEOMETER_FACE_H_