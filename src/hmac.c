/*
  libpgfe
  hmac.c

  Copyright (c) 2022 Charles Dong
*/

#include "hmac.h"

#include "generic-internal.h"

#define __pgfe_hmac_tmpl(name, upper)                                                                                  \
    void pgfe_hmac_##name##_init(struct pgfe_hmac_##name##_ctx *ctx) {                                                 \
        pgfe_##name##_init(&ctx->hash_ctx);                                                                            \
        memset(ctx->k_i_pad, I_UNIT, PGFE_##upper##_BLOCK_SIZE);                                                       \
        memset(ctx->k_o_pad, O_UNIT, PGFE_##upper##_BLOCK_SIZE);                                                       \
        pgfe_##name##_update(&ctx->hash_ctx, ctx->k_i_pad, PGFE_##upper##_BLOCK_SIZE);                                 \
    }                                                                                                                  \
    void pgfe_hmac_##name##_set_key(                                                                                   \
        struct pgfe_hmac_##name##_ctx *ctx, const pgfe_encode_t key[], size_t key_length                               \
    ) {                                                                                                                \
        __pgfe_arrcpy(ctx->k_i_pad, PGFE_##upper##_BLOCK_SIZE, key, key_length);                                       \
        __pgfe_arrcpy(ctx->k_o_pad, PGFE_##upper##_BLOCK_SIZE, key, key_length);                                       \
        for (size_t i = 0; i < PGFE_##upper##_BLOCK_SIZE; i++) {                                                       \
            ctx->k_i_pad[i] ^= I_UNIT;                                                                                 \
            ctx->k_o_pad[i] ^= O_UNIT;                                                                                 \
        }                                                                                                              \
        pgfe_##name##_init(&ctx->hash_ctx);                                                                            \
        pgfe_##name##_update(&ctx->hash_ctx, ctx->k_i_pad, PGFE_##upper##_BLOCK_SIZE);                                 \
    }                                                                                                                  \
    inline void pgfe_hmac_##name##_update(                                                                             \
        struct pgfe_hmac_##name##_ctx *ctx, const pgfe_encode_t data[], size_t length                                  \
    ) {                                                                                                                \
        pgfe_##name##_update(&ctx->hash_ctx, data, length);                                                            \
    }                                                                                                                  \
    void pgfe_hmac_##name##_digest(struct pgfe_hmac_##name##_ctx *ctx, pgfe_encode_t output[]) {                       \
        pgfe_encode_t mid_hash[PGFE_##upper##_DIGEST_SIZE + 1];                                                        \
        pgfe_##name##_digest(&ctx->hash_ctx, mid_hash);                                                                \
        pgfe_##name##_encode_multiple(                                                                                 \
            output, 2, ctx->k_o_pad, PGFE_##upper##_BLOCK_SIZE, mid_hash, PGFE_##upper##_DIGEST_SIZE                   \
        );                                                                                                             \
                                                                                                                       \
        /* Wipe buffers' data */                                                                                       \
        memset(mid_hash, 0, PGFE_##upper##_DIGEST_SIZE);                                                               \
        memset(ctx->k_i_pad, 0, PGFE_##upper##_BLOCK_SIZE);                                                            \
        memset(ctx->k_o_pad, 0, PGFE_##upper##_BLOCK_SIZE);                                                            \
    }                                                                                                                  \
    inline void pgfe_hmac_##name(                                                                                      \
        const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length,                       \
        pgfe_encode_t output[]                                                                                         \
    ) {                                                                                                                \
        struct pgfe_hmac_##name##_ctx ctx;                                                                             \
        pgfe_hmac_##name##_init(&ctx);                                                                                 \
        pgfe_hmac_##name##_set_key(&ctx, key, key_length);                                                             \
        pgfe_hmac_##name##_update(&ctx, data, length);                                                                 \
        pgfe_hmac_##name##_digest(&ctx, output);                                                                       \
    }

__pgfe_hmac_tmpl(md5, MD5);
__pgfe_hmac_tmpl(sha1, SHA1);
__pgfe_hmac_tmpl(sha224, SHA224);
__pgfe_hmac_tmpl(sha256, SHA256);
__pgfe_hmac_tmpl(sha384, SHA384);
__pgfe_hmac_tmpl(sha512, SHA512);
__pgfe_hmac_tmpl(sha512_224, SHA512_224);
__pgfe_hmac_tmpl(sha512_256, SHA512_256);
__pgfe_hmac_tmpl(sha3_224, SHA3_224);
__pgfe_hmac_tmpl(sha3_256, SHA3_256);
__pgfe_hmac_tmpl(sha3_384, SHA3_384);
__pgfe_hmac_tmpl(sha3_512, SHA3_512);

#define __PGFE_ALG_SELECT_CASE_C(upper, lower)                                                                         \
    case upper:                                                                                                        \
        pgfe_hmac_##lower(key, key_length, data, length, output);                                                      \
        break

void pgfe_hmac(
    enum pgfe_algorithm_choice alg, const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[],
    size_t length, pgfe_encode_t output[]
) {
    __PGFE_BATCH_CASES_SP_C(alg, ALG_SELECT)
}