#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <peripheral_clk_config.h>
#include "filesystem.h"
#include "watch.h"
#include "lfs.h"
#include "hpl_flash.h"
#if __EMSCRIPTEN__
#include <emscripten.h>
#endif

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

static lfs_t lfs;
static lfs_file_t file;
static struct lfs_info info;

#if __EMSCRIPTEN__
static uint8_t _str_len(const char *string) {
    uint8_t len;
    for (len = 0; len < UINT8_MAX; len++) {
        if (string[len] == 0) break;
    }
    return ++len;
}
#else
static int _traverse_df_cb(void *p, lfs_block_t block) {
    (void) block;
	uint32_t *nb = p;
	*nb += 1;
	return 0;
}
#endif

int32_t filesystem_get_free_space(void) {
#if __EMSCRIPTEN__
    // *** emulator version ***
    int val = EM_ASM_INT({
        if ('localStorage' in window && window['localStorage'] !== null) {
            var available = 8192;   // max capacity
            for (let i = 0; i < localStorage.length; i++) {
                var fileContent = localStorage.getItem(localStorage.key(i));
                var strData = fileContent.split(",");
                available -= strData.length;
            }
            return available < 0 ? 0 : available;
        } else {
            return -1;
        }
    });
    return (int32_t)val;
#else
    // *** hardware version ***
    int err;

	uint32_t free_blocks = 0;
	err = lfs_fs_traverse(&lfs, _traverse_df_cb, &free_blocks);
	if (err < 0) return err;

	uint32_t available = cfg.block_count * cfg.block_size - free_blocks * cfg.block_size;

	return (int32_t)available;
#endif
}

