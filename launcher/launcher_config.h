#ifndef LAUNCHER_CONFIG_H_
#define LAUNCHER_CONFIG_H_

#include "simple_clock_widget.h"
#include "preferences_widget.h"
#include "set_time_widget.h"
#include "pulseometer_widget.h"
#include "fake_widget_1.h"
#include "fake_widget_2.h"

#define LAUNCHER_NUM_WIDGETS 3

WatchWidget widgets[LAUNCHER_NUM_WIDGETS] = {
    simple_clock_widget,
    preferences_widget,
    set_time_widget,
};


#endif // LAUNCHER_CONFIG_H_
