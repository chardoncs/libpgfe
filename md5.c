/*
  libpgfe
  md5.c

  Copyright (C) 2022 Charles Dong

  libpgfe is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
*/

#include "md5.h"

#include <string.h>

#include "md5-backend.h"
#include "templates.c"

__PGFE_FRONTEND_GEN2(md5);
__PGFE_FRONTEND_DEFAULT_GEN2(md5, MD5);

const pgfe_word_t H0[] = {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476};

const pgfe_encode_t PADDING[] = {
    0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

void pgfe_md5_init(struct pgfe_md5_ctx *ctx) {
    memset(ctx->count, 0, sizeof(ctx->count));
    memcpy(ctx->state, H0, sizeof(H0));
}

void pgfe_md5_update(struct pgfe_md5_ctx *ctx, const pgfe_encode_t input[], size_t length) {
    size_t i, index, part_len;

    index = (ctx->count[0] >> 3) & 0x3F;

    ctx->count[0] += (uint32_t)length << 3;
    if (ctx->count[0] < (length << 3)) {
        ctx->count[1]++;
    }

    ctx->count[1] += (uint32_t)length >> 29;
    part_len = 64 - index;

    if (length >= part_len) {
        memcpy(ctx->block + index, input, part_len);
        __pgfe_md5_transform(ctx->state, ctx->block);

        for (i = part_len; i + 63 < length; i += 64) {
            __pgfe_md5_transform(ctx->state, input + i);
        }

        index = 0;
    }
    else {
        i = 0;
    }

    memcpy(ctx->block + index, input + i, length - i);
}

void pgfe_md5_digest(struct pgfe_md5_ctx *ctx, pgfe_encode_t output[], size_t out_length) {
    pgfe_encode_t chunk[8];
    size_t i, padding_len;

    __pgfe_md5_encode(ctx->count, 8, chunk);

    i = (size_t)((ctx->count[0] >> 3) & 0x3F);
    padding_len = (i < 56) ? (56 - i) : (120 - i);

    pgfe_md5_update(ctx, PADDING, padding_len);
    pgfe_md5_update(ctx, chunk, 8);

    // Wipe sensitive data from the RAM
    memset(ctx->block, 0, sizeof(ctx->block));
    ctx->count[0] = ctx->count[1] = 0;

    __pgfe_md5_encode(ctx->state, out_length >= PGFE_MD5_DIGEST_SIZE ? PGFE_MD5_DIGEST_SIZE : out_length, output);
}