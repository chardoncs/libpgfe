#ifndef LIBPGFE_SHA1_H
#define LIBPGFE_SHA1_H

#include <stdio.h>

#include <nettle/sha1.h>

#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_SHA1_DIGEST_SIZE 20

void pgfe_sha1_encode(const pgfe_encode_t input_string[], pgfe_encode_t output[], const size_t length);

void pgfe_sha1_encode_f(FILE *fp, pgfe_encode_t output[], const size_t length);

void pgfe_sha1_encode_default(const pgfe_encode_t input_string[], pgfe_encode_t output[]);

void pgfe_sha1_encode_default_f(FILE *fp, pgfe_encode_t output[]);

#ifdef __cplusplus
}
#endif

#endif