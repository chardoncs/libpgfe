/*
  libpgfe
  hmac.h

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_HMAC_H
#define LIBPGFE_HMAC_H

#include "generic-internal.h"
#include "generic.h"
#include "md5.h"
#include "sha1.h"
#include "sha2.h"
#include "sha3.h"

#ifdef __cplusplus
extern "C" {
#endif

#define I_UNIT 0x36
#define O_UNIT 0x5c

// Extended HMAC interfaces -->

// Data structure template
#define __PGFE_HMAC_CTX_TMPL(alg, upper)                                                                               \
    {                                                                                                                  \
        struct pgfe_##alg##_ctx hash_ctx;                                                                              \
        pgfe_encode_t k_i_pad[PGFE_##upper##_BLOCK_SIZE], k_o_pad[PGFE_##upper##_BLOCK_SIZE];                          \
    }

// Contexts
struct pgfe_hmac_md5_ctx __PGFE_HMAC_CTX_TMPL(md5, MD5);
struct pgfe_hmac_sha1_ctx __PGFE_HMAC_CTX_TMPL(sha1, SHA1);
struct pgfe_hmac_sha224_ctx __PGFE_HMAC_CTX_TMPL(sha224, SHA224);
struct pgfe_hmac_sha256_ctx __PGFE_HMAC_CTX_TMPL(sha256, SHA256);
struct pgfe_hmac_sha384_ctx __PGFE_HMAC_CTX_TMPL(sha384, SHA384);
struct pgfe_hmac_sha512_ctx __PGFE_HMAC_CTX_TMPL(sha512, SHA512);
struct pgfe_hmac_sha512_224_ctx __PGFE_HMAC_CTX_TMPL(sha512_224, SHA512_224);
struct pgfe_hmac_sha512_256_ctx __PGFE_HMAC_CTX_TMPL(sha512_256, SHA512_256);
struct pgfe_hmac_sha3_224_ctx __PGFE_HMAC_CTX_TMPL(sha3_224, SHA3_224);
struct pgfe_hmac_sha3_256_ctx __PGFE_HMAC_CTX_TMPL(sha3_256, SHA3_256);
struct pgfe_hmac_sha3_384_ctx __PGFE_HMAC_CTX_TMPL(sha3_384, SHA3_384);
struct pgfe_hmac_sha3_512_ctx __PGFE_HMAC_CTX_TMPL(sha3_512, SHA3_512);
// struct pgfe_hmac_shake128_ctx __PGFE_HMAC_CTX_TMPL(shake128, SHAKE128);
// struct pgfe_hmac_rawshake128_ctx __PGFE_HMAC_CTX_TMPL(rawshake128, RawSHAKE128);
// struct pgfe_hmac_shake256_ctx __PGFE_HMAC_CTX_TMPL(shake256, SHAKE256);
// struct pgfe_hmac_rawshake256_ctx __PGFE_HMAC_CTX_TMPL(rawshake256, RawSHAKE256);

// Initialization functions
void pgfe_hmac_md5_init(struct pgfe_hmac_md5_ctx *ctx);
void pgfe_hmac_sha1_init(struct pgfe_hmac_sha1_ctx *ctx);
void pgfe_hmac_sha224_init(struct pgfe_hmac_sha224_ctx *ctx);
void pgfe_hmac_sha256_init(struct pgfe_hmac_sha256_ctx *ctx);
void pgfe_hmac_sha384_init(struct pgfe_hmac_sha384_ctx *ctx);
void pgfe_hmac_sha512_init(struct pgfe_hmac_sha512_ctx *ctx);
void pgfe_hmac_sha512_224_init(struct pgfe_hmac_sha512_224_ctx *ctx);
void pgfe_hmac_sha512_256_init(struct pgfe_hmac_sha512_256_ctx *ctx);
void pgfe_hmac_sha3_224_init(struct pgfe_hmac_sha3_224_ctx *ctx);
void pgfe_hmac_sha3_256_init(struct pgfe_hmac_sha3_256_ctx *ctx);
void pgfe_hmac_sha3_384_init(struct pgfe_hmac_sha3_384_ctx *ctx);
void pgfe_hmac_sha3_512_init(struct pgfe_hmac_sha3_512_ctx *ctx);
// void pgfe_hmac_shake128_int(struct pgfe_hmac_shake128_ctx *ctx);
// void pgfe_hmac_rawshake128_int(struct pgfe_hmac_rawshake128_ctx *ctx);
// void pgfe_hmac_shake256_int(struct pgfe_hmac_shake256_ctx *ctx);
// void pgfe_hmac_rawshake256_int(struct pgfe_hmac_rawshake256_ctx *ctx);

// Key setting functions
void pgfe_hmac_md5_set_key(struct pgfe_hmac_md5_ctx *ctx, const pgfe_encode_t key[], size_t key_length);
void pgfe_hmac_sha1_set_key(struct pgfe_hmac_sha1_ctx *ctx, const pgfe_encode_t key[], size_t key_length);
void pgfe_hmac_sha224_set_key(struct pgfe_hmac_sha224_ctx *ctx, const pgfe_encode_t key[], size_t key_length);
void pgfe_hmac_sha256_set_key(struct pgfe_hmac_sha256_ctx *ctx, const pgfe_encode_t key[], size_t key_length);
void pgfe_hmac_sha384_set_key(struct pgfe_hmac_sha384_ctx *ctx, const pgfe_encode_t key[], size_t key_length);
void pgfe_hmac_sha512_set_key(struct pgfe_hmac_sha512_ctx *ctx, const pgfe_encode_t key[], size_t key_length);
void pgfe_hmac_sha512_224_set_key(struct pgfe_hmac_sha512_224_ctx *ctx, const pgfe_encode_t key[], size_t key_length);
void pgfe_hmac_sha512_256_set_key(struct pgfe_hmac_sha512_256_ctx *ctx, const pgfe_encode_t key[], size_t key_length);
void pgfe_hmac_sha3_224_set_key(struct pgfe_hmac_sha3_224_ctx *ctx, const pgfe_encode_t key[], size_t key_length);
void pgfe_hmac_sha3_256_set_key(struct pgfe_hmac_sha3_256_ctx *ctx, const pgfe_encode_t key[], size_t key_length);
void pgfe_hmac_sha3_384_set_key(struct pgfe_hmac_sha3_384_ctx *ctx, const pgfe_encode_t key[], size_t key_length);
void pgfe_hmac_sha3_512_set_key(struct pgfe_hmac_sha3_512_ctx *ctx, const pgfe_encode_t key[], size_t key_length);
// void pgfe_hmac_shake128_set_key(struct pgfe_hmac_shake128_ctx *ctx, const pgfe_encode_t key[], size_t key_length);
// void pgfe_hmac_rawshake128_set_key(struct pgfe_hmac_rawshake128_ctx *ctx, const pgfe_encode_t key[], size_t
// key_length); void pgfe_hmac_shake256_set_key(struct pgfe_hmac_shake256_ctx *ctx, const pgfe_encode_t key[], size_t
// key_length); void pgfe_hmac_rawshake256_set_key(struct pgfe_hmac_rawshake256_ctx *ctx, const pgfe_encode_t key[],
// size_t key_length);

// Data appending functions
void pgfe_hmac_md5_update(struct pgfe_hmac_md5_ctx *ctx, const pgfe_encode_t data[], size_t length);
void pgfe_hmac_sha1_update(struct pgfe_hmac_sha1_ctx *ctx, const pgfe_encode_t data[], size_t length);
void pgfe_hmac_sha224_update(struct pgfe_hmac_sha224_ctx *ctx, const pgfe_encode_t data[], size_t length);
void pgfe_hmac_sha256_update(struct pgfe_hmac_sha256_ctx *ctx, const pgfe_encode_t data[], size_t length);
void pgfe_hmac_sha384_update(struct pgfe_hmac_sha384_ctx *ctx, const pgfe_encode_t data[], size_t length);
void pgfe_hmac_sha512_update(struct pgfe_hmac_sha512_ctx *ctx, const pgfe_encode_t data[], size_t length);
void pgfe_hmac_sha512_224_update(struct pgfe_hmac_sha512_224_ctx *ctx, const pgfe_encode_t data[], size_t length);
void pgfe_hmac_sha512_256_update(struct pgfe_hmac_sha512_256_ctx *ctx, const pgfe_encode_t data[], size_t length);
void pgfe_hmac_sha3_224_update(struct pgfe_hmac_sha3_224_ctx *ctx, const pgfe_encode_t data[], size_t length);
void pgfe_hmac_sha3_256_update(struct pgfe_hmac_sha3_256_ctx *ctx, const pgfe_encode_t data[], size_t length);
void pgfe_hmac_sha3_384_update(struct pgfe_hmac_sha3_384_ctx *ctx, const pgfe_encode_t data[], size_t length);
void pgfe_hmac_sha3_512_update(struct pgfe_hmac_sha3_512_ctx *ctx, const pgfe_encode_t data[], size_t length);
// void pgfe_hmac_shake128_update(struct pgfe_hmac_shake128_ctx *ctx, const pgfe_encode_t data[], size_t length);
// void pgfe_hmac_rawshake128_update(struct pgfe_hmac_rawshake128_ctx *ctx, const pgfe_encode_t data[], size_t length);
// void pgfe_hmac_shake256_update(struct pgfe_hmac_shake256_ctx *ctx, const pgfe_encode_t data[], size_t length);
// void pgfe_hmac_rawshake256_update(struct pgfe_hmac_rawshake256_ctx *ctx, const pgfe_encode_t data[], size_t length);

// Digest generating functions
void pgfe_hmac_md5_digest(struct pgfe_hmac_md5_ctx *ctx, pgfe_encode_t output[]);
void pgfe_hmac_sha1_digest(struct pgfe_hmac_sha1_ctx *ctx, pgfe_encode_t output[]);
void pgfe_hmac_sha224_digest(struct pgfe_hmac_sha224_ctx *ctx, pgfe_encode_t output[]);
void pgfe_hmac_sha256_digest(struct pgfe_hmac_sha256_ctx *ctx, pgfe_encode_t output[]);
void pgfe_hmac_sha384_digest(struct pgfe_hmac_sha384_ctx *ctx, pgfe_encode_t output[]);
void pgfe_hmac_sha512_digest(struct pgfe_hmac_sha512_ctx *ctx, pgfe_encode_t output[]);
void pgfe_hmac_sha512_224_digest(struct pgfe_hmac_sha512_224_ctx *ctx, pgfe_encode_t output[]);
void pgfe_hmac_sha512_256_digest(struct pgfe_hmac_sha512_256_ctx *ctx, pgfe_encode_t output[]);
void pgfe_hmac_sha3_224_digest(struct pgfe_hmac_sha3_224_ctx *ctx, pgfe_encode_t output[]);
void pgfe_hmac_sha3_256_digest(struct pgfe_hmac_sha3_256_ctx *ctx, pgfe_encode_t output[]);
void pgfe_hmac_sha3_384_digest(struct pgfe_hmac_sha3_384_ctx *ctx, pgfe_encode_t output[]);
void pgfe_hmac_sha3_512_digest(struct pgfe_hmac_sha3_512_ctx *ctx, pgfe_encode_t output[]);
// void pgfe_hmac_shake128_digest(struct pgfe_hmac_shake128_ctx *ctx, pgfe_encode_t output[]);
// void pgfe_hmac_rawshake128_digest(struct pgfe_hmac_rawshake128_ctx *ctx, pgfe_encode_t output[]);
// void pgfe_hmac_shake256_digest(struct pgfe_hmac_shake256_ctx *ctx, pgfe_encode_t output[]);
// void pgfe_hmac_rawshake256_digest(struct pgfe_hmac_rawshake256_ctx *ctx, pgfe_encode_t output[]);

// Generic HMAC function
void pgfe_hmac(
    enum pgfe_algorithm_choice alg, const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[],
    size_t length, pgfe_encode_t output[]
);

// <-- END Extended HMAC interfaces

// Legacy interfaces -->

void pgfe_hmac_md5(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha1(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha224(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha256(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha384(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha512(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha512_224(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha512_256(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha3_224(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha3_256(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha3_384(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha3_512(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

// void pgfe_hmac_shake128(
//     const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
// );

// void pgfe_hmac_rawshake128(
//     const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
// );

// void pgfe_hmac_shake256(
//     const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
// );

// void pgfe_hmac_rawshake256(
//     const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
// );

// <-- END Legacy interfaces

#ifdef __cplusplus
}
#endif

#endif