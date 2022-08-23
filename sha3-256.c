/*
  libpgfe
  sha3-256.c

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

#include "sha3.h"
#include "templates.c"

__PGFE_FRONTEND_GEN2(sha3_256);
__PGFE_FRONTEND_DEFAULT_GEN2(sha3_256, SHA3_256);

void pgfe_sha3_256_init(struct pgfe_sha3_256_ctx *ctx) {
    memset(ctx->S, 0, 200);
}

void pgfe_sha3_256_update(struct pgfe_sha3_256_ctx *ctx, const pgfe_encode_t input[], size_t length) {
    __pgfe_keccak_sponge_absorb_b1600(ctx, 512, input, length);
}

void pgfe_sha3_256_digest(struct pgfe_sha3_256_ctx *ctx, pgfe_encode_t output[], size_t out_length) {
    pgfe_encode_t tmp_out[PGFE_SHA3_256_DIGEST_SIZE];

    __pgfe_keccak_sponge_squeeze_b1600(ctx, 512, tmp_out, PGFE_SHA3_256_DIGEST_SIZE);

    memcpy(output, tmp_out, out_length < PGFE_SHA3_256_DIGEST_SIZE ? out_length : PGFE_SHA3_256_DIGEST_SIZE);
}