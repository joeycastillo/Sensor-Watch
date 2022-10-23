#ifndef TOTP_FACE_LFS_H_
#define TOTP_FACE_LFS_H_

#include "movement.h"

typedef struct {
    uint32_t timestamp;
    uint8_t steps;
    uint32_t current_code;
    uint8_t current_index;
} totp_lfs_state_t;

void totp_face_lfs_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void totp_face_lfs_activate(movement_settings_t *settings, void *context);
bool totp_face_lfs_loop(movement_event_t event, movement_settings_t *settings, void *context);
void totp_face_lfs_resign(movement_settings_t *settings, void *context);

#define totp_face_lfs ((const watch_face_t){ \
    totp_face_lfs_setup, \
    totp_face_lfs_activate, \
    totp_face_lfs_loop, \
    totp_face_lfs_resign, \
    NULL, \
})

#endif // TOTP_FACE_LFS_H_
