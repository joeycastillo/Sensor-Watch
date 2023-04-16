/*
 * MIT License
 *
 * Copyright (c) 2023 Gabor L Ugray
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

#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "chirpy_tx.h"

static const uint32_t chirpy_min_freq = 2500;
static const uint32_t cirpy_freq_step = 250;

// This many bytes are followed by a CRC and block separator
// It's a multiple of 3 so no bits are wasted (a tone encodes 3 bits)
// Last block can be shorter
static const uint8_t chirpy_default_block_size = 15;

// The dedicated control tone. This is the highest tone index.
static const uint8_t chirpy_control_tone = 8;

// Pre-computed tone periods. This is allocated and populated on-demand.
static uint32_t *chirpy_tone_periods = NULL;

uint8_t chirpy_crc8(const uint8_t *addr, uint16_t len) {
    uint8_t crc = 0;
    for (uint16_t i = 0; i < len; i++)
        crc = chirpy_update_crc8(addr[i], crc);
    return crc;
}

uint8_t chirpy_update_crc8(uint8_t next_byte, uint8_t crc) {
    for (uint8_t j = 0; j < 8; j++) {
        uint8_t mix = (crc ^ next_byte) & 0x01;
        crc >>= 1;
        if (mix)
            crc ^= 0x8C;
        next_byte >>= 1;
    }
    return crc;
}

static void _chirpy_append_tone(chirpy_encoder_state_t *ces, uint8_t tone) {
    // This is BAD and should never happen. But if it does, we'd rather
    // create a corrupt transmission than corrupt memory #$^@
    if (ces->tone_count == CHIRPY_TONE_BUF_SIZE)
        return;
    ces->tone_buf[ces->tone_count] = tone;
    ++ces->tone_count;
}

void chirpy_init_encoder(chirpy_encoder_state_t *ces, chirpy_get_next_byte_t get_next_byte) {
    memset(ces, 0, sizeof(chirpy_encoder_state_t));
    ces->block_size = chirpy_default_block_size;
    ces->get_next_byte = get_next_byte;
    _chirpy_append_tone(ces, 8);
    _chirpy_append_tone(ces, 0);
    _chirpy_append_tone(ces, 8);
    _chirpy_append_tone(ces, 0);
}

static uint8_t _chirpy_retrieve_next_tone(chirpy_encoder_state_t *ces) {
    if (ces->tone_pos == ces->tone_count)
        return 255;

    uint8_t res = ces->tone_buf[ces->tone_pos];
    ++ces->tone_pos;
    if (ces->tone_pos == ces->tone_count) {
        // End of buffer: reset buffer
        ces->tone_pos = 0;
        ces->tone_count = 0;
    }
    return res;
}

static void _chirpy_encode_bits(chirpy_encoder_state_t *ces, uint8_t force_partial) {
    while (ces->bit_count > 0) {
        if (ces->bit_count < 3 && !force_partial) break;
        uint8_t tone = (uint8_t)(ces->bits >> 13);
        _chirpy_append_tone(ces, tone);
        if (ces->bit_count >= 3) {
            ces->bits <<= 3;
            ces->bit_count -= 3;
        } else {
            ces->bits = 0;
            ces->bit_count = 0;
        }
    }
}

static void _chirpy_finish_block(chirpy_encoder_state_t *ces) {
    _chirpy_append_tone(ces, chirpy_control_tone);
    ces->bits = ces->crc;
    ces->bits <<= 8;
    ces->bit_count = 8;
    _chirpy_encode_bits(ces, 1);
    ces->bit_count = 0;
    ces->crc = 0;
    ces->block_len = 0;
    _chirpy_append_tone(ces, chirpy_control_tone);
}

static void _chirpy_finish_transmission(chirpy_encoder_state_t *ces) {
    _chirpy_append_tone(ces, chirpy_control_tone);
    _chirpy_append_tone(ces, chirpy_control_tone);
}

uint8_t chirpy_get_next_tone(chirpy_encoder_state_t *ces) {
    // If there are tones left in the buffer, keep sending those
    if (ces->tone_pos < ces->tone_count)
        return _chirpy_retrieve_next_tone(ces);

    // We know data is over: that means we've wrapped up transmission
    // Just drain tone buffer, and then keep sendig EOB
    if (ces->get_next_byte == 0)
        return _chirpy_retrieve_next_tone(ces);

    // Fetch next byte
    uint8_t next_byte;
    uint8_t got_more = ces->get_next_byte(&next_byte);

    // Data over: write CRC if we sent a partial buffer; send end signal
    if (got_more == 0) {
        ces->get_next_byte = 0;
        if (ces->bit_count > 0) _chirpy_encode_bits(ces, 1);
        if (ces->block_len > 0) _chirpy_finish_block(ces);
        _chirpy_finish_transmission(ces);
        return _chirpy_retrieve_next_tone(ces);
    }

    // Got more data: add to bits; convert
    uint16_t msk = next_byte;
    msk <<= (8 - ces->bit_count);
    ces->bits |= msk;
    ces->bit_count += 8;
    _chirpy_encode_bits(ces, 0);
    ++ces->block_len;
    ces->crc = chirpy_update_crc8(next_byte, ces->crc);
    if (ces->block_len == ces->block_size)
        _chirpy_finish_block(ces);

    return _chirpy_retrieve_next_tone(ces);
}

uint16_t chirpy_get_tone_period(uint8_t tone) {
    // Create pre-computed tone periods array on first use
    if (chirpy_tone_periods == NULL) {
      chirpy_tone_periods = malloc((chirpy_control_tone + 1) * sizeof(uint32_t));
      for (uint8_t i = 0; i < chirpy_control_tone + 1; ++i) {
        uint32_t freq = chirpy_min_freq + i * cirpy_freq_step;
        uint16_t period = 1000000 / freq;
        chirpy_tone_periods[i] = period;
      }
    }
    // Return pre-computed value, but be paranoid about indexing into array
    if (tone > chirpy_control_tone)
      tone = chirpy_control_tone;
    return chirpy_tone_periods[tone];
}
