/*
 * MIT License
 *
 * Copyright (c) 2022 Joey Castillo
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef FILESYSTEM_H_
#define FILESYSTEM_H_
#include <stdio.h>
#include <stdbool.h>
#include "watch.h"

/** @brief Initializes and mounts the tiny 8kb filesystem, formatting it if need be.
  * @return true if the filesystem was mounted successfully.
  */
bool filesystem_init(void);

/** @brief Gets the space available on the filesystem.
  * @return the free space in bytes
  */
int32_t filesystem_get_free_space(void);

/** @brief Checks for the existence of a file on the filesystem.
  * @param filename the file you wish to check
  * @return true if the file exists; false otherwise
  */
bool filesystem_file_exists(char *filename);

/** @brief Removes a file on the filesystem.
  * @param filename the file you wish to remove
  * @return true if the file was deleted successfully; false otherwise
  */
bool filesystem_rm(char *filename);

/** @brief Gets the size of a file on the filesystem.
  * @param filename the file whose size you wish to determine
  * @return the file's size in bytes, or -1 if the file does not exist.
  */
int32_t filesystem_get_file_size(char *filename);

/** @brief Reads a file from the filesystem into a buffer
  * @param filename the file you wish to read
  * @param buf A buffer of at least length bytes; the file will be read into this buffer
  * @param length The number of bytes to read
  * @return true if the read was successful; false otherwise
  * @note This function will set buf to zero and read all bytes of the file into the buffer.
  *       If you are reading a raw value (say you wrote a uint32 to a file), you can read back
  *       the value by passing in the file's length for length. If you wish to treat the buffer
  *       as a null-terminated string, allocate a buffer one byte longer than the file's length,
  *       and the last byte will be guaranteed to be 0.
  */
bool filesystem_read_file(char *filename, char *buf, int32_t length);

/** @brief Reads a line from a file into a buffer
  * @param filename the file you wish to read
  * @param buf A buffer of at least length + 1 bytes; the file will be read into this buffer,
  *            and the last byte (buf[length]) will be set to 0 as a null terminator.
  * @param offset Pointer to an int representing the offset into the file. This will be updated
  *               to reflect the offset of the next line.
  * @param length The maximum number of bytes to read
  * @return true if the read was successful; false otherwise
  */
bool filesystem_read_line(char *filename, char *buf, int32_t *offset, int32_t length);

/** @brief Writes file to the filesystem
  * @param filename the file you wish to write
  * @param text The contents of the file
  * @param length The number of bytes to write
  * @return true if the write was successful; false otherwise
  */
bool filesystem_write_file(char *filename, char *text, int32_t length);

/** @brief Appends text to file on the filesystem
  * @param filename the file you wish to write
  * @param text The contents to write
  * @param length The number of bytes to write
  * @return true if the write was successful; false otherwise
  */
bool filesystem_append_file(char *filename, char *text, int32_t length);

int filesystem_cmd_ls(int argc, char *argv[]);
int filesystem_cmd_cat(int argc, char *argv[]);
int filesystem_cmd_df(int argc, char *argv[]);
int filesystem_cmd_rm(int argc, char *argv[]);
int filesystem_cmd_echo(int argc, char *argv[]);

#endif // FILESYSTEM_H_
