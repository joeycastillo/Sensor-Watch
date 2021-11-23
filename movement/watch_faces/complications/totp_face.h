#ifndef TOTP_FACE_H_
#define TOTP_FACE_H_

#include "movement.h"

void totp_face_setup(movement_settings_t *settings, void ** context_ptr);
void totp_face_activate(movement_settings_t *settings, void *context);
bool totp_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void totp_face_resign(movement_settings_t *settings, void *context);

static const watch_face_t totp_face = {
    totp_face_setup,
    totp_face_activate,
    totp_face_loop,
    totp_face_resign,
    NULL
};

#endif // TOTP_FACE_H_