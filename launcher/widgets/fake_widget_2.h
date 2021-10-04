#ifndef FAKE_WIDGET_2_H_
#define FAKE_WIDGET_2_H_

#include "launcher.h"

void fake_widget_2_setup(LauncherSettings *settings, void ** context_ptr);
void fake_widget_2_activate(LauncherSettings *settings, void *context);
bool fake_widget_2_loop(LauncherEvent event, LauncherSettings *settings, void *context);
void fake_widget_2_resign(LauncherSettings *settings, void *context);

#define fake_widget_2 { \
    fake_widget_2_setup, \
    fake_widget_2_activate, \
    fake_widget_2_loop, \
    fake_widget_2_resign, \
}

#endif // FAKE_WIDGET_2_H_