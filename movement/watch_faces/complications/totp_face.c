/**
 * TODO:
 * - Add support for UTC offset in settings?
 * - Support for multiple codes
 */
#include <stdlib.h>
#include <string.h>
#include "totp_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "TOTP.h"

// test key: JBSWY3DPEHPK3PXP
// Use https://cryptii.com/pipes/base32-to-hex to convert base32 to hex
// Use https://totp.danhersam.com/ to generate test codes for verification
static uint8_t hmacKey[] = {0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x21, 0xde, 0xad, 0xbe, 0xef}; // Secret key


static const uint8_t UTC_OFFSET = 5; // set to your current UTC offset
static const uint32_t TIMESTEP = 30;

void totp_face_setup(movement_settings_t *settings, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) *context_ptr = malloc(sizeof(totp_state_t));
    TOTP(hmacKey, sizeof(hmacKey), TIMESTEP);
}

void totp_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    memset(context, 0, sizeof(totp_state_t));
    totp_state_t *totp_state = (totp_state_t *)context;
    totp_state->timestamp = watch_utility_date_time_to_unix_time(watch_rtc_get_date_time(), UTC_OFFSET);
    totp_state->current_code = getCodeFromTimestamp(totp_state->timestamp);
}

bool totp_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;

    totp_state_t *totp_state = (totp_state_t *)context;
    char buf[14];
    uint8_t valid_for;
    div_t result;

    switch (event.event_type) {
        case EVENT_TICK:
            totp_state->timestamp++;
            // fall through
        case EVENT_ACTIVATE:
            result = div(totp_state->timestamp, TIMESTEP);
            if (result.quot != totp_state->steps) {
                totp_state->current_code = getCodeFromTimestamp(totp_state->timestamp);
                totp_state->steps = result.quot;
            }
            valid_for = TIMESTEP - result.rem;
            sprintf(buf, "2f%2d%06lu", valid_for, totp_state->current_code);

            watch_display_string(buf, 0);
            break;
        case EVENT_MODE_BUTTON_UP:
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_DOWN:
            movement_illuminate_led();
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
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
