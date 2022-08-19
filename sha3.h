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

#include <nettle/sha3.h>

#include "generic.h"

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

// SHA3-224
void pgfe_sha3_224_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha3_224_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha3_224_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha3_224_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha3_224_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

// SHA-256
void pgfe_sha3_256_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha3_256_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha3_256_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha3_256_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha3_256_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

// SHA3-384
void pgfe_sha3_384_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha3_384_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha3_384_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha3_384_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha3_384_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

// SHA3-512
void pgfe_sha3_512_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha3_512_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha3_512_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha3_512_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha3_512_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

#ifdef __cplusplus
}
#endif

#endif