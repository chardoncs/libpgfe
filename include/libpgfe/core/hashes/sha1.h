/*
  libpgfe
  sha1.h

  Copyright (c) 2022-2023 Charles Dong
*/

#ifndef LIBPGFE_CORE_SHA1_H
#define LIBPGFE_CORE_SHA1_H

#include <stdio.h>

#include "libpgfe/core/generic.h"

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

void pgfe_sha1_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]);

void pgfe_sha1_encode_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha1_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha1_encode_multiple(pgfe_encode_t output[], size_t input_c, ...);

void pgfe_sha1_init(struct pgfe_sha1_ctx *ctx);

void pgfe_sha1_update(struct pgfe_sha1_ctx *ctx, const pgfe_encode_t input[], size_t length);

void pgfe_sha1_digest(struct pgfe_sha1_ctx *ctx, pgfe_encode_t output[]);

#ifdef __cplusplus
}
#endif

#endif