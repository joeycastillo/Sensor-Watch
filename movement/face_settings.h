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

#ifndef FACE_SETTINGS_H_
#define FACE_SETTINGS_H_
#include <stdio.h>
#include <stdbool.h>
#include "watch.h"

/** @brief A function that is invoked when a previous version of a data file is detected.
  * @param context_old A pointer to the structure corresponding to the older version's data file.
  * @param schema_version The schema version of the older structure.
  * @param context A pointer to the current data structure of the watch face.
  * @param erase_data Pointer to a flag indicating if the old data file will be erased. If you want to 
  *                   keep the file set this to false. The default value is true. 
  * @note You can use this function to import data from an older schema version and transfer it to
  *       the current version of your watch face. This function is only called once time in 
  *       the context of using face_data_init(). 
  */
typedef void (*face_data_version_callback_t)(void *context_old, uint8_t schema_version, void *context, bool *erase_data);

/** @brief A function that is invoked before writing the watch face data to a file.
  * @param context A pointer to a copy of the current data structure of the watch face.
  * @note You can use this function to perform some "cleaning up" before data is written.
  *       E. g. if you have some properties that do not need to be saved permanently, you should
  *       set these to zero (or any other useful value), thus avoiding unnecessary write operations
  *       on the flash storage. You can savely alter the structure pointed at by context_ptr, since
  *       it will be a copy of the original data structure. 
  */
 typedef void (*face_data_save_callback_t)(void *context);

typedef struct {
    uint32_t identifier_hash;
    uint8_t schema_version;
    void *context_data;
    uint16_t context_length;
    uint32_t context_hash;
    face_data_save_callback_t save_callback;
} face_data_details_t;

typedef struct face_data_item {
  face_data_details_t *details;
  struct face_data_item *next_item;
} face_data_item_t;

/** @brief Connects the given details with the given watch face context pointer, to make subsequent calls of face_save_data()
 *         easier and tries to load a data file.
 *  @param watch_face_identifier A short string identifying the watch face. Must be unique within the whole project!
 *  @param schema_version A version number. Helps identifying outdated data files from previous versions of the watch face.
 *  @param context Pointer to the watch face data buffer/structure.
 *  @param context_length Number of bytes to load into the buffer and to write to the persistent data file.
 *  @param save_callback Pointer to a callback function that will be invoked each time the face_data_save() function is used.
 *  @param init_callback Pointer to a callback function that will be invoked if an older version of a data file is found.
 *  @return True when a data file has been found and loaded, false otherwise.
 *  @note Data is stored as a file named 'data_[hash of identifier string]_[schema_version]'. If a corresponding file is 
 *        found, it will be loaded immediately. If there is no such file and the parameter version_callback is set,
 *        the function look for previous versions of data files named like 'data_[hash of identifier string]_[schema_version - n]'.
 *        If such a file is found, the callback function is invoked and the previous data file will be erased (unless the
 *        callback function indicates otherwise).
 */
bool face_data_init(const char* watch_face_identifier, 
    uint8_t schema_version, 
    void *context, 
    uint16_t context_length,
    face_data_save_callback_t save_callback,
    face_data_version_callback_t version_callback);

/** @brief Save watch face data to the filesystem.
 *  @param context Pointer to the data structure that needs to be saved. Must be the same as given at
 *                 the preceding call of face_data_init().  
 *  @return True, if a file has been saved. False, if there was no need to save the data (again).
 *  @note The file will only be saved if the data has changed since the last call. If save_data_init()
 *        has been provided a save callback function, the latter will be called right before checking for
 *        data modifications since the last call of face_data_save(). You can use the save data callback
 *        to set some less relevant data details to default values before saving the whole data structure.
 *        This way you can fine-tune what is saved persistently while minimizing write operations, since
 *        data will only be written to the flash storage when relevant parts have changed.
 */
bool face_data_save(void *context);


#endif // FACE_SETTINGS_H_
