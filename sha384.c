/*
  libpgfe
  sha384.c

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

#include "sha2.h"

#include "sha2-backend.h"
#include "templates.c"

const pgfe_word_t __pgfe_sha384_H0[] = {
    0xC1059ED8, 0xCBBB9D5D, 0x367CD507, 0x629A292A, 0x3070DD17, 0x9159015A, 0xF70E5939, 0x152FECD8,
    0xFFC00B31, 0x67332667, 0x68581511, 0x8EB44A87, 0x64F98FA7, 0xDB0C2E0D, 0xBEFA4FA4, 0x47B5481D,
};

__PGFE_FRONTEND_GEN2(sha384)
__PGFE_FRONTEND_DEFAULT_GEN2(sha384, SHA384)

void pgfe_sha384_init(struct pgfe_sha384_ctx *ctx) {
    if (!ctx) return;

    ctx->len_low = ctx->len_high = 0;
    ctx->index = 0;

    memcpy(ctx->state, __pgfe_sha384_H0, sizeof(ctx->state));
}

inline void pgfe_sha384_update(struct pgfe_sha384_ctx *ctx, const pgfe_encode_t input[], size_t length) {
    __pgfe_sha384n512_update(ctx, input, length);
}

inline void pgfe_sha384_digest(struct pgfe_sha384_ctx *ctx, pgfe_encode_t output[], size_t out_length) {
    __pgfe_sha384n512_digest(ctx, output, out_length, PGFE_SHA384_DIGEST_SIZE);
}