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

#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "../src/lib/chirpy_tx.h"
#include "unity.h"


void setUp(void) {
}

void tearDown(void) {
}

const char *crc_test_str0 = "";
const char *crc_test_str1 = "h";
const char *crc_test_str2 = "he";
const char *crc_test_str3 = "hen";
const char *crc_test_str4 = "henl";
const char *crc_test_str5 = "henlO";

#define CRC_VAL_COUNT 5
const uint8_t crc_vals[] = {167, 118, 95, 92, 127};

void test_crc8() {
  TEST_ASSERT_EQUAL_UINT8(0, chirpy_crc8((const uint8_t *)crc_test_str0, 0));
  TEST_ASSERT_EQUAL_UINT8(167, chirpy_crc8((const uint8_t *)crc_test_str1, strlen(crc_test_str1)));
  TEST_ASSERT_EQUAL_UINT8(118, chirpy_crc8((const uint8_t *)crc_test_str2, strlen(crc_test_str2)));
  TEST_ASSERT_EQUAL_UINT8(95, chirpy_crc8((const uint8_t *)crc_test_str3, strlen(crc_test_str3)));
  TEST_ASSERT_EQUAL_UINT8(92, chirpy_crc8((const uint8_t *)crc_test_str4, strlen(crc_test_str4)));
  TEST_ASSERT_EQUAL_UINT8(127, chirpy_crc8((const uint8_t *)crc_test_str5, strlen(crc_test_str5)));

  uint8_t crc = 0;
  for (uint16_t i = 0; i < CRC_VAL_COUNT; ++i) {
    uint8_t next_byte = crc_test_str5[i];
    crc = chirpy_update_crc8(next_byte, crc);
    TEST_ASSERT_EQUAL_UINT8(crc_vals[i], crc);
  }

  crc = chirpy_update_crc8(0, 0);
  TEST_ASSERT_EQUAL(0, crc);

  crc = chirpy_update_crc8(0x4f, 0);
  TEST_ASSERT_EQUAL(7, crc);
}

const uint16_t data_len_01 = 0;
const uint8_t data_01[] = {};
const uint16_t tones_len_01 = 6;
const uint8_t tones_01[] = {8, 0, 8, 0, 8, 8};

const uint16_t data_len_02 = 1;
const uint8_t data_02[] = {0};
const uint16_t tones_len_02 = 14;
const uint8_t tones_02[] = {8, 0, 8, 0, 0, 0, 0, 8, 0, 0, 0, 8, 8, 8};

const uint16_t data_len_03 = 1;
const uint8_t data_03[] = {0x68};
const uint16_t tones_len_03 = 14;
const uint8_t tones_03[] = {8, 0, 8, 0, 3, 2, 0, 8, 5, 1, 6, 8, 8, 8};

const uint16_t data_len_04 = 3;
const uint8_t data_04[] = {0x68, 0x65, 0x6e};
const uint16_t tones_len_04 = 19;
const uint8_t tones_04[] = {8, 0, 8, 0, 3, 2, 0, 6, 2, 5, 5, 6, 8, 2, 7, 6, 8, 8, 8};

const uint16_t data_len_05 = 4;
const uint8_t data_05[] = {0x68, 0x65, 0x6e, 0x4f};
const uint16_t tones_len_05 = 27;
const uint8_t tones_05[] = {
    8, 0, 8, 0, 3, 2, 0, 6, 2, 5, 5, 6, 8, 2, 7, 6, 8,
    2, 3, 6, 8, 0, 1, 6, 8, 8, 8};

uint8_t curr_data_pos;
uint8_t curr_data_len;
const uint8_t *curr_data;

uint8_t get_next_byte(uint8_t *next_byte) {
  if (curr_data_pos < curr_data_len) {
    *next_byte = curr_data[curr_data_pos];
    ++curr_data_pos;
    return 1;
  }
  return 0;
}

void test_encoder_one(const uint8_t *data, uint16_t data_len, const uint8_t *tones, uint16_t tones_len) {
  curr_data = data;
  curr_data_len = data_len;
  curr_data_pos = 0;
  chirpy_encoder_state_t ces;
  chirpy_init_encoder(&ces, get_next_byte);
  ces.block_size = 3;

  uint8_t got_tones[2048] = {0};
  uint16_t got_tone_pos = 0;
  while (got_tone_pos < 2048) {
    uint8_t tone = chirpy_get_next_tone(&ces);
    got_tones[got_tone_pos] = tone;
    if (tone == 255) break;
    ++got_tone_pos;
  }
  char buf1[65536];
  char bufx[256];
  memset(buf1, 0, 65536);
  for (uint16_t i = 0; i < got_tone_pos; ++i) {
    if (i == 0)
      sprintf(bufx, "%d", got_tones[i]);
    else
      sprintf(bufx, ", %d", got_tones[i]);
    strcat(buf1, bufx);
  }
  TEST_MESSAGE(buf1);
  TEST_ASSERT_EQUAL(tones_len, got_tone_pos);
  uint16_t smaller_len = tones_len < got_tone_pos ? tones_len : got_tone_pos;
  TEST_ASSERT_EQUAL_UINT8_ARRAY(tones, got_tones, smaller_len);
}

void test_encoder() {
  TEST_MESSAGE("Testing encoder with dataset 01");
  test_encoder_one(data_01, data_len_01, tones_01, tones_len_01);
  TEST_MESSAGE("Testing encoder with dataset 02");
  test_encoder_one(data_02, data_len_02, tones_02, tones_len_02);
  TEST_MESSAGE("Testing encoder with dataset 03");
  test_encoder_one(data_03, data_len_03, tones_03, tones_len_03);
  TEST_MESSAGE("Testing encoder with dataset 04");
  test_encoder_one(data_04, data_len_04, tones_04, tones_len_04);
  TEST_MESSAGE("Testing encoder with dataset 05");
  test_encoder_one(data_05, data_len_05, tones_05, tones_len_05);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_crc8);
  RUN_TEST(test_encoder);
  return UNITY_END();
}
