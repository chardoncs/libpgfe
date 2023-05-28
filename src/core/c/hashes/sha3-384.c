/*
  libpgfe
  sha3-384.c

  Copyright (c) 2022-2023 Charles Dong
*/

#include "libpgfe/core/hashes/sha3.h"

#include <string.h>

#include "./keccak-backend.h"
#include "./templates.h"

FRONTEND_GEN2(sha3_384);
FRONTEND_GEN2_DEFAULT(sha3_384, SHA3_384);

inline void pgfe_sha3_384_init(struct pgfe_sha3_384_ctx *ctx) {
    keccak_init(ctx, 768);
    ctx->out_length = 384;
    ctx->ap = PGFE_SHA3_APPENDIX;
    ctx->ap_len = PGFE_SHA3_APPENDIX_SIZE;
}

inline void pgfe_sha3_384_update(struct pgfe_sha3_384_ctx *ctx, const pgfe_encode_t input[], size_t length) {
    keccak_absorb_b1600(ctx, input, to_bit((uint64_t)length));
}

inline void pgfe_sha3_384_digest(struct pgfe_sha3_384_ctx *ctx, pgfe_encode_t output[]) {
    keccak_squeeze_b1600(ctx, output);
}