##############################################################################
BUILD = build
BIN = watch

##############################################################################
.PHONY: all directory clean size

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size
UF2 = python uf2conv.py

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
LDFLAGS += -Wl,--script=../linker/saml22j18.ld

INCLUDES += \
  -I../include \
  -I../hal/ \
  -I../hal/documentation/ \
  -I../hal/include/ \
  -I../hal/src/ \
  -I../hal/utils/ \
  -I../hal/utils/include/ \
  -I../hal/utils/src/ \
  -I../hpl/ \
  -I../hpl/adc/ \
  -I../hpl/core/ \
  -I../hpl/dmac/ \
  -I../hpl/eic/ \
  -I../hpl/gclk/ \
  -I../hpl/mclk/ \
  -I../hpl/osc32kctrl/ \
  -I../hpl/oscctrl/ \
  -I../hpl/pm/ \
  -I../hpl/port/ \
  -I../hpl/rtc/ \
  -I../hpl/sercom/ \
  -I../hpl/slcd/ \
  -I../hpl/systick/ \
  -I../hpl/tcc/ \
  -I../hpl/tc/ \
  -I../hri/ \
  -I../config/ \
  -I..

SRCS += \
  ../main.c \
  ../startup_saml22.c \
  ../hal/src/hal_adc_sync.c \
  ../hal/src/hal_atomic.c \
  ../hal/src/hal_calendar.c \
  ../hal/src/hal_delay.c \
  ../hal/src/hal_ext_irq.c \
  ../hal/src/hal_gpio.c \
  ../hal/src/hal_i2c_m_sync.c \
  ../hal/src/hal_init.c \
  ../hal/src/hal_io.c \
  ../hal/src/hal_pwm.c \
  ../hal/src/hal_slcd_sync.c \
  ../hal/src/hal_sleep.c \
  ../hal/utils/src/utils_assert.c \
  ../hal/utils/src/utils_event.c \
  ../hal/utils/src/utils_list.c \
  ../hal/utils/src/utils_syscalls.c \
  ../hpl/adc/hpl_adc.c \
  ../hpl/core/hpl_core_m0plus_base.c \
  ../hpl/core/hpl_init.c \
  ../hpl/dmac/hpl_dmac.c \
  ../hpl/eic/hpl_eic.c \
  ../hpl/gclk/hpl_gclk.c \
  ../hpl/mclk/hpl_mclk.c \
  ../hpl/osc32kctrl/hpl_osc32kctrl.c \
  ../hpl/oscctrl/hpl_oscctrl.c \
  ../hpl/pm/hpl_pm.c \
  ../hpl/rtc/hpl_rtc.c \
  ../hpl/sercom/hpl_sercom.c \
  ../hpl/slcd/hpl_slcd.c \
  ../hpl/systick/hpl_systick.c \
  ../hpl/tcc/hpl_tcc.c \
  ../hpl/tc/hpl_tc.c

DEFINES += \
  -D__SAML22J18A__ \
  -DDONT_USE_CMSIS_INIT \
  -DF_CPU=16000000

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

