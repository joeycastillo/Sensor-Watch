/**
 * TODO:
 * - Support for multiple codes
 */
#include <stdlib.h>
#include <string.h>
#include "totp_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "TOTP.h"
#include "base32.h"
#include "filesystem.h"

// test key: JBSWY3DPEHPK3PXP
// Use https://cryptii.com/pipes/base32-to-hex to convert base32 to hex
// Use https://totp.danhersam.com/ to generate test codes for verification
static uint8_t last_filename_index = 0;

static const uint32_t TIMESTEP = 30;

static void read_totp_file(totp_state_t *totp_state) {
    totp_state->valid = false;
    char filename[12];
    sprintf(filename, "totp%d.txt", totp_state->my_filename_index);
    int32_t size = filesystem_get_file_size(filename);
    if (size > 0) {
        char *buf = malloc(size + 1);
        filesystem_read_file(filename, buf, size);
        char *site_name = strtok(buf, " \n");
        char *hmac_string = strtok(NULL, " \n");
        if (strlen(hmac_string) == 16) {
            memcpy(totp_state->site_name, site_name, min(strlen(site_name), 2));
            base32_decode(hmac_string, totp_state->hmac_key);
            totp_state->valid = true;
        }
        free(buf);
    }
}

void totp_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(totp_state_t));
        (((totp_state_t *)(*context_ptr))->my_filename_index) = ++last_filename_index;
        read_totp_file((totp_state_t *)(*context_ptr));
    }
}

void totp_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    totp_state_t *totp_state = (totp_state_t *)context;
    if (!totp_state->valid) {
        read_totp_file(totp_state);
    }
    if (totp_state->valid) {
        TOTP(totp_state->hmac_key, sizeof(totp_state->hmac_key), TIMESTEP);
        totp_state->steps = 0;
        totp_state->timestamp = watch_utility_date_time_to_unix_time(watch_rtc_get_date_time(), movement_timezone_offsets[settings->bit.time_zone] * 60);
        totp_state->current_code = getCodeFromTimestamp(totp_state->timestamp);
    }
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
            if (totp_state->valid) {
                result = div(totp_state->timestamp, TIMESTEP);
                if (result.quot != totp_state->steps) {
                    totp_state->current_code = getCodeFromTimestamp(totp_state->timestamp);
                    totp_state->steps = result.quot;
                }
                valid_for = TIMESTEP - result.rem;
                sprintf(buf, "%s%2d%06lu", totp_state->site_name, valid_for, totp_state->current_code);
                watch_display_string(buf, 0);
            } else {
                watch_display_string("2f  noCode", 0);
                read_totp_file(totp_state);
                if (totp_state->valid) {
                    TOTP(totp_state->hmac_key, sizeof(totp_state->hmac_key), TIMESTEP);
                    totp_state->steps = 0;
                    totp_state->timestamp = watch_utility_date_time_to_unix_time(watch_rtc_get_date_time(), movement_timezone_offsets[settings->bit.time_zone] * 60);
                    totp_state->current_code = getCodeFromTimestamp(totp_state->timestamp);
                }
            }
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
