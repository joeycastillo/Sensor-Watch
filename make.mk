##############################################################################
BUILD = ./build
BIN = watch

ifndef BOARD
override BOARD = OSO-SWAT-A1-04
endif

##############################################################################
.PHONY: all directory clean size

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size
UF2 = python $(TOP)/utils/uf2conv.py

ifeq ($(OS), Windows_NT)
  MKDIR = gmkdir
else
  MKDIR = mkdir
endif

CFLAGS += -W -Wall --std=gnu99 -Os
CFLAGS += -fno-diagnostics-show-caret
CFLAGS += -fdata-sections -ffunction-sections
CFLAGS += -funsigned-char -funsigned-bitfields
CFLAGS += -mcpu=cortex-m0plus -mthumb
CFLAGS += -MD -MP -MT $(BUILD)/$(*F).o -MF $(BUILD)/$(@F).d

LDFLAGS += -mcpu=cortex-m0plus -mthumb
LDFLAGS += -Wl,--gc-sections
LDFLAGS += -Wl,--script=$(TOP)//watch-library/linker/saml22j18.ld

INCLUDES += \
  -I$(TOP)/tinyusb/src \
  -I$(TOP)/boards/$(BOARD) \
  -I$(TOP)/watch-library/include \
  -I$(TOP)/watch-library/hal/ \
  -I$(TOP)/watch-library/hal/documentation/ \
  -I$(TOP)/watch-library/hal/include/ \
  -I$(TOP)/watch-library/hal/src/ \
  -I$(TOP)/watch-library/hal/utils/ \
  -I$(TOP)/watch-library/hal/utils/include/ \
  -I$(TOP)/watch-library/hal/utils/src/ \
  -I$(TOP)/watch-library/hpl/ \
  -I$(TOP)/watch-library/hpl/core/ \
  -I$(TOP)/watch-library/hpl/dmac/ \
  -I$(TOP)/watch-library/hpl/eic/ \
  -I$(TOP)/watch-library/hpl/gclk/ \
  -I$(TOP)/watch-library/hpl/mclk/ \
  -I$(TOP)/watch-library/hpl/osc32kctrl/ \
  -I$(TOP)/watch-library/hpl/oscctrl/ \
  -I$(TOP)/watch-library/hpl/pm/ \
  -I$(TOP)/watch-library/hpl/port/ \
  -I$(TOP)/watch-library/hpl/sercom/ \
  -I$(TOP)/watch-library/hpl/slcd/ \
  -I$(TOP)/watch-library/hpl/systick/ \
  -I$(TOP)/watch-library/hri/ \
  -I$(TOP)/watch-library/config/ \
  -I$(TOP)/watch-library/hw/ \
  -I$(TOP)/watch-library/watch/ \
  -I$(TOP)/watch-library

SRCS += \
  $(TOP)/tinyusb/src/tusb.c \
  $(TOP)/tinyusb/src/common/tusb_fifo.c \
  $(TOP)/tinyusb/src/class/cdc/cdc_device.c \
  $(TOP)/tinyusb/src/device/usbd.c \
  $(TOP)/tinyusb/src/device/usbd_control.c \
  $(TOP)/tinyusb/src/portable/microchip/samd/dcd_samd.c \
  $(TOP)/watch-library/main.c \
  $(TOP)/watch-library/startup_saml22.c \
  $(TOP)/watch-library/hw/driver_init.c \
  $(TOP)/watch-library/watch/watch_rtc.c \
  $(TOP)/watch-library/watch/watch_slcd.c \
  $(TOP)/watch-library/watch/watch_extint.c \
  $(TOP)/watch-library/watch/watch_led.c \
  $(TOP)/watch-library/watch/watch_buzzer.c \
  $(TOP)/watch-library/watch/watch_adc.c \
  $(TOP)/watch-library/watch/watch_gpio.c \
  $(TOP)/watch-library/watch/watch_i2c.c \
  $(TOP)/watch-library/watch/watch_uart.c \
  $(TOP)/watch-library/watch/watch_deepsleep.c \
  $(TOP)/watch-library/watch/watch_utility.c \
  $(TOP)/watch-library/watch/watch_private.c \
  $(TOP)/watch-library/watch/watch.c \
  $(TOP)/watch-library/hal/src/hal_atomic.c \
  $(TOP)/watch-library/hal/src/hal_delay.c \
  $(TOP)/watch-library/hal/src/hal_ext_irq.c \
  $(TOP)/watch-library/hal/src/hal_gpio.c \
  $(TOP)/watch-library/hal/src/hal_i2c_m_sync.c \
  $(TOP)/watch-library/hal/src/hal_spi_m_sync.c \
  $(TOP)/watch-library/hal/src/hal_init.c \
  $(TOP)/watch-library/hal/src/hal_io.c \
  $(TOP)/watch-library/hal/src/hal_slcd_sync.c \
  $(TOP)/watch-library/hal/src/hal_sleep.c \
  $(TOP)/watch-library/hal/utils/src/utils_assert.c \
  $(TOP)/watch-library/hal/utils/src/utils_event.c \
  $(TOP)/watch-library/hal/utils/src/utils_list.c \
  $(TOP)/watch-library/hal/utils/src/utils_syscalls.c \
  $(TOP)/watch-library/hpl/core/hpl_core_m0plus_base.c \
  $(TOP)/watch-library/hpl/core/hpl_init.c \
  $(TOP)/watch-library/hpl/dmac/hpl_dmac.c \
  $(TOP)/watch-library/hpl/eic/hpl_eic.c \
  $(TOP)/watch-library/hpl/gclk/hpl_gclk.c \
  $(TOP)/watch-library/hpl/mclk/hpl_mclk.c \
  $(TOP)/watch-library/hpl/osc32kctrl/hpl_osc32kctrl.c \
  $(TOP)/watch-library/hpl/oscctrl/hpl_oscctrl.c \
  $(TOP)/watch-library/hpl/pm/hpl_pm.c \
  $(TOP)/watch-library/hpl/sercom/hpl_sercom.c \
  $(TOP)/watch-library/hpl/slcd/hpl_slcd.c \
  $(TOP)/watch-library/hpl/systick/hpl_systick.c \

DEFINES += \
  -D__SAML22J18A__ \
  -DDONT_USE_CMSIS_INIT

ifeq ($(LED), BLUE)
CFLAGS += -DWATCH_SWAP_LED_PINS
endif

ifeq ($(BOARD), OSO-FEAL-A1-00)
CFLAGS += -DCRYSTALLESS
endif
