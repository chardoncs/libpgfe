/*
  libpgfe
  sha3.h

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

#ifndef LIBPGFE_SHA3_H
#define LIBPGFE_SHA3_H

#include <stdio.h>

#include "generic.h"
#include "keccak-backend.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_SHA3_224_DIGEST_SIZE 28
#define PGFE_SHA3_256_DIGEST_SIZE 32
#define PGFE_SHA3_384_DIGEST_SIZE 48
#define PGFE_SHA3_512_DIGEST_SIZE 64

#define PGFE_SHA3_224_BLOCK_SIZE 144
#define PGFE_SHA3_256_BLOCK_SIZE 136
#define PGFE_SHA3_384_BLOCK_SIZE 104
#define PGFE_SHA3_512_BLOCK_SIZE 72

#define pgfe_sha3_224_ctx pgfe_keccak_sponge_ctx
#define pgfe_sha3_256_ctx pgfe_keccak_sponge_ctx
#define pgfe_sha3_384_ctx pgfe_keccak_sponge_ctx
#define pgfe_sha3_512_ctx pgfe_keccak_sponge_ctx

#define PGFE_SHA3_APPENDIX 0b10
#define PGFE_SHA3_APPENDIX_SIZE 2

#define PGFE_SHAKE_APPENDIX 0b1111
#define PGFE_SHAKE_APPENDIX_SIZE 4

#define PGFE_RAWSHAKE_APPENDIX 0b11
#define PGFE_RAWSHAKE_APPENDIX_SIZE 2

// SHA3-224
void pgfe_sha3_224_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha3_224_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha3_224_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha3_224_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha3_224_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

// -- Context-based functions

void pgfe_sha3_224_init(struct pgfe_sha3_224_ctx *ctx);

void pgfe_sha3_224_update(struct pgfe_sha3_224_ctx *ctx, const pgfe_encode_t input[], size_t length);

void pgfe_sha3_224_digest(struct pgfe_sha3_224_ctx *ctx, pgfe_encode_t output[], size_t out_length);

// SHA-256
void pgfe_sha3_256_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha3_256_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha3_256_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha3_256_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha3_256_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

// -- Context-based functions

void pgfe_sha3_256_init(struct pgfe_sha3_256_ctx *ctx);

void pgfe_sha3_256_update(struct pgfe_sha3_256_ctx *ctx, const pgfe_encode_t input[], size_t length);

void pgfe_sha3_256_digest(struct pgfe_sha3_256_ctx *ctx, pgfe_encode_t output[], size_t out_length);

// SHA3-384
void pgfe_sha3_384_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha3_384_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha3_384_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha3_384_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha3_384_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

// -- Context-based functions

void pgfe_sha3_384_init(struct pgfe_sha3_384_ctx *ctx);

void pgfe_sha3_384_update(struct pgfe_sha3_384_ctx *ctx, const pgfe_encode_t input[], size_t length);

void pgfe_sha3_384_digest(struct pgfe_sha3_384_ctx *ctx, pgfe_encode_t output[], size_t out_length);

// SHA3-512
void pgfe_sha3_512_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha3_512_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha3_512_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha3_512_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha3_512_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

// -- Context-based functions

void pgfe_sha3_512_init(struct pgfe_sha3_512_ctx *ctx);

void pgfe_sha3_512_update(struct pgfe_sha3_512_ctx *ctx, const pgfe_encode_t input[], size_t length);

void pgfe_sha3_512_digest(struct pgfe_sha3_512_ctx *ctx, pgfe_encode_t output[], size_t out_length);

#ifdef __cplusplus
}
#endif

#endif