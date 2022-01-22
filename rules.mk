CFLAGS += $(INCLUDES) $(DEFINES)

OBJS = $(addprefix $(BUILD)/, $(notdir %/$(subst .c,.o, $(SRCS))))

SUBMODULES = tinyusb

ifndef EMSCRIPTEN
all: directory $(SUBMODULES) $(BUILD)/$(BIN).elf $(BUILD)/$(BIN).hex $(BUILD)/$(BIN).bin $(BUILD)/$(BIN).uf2 size
else
all: directory $(SUBMODULES) $(BUILD)/$(BIN).html
endif

$(BUILD)/$(BIN).html: $(OBJS)
	@echo HTML $@
	@$(CC) $(LDFLAGS) $(OBJS) $(LIBS) -o $@ \
		-s EXPORTED_FUNCTIONS=_main,_watch_invoke_interrupt_callback \
		-s EXPORTED_RUNTIME_METHODS=cwrap \
		--shell-file=$(TOP)/watch-library/simulator/shell.html

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

$(SUBMODULES):
	git submodule update --init

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
