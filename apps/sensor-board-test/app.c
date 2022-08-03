#include <stdio.h>
#include <string.h>
#include "watch.h"

bool even = false;

static void cb_tick(void) {
    even = !even;
}

void app_init(void) {
}

void app_wake_from_backup(void) {
}

void app_setup(void) {
    watch_enable_digital_output(RED);
    watch_enable_digital_output(GREEN);
    watch_enable_digital_output(A0);
    watch_enable_digital_output(SCL);
    watch_enable_digital_output(SDA);
    watch_enable_digital_output(A1);
    watch_enable_digital_output(A2);
    watch_enable_digital_output(A3);
    watch_enable_digital_output(A4);

    watch_set_pin_level(A0, false);
    watch_set_pin_level(SCL, false);
    watch_set_pin_level(SDA, false);
    watch_set_pin_level(A1, false);
    watch_set_pin_level(A2, false);
    watch_set_pin_level(A3, false);
    watch_set_pin_level(A4, false);

    watch_rtc_register_periodic_callback(cb_tick, 2);
}

void app_prepare_for_standby(void) {
}

void app_wake_from_standby(void) {
}

bool app_loop(void) {
    watch_date_time date_time = watch_rtc_get_date_time();
    char buf[16];
    sprintf(buf, "%2d:%02d:%02d: ", date_time.unit.hour, date_time.unit.minute, date_time.unit.second);
    printf(buf);
    if (even) {
        printf("Even\n");
        watch_set_pin_level(RED, false);
        watch_set_pin_level(GREEN, true);
        watch_set_pin_level(A0, true);
        watch_set_pin_level(SCL, false);
        watch_set_pin_level(SDA, true);
        watch_set_pin_level(A1, false);
        watch_set_pin_level(A2, true);
        watch_set_pin_level(A3, false);
        watch_set_pin_level(A4, true);
    } else {
        printf("Odd\n");
        watch_set_pin_level(RED, true);
        watch_set_pin_level(GREEN, false);
        watch_set_pin_level(A0, false);
        watch_set_pin_level(SCL, true);
        watch_set_pin_level(SDA, false);
        watch_set_pin_level(A1, true);
        watch_set_pin_level(A2, false);
        watch_set_pin_level(A3, true);
        watch_set_pin_level(A4, false);
    }

    return true;
}
