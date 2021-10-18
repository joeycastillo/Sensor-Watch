Movement: the community watch face app
======================================

The Sensor Watch Library allows you to write your own bare-metal applications for the Sensor Watch. This is great if you want full control over the code running on the device, but it also means that you may have to implement your own UI for many common tasks like setting the time or illuminating the screen.

**Movement** is an application that manages the display of different screens of content on the watch. These screens are called **watch faces**. Watch faces can be passive displays of information like a clock or a calendar, or they can be fully interactive user interfaces like the Preferences face, which allows the user to customize Movement's behavior. Movement handles the instantiation of your watch face and manages transitions between screens. It also provides a low-power sleep mode, triggered after a period of inactivity, to preserve the watch battery.

Several faces are provided that offer baseline functionality like a clock, a settings screen and an interface for setting the time. You can change and reorder the watch faces that Movement displays by editing `movement_config.h`, and you can write your own watch face using the guidance in this document.

Watch Face API
--------------

You can implement a watch face using just four functions: 

* `watch_face_setup`
* `watch_face_activate`
* `watch_face_loop`
* `watch_face_resign`

A fifth optional function, `watch_face_wants_background_task`, has not yet had its implementation ironed out, but it will be added to the guide at a later date.

To create a new watch face, you should create a new C header and source file in the watch-faces folder (i.e. for a watch face that displays moon phases: `moon_phase_face.h`, `moon_phase_face.c`), and implement these functions with your own unique prefix (i.e. `moon_phase_face_setup`). Then declare your watch face in your header file as follows:

```c
static const watch_face_t moon_phase_face = {
    moon_phase_face_setup,
    moon_phase_face_activate,
    moon_phase_face_loop,
    moon_phase_face_resign,
    NULL // or moon_phase_face_wants_background_task, if you implemented this function
};
```

This section will go over how each function works. The section headings use the watch_face prefix, but know that you should implement each function with your own prefix as described above.

### watch_face_setup

If you have worked with Arduino, this function is similar to setup() in that it is called at first boot. In our case, it is also called when waking from sleep mode. You will be passed three parameters:

* `settings` - a pointer to the global Movement settings. You can use this to inform how you present your display to the user (i.e. taking into account whether they have silenced the buttons, or if they prefer 12 or 24-hour mode). You can also change these settings if you like.
* `position` - The 0-indexed position of your watch face in the list of faces.
* `context_ptr` - A pointer to a pointer. On first run, the pointee will be NULL. If you need to keep track of any state within your watch face, you should check if it is NULL, and if so, set its value to a pointer to some value or struct that will keep track of that state. For example, the Preferences face needs to keep track of which page the user is viewing (just an integer), whereas the Pulsometer face needs to track several different properties in a struct.

Beyond setting up the context pointer, you may want to configure any peripherals that your watch face requires; for example, a temperature watch face that reads a thermistor output may want to configure the ADC here. Still, to save power, you should avoid leaving the peripheral enabled, and wait to set pin function in the activate function.

It was mentioned above but it's worth mentioning again: this function will be called again after waking from sleep mode, since sleep mode disables all of the device's pins and peripherals. This would give the temperature watch face a chance to re-configure the ADC.

### watch_face_activate

This function is called just before your watch enters the foreground. If your watch face has any segments or text that is always displayed, you may want to set that here. In addition, if your watch face depends on data from a peripheral (like that temperature watch face), you will likely want to enable that peripheral and set any required pin modes here. This function is also passed a pointer to the settings and your application context.

### watch_face_loop

This is a lot like your loop() function in Arduinoland in that it is called repeatedly whenever your watch face is on screen. There is one crucial difference though: it is called less often. By default, this function is called once per second, and in response to events like button presses. You can request a more frequent tick interval by calling `movement_request_tick_frequency` with any power of 2 from 1 to 128. 

In addition to the settings and context, this function receives another parameter: an `event`. This is a struct containing information about the event that triggered the update. You mostly need to check the `event_type` to determine what kind of event triggered the loop. A detailed list of all events is provided at the bottom of this document. 

There is also a `subsecond` property on the event that contains the fractional second of the event. If you are using 1 Hz updates, subsecond will always be 0.

You should set up a switch statement that handles, at the very least, the `EVENT_TICK` and `EVENT_MODE_BUTTON_UP` event types. The mode button up event occurs when the user presses the MODE button. **Your loop function SHOULD call the movement_move_to_next_face function in response to this event.** If you have a good reason to override this behavior (e.g. your user interface requires all three buttons), your watch face MUST call the movement_move_to_next_face function in response to the EVENT_MODE_LONG_PRESS event. If you fail to do this, the user will become stuck on your watch face.

### watch_face_resign

This function is called just before your watch face goes off screen. You should disable any peripherals you enabled in `watch_face_activate`. If you requested a tick frequency other than 1 Hz at any point in your code, **you must reset it to 1 Hz when you resign**. The watch_face_resign function is passed the same settings and context as the other functions.

