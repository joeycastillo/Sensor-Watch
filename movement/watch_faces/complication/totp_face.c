#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "TOTP.h"
#include "base32.h"

#include "watch.h"
#include "watch_utility.h"
#include "filesystem.h"

#include "totp_face.h"

/* Reads from a file totp_uris.txt where each line is what's in a QR code:
 * e.g.
 *   otpauth://totp/Example:alice@google.com?secret=JBSWY3DPEHPK3PXP&issuer=Example
 *   otpauth://totp/ACME%20Co:john.doe@email.com?secret=HXDMVJECJJWSRB3HWIZR4IFUGFTMXBOZ&issuer=ACME%20Co&algorithm=SHA1&digits=6&period=30
 * This is also the same as what Aegis exports in plain-text format.
 *
 * Minimal sanitisation of input, however.
 *
 * At the moment, to get the records onto the filesystem, start a serial connection and do:
 *   echo otpauth://totp/Example:alice@google.com?secret=JBSWY3DPEHPK3PXP&issuer=Example > totp_uris.txt
 *   echo otpauth://totp/ACME%20Co:john.doe@email.com?secret=HXDMVJECJJWSRB3HWIZR4IFUGFTMXBOZ&issuer=ACME%20Co&algorithm=SHA1&digits=6&period=30 >> totp_uris.txt
 * (note the double >> in the second one)
 *
 * You may want to customise the characters that appear to identify the 2FA code. These are just the first two characters of the issuer,
 * and it's fine to modify the URI.
 */


#define MAX_TOTP_RECORDS 20
#define TOTP_FILE "totp_uris.txt"

const char* TOTP_URI_START = "otpauth://totp/";

struct totp_record {
    uint8_t secret[48];
    size_t secret_size;
    char label[2];
    uint32_t period;
};

static struct totp_record totp_records[MAX_TOTP_RECORDS];
static int num_totp_records = 0;

static void init_totp_record(struct totp_record *totp_record) {
    totp_record->secret_size = 0;
    totp_record->label[0] = 'A';
    totp_record->label[1] = 'A';
    totp_record->period = 30;
}

static bool totp_face_read_param(struct totp_record *totp_record, char *param, char *value) {
    if (!strcmp(param, "issuer")) {
        if (value[0] == '\0' || value[1] == '\0') {
            printf("TOTP issuer must be >= 2 chars, got '%s'\n", value);
            return false;
        }
        totp_record->label[0] = value[0];
        totp_record->label[1] = value[1];
    } else if (!strcmp(param, "secret")) {
        totp_record->secret_size = base32_decode((unsigned char *)value, totp_record->secret);
        if (totp_record->secret_size == 0) {
            printf("TOTP can't decode secret: %s", value);
            return false;
        }
    } else if (!strcmp(param, "digits")) {
        if (!strcmp(param, "6")) {
            printf("TOTP got %s, not 6 digits\n", value);
            return false;
        }
    } else if (!strcmp(param, "period")) {
        totp_record->period = atoi(value);
        if (totp_record->period == 0) {
            printf("TOTP invalid period %s\n", value);
            return false;
        }
    } else if (!strcmp(param, "algorithm")) {
        if (!strcmp(param, "SHA1")) {
            printf("TOTP ignored due to algorithm %s\n", value);
            return false;
        }
    }

    return true;
}

static void totp_face_read_file(char *filename) {
    // For 'format' of file, see comment at top.
    const size_t uri_start_len = strlen(TOTP_URI_START);

    if (!filesystem_file_exists(filename)) {
        printf("TOTP file error: %s\n", filename);
        return;
    }

    char line[256];
    int32_t offset = 0;
    while (filesystem_read_line(filename, line, offset, 255) && strlen(line)) {
        offset += strlen(line) + 1;
        
        if (num_totp_records == MAX_TOTP_RECORDS) {
            printf("TOTP max records: %d\n", MAX_TOTP_RECORDS);
            break;
        }

        // Check that it looks like a URI
        if (strncmp(TOTP_URI_START, line, uri_start_len)) {
            printf("TOTP invalid uri start: %s\n", line);
            continue;
        }

        // Check that we can find a '?' (to start our parameters)
        char *param;
        char *param_saveptr = NULL;
        char *params = strchr(line + uri_start_len, '?');
        if (params == NULL) {
            printf("TOTP no params: %s\n", line);
            continue;
        }

        // Process the parameters and put them in the record
        init_totp_record(&totp_records[num_totp_records]);
        bool error = false;
        param = strtok_r(params + 1, "&", &param_saveptr);
        do {
            char *param_middle = strchr(param, '=');
            *param_middle = '\0';
            error = error || !totp_face_read_param(&totp_records[num_totp_records], param, param_middle + 1);
        } while ((param = strtok_r(NULL, "&", &param_saveptr)));

        if (error) {
            totp_records[num_totp_records].secret_size = 0;
            continue;
        }

        // If we found a probably valid TOTP record, keep it. 
        if (totp_records[num_totp_records].secret_size) {
            num_totp_records += 1;
        } else {
            printf("TOTP missing secret: %s\n", line);
        }
    }
}

void totp_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(totp_state_t));
        totp_face_read_file(TOTP_FILE);
    }
}

void totp_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    memset(context, 0, sizeof(totp_state_t));
    totp_state_t *totp_state = (totp_state_t *)context;

    if (num_totp_records > 0) {
        totp_state->current_index = 0;
        totp_state->steps = 0;  // Force getting a new code in the loop.
        totp_state->timestamp = watch_utility_date_time_to_unix_time(watch_rtc_get_date_time(), movement_timezone_offsets[settings->bit.time_zone] * 60);
        TOTP(totp_records[0].secret, totp_records[0].secret_size, totp_records[0].period);
    } else {
        watch_display_string("NA00000000", 0);
    }
}

bool totp_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;

    totp_state_t *totp_state = (totp_state_t *)context;
    char buf[14];
    uint8_t valid_for;
    div_t result;
    uint8_t index = totp_state->current_index;

    switch (event.event_type) {
        case EVENT_TICK:
            if (num_totp_records == 0) {
                break;
            }

            totp_state->timestamp++;
            // fall through
        case EVENT_ACTIVATE:
            if (num_totp_records == 0) {
                break;
            }

            result = div(totp_state->timestamp, totp_records[index].period);
            if (result.quot != totp_state->steps) {
                totp_state->current_code = getCodeFromTimestamp(totp_state->timestamp);
                totp_state->steps = result.quot;
            }
            valid_for = totp_records[index].period - result.rem;
            sprintf(buf, "%c%c%2d%06lu", totp_records[index].label[0], totp_records[index].label[1], valid_for, totp_state->current_code);

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
        case EVENT_ALARM_BUTTON_UP:
            if (num_totp_records == 0) {
                break;
            }
            totp_state->current_index = (index + 1) % num_totp_records;
            TOTP(totp_records[totp_state->current_index].secret, totp_records[totp_state->current_index].secret_size, totp_records[totp_state->current_index].period);
            break;
        case EVENT_ALARM_BUTTON_DOWN:
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
