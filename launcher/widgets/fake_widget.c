#include "fake_widget.h"

void fake_widget_setup(LauncherSettings *settings, void ** context_ptr) {
    (void) settings;
    *context_ptr = NULL;
}

void fake_widget_enter_foreground(LauncherSettings *settings, void *context) {
    (void) settings;
    (void) context;
}

bool fake_widget_loop(LauncherEvent event, LauncherSettings *settings, void *context) {
    (void) event;
    (void) settings;
    (void) context;

    return true;
}

void fake_widget_enter_background(LauncherSettings *settings, void *context) {
    (void) settings;
    (void) context;
}
