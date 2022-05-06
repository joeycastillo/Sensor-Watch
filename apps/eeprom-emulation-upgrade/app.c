#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <peripheral_clk_config.h>
#include "watch.h"

void app_init(void) {
}

void app_wake_from_backup(void) {
}

void app_setup(void) {
    delay_ms(5000);
    while (!(NVMCTRL->INTFLAG.reg & NVMCTRL_INTFLAG_READY));
    uint32_t user_row = (*((uint32_t *)NVMCTRL_AUX0_ADDRESS));
    uint8_t eeprom = (user_row >> NVMCTRL_FUSES_EEPROM_SIZE_Pos) & 7;
    printf("User row read successfully: 0x%lx\n", user_row);

    if (eeprom != 1) {
        user_row &= ~NVMCTRL_FUSES_EEPROM_SIZE_Msk;
        user_row |= NVMCTRL_FUSES_EEPROM_SIZE(1);
        if (NVMCTRL->STATUS.reg & NVMCTRL_STATUS_SB) {
            printf("Secured bit was set; cannot perform upgrade.\n");
            return;
        }
        printf("EEPROM configuration was %d.\nApplying change...\n", eeprom);

        uint32_t temp = NVMCTRL->CTRLB.reg;                                     // Backup settings
        NVMCTRL->CTRLB.reg = temp | NVMCTRL_CTRLB_CACHEDIS;                     // Disable Cache
        NVMCTRL->STATUS.reg |= NVMCTRL_STATUS_MASK;                             // Clear error flags
        NVMCTRL->ADDR.reg = NVMCTRL_AUX0_ADDRESS / 2;                           // Set address, command will be issued elsewhere
        NVMCTRL->CTRLA.reg = NVMCTRL_CTRLA_CMD_EAR | NVMCTRL_CTRLA_CMDEX_KEY;   // Erase the user page
        while (!(NVMCTRL->INTFLAG.reg & NVMCTRL_INTFLAG_READY));                // Wait for NVM command to complete
        NVMCTRL->STATUS.reg |= NVMCTRL_STATUS_MASK;                             // Clear error flags
        NVMCTRL->ADDR.reg = NVMCTRL_AUX0_ADDRESS / 2;                           // Set address, command will be issued elsewhere
        NVMCTRL->CTRLA.reg = NVMCTRL_CTRLA_CMD_PBC | NVMCTRL_CTRLA_CMDEX_KEY;   // Erase the page buffer before buffering new data
        while (!(NVMCTRL->INTFLAG.reg & NVMCTRL_INTFLAG_READY));                // Wait for NVM command to complete
        NVMCTRL->STATUS.reg |= NVMCTRL_STATUS_MASK;                             // Clear error flags
        NVMCTRL->ADDR.reg = NVMCTRL_AUX0_ADDRESS / 2;                           // Set address, command will be issued elsewhere
        *((uint32_t *)NVMCTRL_AUX0_ADDRESS) = user_row;                         // write the new fuse values to the memory buffer
        NVMCTRL->CTRLA.reg = NVMCTRL_CTRLA_CMD_WAP | NVMCTRL_CTRLA_CMDEX_KEY;   // Write the user page
        NVMCTRL->CTRLB.reg = temp;                                              // Restore settings

        printf("Done! Resetting...\n");
        delay_ms(1000);
        NVIC_SystemReset();
    } else {
        printf("EEPROM configuration was %d (8192 bytes). Upgrade successful!\n", eeprom);
    }
    printf("%d %d\n", eeprom, NVMCTRL->PARAM.bit.RWWEEP);
}

void app_prepare_for_standby(void) {
}

void app_wake_from_standby(void) {
}

bool app_loop(void) {
    return true;
}
