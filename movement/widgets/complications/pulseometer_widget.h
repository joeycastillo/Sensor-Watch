#ifndef PULSEOMETER_WIDGET_H_
#define PULSEOMETER_WIDGET_H_

#include "movement.h"

typedef struct {
    bool measuring;
    int16_t pulse;
    int16_t ticks;
} PulsometerState;

void pulseometer_widget_setup(LauncherSettings *settings, void ** context_ptr);
void pulseometer_widget_activate(LauncherSettings *settings, void *context);
bool pulseometer_widget_loop(LauncherEvent event, LauncherSettings *settings, void *context);
void pulseometer_widget_resign(LauncherSettings *settings, void *context);

#define pulseometer_widget { \
    pulseometer_widget_setup, \
    pulseometer_widget_activate, \
    pulseometer_widget_loop, \
    pulseometer_widget_resign, \
}

#endif // PULSEOMETER_WIDGET_H_