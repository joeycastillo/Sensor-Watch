#ifndef THERMISTOR_FACE_H_
#define THERMISTOR_FACE_H_

#include "movement.h"

void thermistor_readout_face_setup(movement_settings_t *settings, void ** context_ptr);
void thermistor_readout_face_activate(movement_settings_t *settings, void *context);
bool thermistor_readout_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void thermistor_readout_face_resign(movement_settings_t *settings, void *context);

static const watch_face_t thermistor_readout_face = {
    thermistor_readout_face_setup,
    thermistor_readout_face_activate,
    thermistor_readout_face_loop,
    thermistor_readout_face_resign,
    NULL
};

#endif // THERMISTOR_FACE_H_