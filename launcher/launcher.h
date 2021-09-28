#ifndef LAUNCHER_H_
#define LAUNCHER_H_
#include <stdio.h>
#include <stdbool.h>

// TODO: none of this is implemented
typedef union {
    struct {
        uint32_t reserved : 1;
        uint32_t clock_mode_24h : 1;        // determines whether display should use 12 or 24 hour mode.
        uint32_t signal_should_sound : 1;   // if true, a double beep is played at the top of each hour.
        uint32_t alarm_should_sound : 1;    // if true, the alarm interrupt plays a song.
        uint32_t note_index : 7;            // the index of the tone to play, or 0x7F for no tone.
        uint32_t snapback_enabled : 1;      // if true, snaps back to the main screen after 5 minutes
        uint32_t sleep_interval : 3;        // 0 to disable sleep, or a number of days to sleep after.
        uint32_t sleep_blanks_screen : 1;   // blank screen or display "SLEEP" when asleep
        uint32_t led_red_color : 8;         // for general purpose illumination, the red LED value
        uint32_t led_green_color : 8;       // for general purpose illumination, the green LED value
    } bit;
    uint32_t value;
} LauncherSettings;

typedef enum LauncherEvent {
    EVENT_NONE = 0,             // There is no event to report.
    EVENT_ACTIVATE,             // Your widget is entering the foreground.
    EVENT_TICK,                 // Most common event type. Your widget is being called from the tick callback.
    EVENT_LOOP,                 // The app did not sleep, and is going into another invocation of the run loop.
    EVENT_LIGHT_BUTTON_DOWN,    // The light button has been pressed, but not yet released.
    EVENT_LIGHT_BUTTON_UP,      // The light button was pressed and released.
    EVENT_LIGHT_LONG_PRESS,     // The light button was held for >2 seconds, and released.
    EVENT_MODE_BUTTON_DOWN,     // The mode button has been pressed, but not yet released.
    EVENT_MODE_BUTTON_UP,       // The mode button was pressed and released.
    EVENT_MODE_LONG_PRESS,      // The mode button was held for >2 seconds, and released.
    EVENT_ALARM_BUTTON_DOWN,    // The alarm button has been pressed, but not yet released.
    EVENT_ALARM_BUTTON_UP,      // The alarm button was pressed and released.
    EVENT_ALARM_LONG_PRESS,     // The alarm button was held for >2 seconds, and released.
} LauncherEvent;

typedef void (*launcher_widget_setup)(LauncherSettings *settings, void ** context_ptr);
typedef void (*launcher_widget_enter_foreground)(LauncherSettings *settings, void *context);
typedef bool (*launcher_widget_loop)(LauncherEvent event, LauncherSettings *settings, void *context);
typedef void (*launcher_widget_enter_background)(LauncherSettings *settings, void *context);

typedef struct WatchWidget {
    launcher_widget_setup setup;
    launcher_widget_enter_foreground enter_foreground;
    launcher_widget_loop loop;
    launcher_widget_enter_background enter_background;
} WatchWidget;

typedef struct LauncherState {
    // properties stored in BACKUP register
    LauncherSettings launcherSettings;

    // transient properties
    int16_t current_widget;
    bool widget_changed;

    // LED stuff
    uint8_t light_ticks;
    bool led_on;
    
    // button tracking for long press
    uint8_t light_down_timestamp;
    uint8_t mode_down_timestamp;
    uint8_t alarm_down_timestamp;
} LauncherState;

void cb_mode_pressed();
void cb_light_pressed();
void cb_alarm_pressed();
void cb_tick();

#endif // LAUNCHER_H_
