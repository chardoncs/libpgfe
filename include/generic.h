/*
  libpgfe
  generic.h

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_GENERIC_H
#define LIBPGFE_GENERIC_H

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "algorithm-choice.h"

#ifdef __cplusplus
extern "C" {
#endif

// Common reading buffer size
#define PGFE_BUFFER_SIZE 1024

// Byte -> Bit (e.g. to_bit(4) = 32)
#define to_bit(value) ((value)*8)
// Byte -> Bit (e.g. to_byte(32) = 4)
#define to_byte(value) ((value) / 8)

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

#define __PGFE_BATCH_CASES_C(target, name)                                                                             \
    switch (target) {                                                                                                  \
        __PGFE_##name##_CASE_C(MD5, md5);                                                                              \
        __PGFE_##name##_CASE_C(SHA1, sha1);                                                                            \
        __PGFE_##name##_CASE_C(SHA224, sha224);                                                                        \
        __PGFE_##name##_CASE_C(SHA256, sha256);                                                                        \
        __PGFE_##name##_CASE_C(SHA384, sha384);                                                                        \
        __PGFE_##name##_CASE_C(SHA512, sha512);                                                                        \
        __PGFE_##name##_CASE_C(SHA512_224, sha512_224);                                                                \
        __PGFE_##name##_CASE_C(SHA512_256, sha512_256);                                                                \
        __PGFE_##name##_CASE_C(SHA3_224, sha3_224);                                                                    \
        __PGFE_##name##_CASE_C(SHA3_256, sha3_256);                                                                    \
        __PGFE_##name##_CASE_C(SHA3_384, sha3_384);                                                                    \
        __PGFE_##name##_CASE_C(SHA3_512, sha3_512);                                                                    \
        __PGFE_##name##_CASE_C(RawSHAKE128, rawshake128);                                                              \
        __PGFE_##name##_CASE_C(SHAKE128, shake128);                                                                    \
        __PGFE_##name##_CASE_C(RawSHAKE256, rawshake256);                                                              \
        __PGFE_##name##_CASE_C(SHAKE256, shake256);                                                                    \
    default:                                                                                                           \
        break;                                                                                                         \
    }

#define __PGFE_BATCH_CASES_SP_C(target, name)                                                                          \
    switch (target) {                                                                                                  \
        __PGFE_##name##_CASE_C(MD5, md5);                                                                              \
        __PGFE_##name##_CASE_C(SHA1, sha1);                                                                            \
        __PGFE_##name##_CASE_C(SHA224, sha224);                                                                        \
        __PGFE_##name##_CASE_C(SHA256, sha256);                                                                        \
        __PGFE_##name##_CASE_C(SHA384, sha384);                                                                        \
        __PGFE_##name##_CASE_C(SHA512, sha512);                                                                        \
        __PGFE_##name##_CASE_C(SHA512_224, sha512_224);                                                                \
        __PGFE_##name##_CASE_C(SHA512_256, sha512_256);                                                                \
        __PGFE_##name##_CASE_C(SHA3_224, sha3_224);                                                                    \
        __PGFE_##name##_CASE_C(SHA3_256, sha3_256);                                                                    \
        __PGFE_##name##_CASE_C(SHA3_384, sha3_384);                                                                    \
        __PGFE_##name##_CASE_C(SHA3_512, sha3_512);                                                                    \
    default:                                                                                                           \
        break;                                                                                                         \
    }

#define __PGFE_BATCH_CASES_SHAKE_C(target, name)                                                                       \
    switch (target) {                                                                                                  \
        __PGFE_##name##_CASE_C(RawSHAKE128, rawshake128);                                                              \
        __PGFE_##name##_CASE_C(SHAKE128, shake128);                                                                    \
        __PGFE_##name##_CASE_C(RawSHAKE256, rawshake256);                                                              \
        __PGFE_##name##_CASE_C(SHAKE256, shake256);                                                                    \
    default:                                                                                                           \
        break;                                                                                                         \
    }

// Common encoding character type in libpgfe
typedef uint8_t pgfe_encode_t;

typedef void pgfe_encode_func(const pgfe_encode_t input[], pgfe_encode_t output[]);

typedef void pgfe_encode_multi_func(pgfe_encode_t output[], size_t input_c, ...);

// Common UNIX time type in libpgfe
typedef time_t pgfe_time_t;

#ifdef __cplusplus
}
#endif

#endif