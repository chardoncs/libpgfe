/*
  libpgfe
  sha3-256.c

  Copyright (c) 2022 Charles Dong
*/

#include "libpgfe/sha3.h"

#include <string.h>

#include "./templates.h"

__PGFE_FRONTEND_GEN2(sha3_256);
__PGFE_FRONTEND_DEFAULT_GEN2(sha3_256, SHA3_256);

inline void pgfe_sha3_256_init(struct pgfe_sha3_256_ctx *ctx) {
    __pgfe_keccak_init(ctx, 512);
    ctx->out_length = 256;
    ctx->ap = PGFE_SHA3_APPENDIX;
    ctx->ap_len = PGFE_SHA3_APPENDIX_SIZE;
}

inline void pgfe_sha3_256_update(struct pgfe_sha3_256_ctx *ctx, const pgfe_encode_t input[], size_t length) {
    __pgfe_keccak_absorb_b1600(ctx, input, to_bit((uint64_t)length));
}

inline void pgfe_sha3_256_digest(struct pgfe_sha3_256_ctx *ctx, pgfe_encode_t output[]) {
    __pgfe_keccak_squeeze_b1600(ctx, output);
}