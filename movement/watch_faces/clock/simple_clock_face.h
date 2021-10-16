#ifndef SIMPLE_CLOCK_FACE_H_
#define SIMPLE_CLOCK_FACE_H_

#include "movement.h"

void simple_clock_face_setup(LauncherSettings *settings, void ** context_ptr);
void simple_clock_face_activate(LauncherSettings *settings, void *context);
bool simple_clock_face_loop(LauncherEvent event, LauncherSettings *settings, void *context);
void simple_clock_face_resign(LauncherSettings *settings, void *context);

uint8_t simple_clock_face_get_weekday(uint16_t day, uint16_t month, uint16_t year);

#define simple_clock_face { \
    simple_clock_face_setup, \
    simple_clock_face_activate, \
    simple_clock_face_loop, \
    simple_clock_face_resign, \
}

#endif // FAKE_FACE_H_