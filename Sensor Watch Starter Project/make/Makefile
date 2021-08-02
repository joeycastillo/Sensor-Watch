##############################################################################
BUILD = build
BIN = watch

##############################################################################
.PHONY: all directory clean size

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size
UF2 = python ../../utils/uf2conv.py

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
LDFLAGS += -Wl,--script=../../watch-library/linker/saml22j18.ld

# If you add any additional directories with headers, add them to this list, e.g.
# ../drivers/
INCLUDES += \
  -I../ \
  -I../../watch-library/include \
  -I../../watch-library/hal/ \
  -I../../watch-library/hal/documentation/ \
  -I../../watch-library/hal/include/ \
  -I../../watch-library/hal/src/ \
  -I../../watch-library/hal/utils/ \
  -I../../watch-library/hal/utils/include/ \
  -I../../watch-library/hal/utils/src/ \
  -I../../watch-library/hpl/ \
  -I../../watch-library/hpl/adc/ \
  -I../../watch-library/hpl/core/ \
  -I../../watch-library/hpl/dmac/ \
  -I../../watch-library/hpl/eic/ \
  -I../../watch-library/hpl/gclk/ \
  -I../../watch-library/hpl/mclk/ \
  -I../../watch-library/hpl/osc32kctrl/ \
  -I../../watch-library/hpl/oscctrl/ \
  -I../../watch-library/hpl/pm/ \
  -I../../watch-library/hpl/port/ \
  -I../../watch-library/hpl/rtc/ \
  -I../../watch-library/hpl/sercom/ \
  -I../../watch-library/hpl/slcd/ \
  -I../../watch-library/hpl/systick/ \
  -I../../watch-library/hpl/tcc/ \
  -I../../watch-library/hpl/tc/ \
  -I../../watch-library/hri/ \
  -I../../watch-library/config/ \
  -I../../watch-library/hw/ \
  -I../../watch-library/watch/ \
  -I../../watch-library

# If you add any additional C files to your project, add them each to this list, e.g.
# ../drivers/st25dv.c
SRCS += \
  ../app.c \
  ../../watch-library/main.c \
  ../../watch-library/startup_saml22.c \
  ../../watch-library/hw/driver_init.c \
  ../../watch-library/watch/watch.c \
  ../../watch-library/hal/src/hal_adc_sync.c \
  ../../watch-library/hal/src/hal_atomic.c \
  ../../watch-library/hal/src/hal_calendar.c \
  ../../watch-library/hal/src/hal_delay.c \
  ../../watch-library/hal/src/hal_ext_irq.c \
  ../../watch-library/hal/src/hal_gpio.c \
  ../../watch-library/hal/src/hal_i2c_m_sync.c \
  ../../watch-library/hal/src/hal_init.c \
  ../../watch-library/hal/src/hal_io.c \
  ../../watch-library/hal/src/hal_pwm.c \
  ../../watch-library/hal/src/hal_slcd_sync.c \
  ../../watch-library/hal/src/hal_sleep.c \
  ../../watch-library/hal/utils/src/utils_assert.c \
  ../../watch-library/hal/utils/src/utils_event.c \
  ../../watch-library/hal/utils/src/utils_list.c \
  ../../watch-library/hal/utils/src/utils_syscalls.c \
  ../../watch-library/hpl/adc/hpl_adc.c \
  ../../watch-library/hpl/core/hpl_core_m0plus_base.c \
  ../../watch-library/hpl/core/hpl_init.c \
  ../../watch-library/hpl/dmac/hpl_dmac.c \
  ../../watch-library/hpl/eic/hpl_eic.c \
  ../../watch-library/hpl/gclk/hpl_gclk.c \
  ../../watch-library/hpl/mclk/hpl_mclk.c \
  ../../watch-library/hpl/osc32kctrl/hpl_osc32kctrl.c \
  ../../watch-library/hpl/oscctrl/hpl_oscctrl.c \
  ../../watch-library/hpl/pm/hpl_pm.c \
  ../../watch-library/hpl/rtc/hpl_rtc.c \
  ../../watch-library/hpl/sercom/hpl_sercom.c \
  ../../watch-library/hpl/slcd/hpl_slcd.c \
  ../../watch-library/hpl/systick/hpl_systick.c \
  ../../watch-library/hpl/tcc/hpl_tcc.c \
  ../../watch-library/hpl/tc/hpl_tc.c

DEFINES += \
  -D__SAML22J18A__ \
  -DDONT_USE_CMSIS_INIT

CFLAGS += $(INCLUDES) $(DEFINES)

OBJS = $(addprefix $(BUILD)/, $(notdir %/$(subst .c,.o, $(SRCS))))

all: directory $(BUILD)/$(BIN).elf $(BUILD)/$(BIN).hex $(BUILD)/$(BIN).bin $(BUILD)/$(BIN).uf2 size

$(BUILD)/$(BIN).elf: $(OBJS)
	@echo LD $@
	@$(CC) $(LDFLAGS) $(OBJS) $(LIBS) -o $@

$(BUILD)/$(BIN).hex: $(BUILD)/$(BIN).elf
	@echo OBJCOPY $@
	@$(OBJCOPY) -O ihex $^ $@

$(BUILD)/$(BIN).bin: $(BUILD)/$(BIN).elf
	@echo OBJCOPY $@
	@$(OBJCOPY) -O binary $^ $@

$(BUILD)/$(BIN).uf2: $(BUILD)/$(BIN).bin
	@echo UF2CONV $@
	@$(UF2) $^ -co $@

install:
	@$(UF2) -D $(BUILD)/$(BIN).uf2

%.o:
	@echo CC $@
	@$(CC) $(CFLAGS) $(filter %/$(subst .o,.c,$(notdir $@)), $(SRCS)) -c -o $@

directory:
	@$(MKDIR) -p $(BUILD)

size: $(BUILD)/$(BIN).elf
	@echo size:
	@$(SIZE) -t $^

clean:
	@echo clean
	@-rm -rf $(BUILD)

-include $(wildcard $(BUILD)/*.d)

