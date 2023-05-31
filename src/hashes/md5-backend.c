/*
  libpgfe
  md5-backend.c

  Copyright (c) 2022-2023 Charles Dong
*/

#include "./md5-backend.h"

#include <string.h>

#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

#define _ROUND_TRAN(a, apl, b, x, s, ac) ((a) += (apl) + (x) + (uint32_t)(ac), (a) = clshift((a), (s)), (a) += (b))

#define _O(i, offset, limit) (((i) + (offset)) % (limit))

static const uint8_t S[4][4] = {
    {7, 12, 17, 22},
    {5, 9,  14, 20},
    {4, 11, 16, 23},
    {6, 10, 15, 21},
};

static const uint8_t idx[4][16] = {
    {0, 1, 2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15},
    {1, 6, 11, 0,  5,  10, 15, 4,  9,  14, 3,  8,  13, 2,  7,  12},
    {5, 8, 11, 14, 1,  4,  7,  10, 13, 0,  3,  6,  9,  12, 15, 2 },
    {0, 7, 14, 5,  12, 3,  10, 1,  8,  15, 6,  13, 4,  11, 2,  9 },
};

static const uint32_t ac[4][16] = {
    {0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501, 0x698098d8,
     0x8b44f7af, 0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821},
    {0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x2441453,  0xd8a1e681, 0xe7d3fbc8, 0x21e1cde6,
     0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a},
    {0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70, 0x289b7ec6,
     0xeaa127fa, 0xd4ef3085, 0x4881d05,  0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665},
    {0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1, 0x6fa87e4f,
     0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391},
};

#define _F(r, a, b, c, d, x, s, ac)                                                                                    \
    switch (r) {                                                                                                       \
    case 0:                                                                                                            \
        _ROUND_TRAN((a), F((b), (c), (d)), (b), (x), (s), (ac));                                                       \
        break;                                                                                                         \
    case 1:                                                                                                            \
        _ROUND_TRAN((a), G((b), (c), (d)), (b), (x), (s), (ac));                                                       \
        break;                                                                                                         \
    case 2:                                                                                                            \
        _ROUND_TRAN((a), H((b), (c), (d)), (b), (x), (s), (ac));                                                       \
        break;                                                                                                         \
    case 3:                                                                                                            \
        _ROUND_TRAN((a), I((b), (c), (d)), (b), (x), (s), (ac));                                                       \
        break;                                                                                                         \
    default:                                                                                                           \
        break;                                                                                                         \
    }

void md5_decode(const pgfe_encode_t input[], size_t length, pgfe_word_t output[]) {
    size_t i, ix4;

    for (i = ix4 = 0; ix4 < length; i++, ix4 += 4) {
        output[i] = (pgfe_word_t)input[ix4];
        output[i] |= ((pgfe_word_t)input[ix4 + 1] << 8);
        output[i] |= ((pgfe_word_t)input[ix4 + 2] << 16);
        output[i] |= ((pgfe_word_t)input[ix4 + 3] << 24);
    }
}

void md5_encode(pgfe_word_t input[], size_t length, pgfe_encode_t output[]) {
    size_t i, ix4;

    for (i = ix4 = 0; ix4 < length; i++, ix4 += 4) {
        output[ix4] = (pgfe_encode_t)(input[i] & 0xFF);
        output[ix4 + 1] = (pgfe_encode_t)((input[i] >> 8) & 0xFF);
        output[ix4 + 2] = (pgfe_encode_t)((input[i] >> 16) & 0xFF);
        output[ix4 + 3] = (pgfe_encode_t)((input[i] >> 24) & 0xFF);
    }
}

void md5_transform(pgfe_word_t state[4], const pgfe_encode_t block[64]) {
    pgfe_word_t x[16], buf[4];
    uint16_t r, i;

    // Copy to the buffer reversely
    buf[3] = state[0]; // a
    buf[2] = state[1]; // b
    buf[1] = state[2]; // c
    buf[0] = state[3]; // d

    md5_decode(block, 64, x);

    // Round 1 - 4
    for (r = 0; r < 4; r++) {
        for (i = 0; i < 16; i++) {
            _F(r, buf[_O(i, 3, 4)], buf[_O(i, 2, 4)], buf[_O(i, 1, 4)], buf[_O(i, 0, 4)], x[idx[r][i]], S[r][i % 4],
               ac[r][i]);
        }
    }

    // Add back
    state[0] += buf[3]; // a
    state[1] += buf[2]; // b
    state[2] += buf[1]; // c
    state[3] += buf[0]; // d

    // Wipe sensitive data from the RAM
    memset(x, 0, sizeof(x));
    memset(buf, 0, 16);
}