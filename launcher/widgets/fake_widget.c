#include "fake_widget.h"

void fake_widget_setup(LauncherSettings *settings, void ** context_ptr) {
    (void) settings;
    *context_ptr = NULL;
}

void fake_widget_activate(LauncherSettings *settings, void *context) {
    (void) settings;
    (void) context;
}

void fake_widget_loop(LauncherEvent event, LauncherSettings *settings, void *context) {
    (void) event;
    (void) settings;
    (void) context;

    return true;
}

void fake_widget_resign(LauncherSettings *settings, void *context) {
    (void) settings;
    (void) context;
}
