/*
  libpgfe
  shake.c

  Copyright (c) 2022 Charles Dong
*/

#include "libpgfe/sha3.h"

#include <string.h>

#include "./templates.h"

// RawSHAKE128

__PGFE_FRONTEND_GEN3(rawshake128, RAWSHAKE128)

// -- Context-based functions

void pgfe_rawshake128_init(struct pgfe_shake128_ctx *ctx) {
    __pgfe_keccak_init(ctx, 256);
    ctx->ap = PGFE_RAWSHAKE_APPENDIX;
    ctx->ap_len = PGFE_RAWSHAKE_APPENDIX_SIZE;
}

void pgfe_rawshake128_update(struct pgfe_shake128_ctx *ctx, const pgfe_encode_t input[], size_t length) {
    __pgfe_keccak_absorb_b1600(ctx, input, to_bit((uint64_t)length));
}

void pgfe_rawshake128_digest(struct pgfe_shake128_ctx *ctx, pgfe_encode_t output[], size_t output_bitlength) {
    ctx->out_length = output_bitlength;
    __pgfe_keccak_squeeze_b1600(ctx, output);
}

// SHAKE128

__PGFE_FRONTEND_GEN3(shake128, SHAKE128)

// -- Context-based functions

void pgfe_shake128_init(struct pgfe_shake128_ctx *ctx) {
    __pgfe_keccak_init(ctx, 256);
    ctx->ap = PGFE_SHAKE_APPENDIX;
    ctx->ap_len = PGFE_SHAKE_APPENDIX_SIZE;
}

inline void pgfe_shake128_update(struct pgfe_shake128_ctx *ctx, const pgfe_encode_t input[], size_t length) {
    pgfe_rawshake128_update(ctx, input, length);
}

inline void pgfe_shake128_digest(struct pgfe_shake128_ctx *ctx, pgfe_encode_t output[], size_t output_bitlength) {
    pgfe_rawshake128_digest(ctx, output, output_bitlength);
}

// RawSHAKE256

__PGFE_FRONTEND_GEN3(rawshake256, RAWSHAKE256)

// -- Context-based functions

void pgfe_rawshake256_init(struct pgfe_shake256_ctx *ctx) {
    __pgfe_keccak_init(ctx, 512);
    ctx->ap = PGFE_RAWSHAKE_APPENDIX;
    ctx->ap_len = PGFE_RAWSHAKE_APPENDIX_SIZE;
}

void pgfe_rawshake256_update(struct pgfe_shake256_ctx *ctx, const pgfe_encode_t input[], size_t length) {
    __pgfe_keccak_absorb_b1600(ctx, input, to_bit((uint64_t)length));
}

void pgfe_rawshake256_digest(struct pgfe_shake256_ctx *ctx, pgfe_encode_t output[], size_t output_bitlength) {
    ctx->out_length = output_bitlength;
    __pgfe_keccak_squeeze_b1600(ctx, output);
}

// SHAKE256

__PGFE_FRONTEND_GEN3(shake256, SHAKE256)

// -- Context-based functions

void pgfe_shake256_init(struct pgfe_shake256_ctx *ctx) {
    __pgfe_keccak_init(ctx, 512);
    ctx->ap = PGFE_SHAKE_APPENDIX;
    ctx->ap_len = PGFE_SHAKE_APPENDIX_SIZE;
}

inline void pgfe_shake256_update(struct pgfe_shake256_ctx *ctx, const pgfe_encode_t input[], size_t length) {
    pgfe_rawshake256_update(ctx, input, length);
}

inline void pgfe_shake256_digest(struct pgfe_shake256_ctx *ctx, pgfe_encode_t output[], size_t output_bitlength) {
    pgfe_rawshake256_digest(ctx, output, output_bitlength);
}