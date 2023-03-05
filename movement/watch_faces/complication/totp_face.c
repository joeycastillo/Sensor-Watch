#include <stdlib.h>
#include <string.h>
#include "totp_face.h"
#include "watch.h"
#include "watch_utility.h"
#include "TOTP.h"

// Use https://cryptii.com/pipes/base32-to-hex to convert base32 to hex
// Use https://github.com/susam/mintotp to generate test codes for verification
// Available algorothms:
// SHA1 (most TOTP codes use this)
// SHA224
// SHA256
// SHA384
// SHA512

////////////////////////////////////////////////////////////////////////////////
// Enter your TOTP key data below
static const uint8_t num_keys = 2;
static uint8_t keys[] = {
    0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x21, 0xde, 0xad, 0xbe, 0xef, // 1 - JBSWY3DPEHPK3PXP
    0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x21, 0xde, 0xad, 0xbe, 0xef, // 2 - JBSWY3DPEHPK3PXP
};
static const uint8_t key_sizes[] = {
    10,
    10,
};
static const uint32_t timesteps[] = {
    30,
    30,
};
static const char labels[][2] = {
    { '2', 'F' },
    { 'A', 'C' },
};
static const hmac_alg algorithms[] = {
    SHA1,
    SHA1,
};
// END OF KEY DATA.
////////////////////////////////////////////////////////////////////////////////

static void _update_display(totp_state_t *totp_state) {
    char buf[14];
    div_t result;
    uint8_t valid_for;

    result = div(totp_state->timestamp, timesteps[totp_state->current_index]);
    if (result.quot != totp_state->steps) {
        totp_state->current_code = getCodeFromTimestamp(totp_state->timestamp);
        totp_state->steps = result.quot;
    }
    valid_for = timesteps[totp_state->current_index] - result.rem;
    sprintf(buf, "%c%c%2d%06lu", labels[totp_state->current_index][0], labels[totp_state->current_index][1], valid_for, totp_state->current_code);

    watch_display_string(buf, 0);
}

void totp_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) *context_ptr = malloc(sizeof(totp_state_t));
}

void totp_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    memset(context, 0, sizeof(totp_state_t));
    totp_state_t *totp_state = (totp_state_t *)context;
    TOTP(keys, key_sizes[0], timesteps[0], algorithms[0]);
    totp_state->timestamp = watch_utility_date_time_to_unix_time(watch_rtc_get_date_time(), movement_timezone_offsets[settings->bit.time_zone] * 60);
    totp_state->current_code = getCodeFromTimestamp(totp_state->timestamp);
}

bool totp_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    totp_state_t *totp_state = (totp_state_t *)context;

    switch (event.event_type) {
        case EVENT_TICK:
            totp_state->timestamp++;
            // fall through
        case EVENT_ACTIVATE:
            _update_display(totp_state);
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        case EVENT_ALARM_BUTTON_UP:
            if (totp_state->current_index + 1 < num_keys) {
                totp_state->current_key_offset += key_sizes[totp_state->current_index];
                totp_state->current_index++;
            } else {
                // wrap around to first key
                totp_state->current_key_offset = 0;
                totp_state->current_index = 0;
            }
            TOTP(keys + totp_state->current_key_offset, key_sizes[totp_state->current_index], timesteps[totp_state->current_index], algorithms[totp_state->current_index]);
            _update_display(totp_state);
            break;
        case EVENT_ALARM_BUTTON_DOWN:
        case EVENT_ALARM_LONG_PRESS:
            break;
        default:
            movement_default_loop_handler(event, settings);
            break;
    }

    return true;
}

void totp_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
}
