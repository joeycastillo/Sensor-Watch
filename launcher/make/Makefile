# Leave this line at the top of the file; it has all the watch library sources and includes.
TOP = ../..
include $(TOP)/make.mk

# If you add any other subdirectories with header files you wish to include, add them after ../
# Note that you will need to add a backslash at the end of any line you wish to continue, i.e.
# INCLUDES += \
#   -I../ \
#   -I../drivers/ \
#   -I../utils/
INCLUDES += \
  -I../ \
  -I../widgets/ \
  -I../widgets/clock/ \
  -I../widgets/settings/ \

# If you add any other source files you wish to compile, add them after ../app.c
# Note that you will need to add a backslash at the end of any line you wish to continue, i.e.
# SRCS += \
#   ../app.c \
#   ../drivers/bmp280.c \
#   ../utils/temperature.c
SRCS += \
  ../launcher.c \
  ../widgets/clock/simple_clock_widget.c \
  ../widgets/settings/preferences_widget.c \
  ../widgets/fake_widget_1.c \
  ../widgets/fake_widget_2.c \

# Leave this line at the bottom of the file; it has all the targets for making your project.
include $(TOP)/rules.mk
