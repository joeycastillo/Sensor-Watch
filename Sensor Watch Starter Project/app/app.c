#include <stdio.h>
#include <string.h>
#include "app.h"

// these are implemented in main.c, just want to have access to them here.
void uart_putc(char c);
void uart_puts(char *s);

typedef enum ApplicationMode {
    MODE_TIME,
    MODE_SENSE,
    MODE_SET_HOUR,
    MODE_SET_MINUTE,
    MODE_SET_SECOND
} ApplicationMode;

typedef struct ApplicationState {
    ApplicationMode mode;
    bool light_pressed;
    bool mode_pressed;
    bool alarm_pressed;
    bool light_on;
    uint16_t dig_T1; /**< dig_T1 cal register. */
    int16_t dig_T2;  /**<  dig_T2 cal register. */
    int16_t dig_T3;  /**< dig_T3 cal register. */
} ApplicationState;

ApplicationState applicationState;

void cb_light_pressed() {
    applicationState.light_pressed = true;
}

void cb_mode_pressed() {
    applicationState.mode_pressed = true;
}

void cb_alarm_pressed() {
    applicationState.alarm_pressed = true;
}

void cb_tick() {
    ;
}
#define BMP280_REGISTER_DIG_T1 0x88
#define BMP280_REGISTER_DIG_T2 0x8A
#define BMP280_REGISTER_DIG_T3 0x8C
#define BMP280_REGISTER_SOFTRESET 0xE0
#define BMP280_REGISTER_STATUS 0xF3
#define BMP280_REGISTER_CONTROL 0xF4
#define BMP280_REGISTER_CONFIG 0xF5
#define BMP280_REGISTER_PRESSUREDATA 0xF7
#define BMP280_REGISTER_TEMPDATA 0xFA

uint16_t read8(uint8_t reg) {
    uint8_t val;
    watch_i2c_send(0x77, &reg, 1);
    watch_i2c_receive(0x77, &val, 1);
    return val;
}

uint16_t read16(uint8_t reg) {
    uart_puts("\nReading 2 bytes... ");
    uint8_t buf[2];
    watch_i2c_send(0x77, &reg, 1);
    watch_i2c_receive(0x77, (uint8_t *)&buf, 2);
    uart_puts("received!\n");
    char buf2[32] = {0};
    sprintf(buf2, "buf has values: %#02x, %#02x", buf[0], buf[1]);
    uart_puts(buf2);

    return (buf[0] << 8) | buf[1];
}

uint32_t read24(uint8_t reg) {
    uart_puts("\nReading 3 bytes... ");
    uint32_t value;
    uint8_t buf[3];

    watch_i2c_send(0x77, &reg, 1);
    watch_i2c_receive(0x77, (uint8_t *)&buf, 3);
    uart_puts("received!\n");
    char buf2[33] = {0};
    sprintf(buf2, "buf has values: %#02x, %#02x, %#02x", buf[0], buf[1], buf[2]);
    uart_puts(buf2);

    value = buf[0];
    value <<= 8;
    value |= buf[1];
    value <<= 8;
    value |= buf[2];

    return value;
}

uint16_t read16_LE(uint8_t reg) {
  uint16_t temp = read16(reg);
  return (temp >> 8) | (temp << 8);
}

int16_t readS16(uint8_t reg) { 
    return (int16_t)read16(reg); 
}

int16_t readS16_LE(uint8_t reg) {
  return (int16_t)read16_LE(reg);
}

void print_temperature() {
    int32_t var1, var2;
    int32_t t_fine;

    int32_t adc_T = read24(BMP280_REGISTER_TEMPDATA);
    adc_T >>= 4;

    var1 = ((((adc_T >> 3) - ((int32_t)applicationState.dig_T1 << 1))) *
        ((int32_t)applicationState.dig_T2)) >>
        11;

    var2 = (((((adc_T >> 4) - ((int32_t)applicationState.dig_T1)) *
        ((adc_T >> 4) - ((int32_t)applicationState.dig_T1))) >>
        12) *
        ((int32_t)applicationState.dig_T3)) >>
        14;

    t_fine = var1 + var2;

    float T = ((t_fine * 5 + 128) >> 8) / 100.0;

    char buf[32] = {0};
    sprintf(buf, "\n\nTemp is %3.2f degrees C", T);
    uart_puts(buf);
}

/**
 * @brief the app_init function is like setup() in Arduino. It is called once when the
 * program begins. You should set pin modes and enable any peripherals you want to
 * set up (real-time clock, I2C, etc.)
 * 
 * @note If your app enters the ultra-low power BACKUP sleep mode, this function will 
 * be called again when it wakes from that deep sleep state. In this state, the RTC will
 * still be configured with the correct date and time.
 */
void app_init() {
    memset(&applicationState, 0, sizeof(applicationState));
    watch_enable_buttons();
    watch_register_button_callback(BTN_LIGHT, cb_light_pressed);

    watch_enable_date_time();
    watch_enable_tick_callback(cb_tick);
    
    watch_enable_display();
    watch_enable_led();
    watch_enable_i2c();

    uart_puts("\n\nI2C Driver Test\n");
    uint8_t reset_cmd[] = {0xE0, 0xB6};
    watch_i2c_send(0x77, reset_cmd, 2);
    uart_puts("Reset BMP280\n");
    applicationState.dig_T1 = read16_LE(BMP280_REGISTER_DIG_T1);
    applicationState.dig_T2 = readS16_LE(BMP280_REGISTER_DIG_T2);
    applicationState.dig_T3 = readS16_LE(BMP280_REGISTER_DIG_T3);

    uint8_t ctrl_cmd[] = {0xF4, 0xA3};
    watch_i2c_send(0x77, ctrl_cmd, 2);
}

/**
 * @brief the app_prepare_for_sleep function is called before the watch goes into the
 * STANDBY sleep mode. In STANDBY mode, most peripherals are shut down, and no code
 * will run until the watch receives an interrupt (generally either the 1Hz tick or
 * a press on one of the buttons).
 */
void app_prepare_for_sleep() {
    applicationState.light_pressed = false;
    applicationState.mode_pressed = false;
    applicationState.alarm_pressed = false;
}

/**
 * @brief the app_wake_from_sleep function is called after the watch wakes from the
 * STANDBY sleep mode.
 */
void app_wake_from_sleep() {

}

void app_loop() {
    if (applicationState.light_pressed) {
        print_temperature();
    }
    uart_putc('.');
}
