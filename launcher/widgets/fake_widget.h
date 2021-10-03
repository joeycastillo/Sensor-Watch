#ifndef FAKE_WIDGET_H_
#define FAKE_WIDGET_H_

#include "launcher.h"

void fake_widget_setup(LauncherSettings *settings, void ** context_ptr);
void fake_widget_activate(LauncherSettings *settings, void *context);
void fake_widget_loop(LauncherEvent event, LauncherSettings *settings, void *context);
void fake_widget_resign(LauncherSettings *settings, void *context);

#define fake_widget { \
    "WI dGIt01", \
    true, \
    fake_widget_setup, \
    fake_widget_activate, \
    fake_widget_loop, \
    fake_widget_resign, \
}

#endif // FAKE_WIDGET_H_