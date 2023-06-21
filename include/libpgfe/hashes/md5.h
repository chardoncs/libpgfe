/*
  libpgfe
  md5.h

  Copyright (c) 2022-2023 Charles Dong
*/

#ifndef LIBPGFE_MD5_H
#define LIBPGFE_MD5_H

#include <stdio.h>

#include "libpgfe/generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_MD5_DIGEST_SIZE 16
#define PGFE_MD5_BLOCK_SIZE 64

struct pgfe_md5_ctx
{
    pgfe_word_t state[4];
    uint64_t block_len;
    pgfe_encode_t block[PGFE_MD5_BLOCK_SIZE];
};

void pgfe_md5_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]);

void pgfe_md5_encode_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_md5_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_md5_encode_multiple(pgfe_encode_t output[], size_t input_c, ...);

// Context-based functions

void pgfe_md5_init(struct pgfe_md5_ctx *ctx);

void pgfe_md5_update(struct pgfe_md5_ctx *ctx, const pgfe_encode_t input[], size_t length);

void pgfe_md5_digest(struct pgfe_md5_ctx *ctx, pgfe_encode_t output[]);

#ifdef __cplusplus
}
#endif

#endif