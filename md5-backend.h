#ifndef LIBPGFE_MD5_BACKEND_H
#define LIBPGFE_MD5_BACKEND_H

#include "generic.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

void __pgfe_md5_transform(pgfe_word_t state[4], const pgfe_encode_t block[64]);

void __pgfe_md5_encode(pgfe_word_t input[], size_t length, pgfe_encode_t output[]);

void __pgfe_md5_decode(const pgfe_encode_t input[], size_t length, pgfe_word_t output[]);

#ifdef __cplusplus
}
#endif

#endif