TOP = ../..
include $(TOP)/make.mk

INCLUDES += \
  -I$(TOP)/littlefs/ \
  -I./

SRCS += \
  $(TOP)/littlefs/lfs.c \
  $(TOP)/littlefs/lfs_util.c \
  ./app.c

include $(TOP)/rules.mk
