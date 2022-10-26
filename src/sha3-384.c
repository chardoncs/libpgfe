/*
  libpgfe
  sha3-384.c

  Copyright (c) 2022 Charles Dong
*/

#include "sha3.h"
#include "templates.c"

__PGFE_FRONTEND_GEN2(sha3_384);
__PGFE_FRONTEND_DEFAULT_GEN2(sha3_384, SHA3_384);

inline void pgfe_sha3_384_init(struct pgfe_sha3_384_ctx *ctx) {
    __pgfe_keccak_init(ctx, 768);
    ctx->out_length = 384;
    ctx->ap = PGFE_SHA3_APPENDIX;
    ctx->ap_len = PGFE_SHA3_APPENDIX_SIZE;
}

inline void pgfe_sha3_384_update(struct pgfe_sha3_384_ctx *ctx, const pgfe_encode_t input[], size_t length) {
    __pgfe_keccak_absorb_b1600(ctx, input, to_bit((uint64_t)length));
}

inline void pgfe_sha3_384_digest(struct pgfe_sha3_384_ctx *ctx, pgfe_encode_t output[]) {
    __pgfe_keccak_squeeze_b1600(ctx, output);
}