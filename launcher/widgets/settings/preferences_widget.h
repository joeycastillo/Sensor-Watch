#ifndef PREFERENCES_WIDGET_H_
#define PREFERENCES_WIDGET_H_

#include "launcher.h"

void preferences_widget_setup(LauncherSettings *settings, void ** context_ptr);
void preferences_widget_activate(LauncherSettings *settings, void *context);
void preferences_widget_loop(LauncherEvent event, LauncherSettings *settings, uint8_t subsecond, void *context);
void preferences_widget_resign(LauncherSettings *settings, void *context);

#define preferences_widget { \
    preferences_widget_setup, \
    preferences_widget_activate, \
    preferences_widget_loop, \
    preferences_widget_resign, \
}

#endif // PREFERENCES_WIDGET_H_