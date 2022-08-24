/*
  libpgfe
  sha3-224.c

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

__PGFE_FRONTEND_GEN2(sha3_224);
__PGFE_FRONTEND_DEFAULT_GEN2(sha3_224, SHA3_224);

inline void pgfe_sha3_224_init(struct pgfe_sha3_224_ctx *ctx) {
    __pgfe_keccak_init(ctx, 448);
    ctx->out_length = 224;
}

inline void pgfe_sha3_224_update(struct pgfe_sha3_224_ctx *ctx, const pgfe_encode_t input[], size_t length) {
    __pgfe_keccak_absorb_b1600(ctx, input, length);
}

inline void pgfe_sha3_224_digest(struct pgfe_sha3_224_ctx *ctx, pgfe_encode_t output[], size_t out_length) {
    __pgfe_keccak_squeeze_b1600(
        ctx, output, out_length < PGFE_SHA3_224_DIGEST_SIZE ? out_length : PGFE_SHA3_224_DIGEST_SIZE
    );
}