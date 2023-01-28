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
  -I../../littlefs/ \
  -I../lib/TOTP/ \
  -I../lib/base32/ \
  -I../lib/sunriset/ \
  -I../lib/vsop87/ \
  -I../lib/astrolib/ \
  -I../lib/morsecalc/ \

# If you add any other source files you wish to compile, add them after ../app.c
# Note that you will need to add a backslash at the end of any line you wish to continue, i.e.
# SRCS += \
#   ../movement.c \
#   ../drivers/lis2dh.c \
#   ../watch_faces/fitness/step_count_face.c
SRCS += \
  ../lib/TOTP/sha1.c \
  ../lib/TOTP/sha256.c \
  ../lib/TOTP/sha512.c \
  ../lib/TOTP/TOTP.c \
  ../lib/base32/base32.c \
  ../lib/sunriset/sunriset.c \
  ../lib/vsop87/vsop87a_milli.c \
  ../lib/astrolib/astrolib.c \
  ../lib/morsecalc/calc.c \
  ../lib/morsecalc/calc_fns.c \
  ../lib/morsecalc/calc_strtof.c \
  ../lib/morsecalc/mc.c \
  ../../littlefs/lfs.c \
  ../../littlefs/lfs_util.c \
  ../movement.c \
  ../filesystem.c \
  ../watch_faces/clock/simple_clock_face.c \
  ../watch_faces/clock/world_clock_face.c \
  ../watch_faces/clock/beats_face.c \
  ../watch_faces/clock/weeknumber_clock_face.c \
  ../watch_faces/settings/preferences_face.c \
  ../watch_faces/settings/set_time_face.c \
  ../watch_faces/settings/set_time_hackwatch_face.c \
  ../watch_faces/sensor/thermistor_readout_face.c \
  ../watch_faces/sensor/thermistor_logging_face.c \
  ../watch_faces/sensor/thermistor_testing_face.c \
  ../watch_faces/demo/character_set_face.c \
  ../watch_faces/demo/voltage_face.c \
  ../watch_faces/demo/lis2dw_logging_face.c \
  ../watch_faces/demo/demo_face.c \
  ../watch_faces/demo/hello_there_face.c \
  ../watch_faces/complication/pulsometer_face.c \
  ../watch_faces/complication/day_one_face.c \
  ../watch_faces/complication/stopwatch_face.c \
  ../watch_faces/complication/totp_face.c \
  ../watch_faces/complication/totp_face_lfs.c \
  ../watch_faces/complication/sunrise_sunset_face.c \
  ../watch_faces/complication/countdown_face.c \
  ../watch_faces/complication/sailing_face.c \
  ../watch_faces/complication/counter_face.c \
  ../watch_faces/complication/blinky_face.c \
  ../watch_faces/complication/moon_phase_face.c \
  ../watch_faces/sensor/accelerometer_data_acquisition_face.c \
  ../watch_faces/clock/mars_time_face.c \
  ../watch_faces/complication/orrery_face.c \
  ../watch_faces/complication/astronomy_face.c \
  ../watch_faces/complication/tomato_face.c \
  ../watch_faces/complication/probability_face.c \
  ../watch_faces/complication/wake_face.c \
  ../watch_faces/demo/frequency_correction_face.c \
  ../watch_faces/complication/alarm_face.c \
  ../watch_faces/complication/ratemeter_face.c \
  ../watch_faces/complication/interval_face.c \
  ../watch_faces/complication/rpn_calculator_alt_face.c \
  ../watch_faces/complication/stock_stopwatch_face.c \
  ../watch_faces/complication/tachymeter_face.c \
  ../watch_faces/settings/nanosec_face.c \
  ../watch_faces/settings/finetune_face.c \
  ../watch_faces/complication/databank_face.c \
  ../watch_faces/complication/tempchart_face.c \
  ../watch_faces/complication/tally_face.c \
  ../watch_faces/complication/tarot_face.c \
  ../watch_faces/complication/morsecalc_face.c \
  ../watch_faces/complication/rpn_calculator_face.c \
  ../watch_faces/complication/ships_bell_face.c \
  ../watch_faces/complication/habit_face.c \
# New watch faces go above this line.

# Leave this line at the bottom of the file; it has all the targets for making your project.
include $(TOP)/rules.mk
