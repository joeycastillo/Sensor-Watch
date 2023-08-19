/*
 * MIT License
 *
 * Copyright (c) 2023 Alessandro Genova
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

#ifndef PAGE_ORDERING_FACE_H_
#define PAGE_ORDERING_FACE_H_

#include "movement.h"

/*
 * PAGE ORDERING FACE
 * 
 * This face gives the user complete control to reorganizing the faces in the firmware:
 *   - Each face can be enabled/disable
 *   - The order of the faces can be changed
 *   - The secondary face index can be set to any face
 * 
 * Usage
 * 
 * Normal mode:
 *   - Press the ALARM button to select the next page
 *   - Long press the ALARM button to select the previous page
 *   - Press the LIGHT button to enable/disable the currently selected page
 *   - Long press the LIGHT button to enter the reordering mode
 * 
 * Reordering mode (page number flashing):
 *   - Press the ALARM button to move the current face to the next page
 *   - Long press the ALARM button to move the current face to the previous page
 *   - Long press the LIGHT button to mark this page as the first of the secondary pages (colon indicator)
 *   - Press the LIGHT button to exit reordering mode
 */

void page_ordering_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void page_ordering_face_activate(movement_settings_t *settings, void *context);
bool page_ordering_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void page_ordering_face_resign(movement_settings_t *settings, void *context);
void page_ordering_face_label(movement_settings_t *settings, void *context, char* label, uint8_t size);

#define page_ordering_face ((const watch_face_t){ \
    page_ordering_face_setup, \
    page_ordering_face_activate, \
    page_ordering_face_loop, \
    page_ordering_face_resign, \
    NULL, \
    page_ordering_face_label, \
})

#endif // PAGE_ORDERING_FACE_H_
