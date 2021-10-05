# Leave this line at the top of the file; it has all the watch library sources and includes.
TOP = ../..
include $(TOP)/make.mk

# If you add any other subdirectories with header files you wish to include, add them after ../
# Note that you will need to add a backslash at the end of any line you wish to continue, i.e.
# INCLUDES += \
#   -I../ \
#   -I../drivers/ \
#   -I../widgets/fitness/
INCLUDES += \
  -I../ \
  -I../widgets/ \
  -I../widgets/clock/ \
  -I../widgets/settings/ \
  -I../widgets/complications/ \

# If you add any other source files you wish to compile, add them after ../app.c
# Note that you will need to add a backslash at the end of any line you wish to continue, i.e.
# SRCS += \
#   ../launcher.c \
#   ../drivers/lis2dh.c \
#   ../widgets/fitness/step_count_widget.c
SRCS += \
  ../launcher.c \
  ../widgets/clock/simple_clock_widget.c \
  ../widgets/settings/preferences_widget.c \
  ../widgets/settings/set_time_widget.c \
  ../widgets/complications/pulseometer_widget.c \

# Leave this line at the bottom of the file; it has all the targets for making your project.
include $(TOP)/rules.mk
