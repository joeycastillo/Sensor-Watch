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

static int _traverse_df_cb(void *p, lfs_block_t block) {
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

static int lfs_ls(lfs_t *lfs, const char *path) {
    lfs_dir_t dir;
    int err = lfs_dir_open(lfs, &dir, path);
    if (err) {
        return err;
    }

    struct lfs_info info;
    while (true) {
        int res = lfs_dir_read(lfs, &dir, &info);
        if (res < 0) {
            return res;
        }

        if (res == 0) {
            break;
        }

        switch (info.type) {
            case LFS_TYPE_REG: printf("file "); break;
            case LFS_TYPE_DIR: printf("dir  "); break;
            default:           printf("?    "); break;
        }

        printf("%4ld bytes ", info.size);

        printf("%s\n", info.name);
    }

    err = lfs_dir_close(lfs, &dir);
    if (err) {
        return err;
    }

    return 0;
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
}

void app_prepare_for_standby(void) {
}

void app_wake_from_standby(void) {
}

bool app_loop(void) {
    char line[256] = {0};
    char *buf;
    struct lfs_info info;

    read(0, line, 256);
    if (strlen(line)) {
        printf("$ %s", line);
        char *command = strtok(line, " \n");
        
        if (strcmp(command, "ls") == 0) {
            char *directory = strtok(NULL, " \n");
            if (directory == NULL) {
                lfs_ls(&lfs, "/");
            } else {
                printf("usage: ls\n");
            }
        } else if (strcmp(command, "cat") == 0) {
            char *filename = strtok(NULL, " \n");
            if (filename == NULL) {
                printf("usage: cat file\n");
            } else {
                info.type = 0;
                lfs_stat(&lfs, filename, &info);
                if (info.type == LFS_TYPE_REG) {
                    if (info.size > 0) {
                        buf = malloc(info.size);
                        lfs_file_open(&lfs, &file, filename, LFS_O_RDONLY);
                        lfs_file_read(&lfs, &file, buf, info.size);
                        printf("%s\n", buf);
                        free(buf);
                        lfs_file_close(&lfs, &file);
                    } else {
                        printf("\n");
                    }
                } else {
                    printf("cat: %s: No such file\n", filename);
                }
            }
        } else if (strcmp(command, "df") == 0) {
            printf("free space: %d bytes\n", get_free_space());
        } else if (strcmp(command, "rm") == 0) {
            char *filename = strtok(NULL, " \n");
            if (filename == NULL) {
                printf("usage: rm file\n");
            } else {
                info.type = 0;
                lfs_stat(&lfs, filename, &info);
                if (info.type == LFS_TYPE_REG) {
                    lfs_remove(&lfs, filename);
                } else {
                    printf("rm: %s: No such file\n", filename);
                }
            } 
        } else if (strcmp(command, "echo") == 0) {
            buf = malloc(64);
            memset(buf, 0, 64);
            size_t pos = 0;
            char *text = strtok(NULL, " \n");
            while (strcmp(text, ">")) {
                sprintf(buf + pos, "%s ", text);
                pos += strlen(text) + 1;
                text = strtok(NULL, " \n");
                if (text == NULL) break;
            }
            buf[strlen(buf) - 1] = 0;
            char *filename = strtok(NULL, " \n");
            if (filename == NULL) {
                printf("usage: echo text > file\n");
            } else if (strchr(filename, '/') || strchr(filename, '\\')) {
                printf("subdirectories are not supported\n");
            } else {
                lfs_file_open(&lfs, &file, filename, LFS_O_RDWR | LFS_O_CREAT | LFS_O_TRUNC);
                lfs_file_write(&lfs, &file, buf, strlen(buf));
                lfs_file_close(&lfs, &file);
            }
            free(buf);
        } else {
            printf("%s: command not found\n", command);
        }
    }
    return false;
}
