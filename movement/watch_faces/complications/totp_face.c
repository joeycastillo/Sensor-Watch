/**
 * 
 * TODO:
 * - this ONLY works if watch is set to UTC, probably worth including a TZ offset setting since it can be used by beats as well
 * - show how long code is valid for in upper right corner of LCD
 * - optimize code so that we don't calculating a new unix timestamp every second AND a new TOTP code
 * - Support for multiple codes
 */
#include <stdlib.h>
#include <string.h>
#include "totp_face.h"
#include "watch.h"
#include "TOTP.h"

// test key: JBSWY3DPEHPK3PXP
// Use https://cryptii.com/pipes/base32-to-hex to convert base32 to hex
// Use https://totp.danhersam.com/ to generate test codes for verification
uint8_t hmacKey[] = {0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x21, 0xde, 0xad, 0xbe, 0xef};               // Secret key

void totp_face_setup(movement_settings_t *settings, void ** context_ptr) {
    (void) settings;
    (void) context_ptr;
    TOTP(hmacKey, sizeof(hmacKey), 30);
}

void totp_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}

/**
 * @brief Get unix timestamp from component parts
 * 
 * @param year 
 * @param month 
 * @param day 
 * @param hour 
 * @param minute 
 * @param second 
 * @return uint32_t 
 * 
 * Based on code by Josh Haberman for upb
 * from https://blog.reverberate.org/2020/05/12/optimizing-date-algorithms.html
 * 
 * Essentially we need to calculate how many days have occured since year 0
 * including leap years! The following code does some clever calculations
 * of the number of february's then offsets based on how many leap years
 * there have been
 * 
 * Once we have the number of days in the year, it's easy enough to add how
 * many days have happened in the current year, then convert that to seconds
 */
uint32_t current_unix_time(uint32_t year, uint32_t month, uint32_t day,
                            uint32_t hour, uint32_t minute, uint32_t second) {
    uint16_t DAYS_SO_FAR[] = {
        0,   // Jan
        31,  // Feb
        59,  // March
        90,  // April
        120, // May
        151, // June
        181, // July
        212, // August
        243, // September
        273, // October
        304, // November
        334  // December
    };


    uint32_t year_adj = year + 4800;
    uint32_t febs = year_adj - (month <= 2 ? 1 : 0);  /* Februaries since base. */
    uint32_t leap_days = 1 + (febs / 4) - (febs / 100) + (febs / 400);
    uint32_t days = 365 * year_adj + leap_days + DAYS_SO_FAR[month - 1] + day - 1;
    days -= 2472692;  /* Adjust to Unix epoch. */

    uint32_t timestamp = days * 86400;
    timestamp += hour * 3600;
    timestamp += minute * 60;
    timestamp += second;

    return timestamp;
}

uint32_t current_unix_time_from_rtc() {
    watch_date_time date_time = watch_rtc_get_date_time();
    return current_unix_time(
        date_time.unit.year + 2020, // year is stored starting in 2020
        date_time.unit.month,
        date_time.unit.day,
        date_time.unit.hour,
        date_time.unit.minute,
        date_time.unit.second
    );
}

bool totp_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    char buf[14];
    watch_date_time date_time = watch_rtc_get_date_time();

    uint32_t ts;
    uint32_t code;
    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
            ts = current_unix_time_from_rtc();
            code = getCodeFromTimestamp(ts);
            sprintf(buf, "2f  %lu", code); 

            watch_display_string(buf, 0);
            break;
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            movement_illuminate_led();
            break;
        case EVENT_TIMEOUT:
            // go home
            break;
        case EVENT_ALARM_BUTTON_DOWN:
        case EVENT_ALARM_BUTTON_UP:
        case EVENT_ALARM_LONG_PRESS:
        default:
            break;
    }

    return true;
}

void totp_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}