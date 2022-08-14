#include "watch.h"

bool watch_is_buzzer_or_led_enabled(void) {
    return false;
}

bool watch_is_usb_enabled(void) {
    return true;
}

void watch_reset_to_bootloader(void) {
    // No bootloader in the simulator; nothing to do here
}
