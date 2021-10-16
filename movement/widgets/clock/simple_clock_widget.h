#ifndef SIMPLE_CLOCK_WIDGET_H_
#define SIMPLE_CLOCK_WIDGET_H_

#include "movement.h"

void simple_clock_widget_setup(LauncherSettings *settings, void ** context_ptr);
void simple_clock_widget_activate(LauncherSettings *settings, void *context);
bool simple_clock_widget_loop(LauncherEvent event, LauncherSettings *settings, void *context);
void simple_clock_widget_resign(LauncherSettings *settings, void *context);

uint8_t simple_clock_widget_get_weekday(uint16_t day, uint16_t month, uint16_t year);

#define simple_clock_widget { \
    simple_clock_widget_setup, \
    simple_clock_widget_activate, \
    simple_clock_widget_loop, \
    simple_clock_widget_resign, \
}

#endif // FAKE_WIDGET_H_