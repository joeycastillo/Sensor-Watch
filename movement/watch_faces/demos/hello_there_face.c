#include <stdlib.h>
#include <string.h>
#include "hello_there_face.h"
#include "watch.h"

void hello_there_face_setup(movement_settings_t *settings, uint8_t watch_face_index, void ** context_ptr) {
    // These next two lines just silence the compiler warnings associated with unused parameters.
    // We have no use for the settings or the watch_face_index, so we make that explicit here.
    (void) settings;
    (void) watch_face_index;
    // At boot, context_ptr will be NULL indicating that we don't have anyplace to store our context.
    if (*context_ptr == NULL) {
        // in this case, we allocate an area of memory sufficient to store the stuff we need to track.
        *context_ptr = malloc(sizeof(hello_there_state_t));
    }
}

void hello_there_face_activate(movement_settings_t *settings, void *context) {
    // same as above: silence the warning, we don't need to check the settings.
    (void) settings;
    // we do however need to set some things in our context. Here we cast it to the correct type...
    hello_there_state_t *state = (hello_there_state_t *)context;
    // ...and set the initial state of our watch face. We start out displaying the word 'Hello',
    state->current_word = 0;
    // and animate by default.
    state->animating = true;
}

bool hello_there_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    hello_there_state_t *state = (hello_there_state_t *)context;

    switch (event.event_type) {
        case EVENT_ACTIVATE:
        case EVENT_TICK:
            // on activate and tick, if we are animating,
            if (state->animating) {
                // we display the current word,
                if (state->current_word == 0) watch_display_string("Hello ", 4);
                else watch_display_string(" there", 4);
                // and increment it so that it will update on the next tick.
                state->current_word = (state->current_word + 1) % 2;
            }
            break;
        case EVENT_MODE_BUTTON_UP:
            // when the user presses 'mode', we tell movement to move to the next watch face.
            // movement will call our resign function, clear the screen, and transfer control
            // to the next watch face in the list.
            movement_move_to_next_face();
            break;
        case EVENT_LIGHT_BUTTON_UP:
            // when the user presses 'light', we illuminate the LED. We could override this if
            // our UI needed an additional button for input, consuming the light button press
            // but not illuminating the LED.
            movement_illuminate_led();
            break;
        case EVENT_ALARM_BUTTON_UP:
            // when the user presses 'alarm', we toggle the state of the animation. If animating,
            // we stop; if stopped, we resume.
            state->animating = !state->animating;   
            break;
        case EVENT_LOW_ENERGY_UPDATE:
            // This low energy mode update occurs once a minute, if the watch face is in the
            // foreground when Movement enters low energy mode. We have the option of supporting
            // this mode, but since our watch face animates once a second, the "Hello there" face
            // isn't very useful in this mode. So we choose not to support it. (continued below)
            break;
        case EVENT_TIMEOUT:
            // ... Instead, we respond to the timeout event. This event happens after a configurable
            // interval on screen (1-30 minutes). The watch will give us this event as a chance to
            // resign control if we want to, and in this case, we do.
            // This function will return the watch to the first screen (usually a simple clock),
            // and it will do it long before the watch enters low energy mode. This ensures we
            // won't be on screen, and thus opts us out of getting the EVENT_LOW_ENERGY_UPDATE above.
            movement_move_to_face(0);
        default:
            break;
    }

    return true;
}

void hello_there_face_resign(movement_settings_t *settings, void *context) {
    // our watch face, like most watch faces, has nothing special to do when resigning.
    // watch faces that enable a peripheral or interact with a sensor may want to turn it off here.
    (void) settings;
    (void) context;
}