static int filesystem_ls(lfs_t *lfs, const char *path) {
    lfs_dir_t dir;
    int err = lfs_dir_open(lfs, &dir, path);
    if (err < 0) {
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
    if (err < 0) {
        return err;
    }

    return 0;
}

bool filesystem_init(void) {
#if __EMSCRIPTEN__
    // *** emulator version ***
    int err = EM_ASM_INT(
        var error = 0;
        if (!('localStorage' in window && window['localStorage'] !== null)) { 
            // local storage not supported!
            error = -10; 
        }
        return error;
    );
#else
    // *** hardware version ***
    int err = lfs_mount(&lfs, &cfg);

    // reformat if we can't mount the filesystem
    // this should only happen on the first boot
    if (err < 0) {
        printf("Ignore that error! Formatting filesystem...\n");
        err = lfs_format(&lfs, &cfg);
        if (err < 0) return false;
        err = lfs_mount(&lfs, &cfg) == LFS_ERR_OK;
        printf("Filesystem mounted with %ld bytes free.\n", filesystem_get_free_space());
    }
#endif
    return err == LFS_ERR_OK;
}

bool filesystem_file_exists(char *filename) {
#if __EMSCRIPTEN__
    // *** emulator version ***
    uint8_t len = _str_len(filename);
    int val = EM_ASM_INT({
        if ('localStorage' in window && window['localStorage'] !== null) {
            var fileStr = UTF8ArrayToString(HEAPU8.subarray($0, $0 + $1), 0, $1);
            return (localStorage.getItem(fileStr) !== null);
        } else {
            return -1;
        }
    }, filename, len);
    return val == 1;
#else
    // *** hardware version ***
    info.type = 0;
    lfs_stat(&lfs, filename, &info);
    return info.type == LFS_TYPE_REG;
#endif
}

bool filesystem_rm(char *filename) {
#if __EMSCRIPTEN__
    // *** emulator version ***
    uint8_t filename_len = _str_len(filename);
    int val = EM_ASM_INT({
        if ('localStorage' in window && window['localStorage'] !== null) {
            var fileStr = UTF8ArrayToString(HEAPU8.subarray($0, $0 + $1), 0, $1);
            var value = -2;
            if (localStorage.getItem(fileStr) !== null) {
                localStorage.removeItem(fileStr);
                value = 0;
            }
            return value;
        } else {
            return -1;
        }
    }, filename, filename_len);
    return val == 0;
#else
    // *** hardware version ***
    info.type = 0;
    lfs_stat(&lfs, filename, &info);
    if (filesystem_file_exists(filename)) {
        return lfs_remove(&lfs, filename) == LFS_ERR_OK;
    } else {
        printf("rm: %s: No such file\n", filename);
        return false;
    }
#endif
}

int32_t filesystem_get_file_size(char *filename) {
#if __EMSCRIPTEN__
    // *** emulator version ***
    uint8_t filename_len = _str_len(filename);
    int val = EM_ASM_INT({
        if ('localStorage' in window && window['localStorage'] !== null) {
            var fileStr = UTF8ArrayToString(HEAPU8.subarray($0, $0 + $1), 0, $1);
            var fileContent = localStorage.getItem(fileStr);
            if (fileContent !== null) {
                var strData = fileContent.split(",");
                return strData.length;
            } else {
                return -2;
            }
        } else {
            return -1;
        }
    }, filename, filename_len);
    if (val >= 0)
        return (int32_t)val;
    else
        return -1;
#else
    // *** hardware version ***
    if (filesystem_file_exists(filename)) {
        return info.size; // info struct was just populated by filesystem_file_exists
    }

    return -1;
#endif
}

bool filesystem_read_file(char *filename, char *buf, int32_t length) {
    memset(buf, 0, length);
#if __EMSCRIPTEN__
    // *** emulator version ***
    uint8_t filename_len = _str_len(filename);
    int val = EM_ASM_INT({
        if ('localStorage' in window && window['localStorage'] !== null) {
            var fileStr = UTF8ArrayToString(HEAPU8.subarray($0, $0 + $1), 0, $1);
            var fileContent = localStorage.getItem(fileStr);
            if (fileContent !== null) {
                var strData = fileContent.split(",");
                for (let i = 0; i < strData.length && i < $3; i++) {
                    Module.HEAPU8[i + $2] = parseInt(strData[i]);
                }
                return 1;
            } else {
                return -2;
            }
        } else {
            return -1;
        }
    }, filename, filename_len, buf, length);
    return val == 1;
#else
    // *** hardware version ***
    int32_t file_size = filesystem_get_file_size(filename);
    if (file_size > 0) {
        int err = lfs_file_open(&lfs, &file, filename, LFS_O_RDONLY);
        if (err < 0) return false;
        err = lfs_file_read(&lfs, &file, buf, min(length, file_size));
        if (err < 0) return false;
        return lfs_file_close(&lfs, &file) == LFS_ERR_OK;
    }
    return false;
#endif
}

bool filesystem_read_line(char *filename, char *buf, int32_t *offset, int32_t length) {
    memset(buf, 0, length + 1);
#if __EMSCRIPTEN__
    // *** emulator version ***
    uint8_t filename_len = _str_len(filename);
    int val = EM_ASM_INT({
        if ('localStorage' in window && window['localStorage'] !== null) {
            var fileStr = UTF8ArrayToString(HEAPU8.subarray($0, $0 + $1), 0, $1);
            var fileContent = localStorage.getItem(fileStr);
            if (fileContent !== null) {
                var strData = fileContent.split(",");
                if ($3 > strData.length) {
                    return -3;
                }
                for (let i = 0; i < strData.length - $3 && i < $4; i++) {
                    Module.HEAPU8[i + $2] = parseInt(strData[i + $3]);
                }
                return 1;
            } else {
                return -2;
            }
        } else {
            return -1;
        }
    }, filename, filename_len, buf, *offset, length);
    if (val == 1) {
        for(int i = 0; i < length; i++) {
            (*offset)++;
            if (buf[i] == '\n' || buf[i] == 0) {
                buf[i] = 0;
                break;
            }
        }
        return true;
    } else {
        return false;
    }
#else
    // *** hardware version ***
    int32_t file_size = filesystem_get_file_size(filename);
    if (file_size > 0) {
        int err = lfs_file_open(&lfs, &file, filename, LFS_O_RDONLY);
        if (err < 0) return false;
        err = lfs_file_seek(&lfs, &file, *offset, LFS_SEEK_SET);
        if (err < 0) return false;
        err = lfs_file_read(&lfs, &file, buf, min(length - 1, file_size - *offset));
        if (err < 0) return false;
        for(int i = 0; i < length; i++) {
            (*offset)++;
            if (buf[i] == '\n' || buf[i] == 0) {
                buf[i] = 0;
                break;
            }
        }
        return lfs_file_close(&lfs, &file) == LFS_ERR_OK;
    }

    return false;
#endif
}

static void filesystem_cat(char *filename) {
    info.type = 0;
    lfs_stat(&lfs, filename, &info);
    if (filesystem_file_exists(filename)) {
        if (info.size > 0) {
            char *buf = malloc(info.size + 1);
            filesystem_read_file(filename, buf, info.size);
            buf[info.size] = '\0';
            printf("%s\n", buf);
            free(buf);
        } else {
            printf("\n");
        }
    } else {
        printf("cat: %s: No such file\n", filename);
    }
}

bool filesystem_write_file(char *filename, char *text, int32_t length) {
#if __EMSCRIPTEN__
    // *** emulator version ***
    uint8_t filename_len = _str_len(filename);
    int val = EM_ASM_INT({
        if ('localStorage' in window && window['localStorage'] !== null) {
            var fileStr = UTF8ArrayToString(HEAPU8.subarray($0, $0 + $1), 0, $1);
            var fileContent = HEAPU8.subarray($2, $2 + $3);
            localStorage.setItem(fileStr, fileContent);
            return 1;
        } else {
            return -1;
        }
    }, filename, filename_len, text, length);
    return val == 1;
#else
    // *** hardware version ***
    int err = lfs_file_open(&lfs, &file, filename, LFS_O_RDWR | LFS_O_CREAT | LFS_O_TRUNC);
    if (err < 0) return false;
    err = lfs_file_write(&lfs, &file, text, length);
    if (err < 0) return false;
    return lfs_file_close(&lfs, &file) == LFS_ERR_OK;
#endif
}

bool filesystem_append_file(char *filename, char *text, int32_t length) {
    int err = lfs_file_open(&lfs, &file, filename, LFS_O_WRONLY | LFS_O_CREAT | LFS_O_APPEND);
    if (err < 0) return false;
    err = lfs_file_write(&lfs, &file, text, length);
    if (err < 0) return false;
    return lfs_file_close(&lfs, &file) == LFS_ERR_OK;
}

void filesystem_process_command(char *line) {
    printf("$ %s", line);
    char *command = strtok(line, " \n");
    
    if (strcmp(command, "ls") == 0) {
        char *directory = strtok(NULL, " \n");
        if (directory == NULL) {
            filesystem_ls(&lfs, "/");
        } else {
            printf("usage: ls\n");
        }
    } else if (strcmp(command, "cat") == 0) {
        char *filename = strtok(NULL, " \n");
        if (filename == NULL) {
            printf("usage: cat file\n");
        } else {
            filesystem_cat(filename);
        }
    } else if (strcmp(command, "df") == 0) {
        printf("free space: %ld bytes\n", filesystem_get_free_space());
    } else if (strcmp(command, "rm") == 0) {
        char *filename = strtok(NULL, " \n");
        if (filename == NULL) {
            printf("usage: rm file\n");
        } else {
            filesystem_rm(filename);
        } 
    } else if (strcmp(command, "echo") == 0) {
        char *text = malloc(248);
        memset(text, 0, 248);
        size_t pos = 0;
        char *word = strtok(NULL, " \n");
        while (strcmp(word, ">") && strcmp(word, ">>")) {
            sprintf(text + pos, "%s ", word);
            pos += strlen(word) + 1;
            word = strtok(NULL, " \n");
            if (word == NULL) break;
        }
        text[strlen(text) - 1] = 0;
        char *filename = strtok(NULL, " \n");
        if (filename == NULL) {
            printf("usage: echo text > file\n");
        } else if (strchr(filename, '/') || strchr(filename, '\\')) {
            printf("subdirectories are not supported\n");
        } else if (!strcmp(word, ">")) {
            filesystem_write_file(filename, text, strlen(text));
            filesystem_append_file(filename, "\n", 1);
        } else if (!strcmp(word, ">>")) {
            filesystem_append_file(filename, text, strlen(text));
            filesystem_append_file(filename, "\n", 1);
        }
        free(text);
    } else {
        printf("%s: command not found\n", command);
    }
}
