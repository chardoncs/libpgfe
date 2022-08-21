#ifndef LIBPGFE_SHA2_INTERNAL_H
#define LIBPGFE_SHA2_INTERNAL_H

#include "sha-internal.h"
#include "sha2.h"

#ifdef __cpluslpus
extern "C" {
#endif

#define sha256_SIGMA0(word) (crshift(word, 2) ^ crshift(word, 13) ^ crshift(word, 22))
#define sha256_SIGMA1(word) (crshift(word, 6) ^ crshift(word, 11) ^ crshift(word, 25))
#define sha256_sigma0(word) (crshift(word, 7) ^ crshift(word, 18) ^ ((word) >> 3))
#define sha256_sigma1(word) (crshift(word, 17) ^ crshift(word, 19) ^ ((word) >> 10))

const pgfe_word_t SHA224_H0[] = {0xC1059ED8, 0x367CD507, 0x3070DD17, 0xF70E5939,
                                 0xFFC00B31, 0x68581511, 0x64F98FA7, 0xBEFA4FA4};

const pgfe_word_t SHA256_H0[] = {0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A,
                                 0x510E527F, 0x9B05688C, 0x1F83D9AB, 0x5BE0CD19};

void __pgfe_sha224n256_init(struct pgfe_sha256_ctx *ctx, const pgfe_word_t H0[]);

void __pgfe_sha224n256_process_block(struct pgfe_sha256_ctx *ctx);

void __pgfe_sha224n256_padding(struct pgfe_sha256_ctx *ctx, pgfe_encode_t padding_byte);

void __pgfe_sha224n256_digest(
    struct pgfe_sha256_ctx *ctx, pgfe_encode_t output[], size_t out_length, uint8_t digest_size
);

#ifdef __cplusplus
}
#endif
#endif