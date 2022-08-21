/*
  libpgfe
  sha2.h

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

#ifndef LIBPGFE_SHA2_H
#define LIBPGFE_SHA2_H

#include <stdio.h>

#include <nettle/sha2.h>

#include "generic-internal.h"

#ifdef __cplusplus
extern "C" {
#endif

// Digest size macros
#define PGFE_SHA224_DIGEST_SIZE 28
#define PGFE_SHA256_DIGEST_SIZE 32
#define PGFE_SHA384_DIGEST_SIZE 48
#define PGFE_SHA512_DIGEST_SIZE 64
#define PGFE_SHA512_224_DIGEST_SIZE PGFE_SHA224_DIGEST_SIZE
#define PGFE_SHA512_256_DIGEST_SIZE PGFE_SHA256_DIGEST_SIZE

// Block size macros
#define PGFE_SHA256_BLOCK_SIZE 64
#define PGFE_SHA224_BLOCK_SIZE PGFE_SHA256_BLOCK_SIZE
#define PGFE_SHA512_BLOCK_SIZE 128
#define PGFE_SHA384_BLOCK_SIZE PGFE_SHA512_BLOCK_SIZE
#define PGFE_SHA512_224_BLOCK_SIZE PGFE_SHA512_BLOCK_SIZE
#define PGFE_SHA512_256_BLOCK_SIZE PGFE_SHA512_BLOCK_SIZE

#define __PGFE_SHA256_BUFHASHSZ 8
#define __PGFE_SHA512_BUFHASHSZ 16
#define __PGFE_SHA512_BUFHASHSZ_64 8

#define pgfe_sha224_ctx pgfe_sha256_ctx
#define pgfe_sha384_ctx pgfe_sha512_ctx

struct pgfe_sha256_ctx
{
    pgfe_word_t state[__PGFE_SHA256_BUFHASHSZ];
    uint32_t len_high, len_low;
    size_t index;
    pgfe_encode_t block[PGFE_SHA256_BLOCK_SIZE];
};

struct pgfe_sha512_ctx
{
#ifdef __PGFE_64Bit
    pgfe_word64_t state[__PGFE_SHA512_BUFHASHSZ_64];
    uint64_t len_high, len_low;
#else
    pgfe_word_t state[__PGFE_SHA512_BUFHASHSZ];
    uint32_t lengths[4];
#endif
    size_t index;
    pgfe_encode_t block[PGFE_SHA512_BLOCK_SIZE];
};

// SHA224
void pgfe_sha224_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha224_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha224_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha224_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha224_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

void pgfe_sha224_init(struct pgfe_sha224_ctx *ctx);

void pgfe_sha224_update(struct pgfe_sha224_ctx *ctx, const pgfe_encode_t input[], size_t length);

void pgfe_sha224_digest(struct pgfe_sha224_ctx *ctx, pgfe_encode_t output[], size_t out_length);

// SHA256
void pgfe_sha256_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha256_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha256_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha256_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha256_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

void pgfe_sha256_init(struct pgfe_sha256_ctx *ctx);

void pgfe_sha256_update(struct pgfe_sha256_ctx *ctx, const pgfe_encode_t input[], size_t length);

void pgfe_sha256_digest(struct pgfe_sha256_ctx *ctx, pgfe_encode_t output[], size_t out_length);

// SHA384
void pgfe_sha384_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha384_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha384_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha384_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha384_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

void pgfe_sha384_init(struct pgfe_sha384_ctx *ctx);

void pgfe_sha384_update(struct pgfe_sha384_ctx *ctx, const pgfe_encode_t input[], size_t length);

void pgfe_sha384_digest(struct pgfe_sha384_ctx *ctx, pgfe_encode_t output[], size_t out_length);

// SHA512
void pgfe_sha512_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha512_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha512_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha512_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha512_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

void pgfe_sha512_init(struct pgfe_sha512_ctx *ctx);

void pgfe_sha512_update(struct pgfe_sha512_ctx *ctx, const pgfe_encode_t input[], size_t length);

void pgfe_sha512_digest(struct pgfe_sha512_ctx *ctx, pgfe_encode_t output[], size_t out_length);

// SHA512-224

void pgfe_sha512_224_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha512_224_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha512_224_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha512_224_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha512_224_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

void pgfe_sha512_224_init(struct pgfe_sha512_ctx *ctx);

void pgfe_sha512_224_update(struct pgfe_sha512_ctx *ctx, const pgfe_encode_t input[], size_t length);

void pgfe_sha512_224_digest(struct pgfe_sha512_ctx *ctx, pgfe_encode_t output[], size_t out_length);

// SHA512-256

void pgfe_sha512_256_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha512_256_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha512_256_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha512_256_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha512_256_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

void pgfe_sha512_256_init(struct pgfe_sha512_ctx *ctx);

void pgfe_sha512_256_update(struct pgfe_sha512_ctx *ctx, const pgfe_encode_t input[], size_t length);

void pgfe_sha512_256_digest(struct pgfe_sha512_ctx *ctx, pgfe_encode_t output[], size_t out_length);

#ifdef __cplusplus
}
#endif

#endif