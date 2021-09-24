// Sensor Watch: Hiking Log Demo App
// This app displays a clock and temperature data from a BME280 temperature and humidiity sensor.
// It also logs up to 36 hours of temperature data for playback.
// You can use this app on backcountry treks: take the watch off at night and place it outside your tent.
// It will log overnight low temperatures for review in the morning and optional transfer to your notepad.

#define MAX_DATA_POINTS 36

typedef enum ApplicationMode {
    MODE_CLOCK = 0, // Displays month, day and current time.
    MODE_TEMP,      // (TE) Displays temperature and an optional humidity reading (0-10 representing 0-100%)
    MODE_LOG,       // (LO) Plays back temperature data (temperature in seconds slot)
    MODE_PREFS,     // (PR) Allows setting options for the application
    MODE_SET,       // (ST) Set time and date
    NUM_MODES       // Last item in the enum, it's the number of cases.
} ApplicationMode;

typedef struct SensorReading {
    bool is_valid;
    uint8_t hour;
    int8_t temperature;
} SensorReading;

typedef struct ApplicationState {
    // Internal application state
    ApplicationMode mode;   // Current mode
    bool mode_changed;      // Lets us perform one-time setup for a given mode
    uint16_t mode_ticks;    // Timeout for the mode (returns to clock after timeout expires)
    uint8_t light_ticks;    // Timeout for the light
    bool led_on;            // Indicates that the LED is on
    uint8_t page;           // Tracks the current page in log, prefs or settings.
} ApplicationState;

void cb_light_pressed();
void cb_mode_pressed();
void cb_alarm_pressed();
void cb_tick();
