#ifndef SET_TIME_FACE_H_
#define SET_TIME_FACE_H_

#include "movement.h"

void set_time_face_setup(LauncherSettings *settings, void ** context_ptr);
void set_time_face_activate(LauncherSettings *settings, void *context);
bool set_time_face_loop(LauncherEvent event, LauncherSettings *settings, void *context);
void set_time_face_resign(LauncherSettings *settings, void *context);

#define set_time_face { \
    set_time_face_setup, \
    set_time_face_activate, \
    set_time_face_loop, \
    set_time_face_resign, \
}

#endif // SET_TIME_FACE_H_
