#include "fake_widget_2.h"
#include "watch.h"

void fake_widget_2_setup(LauncherSettings *settings, void ** context_ptr) {
    (void) settings;
    *context_ptr = NULL;
}

void fake_widget_2_activate(LauncherSettings *settings, void *context) {
    (void) settings;
    (void) context;
}

bool fake_widget_2_loop(LauncherEvent event, LauncherSettings *settings, void *context) {
    printf("fake_widget_2_loop\n");
    (void) settings;
    (void) context;
    watch_display_string("W1 d get02", 0);

    switch (event.bit.event_type) {
        case EVENT_MODE_BUTTON_UP:
            launcher_move_to_next_widget();
            return false;
        case EVENT_LIGHT_BUTTON_UP:
            launcher_illuminate_led();
            break;
        default:
            break;
    }

    return true;
}

void fake_widget_2_resign(LauncherSettings *settings, void *context) {
    (void) settings;
    (void) context;
}
