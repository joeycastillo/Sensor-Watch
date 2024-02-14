/*
 * MIT License
 *
 * Copyright (c) 2023 Wesley Aptekar-Cassels
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdlib.h>
#include <string.h>
#include "save_load_face.h"
#include "filesystem.h"

static void save(save_load_state_t *state) {
    savefile_t savefile = {
        1,
        watch_get_backup_data(0),
        watch_get_backup_data(1),
        watch_get_backup_data(2),
        watch_get_backup_data(3),
        watch_get_backup_data(4),
        watch_get_backup_data(5),
        watch_get_backup_data(6),
        watch_get_backup_data(7),
        watch_rtc_get_date_time(),
    };
    state->slot[state->index] = savefile;
    char filename[23];
    sprintf(filename, "save_load_face_%d.bin", state->index);
    filesystem_write_file(filename, (char*)&savefile, sizeof(savefile_t));
}

static void load(save_load_state_t *state, movement_settings_t *settings) {
    watch_store_backup_data(state->slot[state->index].b0, 0);
    settings->reg = state->slot[state->index].b0;
    watch_store_backup_data(state->slot[state->index].b1, 1);
    watch_store_backup_data(state->slot[state->index].b2, 2);
    watch_store_backup_data(state->slot[state->index].b3, 3);
    watch_store_backup_data(state->slot[state->index].b4, 4);
    watch_store_backup_data(state->slot[state->index].b5, 5);
    watch_store_backup_data(state->slot[state->index].b6, 6);
    watch_store_backup_data(state->slot[state->index].b7, 7);
}

static void load_saves_to_state(save_load_state_t *state) {
    for (uint8_t i = 0; i < SAVE_LOAD_SLOTS; i++) {
        char filename[23];
        sprintf(filename, "save_load_face_%d.bin", i);
        if (filesystem_get_file_size(filename) != sizeof(savefile_t)) {
            state->slot[i].version = 0;
            continue;
        }
        filesystem_read_file(filename, (char*)&state->slot[i], sizeof(savefile_t));
        if (state->slot[i].version != 1) {
            state->slot[i].version = 0;
        }
    }
}

void save_load_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    (void) settings;
    (void) watch_face_index;
    if (*context_ptr == NULL) {
        *context_ptr = malloc(sizeof(save_load_state_t));
        memset(*context_ptr, 0, sizeof(save_load_state_t));
    }
}

void save_load_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    save_load_state_t *state = (save_load_state_t *)context;
    state->index = 0;
    state->update_timeout = 0;
    load_saves_to_state(state);
}

static void update_display(save_load_state_t *state) {
    char buf[11];
    sprintf(buf, "SL %1d", state->index);
    watch_display_string(buf, 0);

    if (state->slot[state->index].version) {
        sprintf(buf, "%02d%02d%02d", state->slot[state->index].rtc.unit.year + 20, state->slot[state->index].rtc.unit.month, state->slot[state->index].rtc.unit.day);
        watch_display_string(buf, 4);
    } else {
        watch_display_string("no dat", 4);
    }
}

bool save_load_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    save_load_state_t *state = (save_load_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
            update_display(state);
            break;
        case EVENT_TICK:
            if (state->update_timeout) {
                if (!--state->update_timeout) {
                    update_display(state);
                }
            }
            break;
        case EVENT_ALARM_BUTTON_UP:
            state->index = (state->index + 1) % SAVE_LOAD_SLOTS;
            update_display(state);
            break;
        case EVENT_LIGHT_LONG_PRESS:
            save(state);
            watch_display_string("Saved ", 4);
            state->update_timeout = 3;
            break;
        case EVENT_ALARM_LONG_PRESS:
            if (state->slot[state->index].version) {
                load(state, settings);
                watch_display_string("Loaded", 4);
                state->update_timeout = 3;
            }
            break;
        case EVENT_TIMEOUT:
            movement_move_to_face(0);
            break;
        default:
            return movement_default_loop_handler(event, settings);
    }

    return true;
}

void save_load_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;

    // handle any cleanup before your watch face goes off-screen.
}

