#ifndef LIBPGFE_SHA1_H
#define LIBPGFE_SHA1_H

#include <stdio.h>

#include <nettle/sha1.h>

#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_SHA1_DIGEST_SIZE 20
#define PGFE_SHA1_BLOCK_SIZE 64

void pgfe_sha1_encode(const pgfe_encode_t data[], const size_t length, pgfe_encode_t output[], const size_t out_length);

void pgfe_sha1_encode_f(FILE *fp, pgfe_encode_t output[], const size_t length);

void pgfe_sha1_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha1_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha1_encode_multiple(pgfe_encode_t output[], const size_t out_length, const size_t input_c, ...);

#ifdef __cplusplus
}
#endif

#endif