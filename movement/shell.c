/*
 * MIT License
 *
 * Copyright (c) 2023 Edward Shin
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

#include "shell.h"

#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include "watch.h"
#include "shell_cmd_list.h"

extern shell_command_t g_shell_commands[];
extern const size_t g_num_shell_commands;

#define NEWLINE  "\r\n"

#define SHELL_BUF_SZ  (256)
#define SHELL_MAX_ARGS  (16)
#define SHELL_PROMPT  "swsh> "

static char s_buf[SHELL_BUF_SZ] = {0};
static size_t s_buf_len = 0;
// Pointer to the first invalid byte after the end of input.
static char *const s_buf_end = s_buf + SHELL_BUF_SZ;

static char *prv_skip_whitespace(char *c) {
    while (c >= s_buf && c < s_buf_end) {
        if (*c == 0) {
            return NULL;
        }
        if ((!isspace((int) *c)) != 0) {
            return c;
        }
        c++;
    }
    return NULL;
}

static char *prv_skip_non_whitespace(char *c) {
    bool in_quote = false;
    char quote_char;
    while (c >= s_buf && c < s_buf_end) {
        if (*c == 0) {
            return NULL;
        }
        // Basic handling of quoted arguments.
        // Can't handle recursive quotes. :(
        if (in_quote || *c == '"' || *c == '\'') {
            if (!in_quote) {
                quote_char = *c;
                in_quote = true;
            } else if (*c == quote_char) {
                in_quote = false;
            }
        } else {
            if (isspace((int) *c) != 0) {
                return c;
            }
        }
        c++;
    }
    return NULL;
}

static int prv_handle_command() {
    char *argv[SHELL_MAX_ARGS] = {0};
    int argc = 0;

    char *c = &s_buf[0];
    s_buf[SHELL_BUF_SZ - 1] = '\0';

    while (argc < SHELL_MAX_ARGS) {
        // Skip contiguous whitespace
        c = prv_skip_whitespace(c);
        if (c == NULL) {
            // Reached end of buffer
            break;
        }

        // We hit non-whitespace, set argv and argc for this upcoming argument
        argv[argc++] = c;

        // Skip contiguous non-whitespace
        c = prv_skip_non_whitespace(c);
        if (c == NULL) {
            // Reached end of buffer
            break;
        }

        // NULL-terminate this arg string and then increment.
        *(c++) = '\0';
    }

    if (argc == 0) {
        return -1;
    }

    // Match against the command list
    for (size_t i = 0; i < g_num_shell_commands; i++) {
        if (!strcasecmp(g_shell_commands[i].name, argv[0])) {
            // If argc isn't valid for this command, display its help instead.
            if (((argc - 1) < g_shell_commands[i].min_args) ||
                ((argc - 1) > g_shell_commands[i].max_args)) {
                if (g_shell_commands[i].help != NULL) {
                    printf(NEWLINE "%s" NEWLINE, g_shell_commands[i].help);
                }
                return -2;
            }
            // Call the command's callback
            if (g_shell_commands[i].cb != NULL) {
                printf(NEWLINE);
                int ret = g_shell_commands[i].cb(argc, argv);
                if (ret == -2) {
                    printf(NEWLINE "%s" NEWLINE, g_shell_commands[i].help);
                }
                return ret;
            }
        }
    }

    return -1;
}

void shell_task(void) {
#if __EMSCRIPTEN__
    // This is a terrible hack; ideally this should be handled deeper in the watch library.
    // Alas, emscripten treats read() as something that should pop up an input box, so I
    // wasn't able to implement this over there. I sense that this relates to read() being
    // the wrong way to read data from USB (like we should be using fgets or something), but
    // until I untangle that, this will have to do.
    char *received_data = (char*)EM_ASM_INT({
        var len = lengthBytesUTF8(tx) + 1;
        var s = _malloc(len);
        stringToUTF8(tx, s, len);
        return s;
    });
    s_buf_len = min((SHELL_BUF_SZ - 2), strlen(received_data));
    memcpy(s_buf, received_data, s_buf_len);
    free(received_data);
    s_buf[s_buf_len++] = '\n';
    s_buf[s_buf_len++] = '\0';
    prv_handle_command();
    EM_ASM({
        tx = "";
    });
#else
    // Read one character at a time until we run out.
    while (true) {
        if (s_buf_len >= (SHELL_BUF_SZ - 1)) {
            printf(NEWLINE "Command too long, clearing.");
            printf(NEWLINE SHELL_PROMPT);
            s_buf_len = 0;
            break;
        }

        int c = getchar();

        if (c < 0) {
            // Nothing left to read, we're done.
            break;
        }

        if (c == '\b') {
            // Handle backspace character.
            // We need to emit a backspace, overwrite the character on the
            // screen with a space, and then backspace again to move the cursor.
            if (s_buf_len > 0) {
                printf("\b \b");
                s_buf_len--;
            }
            continue;
        } else if (c != '\n' && c != '\r') {
            // Print regular characters to the screen.
            putchar(c);
        }

        s_buf[s_buf_len] = c;

        if (c == '\n' || c == '\r') {
            // Newline! Handle the command.
            s_buf[s_buf_len+1] = '\0';
            (void) prv_handle_command();
            s_buf_len = 0;
            printf(NEWLINE SHELL_PROMPT);
            break;
        } else {
            s_buf_len++;
        }
    }
#endif
}
