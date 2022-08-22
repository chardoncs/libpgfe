/*
  libpgfe
  sha1.h

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

#ifndef LIBPGFE_SHA1_H
#define LIBPGFE_SHA1_H

#include <stdio.h>

#include <nettle/sha1.h>

#include "generic-internal.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_SHA1_DIGEST_SIZE 20
#define PGFE_SHA1_BLOCK_SIZE 64

#define __PGFE_SHA1_BUFHASHSZ 5

struct pgfe_sha1_ctx
{
    pgfe_word_t state[__PGFE_SHA1_BUFHASHSZ];  // State
    uint32_t len_low, len_high;                // State length (low and high)
    size_t index;                              // Buffer block index
    pgfe_encode_t block[PGFE_SHA1_BLOCK_SIZE]; // Buffer block
};

void pgfe_sha1_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha1_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha1_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha1_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha1_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

void pgfe_sha1_init(struct pgfe_sha1_ctx *ctx);

void pgfe_sha1_update(struct pgfe_sha1_ctx *ctx, const pgfe_encode_t input[], size_t length);

void pgfe_sha1_digest(struct pgfe_sha1_ctx *ctx, pgfe_encode_t output[], size_t out_length);

// Internal

void __pgfe_sha1_padding(struct pgfe_sha1_ctx *ctx);

void __pgfe_sha1_process_block(struct pgfe_sha1_ctx *ctx);

#ifdef __cplusplus
}
#endif

#endif