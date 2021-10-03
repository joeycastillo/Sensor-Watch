#ifndef FAKE_WIDGET_1_H_
#define FAKE_WIDGET_1_H_

#include "launcher.h"

void fake_widget_1_setup(LauncherSettings *settings, void ** context_ptr);
void fake_widget_1_activate(LauncherSettings *settings, void *context);
void fake_widget_1_loop(LauncherEvent event, LauncherSettings *settings, void *context);
void fake_widget_1_resign(LauncherSettings *settings, void *context);

#define fake_widget_1 { \
    "W1 d get01", \
    fake_widget_1_setup, \
    fake_widget_1_activate, \
    fake_widget_1_loop, \
    fake_widget_1_resign, \
}

#endif // FAKE_WIDGET_1_H_