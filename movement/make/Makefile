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
  -I../watch_faces/complications/ \
  -I../watch_faces/thermistor/ \

# If you add any other source files you wish to compile, add them after ../app.c
# Note that you will need to add a backslash at the end of any line you wish to continue, i.e.
# SRCS += \
#   ../movement.c \
#   ../drivers/lis2dh.c \
#   ../watch_faces/fitness/step_count_face.c
SRCS += \
  ../movement.c \
  ../watch_faces/clock/simple_clock_face.c \
  ../watch_faces/settings/preferences_face.c \
  ../watch_faces/settings/set_time_face.c \
  ../watch_faces/complications/pulsometer_face.c \
  ../watch_faces/thermistor/thermistor_driver.c \
  ../watch_faces/thermistor/thermistor_readout_face.c \

# Leave this line at the bottom of the file; it has all the targets for making your project.
include $(TOP)/rules.mk
