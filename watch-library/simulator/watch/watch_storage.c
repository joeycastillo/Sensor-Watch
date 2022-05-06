#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "watch_storage.h"

uint8_t storage[NVMCTRL_ROW_SIZE * NVMCTRL_RWWEE_PAGES];

bool watch_storage_read(uint32_t row, uint32_t offset, uint8_t *buffer, uint32_t size) {
    // printf("read row %ld offset %ld size %ld\n", row, offset, size);
    memcpy(buffer, storage + row * NVMCTRL_ROW_SIZE + offset, size);

    return true;
}

bool watch_storage_write(uint32_t row, uint32_t offset, const uint8_t *buffer, uint32_t size) {
    // printf("write row %ld offset %ld size %ld\n", row, offset, size);
    memcpy(storage + row * NVMCTRL_ROW_SIZE + offset, buffer, size);

    return true;
}

bool watch_storage_erase(uint32_t row) {
    // printf("erase row %ld\n", row);
    memset(storage + row * NVMCTRL_ROW_SIZE, 0xff, NVMCTRL_ROW_SIZE);

    return true;
}

bool watch_storage_sync(void) {
    // nothing to do here!
    return true;
}
