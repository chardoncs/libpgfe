/*
  libpgfe
  sha512.c

  Copyright (c) 2022 Charles Dong
*/

#include "sha2.h"

#include "backend/sha2-backend.h"
#include "backend/templates.h"

const pgfe_word_t __pgfe_sha512_H0[] = {
    0xF3BCC908, 0x6A09E667, 0x84CAA73B, 0xBB67AE85, 0xFE94F82B, 0x3C6EF372, 0x5F1D36F1, 0xA54FF53A,
    0xADE682D1, 0x510E527F, 0x2B3E6C1F, 0x9B05688C, 0xFB41BD6B, 0x1F83D9AB, 0x137E2179, 0x5BE0CD19,
};

const pgfe_word_t __pgfe_sha512_224_H0[] = {
    0x19544DA2, 0x8C3D37C8, 0x89DCD4D6, 0x73E19966, 0x32FF9C82, 0x1DFAB7AE, 0x582F9FCF, 0x679DD514,
    0x7BD44DA8, 0x0F6D2B69, 0x04C48942, 0x77E36F73, 0x6A1D36C8, 0x3F9D85A8, 0x91D692A1, 0x1112E6AD,
};

const pgfe_word_t __pgfe_sha512_256_H0[] = {
    0xFC2BF72C, 0x22312194, 0xC84C64C2, 0x9F555FA3, 0x6F53B151, 0x2393B86B, 0x5940EABD, 0x96387719,
    0xA88EFFE3, 0x96283EE2, 0x53863992, 0xBE5E1E25, 0x2C85B8AA, 0x2B0199FC, 0x81C52CA2, 0x0EB72DDC,
};

void pgfe_sha512_generic_init(struct pgfe_sha512_ctx *ctx, const pgfe_word_t H0[16]) {
    if (!ctx) return;

    ctx->len_low = ctx->len_high = 0;
    ctx->index = 0;

    memcpy(ctx->state, H0, sizeof(ctx->state));
}

__PGFE_FRONTEND_GEN2(sha512)
__PGFE_FRONTEND_DEFAULT_GEN2(sha512, SHA512);

inline void pgfe_sha512_init(struct pgfe_sha512_ctx *ctx) {
    pgfe_sha512_generic_init(ctx, __pgfe_sha512_H0);
}

inline void pgfe_sha512_update(struct pgfe_sha512_ctx *ctx, const pgfe_encode_t input[], size_t length) {
    __pgfe_sha384n512_update(ctx, input, length);
}

inline void pgfe_sha512_digest(struct pgfe_sha512_ctx *ctx, pgfe_encode_t output[]) {
    __pgfe_sha384n512_digest(ctx, output, PGFE_SHA512_DIGEST_SIZE);
}

__PGFE_FRONTEND_GEN2(sha512_224);
__PGFE_FRONTEND_DEFAULT_GEN2(sha512_224, SHA512_224);

inline void pgfe_sha512_224_init(struct pgfe_sha512_ctx *ctx) {
    pgfe_sha512_generic_init(ctx, __pgfe_sha512_224_H0);
}

inline void pgfe_sha512_224_update(struct pgfe_sha512_ctx *ctx, const pgfe_encode_t input[], size_t length) {
    __pgfe_sha384n512_update(ctx, input, length);
}

inline void pgfe_sha512_224_digest(struct pgfe_sha512_ctx *ctx, pgfe_encode_t output[]) {
    __pgfe_sha384n512_digest(ctx, output, PGFE_SHA512_224_DIGEST_SIZE);
}

__PGFE_FRONTEND_GEN2(sha512_256);
__PGFE_FRONTEND_DEFAULT_GEN2(sha512_256, SHA512_256);

inline void pgfe_sha512_256_init(struct pgfe_sha512_ctx *ctx) {
    pgfe_sha512_generic_init(ctx, __pgfe_sha512_256_H0);
}

inline void pgfe_sha512_256_update(struct pgfe_sha512_ctx *ctx, const pgfe_encode_t input[], size_t length) {
    __pgfe_sha384n512_update(ctx, input, length);
}

inline void pgfe_sha512_256_digest(struct pgfe_sha512_ctx *ctx, pgfe_encode_t output[]) {
    __pgfe_sha384n512_digest(ctx, output, PGFE_SHA512_256_DIGEST_SIZE);
}
