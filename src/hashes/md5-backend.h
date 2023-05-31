/*
  libpgfe
  md5-backend.h

  Backend implementation of MD5 algorithm

  Copyright (c) 2022-2023 Charles Dong
*/

#ifndef LIBPGFE_MD5_BACKEND_H
#define LIBPGFE_MD5_BACKEND_H

#include "../core/generic-internal.h"

#ifdef __cplusplus
extern "C" {
#endif

void md5_transform(pgfe_word_t state[4], const pgfe_encode_t block[64]);

void md5_encode(pgfe_word_t input[], size_t length, pgfe_encode_t output[]);

void md5_decode(const pgfe_encode_t input[], size_t length, pgfe_word_t output[]);

#ifdef __cplusplus
}
#endif

#endif