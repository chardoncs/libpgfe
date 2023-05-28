/*
  libpgfe
  sha2-backend.h

  Generic implementation of SHA2 family

  Copyright (c) 2022-2023 Charles Dong
*/

#ifndef LIBPGFE_SHA2_INTERNAL_H
#define LIBPGFE_SHA2_INTERNAL_H

#include "./sha-internal.h"

#include "libpgfe/core/hashes/sha2.h"

#ifdef __cpluslpus
extern "C" {
#endif

#define sha256_SIGMA0(word) (crshift((word), 2) ^ crshift((word), 13) ^ crshift((word), 22))
#define sha256_SIGMA1(word) (crshift((word), 6) ^ crshift((word), 11) ^ crshift((word), 25))
#define sha256_sigma0(word) (crshift((word), 7) ^ crshift((word), 18) ^ ((word) >> 3))
#define sha256_sigma1(word) (crshift((word), 17) ^ crshift((word), 19) ^ ((word) >> 10))

#define sha512_SIGMA0(word) (crshift((word), 28) ^ crshift((word), 34) ^ crshift((word), 39))
#define sha512_SIGMA1(word) (crshift((word), 14) ^ crshift((word), 18) ^ crshift((word), 41))
#define sha512_sigma0(word) (crshift((word), 1) ^ crshift((word), 8) ^ ((word) >> 7))
#define sha512_sigma1(word) (crshift((word), 19) ^ crshift((word), 61) ^ ((word) >> 6))

void sha224n256_init(struct pgfe_sha256_ctx *ctx, const pgfe_word_t H0[]);

void sha256_process_block(struct pgfe_sha256_ctx *ctx);

#define __pgfe_sha224_process_block __pgfe_sha256_process_block

void sha224n256_padding(struct pgfe_sha256_ctx *ctx);

void sha224n256_digest(struct pgfe_sha256_ctx *ctx, pgfe_encode_t output[], uint8_t digest_size);

void sha384n512_init(struct pgfe_sha512_ctx *ctx, const pgfe_word_t H0[]);

void sha384n512_update(struct pgfe_sha512_ctx *ctx, const pgfe_encode_t input[], size_t length);

void sha384n512_process_block(struct pgfe_sha512_ctx *ctx);

void sha384n512_padding(struct pgfe_sha512_ctx *ctx, pgfe_encode_t padding_byte);

void sha384n512_digest(struct pgfe_sha512_ctx *ctx, pgfe_encode_t output[], uint8_t digest_size);

#ifdef __cplusplus
}
#endif
#endif