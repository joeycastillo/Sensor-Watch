#ifndef SET_TIME_WIDGET_H_
#define SET_TIME_WIDGET_H_

#include "launcher.h"

void set_time_widget_setup(LauncherSettings *settings, void ** context_ptr);
void set_time_widget_activate(LauncherSettings *settings, void *context);
bool set_time_widget_loop(LauncherEvent event, LauncherSettings *settings, void *context);
void set_time_widget_resign(LauncherSettings *settings, void *context);

#define set_time_widget { \
    set_time_widget_setup, \
    set_time_widget_activate, \
    set_time_widget_loop, \
    set_time_widget_resign, \
}

#endif // SET_TIME_WIDGET_H_
