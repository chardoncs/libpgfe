#ifndef LIBPGFE_MD5_H
#define LIBPGFE_MD5_H

#include <stdio.h>

#include <nettle/md5.h>

#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_MD5_DIGEST_SIZE 16
#define PGFE_MD5_BLOCK_SIZE 64

void pgfe_md5_encode(const pgfe_encode_t data[], const size_t length, pgfe_encode_t output[], const size_t out_length);

void pgfe_md5_encode_f(FILE *fp, pgfe_encode_t output[], const size_t length);

void pgfe_md5_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_md5_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_md5_encode_multiple(pgfe_encode_t output[], const size_t out_length, const size_t input_c, ...);

#ifdef __cplusplus
}
#endif

#endif