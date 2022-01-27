##############################################################################
BUILD = ./build
BIN = watch

ifndef BOARD
override BOARD = OSO-SWAT-A1-04
endif

##############################################################################
.PHONY: all directory clean size

ifeq ($(OS), Windows_NT)
  MKDIR = gmkdir
else
  MKDIR = mkdir
endif

ifndef EMSCRIPTEN
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size
UF2 = python $(TOP)/utils/uf2conv.py

CFLAGS += -W -Wall -Wextra -Wmissing-prototypes -Wmissing-declarations
CFLAGS += --std=gnu99 -Os
CFLAGS += -fno-diagnostics-show-caret
CFLAGS += -fdata-sections -ffunction-sections
CFLAGS += -funsigned-char -funsigned-bitfields
CFLAGS += -mcpu=cortex-m0plus -mthumb
CFLAGS += -MD -MP -MT $(BUILD)/$(*F).o -MF $(BUILD)/$(@F).d

LDFLAGS += -mcpu=cortex-m0plus -mthumb
LDFLAGS += -Wl,--gc-sections
LDFLAGS += -Wl,--script=$(TOP)/watch-library/hardware/linker/saml22j18.ld

LIBS += -lm

INCLUDES += \
  -I$(TOP)/tinyusb/src \
  -I$(TOP)/boards/$(BOARD) \
  -I$(TOP)/watch-library/shared/config/ \
  -I$(TOP)/watch-library/shared/driver/ \
  -I$(TOP)/watch-library/shared/watch/ \
  -I$(TOP)/watch-library/hardware/include \
  -I$(TOP)/watch-library/hardware/hal/ \
  -I$(TOP)/watch-library/hardware/hal/documentation/ \
  -I$(TOP)/watch-library/hardware/hal/include/ \
  -I$(TOP)/watch-library/hardware/hal/src/ \
  -I$(TOP)/watch-library/hardware/hal/utils/ \
  -I$(TOP)/watch-library/hardware/hal/utils/include/ \
  -I$(TOP)/watch-library/hardware/hal/utils/src/ \
  -I$(TOP)/watch-library/hardware/hpl/ \
  -I$(TOP)/watch-library/hardware/hpl/core/ \
  -I$(TOP)/watch-library/hardware/hpl/dmac/ \
  -I$(TOP)/watch-library/hardware/hpl/eic/ \
  -I$(TOP)/watch-library/hardware/hpl/gclk/ \
  -I$(TOP)/watch-library/hardware/hpl/mclk/ \
  -I$(TOP)/watch-library/hardware/hpl/osc32kctrl/ \
  -I$(TOP)/watch-library/hardware/hpl/oscctrl/ \
  -I$(TOP)/watch-library/hardware/hpl/pm/ \
  -I$(TOP)/watch-library/hardware/hpl/port/ \
  -I$(TOP)/watch-library/hardware/hpl/sercom/ \
  -I$(TOP)/watch-library/hardware/hpl/slcd/ \
  -I$(TOP)/watch-library/hardware/hpl/systick/ \
  -I$(TOP)/watch-library/hardware/hri/ \
  -I$(TOP)/watch-library/hardware/hw/ \
  -I$(TOP)/watch-library/hardware/watch/ \
  -I$(TOP)/watch-library/hardware \

