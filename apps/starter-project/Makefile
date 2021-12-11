# Leave these lines at the top of the file.
# TOP should get us to the root of the project...
TOP = ../..
# ...and make.mk has all the watch library sources and includes.
include $(TOP)/make.mk

# If you add any other subdirectories with header files you wish to include, add them after ./
# Note that you will need to add a backslash at the end of any line you wish to continue, i.e.
# INCLUDES += \
#   -I./ \
#   -I drivers/ \
#   -I utils/
INCLUDES += \
  -I./ \

# If you add any other source files you wish to compile, add them after app.c
# Note that you will need to add a backslash at the end of any line you wish to continue, i.e.
# SRCS += \
#   ./app.c \
#   ./drivers/bmp280.c \
#   ./utils/temperature.c
SRCS += \
  ./app.c \

# Leave this line at the bottom of the file; rules.mk has all the targets for making your project.
include $(TOP)/rules.mk
