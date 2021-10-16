#ifndef PREFERENCES_FACE_H_
#define PREFERENCES_FACE_H_

#include "movement.h"

void preferences_face_setup(LauncherSettings *settings, void ** context_ptr);
void preferences_face_activate(LauncherSettings *settings, void *context);
bool preferences_face_loop(LauncherEvent event, LauncherSettings *settings, void *context);
void preferences_face_resign(LauncherSettings *settings, void *context);

#define preferences_face { \
    preferences_face_setup, \
    preferences_face_activate, \
    preferences_face_loop, \
    preferences_face_resign, \
}

#endif // PREFERENCES_FACE_H_