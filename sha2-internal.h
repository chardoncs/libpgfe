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

#ifdef __PGFE_64Bit

const pgfe_word64_t SHA384_H0[] = {0xCBBB9D5DC1059ED8ll, 0x629A292A367CD507ll, 0x9159015A3070DD17ll,
                                   0x152FECD8F70E5939ll, 0x67332667FFC00B31ll, 0x8EB44A8768581511ll,
                                   0xDB0C2E0D64F98FA7ll, 0x47B5481DBEFA4FA4ll};

#else

const pgfe_word_t SHA384_H0[] = {0xCBBB9D5D, 0xC1059ED8, 0x629A292A, 0x367CD507, 0x9159015A, 0x3070DD17,
                                 0x152FECD8, 0xF70E5939, 0x67332667, 0xFFC00B31, 0x8EB44A87, 0x68581511,
                                 0xDB0C2E0D, 0x64F98FA7, 0x47B5481D, 0xBEFA4FA4};

const pgfe_word_t SHA512_H0[] = {0x6A09E667, 0xF3BCC908, 0xBB67AE85, 0x84CAA73B, 0x3C6EF372, 0xFE94F82B,
                                 0xA54FF53A, 0x5F1D36F1, 0x510E527F, 0xADE682D1, 0x9B05688C, 0x2B3E6C1F,
                                 0x1F83D9AB, 0xFB41BD6B, 0x5BE0CD19, 0x137E2179};

// Fake 64-int left shift
#define lshift_f64(w, c, o)                                                                                            \
    ((o)[0] = ((c) > sizeof(w))    ? ((w)[1] << ((c) - sizeof(w)))                                                     \
              : ((c) == sizeof(w)) ? (w)[1]                                                                            \
              : ((c) >= 0)         ? (((w)[0] << (c)) | ((w)[1] >> (sizeof(w) - (c))))                                 \
                                   : 0,                                                                                        \
     (o)[1] = (((c) < sizeof(w)) && ((c) >= 0)) ? ((w)[1] << (c)) : 0)

// Fake 64-int right shift
#define rshift_f64(w, c, o)                                                                                            \
    ((o)[0] = (((c) < sizeof(w)) && ((c) >= 0)) ? ((w)[0] >> (c)) : 0,                                                 \
     (o)[1] = ((c) < sizeof(w))  ? ((w)[0] >> ((c) - sizeof(w)))                                                       \
              : (c) == sizeof(w) ? (w)[0]                                                                              \
              : ((c) >= 0)       ? (((w)[0] << (sizeof(w) - (c))) | ((w)[1] >> (c)))                                   \
                                 : 0)

// Fake 64-int AND
#define and_f64(w1, w2, o) ((o)[0] = (w1)[0] & (w2)[0], (o)[1] = (w1)[1] & (w2)[1])

// Fake 64-int OR
#define or_f64(w1, w2, o) ((o)[0] = (w1)[0] | (w2)[0], (o)[1] = (w1)[1] | (w2)[1])

// Fake 64-int XOR
#define xor_f64(w1, w2, o) ((o)[0] = (w1)[0] ^ (w2)[0], (o)[1] = (w1)[1] ^ (w2)[1])

// Fake 64-int NOT
#define not_f64(w, o) ((o)[0] = ~(w)[0], (o)[1] = ~(w)[1])

// Fake 64-int ADD
#define add_f64(w1, w2, o) ((o)[1] = (w1)[1], (o)[1] += (w2)[1], (o)[0] = (w1)[0] + (w2)[0] + ((o)[1] < (w1)[1]))
#endif

void __pgfe_sha224n256_init(struct pgfe_sha256_ctx *ctx, const pgfe_word_t H0[]);

void __pgfe_sha224n256_process_block(struct pgfe_sha256_ctx *ctx);

void __pgfe_sha224n256_padding(struct pgfe_sha256_ctx *ctx, pgfe_encode_t padding_byte);

void __pgfe_sha224n256_digest(
    struct pgfe_sha256_ctx *ctx, pgfe_encode_t output[], size_t out_length, uint8_t digest_size
);

void __pgfe_sha384n512_init(struct pgfe_sha512_ctx *ctx, const pgfe_word_t H0[]);

void __pgfe_sha384n512_process_block(struct pgfe_sha512_ctx *ctx);

void __pgfe_sha384n512_padding(struct pgfe_sha512_ctx *ctx, pgfe_encode_t padding_byte);

void __pgfe_sha384n512_digest(
    struct pgfe_sha512_ctx *ctx, pgfe_encode_t output[], size_t out_length, uint8_t digest_size
);

#ifdef __cplusplus
}
#endif
#endif