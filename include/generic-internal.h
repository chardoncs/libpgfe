/*
  libpgfe
  generic-internal.h

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_GENERIC_INTERNAL_H
#define LIBPGFE_GENERIC_INTERNAL_H

#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_HEX_UNKNOWN_CHAR 0xF1

#define PGFE_ENCODER_DEF_SIG pgfe_encode_multi_func *func, size_t block_size, size_t digest_size
#define PGFE_ENCODER_CALL_SIG func, block_size, digest_size

// Circular left shift
#define clshift(n, c) (((n) << (c)) | ((n) >> (to_bit(sizeof(n)) - (c))))
// Circular right shift
#define crshift(n, c) (((n) >> (c)) | ((n) << (to_bit(sizeof(n)) - (c))))

#define __pgfe_loop for (;;)

void __pgfe_arrinit(pgfe_encode_t arr[], size_t size);

void __pgfe_arrcpy(pgfe_encode_t dest[], size_t dest_s, const pgfe_encode_t src[], size_t src_s);

void __pgfe_ch2hex(char ch, pgfe_encode_t *hex);

void __pgfe_reverse_elements(pgfe_encode_t *low, pgfe_encode_t *high);

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

#ifdef __cplusplus
}
#endif

#endif