SRCS += \
  $(TOP)/tinyusb/src/tusb.c \
  $(TOP)/tinyusb/src/common/tusb_fifo.c \
  $(TOP)/tinyusb/src/class/cdc/cdc_device.c \
  $(TOP)/tinyusb/src/device/usbd.c \
  $(TOP)/tinyusb/src/device/usbd_control.c \
  $(TOP)/tinyusb/src/portable/microchip/samd/dcd_samd.c \
  $(TOP)/watch-library/hardware/main.c \
  $(TOP)/watch-library/hardware/startup_saml22.c \
  $(TOP)/watch-library/hardware/hw/driver_init.c \
  $(TOP)/watch-library/hardware/watch/watch_rtc.c \
  $(TOP)/watch-library/hardware/watch/watch_slcd.c \
  $(TOP)/watch-library/hardware/watch/watch_extint.c \
  $(TOP)/watch-library/hardware/watch/watch_led.c \
  $(TOP)/watch-library/hardware/watch/watch_buzzer.c \
  $(TOP)/watch-library/hardware/watch/watch_adc.c \
  $(TOP)/watch-library/hardware/watch/watch_gpio.c \
  $(TOP)/watch-library/hardware/watch/watch_i2c.c \
  $(TOP)/watch-library/hardware/watch/watch_uart.c \
  $(TOP)/watch-library/hardware/watch/watch_deepsleep.c \
  $(TOP)/watch-library/hardware/watch/watch_private.c \
  $(TOP)/watch-library/hardware/watch/watch.c \
  $(TOP)/watch-library/hardware/hal/src/hal_atomic.c \
  $(TOP)/watch-library/hardware/hal/src/hal_delay.c \
  $(TOP)/watch-library/hardware/hal/src/hal_ext_irq.c \
  $(TOP)/watch-library/hardware/hal/src/hal_gpio.c \
  $(TOP)/watch-library/hardware/hal/src/hal_i2c_m_sync.c \
  $(TOP)/watch-library/hardware/hal/src/hal_spi_m_sync.c \
  $(TOP)/watch-library/hardware/hal/src/hal_usart_sync.c \
  $(TOP)/watch-library/hardware/hal/src/hal_init.c \
  $(TOP)/watch-library/hardware/hal/src/hal_io.c \
  $(TOP)/watch-library/hardware/hal/src/hal_slcd_sync.c \
  $(TOP)/watch-library/hardware/hal/src/hal_sleep.c \
  $(TOP)/watch-library/hardware/hal/utils/src/utils_assert.c \
  $(TOP)/watch-library/hardware/hal/utils/src/utils_event.c \
  $(TOP)/watch-library/hardware/hal/utils/src/utils_list.c \
  $(TOP)/watch-library/hardware/hal/utils/src/utils_syscalls.c \
  $(TOP)/watch-library/hardware/hpl/core/hpl_core_m0plus_base.c \
  $(TOP)/watch-library/hardware/hpl/core/hpl_init.c \
  $(TOP)/watch-library/hardware/hpl/dmac/hpl_dmac.c \
  $(TOP)/watch-library/hardware/hpl/eic/hpl_eic.c \
  $(TOP)/watch-library/hardware/hpl/gclk/hpl_gclk.c \
  $(TOP)/watch-library/hardware/hpl/mclk/hpl_mclk.c \
  $(TOP)/watch-library/hardware/hpl/osc32kctrl/hpl_osc32kctrl.c \
  $(TOP)/watch-library/hardware/hpl/oscctrl/hpl_oscctrl.c \
  $(TOP)/watch-library/hardware/hpl/pm/hpl_pm.c \
  $(TOP)/watch-library/hardware/hpl/sercom/hpl_sercom.c \
  $(TOP)/watch-library/hardware/hpl/slcd/hpl_slcd.c \
  $(TOP)/watch-library/hardware/hpl/systick/hpl_systick.c \
  $(TOP)/watch-library/shared/driver/lis2dh.c \
  $(TOP)/watch-library/shared/driver/lis2dw.c \
  $(TOP)/watch-library/shared/watch/watch_private_display.c \
  $(TOP)/watch-library/shared/watch/watch_utility.c \

DEFINES += \
  -D__SAML22J18A__ \
  -DDONT_USE_CMSIS_INIT

else

CFLAGS += -W -Wall -Wextra -Wmissing-prototypes -Wmissing-declarations
CFLAGS += -Wno-format -Wno-unused-parameter

INCLUDES += \
  -I$(TOP)/boards/$(BOARD) \
  -I$(TOP)/watch-library/shared/driver/ \
  -I$(TOP)/watch-library/shared/config/ \
  -I$(TOP)/watch-library/shared/watch/ \
  -I$(TOP)/watch-library/simulator/hpl/port/ \
  -I$(TOP)/watch-library/hardware/include/component \
  -I$(TOP)/watch-library/hardware/hal/include/ \
  -I$(TOP)/watch-library/hardware/hal/utils/include/ \
  -I$(TOP)/watch-library/hardware/hpl/slcd/ \
  -I$(TOP)/watch-library/hardware/hw/ \

SRCS += \
  $(TOP)/watch-library/simulator/main.c \
  $(TOP)/watch-library/simulator/watch/watch_rtc.c \
  $(TOP)/watch-library/simulator/watch/watch_slcd.c \
  $(TOP)/watch-library/simulator/watch/watch_extint.c \
  $(TOP)/watch-library/simulator/watch/watch_led.c \
  $(TOP)/watch-library/simulator/watch/watch_buzzer.c \
  $(TOP)/watch-library/simulator/watch/watch_adc.c \
  $(TOP)/watch-library/simulator/watch/watch_gpio.c \
  $(TOP)/watch-library/simulator/watch/watch_i2c.c \
  $(TOP)/watch-library/simulator/watch/watch_uart.c \
  $(TOP)/watch-library/simulator/watch/watch_deepsleep.c \
  $(TOP)/watch-library/simulator/watch/watch_private.c \
  $(TOP)/watch-library/simulator/watch/watch.c \
  $(TOP)/watch-library/shared/watch/watch_private_display.c \
  $(TOP)/watch-library/shared/watch/watch_utility.c \

endif

ifeq ($(LED), BLUE)
CFLAGS += -DWATCH_SWAP_LED_PINS
endif

ifeq ($(BOARD), OSO-FEAL-A1-00)
CFLAGS += -DCRYSTALLESS
endif
