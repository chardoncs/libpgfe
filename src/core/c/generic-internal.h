/*
  libpgfe
  generic-internal.h

  Generic configuration backend

  Copyright (c) 2022-2023 Charles Dong
*/

#ifndef LIBPGFE_GENERIC_INTERNAL_H
#define LIBPGFE_GENERIC_INTERNAL_H

#include "libpgfe/core/generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_HEX_UNKNOWN_CHAR 0xF1

#define PGFE_ENCODER_DEF_SIG pgfe_encode_multi_func *func, size_t block_size, size_t digest_size
#define PGFE_ENCODER_CALL_SIG func, block_size, digest_size

// Conversion mapping (to bit)
#define to_bit(value) pgfe_to_bit(value)
// Conversion mapping (to byte)
#define to_byte(value) pgfe_to_byte(value)
// Conversion mapping (bit remainder)
#define bit_rem(value) pgfe_bit_rem(value)

// Circular left shift
#define clshift(n, c) (((n) << (c)) | ((n) >> (to_bit(sizeof(n)) - (c))))
// Circular right shift
#define crshift(n, c) (((n) >> (c)) | ((n) << (to_bit(sizeof(n)) - (c))))

void arrinit(pgfe_encode_t arr[], size_t size);

void arrcpy(pgfe_encode_t dest[], size_t dest_s, const pgfe_encode_t src[], size_t src_s);

void ch2hex(char ch, pgfe_encode_t *hex);

void reverse(pgfe_encode_t *low, pgfe_encode_t *high);

#define __PGFE_BATCH_CASES(target, name)                                                                               \
    switch (target) {                                                                                                  \
        __PGFE_##name##_CASE(MD5, md5);                                                                                \
        __PGFE_##name##_CASE(SHA1, sha1);                                                                              \
        __PGFE_##name##_CASE(SHA224, sha224);                                                                          \
        __PGFE_##name##_CASE(SHA256, sha256);                                                                          \
        __PGFE_##name##_CASE(SHA384, sha384);                                                                          \
        __PGFE_##name##_CASE(SHA512, sha512);                                                                          \
        __PGFE_##name##_CASE(SHA512_224, sha512_224);                                                                  \
        __PGFE_##name##_CASE(SHA512_256, sha512_256);                                                                  \
        __PGFE_##name##_CASE(SHA3_224, sha3_224);                                                                      \
        __PGFE_##name##_CASE(SHA3_256, sha3_256);                                                                      \
        __PGFE_##name##_CASE(SHA3_384, sha3_384);                                                                      \
        __PGFE_##name##_CASE(SHA3_512, sha3_512);                                                                      \
        __PGFE_##name##_CASE(RawSHAKE128, rawshake128);                                                                \
        __PGFE_##name##_CASE(SHAKE128, shake128);                                                                      \
        __PGFE_##name##_CASE(RawSHAKE256, rawshake256);                                                                \
        __PGFE_##name##_CASE(SHAKE256, shake256);                                                                      \
    default:                                                                                                           \
        break;                                                                                                         \
    }

#define __PGFE_BATCH_CASES_SP(target, name)                                                                            \
    switch (target) {                                                                                                  \
        __PGFE_##name##_CASE(MD5, md5);                                                                                \
        __PGFE_##name##_CASE(SHA1, sha1);                                                                              \
        __PGFE_##name##_CASE(SHA224, sha224);                                                                          \
        __PGFE_##name##_CASE(SHA256, sha256);                                                                          \
        __PGFE_##name##_CASE(SHA384, sha384);                                                                          \
        __PGFE_##name##_CASE(SHA512, sha512);                                                                          \
        __PGFE_##name##_CASE(SHA512_224, sha512_224);                                                                  \
        __PGFE_##name##_CASE(SHA512_256, sha512_256);                                                                  \
        __PGFE_##name##_CASE(SHA3_224, sha3_224);                                                                      \
        __PGFE_##name##_CASE(SHA3_256, sha3_256);                                                                      \
        __PGFE_##name##_CASE(SHA3_384, sha3_384);                                                                      \
        __PGFE_##name##_CASE(SHA3_512, sha3_512);                                                                      \
    default:                                                                                                           \
        break;                                                                                                         \
    }

#define __PGFE_BATCH_CASES_SHAKE(target, name)                                                                         \
    switch (target) {                                                                                                  \
        __PGFE_##name##_CASE(RawSHAKE128, rawshake128);                                                                \
        __PGFE_##name##_CASE(SHAKE128, shake128);                                                                      \
        __PGFE_##name##_CASE(RawSHAKE256, rawshake256);                                                                \
        __PGFE_##name##_CASE(SHAKE256, shake256);                                                                      \
    default:                                                                                                           \
        break;                                                                                                         \
    }

// CXX compatibility

#define __PGFE_BATCH_SHAKE_CASES(name)                                                                                 \
    switch (cur_alg) {                                                                                                 \
        __PGFE_##name##_CASE(RawSHAKE128, rawshake128);                                                                \
        __PGFE_##name##_CASE(SHAKE128, shake128);                                                                      \
        __PGFE_##name##_CASE(RawSHAKE256, rawshake256);                                                                \
        __PGFE_##name##_CASE(SHAKE256, shake256);                                                                      \
    default:                                                                                                           \
        break;                                                                                                         \
    }

#define __PGFE_INIT_SIZE_CASE(alg, name)                                                                               \
    case alg:                                                                                                          \
        digsz = PGFE_##alg##_DIGEST_SIZE;                                                                              \
        blocksz = PGFE_##alg##_BLOCK_SIZE;                                                                             \
        break

#define __PGFE_INIT_CTXP_CASE(alg, name)                                                                               \
    case alg:                                                                                                          \
        pgfe_##name##_init((pgfe_##name##_ctx *)ctx);                                                                  \
        break

#define __PGFE_INIT_CTX_CASE(alg, name)                                                                                \
    case alg:                                                                                                          \
        pgfe_##name##_init(&ctx);                                                                                      \
        break

#define __PGFE_SET_CTXP_CASE(alg, name)                                                                                \
    case alg:                                                                                                          \
        ctx = new pgfe_##name##_ctx;                                                                                   \
        break

#define __PGFE_FREE_CTXP_CASE(alg, name)                                                                               \
    case alg:                                                                                                          \
        delete (pgfe_##name##_ctx *)ctx;                                                                               \
        break

#ifdef __cplusplus
}
#endif

#endif