#ifndef THERMISTOR_DRIVER_H_
#define THERMISTOR_DRIVER_H_

// NOTE: This implementation is specific to one prototype sensor board, OSO-MISC-21-009, but both
// the sensor board design and this implementation are likely to change. Thermistor functionality
// may even end up being baked into the Sensor Watch library. This is all by way of saying this
// code is very temporary and the thermistor screens will likely get a rewrite in the future.

void thermistor_driver_enable();
void thermistor_driver_disable();
float thermistor_driver_get_temperature();

#endif // THERMISTOR_DRIVER_H_
