#ifndef LAUNCHER_CONFIG_H_
#define LAUNCHER_CONFIG_H_

#include "fake_widget_1.h"
#include "fake_widget_2.h"

#define LAUNCHER_NUM_WIDGETS 2

WatchWidget widgets[LAUNCHER_NUM_WIDGETS] = {
    fake_widget_1,
    fake_widget_2,
};


#endif // LAUNCHER_CONFIG_H_
