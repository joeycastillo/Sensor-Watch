#ifndef FAKE_WIDGET_H_
#define FAKE_WIDGET_H_

#include "launcher.h"

void fake_widget_setup(LauncherSettings *settings, void ** context_ptr);
void fake_widget_enter_foreground(LauncherSettings *settings, void *context);
bool fake_widget_loop(LauncherEvent event, LauncherSettings *settings, void *context);
void fake_widget_enter_background(LauncherSettings *settings, void *context);

#define fake_widget { \
    fake_widget_setup, \
    fake_widget_enter_foreground, \
    fake_widget_loop, \
    fake_widget_enter_background, \
}

#endif // FAKE_WIDGET_H_