Putting it into practice: the Pulsometer watch face
---------------------------------------------------

Let's take a look at a watch face to see how these pieces fit together. A *pulsometer* is [a mechanical watch complication designed to determine someone's pulse](https://www.ablogtowatch.com/longines-pulsometer-chronograph-watch/) by counting their heartbeats: you start the pulsometer, count heartbeats, and stop it when you reach the specified number. The needle will point to the pulse rate.

Let's implement a pulsometer for the Sensor Watch. These files are in the repository as `pulsometer_face.h` and `pulsometer_face.c`, but we'll walk through them inline here. 

### pulsometer_face.h

First, let's take a look at the header file. First we include the Movement header file, which defines the various types we need to build a watch face:

```c
#include "movement.h"
```

The pulsometer needs to track certain state to do its job, so we define a struct to contain our watch face's context:

```c
typedef struct {
    bool measuring;
    int16_t pulse;
    int16_t ticks;
} pulsometer_state_t;
```

Finally, we define the four required functions, and define the watch face struct that users will use to add the face to their watch:

```c
void pulsometer_face_setup(movement_settings_t *settings, void ** context_ptr);
void pulsometer_face_activate(movement_settings_t *settings, void *context);
bool pulsometer_face_loop(movement_event_t event, movement_settings_t *settings, void *context);
void pulsometer_face_resign(movement_settings_t *settings, void *context);

static const watch_face_t pulsometer_face = {
    pulsometer_face_setup,
    pulsometer_face_activate,
    pulsometer_face_loop,
    pulsometer_face_resign,
    NULL
};
```

### pulsometer_face.c

Now let's look at the implementation of the Pulsometer face. First up, we have a couple of definitions that we'll reference in the code: 

```c
#define PULSOMETER_FACE_FREQUENCY_FACTOR (4ul) // refresh rate will be 2 to this power Hz (0 for 1 Hz, 2 for 4 Hz, etc.)
#define PULSOMETER_FACE_FREQUENCY (1 << PULSOMETER_FACE_FREQUENCY_FACTOR)
```

These define the tick frequency: when the pulsometer widget is updating the screen, it will request 16 Hz updates (2^4).

#### Watch Face Setup

```c
void pulsometer_face_setup(movement_settings_t *settings, void ** context_ptr) {
    (void) settings;
    if (*context_ptr == NULL) *context_ptr = malloc(sizeof(pulsometer_state_t));
}
```

The `(void) settings;` line just silences a compiler warning about the unused parameter. The next line checks if the context pointer is NULL, and if so, allocates a `pulsometer_state_t`-sized chunk of memory to hold our state.

#### Watch Face Activation

```c
void pulsometer_face_activate(movement_settings_t *settings, void *context) {
    (void) settings;
    memset(context, 0, sizeof(pulsometer_state_t));
}
```

The pulsometer face doesn't need to keep track of context in between appearances; there's no need to keep displaying an old pulse reading hours or days after it was taken. So this line just sets the context to all zeroes before the watch face goes on screen.

#### Watch Face Loop

Next we have the loop function. First things first: it fetches our application context, and casts it to a `pulsometer_state_t` type so we can make use of it. It also creates a buffer for any text we plan to put on screen, and declares a switch statement for handling events:

```c
bool pulsometer_face_loop(movement_event_t event, movement_settings_t *settings, void *context) {
    (void) settings;
    pulsometer_state_t *pulsometer_state = (pulsometer_state_t *)context;
    char buf[14];
    switch (event.event_type) {
```

Let's go through each case one by one. In response to the user releasing the MODE button, we tell Movement to move to the next watch face.

```c
case EVENT_MODE_BUTTON_UP:
    movement_move_to_next_face();
    break;
```

Similarly in response to the user releasing the LIGHT button, we tell Movement to illuminate the LED. Movement does not do this automatically, in case your watch face UI has another use for the LIGHT button.

```c
case EVENT_LIGHT_BUTTON_UP:
    movement_illuminate_led();
    break;
```

The ALARM button is the main button the user will use to interact with the pulsometer. In response to the user pressing the ALARM button, we begin a measurement. We also request a faster tick frequency, so that we can update the display at 16 Hz.

```c
case EVENT_ALARM_BUTTON_DOWN:
    pulsometer_state->measuring = true;
    pulsometer_state->pulse = 0xFFFF;
    pulsometer_state->ticks = 0;
    movement_request_tick_frequency(PULSOMETER_FACE_FREQUENCY);
    break;
```

When the user releases the ALARM button, we finish the measurement. We also scale the update frequency back down to 1 Hz.

```c
case EVENT_ALARM_BUTTON_UP:
case EVENT_ALARM_LONG_PRESS:
    pulsometer_state->measuring = false;
    movement_request_tick_frequency(1);
    break;
```

The tick event handler is long, but handles all display updates. The first half of this conditional handles the case where we haven't yet measured anything: it just loops through five screens with instructions, and increments the tick count. 

```c
case EVENT_TICK:
    if (pulsometer_state->pulse == 0 && !pulsometer_state->measuring) {
        switch (pulsometer_state->ticks % 5) {
            case 0:
                watch_display_string("  Hold  ", 2);
                break;
            case 1:
                watch_display_string(" Alarn", 4);
                break;
            case 2:
                watch_display_string("+   Count ", 0);
                break;
            case 3:
                watch_display_string("  30Beats ", 0);
                break;
            case 4:
                watch_clear_display();
                break;
        }
        pulsometer_state->ticks = (pulsometer_state->ticks + 1) % 5;
```

The second half of the conditional handles the case where we are measuring or have a measurement to display. It does the math, updates the screen, and increments the tick count if needed.

```c
    } else {
        if (pulsometer_state->measuring && pulsometer_state->ticks) {
            pulsometer_state->pulse = (int16_t)((30.0 * ((float)(60 << PULSOMETER_FACE_FREQUENCY_FACTOR) / (float)pulsometer_state->ticks)) + 0.5);
        }
        if (pulsometer_state->pulse > 240) {
            watch_display_string("        Hi", 0);
        } else if (pulsometer_state->pulse < 40) {
            watch_display_string("        Lo", 0);
        } else {
            sprintf(buf, "    %-3dbpn", pulsometer_state->pulse);
            watch_display_string(buf, 0);
        }
        if (pulsometer_state->measuring) pulsometer_state->ticks++;
    }
    break;
```

Finally, the timeout event. After a period of inactivity (configurable from one to thirty minutes), Movement will send this event to indicate that the user has not interacted with your watch face in some time. Watch faces do not need to resign when they receive the timeout event, but depending on what kind of information your watch face displays, you may want to resign by asking Movement to return to the first watch face (usually a clock). The pulsometer widget has no need to remain on screen, so it opts to return to the clock when it receives the timeout event.

```c
case EVENT_TIMEOUT:
    movement_move_to_face(0);
    break;
```

#### Watch Face Resignation

The resign function doesn't have to do much here; it just resets the tick frequency to 1 Hz.

```c
void pulsometer_face_resign(movement_settings_t *settings, void *context) {
    (void) settings;
    (void) context;
    movement_request_tick_frequency(1);
}
```

And that's that!

Low Energy Mode
---------------

To save energy, the watch enters a low energy mode after a timeout period (confugurable from 1 hour to 7 days). In this mode, the watch will turn off all pins and peripherals except for the screen and real-time clock, and will wake up once a minute to allow the current watch face to update its display.

Movement Event Types
--------------------

### EVENT_ACTIVATE

You will receive this event when your watch face is entering the foreground. You can treat it like a tick event and just update the display.

### EVENT_TICK

This is the most common event type. Your watch face is being called as a result of the real-time clock ticking. By default this tick occurs once per second, but you can request more frequent updates.

### EVENT_LIGHT_BUTTON_DOWN, EVENT_MODE_BUTTON_DOWN, EVENT_ALARM_BUTTON_DOWN

Your watch face receives these events when one of the buttons is initially depressed, but before it is released.

### EVENT_LIGHT_BUTTON_UP, EVENT_MODE_BUTTON_UP, EVENT_ALARM_BUTTON_UP

Your watch face receives these events when one of these buttons is released quickly after being depressed (i.e. held for less than one second).

### EVENT_LIGHT_LONG_PRESS, EVENT_MODE_LONG_PRESS, EVENT_ALARM_LONG_PRESS

Your watch face receives these events when one of these buttons is released after having been held down for more than two seconds.

### EVENT_TIMEOUT

Your watch face receives this event after it has has been inactive for a while. You may want to resign here, depending on your watch face's intended use case.

### EVENT_LOW_ENERGY_UPDATE

If your watch face is in the foreground when the watch goes into low energy mode, you will receive an `EVENT_LOW_ENERGY_UPDATE` event once a minute (at the top of the minute) so that you can update the screen. Note however that when you receive this event, all pins and peripherals other than the RTC will have been disabled to save energy. If your display is clock or calendar oriented, this is fine. But if your display requires polling an I2C sensor or reading a value with the ADC, you won't be able to do this. You should either display the name of the watch face in response to the low power tick, or ensure that you resign before low power mode triggers (you can do this by calling `movement_move_to_face(0)` in your `EVENT_TIMEOUT` handler).

**Your watch face MUST NOT wake up peripherals in response to a low energy update event.** The purpose of this mode is to consume as little energy as possible during the (potentially long) intervals when it's unlikely the user is wearing or looking at the watch.

### EVENT_BACKGROUND_TASK

The `EVENT_BACKGROUND_TASK` event is not yet implemented, but the plan is for this event type to allow waking peripherals even in low power mode. More information will be added in a future version of this guide.
