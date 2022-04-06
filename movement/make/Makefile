# Leave this line at the top of the file; it has all the watch library sources and includes.
TOP = ../..
include $(TOP)/make.mk

# If you add any other subdirectories with header files you wish to include, add them after ../
# Note that you will need to add a backslash at the end of any line you wish to continue, i.e.
# INCLUDES += \
#   -I../ \
#   -I../drivers/ \
#   -I../watch_faces/fitness/
INCLUDES += \
  -I../ \
  -I../watch_faces/ \
  -I../watch_faces/clock/ \
  -I../watch_faces/settings/ \
  -I../watch_faces/complication/ \
  -I../watch_faces/sensor/ \
  -I../watch_faces/demo/ \
  -I../lib/TOTP-MCU/ \
  -I../lib/sunriset/ \
  -I../lib/vsop87/ \
  -I../lib/astrolib/ \

# If you add any other source files you wish to compile, add them after ../app.c
# Note that you will need to add a backslash at the end of any line you wish to continue, i.e.
# SRCS += \
#   ../movement.c \
#   ../drivers/lis2dh.c \
#   ../watch_faces/fitness/step_count_face.c
SRCS += \
  ../lib/TOTP-MCU/sha1.c \
  ../lib/TOTP-MCU/TOTP.c \
  ../lib/sunriset/sunriset.c \
  ../lib/vsop87/vsop87a_milli.c \
  ../lib/astrolib/astrolib.c \
  ../movement.c \
  ../watch_faces/clock/simple_clock_face.c \
  ../watch_faces/clock/world_clock_face.c \
  ../watch_faces/clock/beats_face.c \
  ../watch_faces/settings/preferences_face.c \
  ../watch_faces/settings/set_time_face.c \
  ../watch_faces/sensor/thermistor_readout_face.c \
  ../watch_faces/sensor/thermistor_logging_face.c \
  ../watch_faces/sensor/thermistor_testing_face.c \
  ../watch_faces/demo/character_set_face.c \
  ../watch_faces/demo/voltage_face.c \
  ../watch_faces/demo/lis2dh_logging_face.c \
  ../watch_faces/demo/demo_face.c \
  ../watch_faces/demo/hello_there_face.c \
  ../watch_faces/complication/pulsometer_face.c \
  ../watch_faces/complication/day_one_face.c \
  ../watch_faces/complication/stopwatch_face.c \
  ../watch_faces/complication/totp_face.c \
  ../watch_faces/complication/sunrise_sunset_face.c \
  ../watch_faces/complication/countdown_face.c \
  ../watch_faces/complication/blinky_face.c \
  ../watch_faces/complication/moon_phase_face.c \
  ../watch_faces/clock/mars_time_face.c \
  ../watch_faces/complication/orrery_face.c \
  ../watch_faces/complication/astronomy_face.c \
  ../watch_faces/complication/tomato_face.c \
# New watch faces go above this line.

# Leave this line at the bottom of the file; it has all the targets for making your project.
include $(TOP)/rules.mk
