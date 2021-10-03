#include "fake_widget_2.h"

void fake_widget_2_setup(LauncherSettings *settings, void ** context_ptr) {
    (void) settings;
    *context_ptr = NULL;
}

void fake_widget_2_activate(LauncherSettings *settings, void *context) {
    (void) settings;
    (void) context;
}

void fake_widget_2_loop(LauncherEvent event, LauncherSettings *settings, void *context) {
    (void) settings;
    (void) context;

    switch (event) {
        case EVENT_MODE_BUTTON_UP:
            launcher_move_to_next_widget();
            break;
        case EVENT_LIGHT_BUTTON_UP:
            launcher_illuminate_led();
            break;
        default:
            break;
    }
}

void fake_widget_2_resign(LauncherSettings *settings, void *context) {
    (void) settings;
    (void) context;
}
