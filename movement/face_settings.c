/*
 * MIT License
 *
 * Copyright (c) 2023 Andreas Nebinger
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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "watch.h"
#include "movement.h"
#include "filesystem.h"
#include "face_settings.h"

#define FACE_DATA_FILENAME_LEN 17

// face_data_details items are implemented as a linked list
static face_data_item_t *_item_head = NULL;

/// @brief Quick and easy hash function.
static uint32_t DJBHash(const char* str, uint16_t length)
{
   uint32_t hash = 5381;
   uint16_t i = 0;
   for (i = 0; i < length; ++str, ++i) {
        hash = ((hash << 5) + hash) + (*str);
   }
   return hash;
}

static void _set_filename(char *filename, uint32_t hash_value, uint8_t schema_version) {
    sprintf(filename, "data_%08x_%02x", hash_value, schema_version);
}

/// @brief Retrieve a pointer to the face data details of a given face data structure pointer.
/// @param context Pointer to the face data structure
/// @return Pointer to the face datails struct of type face_data_details_t or NULL if there was an error
static face_data_details_t * _get_face_data_details(void *context) {
    // find the corresponding details entry or append one
    face_data_item_t *previous_item = NULL;
    face_data_item_t *current_item = _item_head;
    while (current_item != NULL) {
        if (current_item->details->context_data == context) return current_item->details;
        previous_item = current_item;
        current_item = current_item->next_item;
    }
    // nothing found so far - add a new data item
    current_item = malloc(sizeof(face_data_item_t));
    if (current_item == NULL) return NULL;
    if (_item_head == NULL) _item_head = current_item;
    current_item->next_item = NULL;
    current_item->details = malloc(sizeof(face_data_details_t));
    if (current_item->details == NULL) return NULL;
    memset(current_item->details, 0, sizeof(face_data_details_t));
    current_item->details->context_data = context;
    if (previous_item != NULL) previous_item->next_item = current_item;
    return current_item->details;
}

bool face_data_init(const char* watch_face_identifier, 
                    uint8_t schema_version, 
                    void *context, 
                    uint16_t context_length,
                    face_data_save_callback_t save_callback,
                    face_data_version_callback_t version_callback) {
    
    face_data_details_t *face_data_details = _get_face_data_details(context);
    if (face_data_details == NULL) return false;

    printf("face_data_init: callbacks %d, %d\n", save_callback, version_callback);

    // set face data details
    face_data_details->schema_version = schema_version;
    face_data_details->identifier_hash = DJBHash(watch_face_identifier, (uint16_t)strlen(watch_face_identifier));
    face_data_details->context_hash = 0;
    face_data_details->context_length = context_length;
    face_data_details->save_callback = save_callback;
    printf("face_data_init: details pointer %d, identifier hash %08x, content hash %04x, length %d, context pointer %d, version callback %d\n",
        face_data_details,
        face_data_details->identifier_hash,
        face_data_details->context_hash, 
        face_data_details->context_length,
        face_data_details->context_data, version_callback);

    // look for data file (current schema version)
    char filename[FACE_DATA_FILENAME_LEN];
    _set_filename(filename, face_data_details->identifier_hash, schema_version);
    if (filesystem_file_exists(filename)) {
        // we have a context file
        if (filesystem_read_file(filename, face_data_details->context_data, face_data_details->context_length)) {
            face_data_details->context_hash = DJBHash(face_data_details->context_data, face_data_details->context_length);
            printf("face_data_init: file %s loaded, hash updated to %04x\n", filename, face_data_details->context_hash);
            return true;
        }
    } 

    if (version_callback && schema_version) {
        printf("face_data_init: file not read yet, callback is: %d\n", version_callback);
        // check if there is an older data file version
        for (uint8_t i = schema_version - 1; i != UINT8_MAX; i--) {
            _set_filename(filename, face_data_details->identifier_hash, i);
            printf("face_data_init: check for file %s, callback is %d\n", filename, version_callback);
            if (filesystem_file_exists(filename)) {
                printf("face_data_init: file %s exists, callback is %d\n", filename, version_callback);
                bool erase_file = true;
                // load data to temporary buffer
                uint32_t file_len = filesystem_get_file_size(filename);
                void *data_buffer = malloc(file_len);
                if (data_buffer != NULL) {
                    printf("face_data_init: file not read yet, callback is %d\n", version_callback);
                    filesystem_read_file(filename, data_buffer, file_len);
                    printf("face_data_init: previous file %s read / callback fn: %d\n", filename, version_callback);
                    // and invoke callback function
                    version_callback(data_buffer, i, context, &erase_file); // void *context_old, uint8_t schema_version, void *context, bool *erase_data
                    free(data_buffer);
                    if (erase_file) filesystem_rm(filename);
                    printf("face_data_init: return value %d\n", erase_file);
                    return true;
                }
                break;
            }
        }
    }
    return false;
}

bool face_data_save(void *context) {

    face_data_details_t *face_data_details = _get_face_data_details(context);
    if (face_data_details == NULL) return false;

    printf("face_data_save: details pointer %d, identifier hash %08x, content hash %04x, length %d, context pointer %d, save callback %d\n",
        face_data_details,
        face_data_details->identifier_hash,
        face_data_details->context_hash, 
        face_data_details->context_length,
        face_data_details->context_data,
        face_data_details->save_callback);

    // handle the save callback function, if set
    void *data_buffer = NULL;
    if (face_data_details->save_callback) {
        data_buffer = malloc(face_data_details->context_length);
        if (data_buffer != NULL) {
            memcpy(data_buffer, face_data_details->context_data, face_data_details->context_length);
            face_data_details->save_callback(data_buffer);
           free(data_buffer); 
        }
    } else {
        data_buffer = face_data_details->context_data;
    }
    uint32_t mem_hash = DJBHash(data_buffer, face_data_details->context_length);
    if (face_data_details->context_hash) {
        // abort if hashes are identical
        printf("face_data_save: hash file %04x, hash mem %04x\n", face_data_details->context_hash, mem_hash);
        if (mem_hash == face_data_details->context_hash) {
            printf("face_data_save: no changes in data, nothing saved.\n");
            return false;
        }
    } else {
        printf("face_data_save: hash equals zero.\n");
    }
    // save current data to file
    char filename[FACE_DATA_FILENAME_LEN];
    _set_filename(filename, face_data_details->identifier_hash, face_data_details->schema_version);
    printf("face_data_save: save file %s\n", filename);
    if (filesystem_write_file(filename, data_buffer, face_data_details->context_length)) {
        face_data_details->context_hash = mem_hash;
        printf("face_data_save: hash updated to %04x\n", face_data_details->context_hash);
        return true;
    } else {
        return false;
    }
}