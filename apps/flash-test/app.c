#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <peripheral_clk_config.h>
#include "watch.h"
#include "lfs.h"
#include "hpl_flash.h"

int lfs_storage_read(const struct lfs_config *cfg, lfs_block_t block, lfs_off_t off, void *buffer, lfs_size_t size);
int lfs_storage_prog(const struct lfs_config *cfg, lfs_block_t block, lfs_off_t off, const void *buffer, lfs_size_t size);
int lfs_storage_erase(const struct lfs_config *cfg, lfs_block_t block);
int lfs_storage_sync(const struct lfs_config *cfg);

int lfs_storage_read(const struct lfs_config *cfg, lfs_block_t block, lfs_off_t off, void *buffer, lfs_size_t size) {
    (void) cfg;
    return !watch_storage_read(block, off, (void *)buffer, size);
}

int lfs_storage_prog(const struct lfs_config *cfg, lfs_block_t block, lfs_off_t off, const void *buffer, lfs_size_t size) {
    (void) cfg;
    return !watch_storage_write(block, off, (void *)buffer, size);
}

int lfs_storage_erase(const struct lfs_config *cfg, lfs_block_t block) {
    (void) cfg;
    return !watch_storage_erase(block);
}

int lfs_storage_sync(const struct lfs_config *cfg) {
    (void) cfg;
    return !watch_storage_sync();
}

const struct lfs_config cfg = {
    // block device operations
    .read  = lfs_storage_read,
    .prog  = lfs_storage_prog,
    .erase = lfs_storage_erase,
    .sync  = lfs_storage_sync,

    // block device configuration
    .read_size = 16,
    .prog_size = NVMCTRL_PAGE_SIZE,
    .block_size = NVMCTRL_ROW_SIZE,
    .block_count = NVMCTRL_RWWEE_PAGES / 4,
    .cache_size = NVMCTRL_PAGE_SIZE,
    .lookahead_size = 16,
    .block_cycles = 100,
};

lfs_t lfs;
lfs_file_t file;

static int _traverse_df_cb(void *p, lfs_block_t block){
    (void) block;
	uint32_t *nb = p;
	*nb += 1;
	return 0;
}

static int get_free_space(void){
	int err;

	uint32_t free_blocks = 0;
	err = lfs_fs_traverse(&lfs, _traverse_df_cb, &free_blocks);
	if(err < 0){
		return err;
	}

	uint32_t available = cfg.block_count * cfg.block_size - free_blocks * cfg.block_size;

	return available;
}

static void cb_tick(void) {
    watch_date_time date_time = watch_rtc_get_date_time();
    if (date_time.unit.second == 0) {
        int err = lfs_mount(&lfs, &cfg);
        if (err) {
            printf("Mount failed: %d\n", err);
        }
        // read current count
        uint32_t loop_count = 0;
        lfs_file_open(&lfs, &file, "loop_count", LFS_O_RDWR | LFS_O_CREAT);
        lfs_file_read(&lfs, &file, &loop_count, sizeof(loop_count));

        // update loop count
        loop_count += 1;
        lfs_file_rewind(&lfs, &file);
        lfs_file_write(&lfs, &file, &loop_count, sizeof(loop_count));

        // remember the storage is not updated until the file is closed successfully
        lfs_file_close(&lfs, &file);

        // release any resources we were using
        lfs_unmount(&lfs);

        // print the boot count
        printf("loop_count: %ld\n", loop_count);
        printf("free space: %d\n", get_free_space());
    }
}

void app_init(void) {
}

void app_wake_from_backup(void) {
}

void app_setup(void) {
    // mount the filesystem
    int err = lfs_mount(&lfs, &cfg);

    // reformat if we can't mount the filesystem
    // this should only happen on the first boot
    if (err) {
        lfs_format(&lfs, &cfg);
        lfs_mount(&lfs, &cfg);
    }
    watch_rtc_register_tick_callback(cb_tick);
}

void app_prepare_for_standby(void) {
}

void app_wake_from_standby(void) {
}

bool app_loop(void) {
    return true;
}
