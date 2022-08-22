/*
  libpgfe
  md5.h

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

#ifndef LIBPGFE_MD5_H
#define LIBPGFE_MD5_H

#include <stdio.h>

#include <nettle/md5.h>

#include "generic-internal.h"
#include "generic.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_MD5_DIGEST_SIZE 16
#define PGFE_MD5_BLOCK_SIZE 64

struct pgfe_md5_ctx
{
    pgfe_word_t state[4];
    uint32_t count[2];
    pgfe_encode_t block[PGFE_MD5_BLOCK_SIZE];
};

void pgfe_md5_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_md5_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_md5_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_md5_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_md5_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

// Context-based functions

void pgfe_md5_init(struct pgfe_md5_ctx *ctx);

void pgfe_md5_update(struct pgfe_md5_ctx *ctx, const pgfe_encode_t input[], size_t length);

void pgfe_md5_digest(struct pgfe_md5_ctx *ctx, pgfe_encode_t output[], size_t out_length);

#ifdef __cplusplus
}
#endif

#endif