#ifndef MOVEMENT_H_
#define MOVEMENT_H_
#include <stdio.h>
#include <stdbool.h>

// TODO: none of this is implemented
typedef union {
    struct {
        uint32_t reserved : 3;
        uint32_t clock_mode_24h : 1;        // determines whether clock should use 12 or 24 hour mode.
        uint32_t button_should_sound : 1;   // if true, pressing a button emits a sound.
        uint32_t signal_should_sound : 1;   // if true, a double beep is played at the top of each hour.
        uint32_t alarm_should_sound : 1;    // if true, the alarm interrupt can match a time and play a song.
        uint32_t alarm_minute : 6;          // the minute of the alarm we want to match
        uint32_t alarm_hour : 5;            // the second of the alarm we want to match
        uint32_t screensaver_interval : 3;  // 0 to disable screensaver, or a screensaver activation interval.
        uint32_t led_duration : 3;          // how many seconds to shine the LED for, or 0 to disable it.
        uint32_t led_red_color : 4;         // for general purpose illumination, the red LED value (0-15)
        uint32_t led_green_color : 4;       // for general purpose illumination, the green LED value (0-15)
    } bit;
    uint32_t value;
} movement_settings_t;

typedef enum {
    EVENT_NONE = 0,             // There is no event to report.
    EVENT_ACTIVATE,             // Your watch face is entering the foreground.
    EVENT_TICK,                 // Most common event type. Your watch face is being called from the tick callback.
    EVENT_SCREENSAVER,          // Your watch face is being asked to display its output for screensaver mode.
    EVENT_LIGHT_BUTTON_DOWN,    // The light button has been pressed, but not yet released.
    EVENT_LIGHT_BUTTON_UP,      // The light button was pressed and released.
    EVENT_LIGHT_LONG_PRESS,     // The light button was held for >2 seconds, and released.
    EVENT_MODE_BUTTON_DOWN,     // The mode button has been pressed, but not yet released.
    EVENT_MODE_BUTTON_UP,       // The mode button was pressed and released.
    EVENT_MODE_LONG_PRESS,      // The mode button was held for >2 seconds, and released.
    EVENT_ALARM_BUTTON_DOWN,    // The alarm button has been pressed, but not yet released.
    EVENT_ALARM_BUTTON_UP,      // The alarm button was pressed and released.
    EVENT_ALARM_LONG_PRESS,     // The alarm button was held for >2 seconds, and released.
} movement_event_type_t;

typedef struct {
    uint8_t event_type;
    uint8_t subsecond;
} movement_event_t;

typedef void (*watch_face_setup)(movement_settings_t *settings, void ** context_ptr);
typedef void (*watch_face_activate)(movement_settings_t *settings, void *context);
typedef bool (*watch_face_loop)(movement_event_t event, movement_settings_t *settings, void *context);
typedef void (*watch_face_resign)(movement_settings_t *settings, void *context);

typedef struct {
    watch_face_setup setup;
    watch_face_activate activate;
    watch_face_loop loop;
    watch_face_resign resign;
} watch_face_t;

typedef struct {
    // properties stored in BACKUP register
    movement_settings_t movement_settings;

    // transient properties
    int16_t current_watch_face;
    int16_t next_face;
    bool watch_face_changed;

    // LED stuff
    uint8_t light_ticks;
    bool led_on;
    
    // button tracking for long press
    uint8_t light_down_timestamp;
    uint8_t mode_down_timestamp;
    uint8_t alarm_down_timestamp;

    // screensaver countdown
    int32_t screensaver_ticks;

    // stuff for subsecond tracking
    uint8_t tick_frequency;
    uint8_t last_second;
    uint8_t subsecond;
} movement_state_t;

void movement_move_to_face(uint8_t watch_face_index);
void movement_move_to_next_face();
void movement_illuminate_led();
void movement_request_tick_frequency(uint8_t freq);

#endif // MOVEMENT_H_
