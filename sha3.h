#ifndef LIBPGFE_SHA3_H
#define LIBPGFE_SHA3_H

#include <stdio.h>

#include <nettle/sha3.h>

#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_SHA3_224_DIGEST_SIZE 28
#define PGFE_SHA3_256_DIGEST_SIZE 32
#define PGFE_SHA3_384_DIGEST_SIZE 48
#define PGFE_SHA3_512_DIGEST_SIZE 64

#define PGFE_SHA3_224_BLOCK_SIZE 144
#define PGFE_SHA3_256_BLOCK_SIZE 136
#define PGFE_SHA3_384_BLOCK_SIZE 104
#define PGFE_SHA3_512_BLOCK_SIZE 72

// SHA3-224
void pgfe_sha3_224_encode(
    const pgfe_encode_t data[], const size_t length, pgfe_encode_t output[], const size_t out_length
);

void pgfe_sha3_224_encode_f(FILE *fp, pgfe_encode_t output[], const size_t length);

void pgfe_sha3_224_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha3_224_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha3_224_encode_multiple(pgfe_encode_t output[], const size_t out_length, const size_t input_c, ...);

// SHA-256
void pgfe_sha3_256_encode(
    const pgfe_encode_t data[], const size_t length, pgfe_encode_t output[], const size_t out_length
);

void pgfe_sha3_256_encode_f(FILE *fp, pgfe_encode_t output[], const size_t length);

void pgfe_sha3_256_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha3_256_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha3_256_encode_multiple(pgfe_encode_t output[], const size_t out_length, const size_t input_c, ...);

// SHA3-384
void pgfe_sha3_384_encode(
    const pgfe_encode_t data[], const size_t length, pgfe_encode_t output[], const size_t out_length
);

void pgfe_sha3_384_encode_f(FILE *fp, pgfe_encode_t output[], const size_t length);

void pgfe_sha3_384_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha3_384_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha3_384_encode_multiple(pgfe_encode_t output[], const size_t out_length, const size_t input_c, ...);

// SHA3-512
void pgfe_sha3_512_encode(
    const pgfe_encode_t data[], const size_t length, pgfe_encode_t output[], const size_t out_length
);

void pgfe_sha3_512_encode_f(FILE *fp, pgfe_encode_t output[], const size_t length);

void pgfe_sha3_512_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha3_512_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha3_512_encode_multiple(pgfe_encode_t output[], const size_t out_length, const size_t input_c, ...);

#ifdef __cplusplus
}
#endif

#endif