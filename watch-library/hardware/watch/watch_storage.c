#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "watch_storage.h"

#define RWWEE_ADDR_START NVMCTRL_RWW_EEPROM_ADDR
#define RWWEE_ADDR_END (NVMCTRL_RWW_EEPROM_ADDR + NVMCTRL_PAGE_SIZE * NVMCTRL_RWWEE_PAGES)
#define NVM_MEMORY ((volatile uint16_t *)FLASH_ADDR)

static bool _is_valid_address(uint32_t addr, uint32_t size) {
    if ((addr < NVMCTRL_RWW_EEPROM_ADDR) || (addr > (NVMCTRL_RWW_EEPROM_ADDR + NVMCTRL_PAGE_SIZE * NVMCTRL_RWWEE_PAGES))) {
        return false;
    }
    if ((addr + size > (NVMCTRL_RWW_EEPROM_ADDR + NVMCTRL_PAGE_SIZE * NVMCTRL_RWWEE_PAGES))) {
        return false;
    }

    return true;
}

bool watch_storage_read(uint32_t row, uint32_t offset, uint8_t *buffer, uint32_t size) {
    uint32_t address = RWWEE_ADDR_START + row * NVMCTRL_ROW_SIZE + offset;
    if (!_is_valid_address(address, size)) return false;

    uint32_t nvm_address = address / 2;
    uint32_t i;
    uint16_t data;

    watch_storage_sync();

    if (address % 2) {
        data      = NVM_MEMORY[nvm_address++];
        buffer[0] = data >> 8;
        i         = 1;
    } else {
        i = 0;
    }

    while (i < size) {
        data = NVM_MEMORY[nvm_address++];
        buffer[i] = (data & 0xFF);
        if (i < (size - 1)) {
            buffer[i + 1] = (data >> 8);
        }
        i += 2;
    }
    return true;
}

bool watch_storage_write(uint32_t row, uint32_t offset, const uint8_t *buffer, uint32_t size) {
    uint32_t address = RWWEE_ADDR_START + row * NVMCTRL_ROW_SIZE + offset;
    if (!_is_valid_address(address, size)) return false;

    watch_storage_sync();

    uint32_t nvm_address = address / 2;
    uint16_t i, data;

    hri_nvmctrl_write_CTRLA_reg(NVMCTRL, NVMCTRL_CTRLA_CMD_PBC | NVMCTRL_CTRLA_CMDEX_KEY);
    watch_storage_sync();

    for (i = 0; i < size; i += 2) {
        data = buffer[i];
        if (i < NVMCTRL_PAGE_SIZE - 1) {
            data |= (buffer[i + 1] << 8);
        }
        NVM_MEMORY[nvm_address++] = data;
    }
    hri_nvmctrl_write_ADDR_reg(NVMCTRL, address / 2);
    hri_nvmctrl_write_CTRLA_reg(NVMCTRL, NVMCTRL_CTRLA_CMD_RWWEEWP | NVMCTRL_CTRLA_CMDEX_KEY);

    return true;
}

bool watch_storage_erase(uint32_t row) {
    uint32_t address = RWWEE_ADDR_START + row * NVMCTRL_ROW_SIZE;
    if (!_is_valid_address(address, NVMCTRL_ROW_SIZE)) return false;

    watch_storage_sync();
    hri_nvmctrl_write_ADDR_reg(NVMCTRL, address / 2);
    hri_nvmctrl_write_CTRLA_reg(NVMCTRL, NVMCTRL_CTRLA_CMD_RWWEEER | NVMCTRL_CTRLA_CMDEX_KEY);

    return true;
}

bool watch_storage_sync(void) {
    while (!hri_nvmctrl_get_interrupt_READY_bit(NVMCTRL)) {
        // wait for flash to become ready
    }

    hri_nvmctrl_clear_STATUS_reg(NVMCTRL, NVMCTRL_STATUS_MASK);

    return true;
}
