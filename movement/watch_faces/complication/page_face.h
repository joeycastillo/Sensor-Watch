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

#ifndef PAGE_FACE_H_
#define PAGE_FACE_H_

#include "movement.h"

/*
 * Page face
 *
 * This face assists in organizing other faces. It hides some number of other
 * pages, so that they are labeled with a particular string and can be accessed
 * with a long-press of the mode button.
 *
 * For instance, consider a page_face that is in index 6 of watch_faces, with
 * the struct {6, 3, "    Config"}. Upon arriving to the face, on index 6, the
 * string "Config" would appear on the watch. At this point, pressing mode
 * would skip past the next three faces. However, if you instead long-pressed
 * mode (or pressed the alarm button), you would go to the next face, allowing
 * you to scroll through the three faces that would otherwise be hidden.
 */

typedef struct {
    uint8_t watch_face_index;
    uint8_t size;
} page_state_t;

void page_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr);
void page_face_activate(movement_settings_t *settings, void *context);
bool page_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void page_face_resign(movement_settings_t *settings, void *context);

#define page_face ((const watch_face_t){ \
    page_face_setup, \
    page_face_activate, \
    page_face_loop, \
    page_face_resign, \
    NULL, \
})

#endif // PAGE_FACE_H_

