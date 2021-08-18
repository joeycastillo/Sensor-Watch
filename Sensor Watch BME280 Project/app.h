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
    bool is_fahrenheit;     // User preference, C or F
    bool debounce_wait;     // For debouncing button inputs

    // Data logging
    SensorReading logged_data[MAX_DATA_POINTS];

    // User preference
    bool show_humidity;     // Indicates that the LED is on

    // BME280 calibration values
    uint16_t dig_T1;
    int16_t dig_T2;
    int16_t dig_T3;
    uint8_t dig_H1;
    int16_t dig_H2;
    uint8_t dig_H3;
    int16_t dig_H4;
    int16_t dig_H5;
    int8_t dig_H6;
} ApplicationState;

float read_temperature(int32_t *p_t_fine);
float read_humidity(int32_t t_fine);

void log_data();

void do_clock_mode();

void do_temp_mode();
void temp_mode_handle_primary_button();

void do_log_mode();
void log_mode_handle_primary_button();

void do_prefs_mode();
void prefs_mode_handle_primary_button();
void prefs_mode_handle_secondary_button();

void do_set_time_mode();
void set_time_mode_handle_primary_button();
void set_time_mode_handle_secondary_button();

void cb_light_pressed();
void cb_mode_pressed();
void cb_alarm_pressed();
void cb_tick();
