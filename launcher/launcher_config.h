#ifndef LAUNCHER_CONFIG_H_
#define LAUNCHER_CONFIG_H_

#include "simple_clock_widget.h"
#include "preferences_widget.h"
#include "fake_widget_1.h"
#include "fake_widget_2.h"

#define LAUNCHER_NUM_WIDGETS 4

WatchWidget widgets[LAUNCHER_NUM_WIDGETS] = {
    simple_clock_widget,
    preferences_widget,
    fake_widget_1,
    fake_widget_2,
};


#endif // LAUNCHER_CONFIG_H_
