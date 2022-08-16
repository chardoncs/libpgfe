#ifndef LIBPGFE_MD5_H
#define LIBPGFE_MD5_H

#include <stdio.h>

#include <nettle/md5.h>

#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_MD5_DIGEST_SIZE 16

void pgfe_md5_encode(const pgfe_encode_t input_string[], pgfe_encode_t output[], const size_t length);

void pgfe_md5_encode_f(FILE *fp, pgfe_encode_t output[], const size_t length);

void pgfe_md5_encode_default(const pgfe_encode_t input_string[], pgfe_encode_t output[]);

void pgfe_md5_encode_default_f(FILE *fp, pgfe_encode_t output[]);

#ifdef __cplusplus
}
#endif

#endif