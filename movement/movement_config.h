#ifndef MOVEMENT_CONFIG_H_
#define MOVEMENT_CONFIG_H_

#include "simple_clock_widget.h"
#include "preferences_widget.h"
#include "set_time_widget.h"
#include "pulseometer_widget.h"

#define MOVEMENT_NUM_WIDGETS 3

WatchWidget widgets[MOVEMENT_NUM_WIDGETS] = {
    simple_clock_widget,
    preferences_widget,
    set_time_widget,
};


#endif // MOVEMENT_CONFIG_H_
