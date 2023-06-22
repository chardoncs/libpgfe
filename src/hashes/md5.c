/*
  libpgfe
  md5.c

  Copyright (c) 2022-2023 Charles Dong
*/

#include "libpgfe/hashes/md5.h"

#include <string.h>

#include "./md5-backend.h"
#include "./templates.h"

FRONTEND_GEN2(md5);
FRONTEND_GEN2_DEFAULT(md5, MD5);

static const pgfe_word_t H0[] = {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476};

static const pgfe_encode_t PADDING[] = {
    0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

void pgfe_md5_init(struct pgfe_md5_ctx *ctx) {
    if (!ctx) return;

    ctx->block_len = 0;
    memcpy(ctx->state, H0, sizeof(H0));
}

void pgfe_md5_update(struct pgfe_md5_ctx *ctx, const pgfe_encode_t input[], size_t length) {
    if (!ctx || !input) return;

    size_t read_len, written_len, remainder, offset;
    const pgfe_encode_t *p;

    for (p = input; (read_len = p - input) < length; p += written_len) {
        offset = (uint8_t)(ctx->block_len & 0x3F);
        written_len = PGFE_MD5_BLOCK_SIZE - offset;

        if (length - read_len < written_len) {
            break;
        }

        memcpy(ctx->block + offset, p, written_len);
        ctx->block_len += written_len;

        md5_transform(ctx->state, ctx->block);
    }

    // Finish up the last chunk
    remainder = written_len;
    if ((written_len = length - read_len)) {
        memcpy(ctx->block + offset, p, written_len);
        ctx->block_len += written_len;

        remainder -= written_len;
    }

    if (!remainder) {
        md5_transform(ctx->state, ctx->block);
    }
}

void pgfe_md5_digest(struct pgfe_md5_ctx *ctx, pgfe_encode_t output[]) {
    if (!ctx || !output) return;

    pgfe_encode_t chunk[8];
    size_t i;
    uint32_t count[2];

    count[0] = (uint32_t)(ctx->block_len << 3);
    count[1] = (uint32_t)(ctx->block_len >> 29);

    md5_encode(count, 8, chunk);

    i = (size_t)(ctx->block_len & 0x3F);

    pgfe_md5_update(ctx, PADDING, (i < 56) ? (56 - i) : (120 - i));
    pgfe_md5_update(ctx, chunk, 8);

    md5_encode(ctx->state, PGFE_MD5_DIGEST_SIZE, output);
}