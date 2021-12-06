#ifndef THERMISTOR_DRIVER_H_
#define THERMISTOR_DRIVER_H_

// TODO: Do these belong in movement_config.h? In settings we can set on the watch? In an EEPROM configuration area?
// Think on this. [joey 11/22]
#define THERMISTOR_SENSE_PIN (A2)
#define THERMISTOR_ENABLE_PIN (A0)
#define THERMISTOR_ENABLE_VALUE (false)
#define THERMISTOR_HIGH_SIDE (true)
#define THERMISTOR_B_COEFFICIENT (3380.0)
#define THERMISTOR_NOMINAL_TEMPERATURE (25.0)
#define THERMISTOR_NOMINAL_RESISTANCE (10000.0)
#define THERMISTOR_SERIES_RESISTANCE (10000.0)

void thermistor_driver_enable(void);
void thermistor_driver_disable(void);
float thermistor_driver_get_temperature(void);

#endif // THERMISTOR_DRIVER_H_
