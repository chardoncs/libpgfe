/*
  libpgfe
  generic.h

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

#ifndef LIBPGFE_GENERIC_H
#define LIBPGFE_GENERIC_H

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_BUFFER_SIZE 1024

// // File reading behavior options
// #define PGFE_FR_CURRENT_END 0
// #define PGFE_FR_START_END -1

#define PGFE_ENCODER_SIG(name, upper)                                                                                  \
    pgfe_##name##_encode_multiple, PGFE_##upper##_BLOCK_SIZE, PGFE_##upper##_DIGEST_SIZE

#define PGFE_ENCODER_SIG_MD5 PGFE_ENCODER_SIG(md5, MD5)
#define PGFE_ENCODER_SIG_SHA1 PGFE_ENCODER_SIG(sha1, SHA1)
#define PGFE_ENCODER_SIG_SHA224 PGFE_ENCODER_SIG(sha224, SHA224)
#define PGFE_ENCODER_SIG_SHA256 PGFE_ENCODER_SIG(sha256, SHA256)
#define PGFE_ENCODER_SIG_SHA384 PGFE_ENCODER_SIG(sha384, SHA384)
#define PGFE_ENCODER_SIG_SHA512 PGFE_ENCODER_SIG(sha512, SHA512)
#define PGFE_ENCODER_SIG_SHA512_224 PGFE_ENCODER_SIG(sha512_224, SHA512_224)
#define PGFE_ENCODER_SIG_SHA512_256 PGFE_ENCODER_SIG(sha512_256, SHA512_256)
#define PGFE_ENCODER_SIG_SHA3_224 PGFE_ENCODER_SIG(sha3_224, SHA3_224)
#define PGFE_ENCODER_SIG_SHA3_256 PGFE_ENCODER_SIG(sha3_256, SHA3_256)
#define PGFE_ENCODER_SIG_SHA3_384 PGFE_ENCODER_SIG(sha3_384, SHA3_384)
#define PGFE_ENCODER_SIG_SHA3_512 PGFE_ENCODER_SIG(sha3_512, SHA3_512)

typedef uint8_t pgfe_encode_t;

typedef void pgfe_encode_func(const pgfe_encode_t input[], pgfe_encode_t output[]);

typedef void pgfe_encode_multi_func(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

typedef time_t pgfe_time_t;

#ifdef __cplusplus
}
#endif

#endif