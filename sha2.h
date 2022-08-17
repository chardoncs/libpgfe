#ifndef LIBPGFE_SHA2_H
#define LIBPGFE_SHA2_H

#include <stdio.h>

#include <nettle/sha2.h>

#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

// Digest size macros
#define PGFE_SHA224_DIGEST_SIZE 28
#define PGFE_SHA256_DIGEST_SIZE 32
#define PGFE_SHA384_DIGEST_SIZE 48
#define PGFE_SHA512_DIGEST_SIZE 64
#define PGFE_SHA512_224_DIGEST_SIZE PGFE_SHA224_DIGEST_SIZE
#define PGFE_SHA512_256_DIGEST_SIZE PGFE_SHA256_DIGEST_SIZE

// Block size macros
#define PGFE_SHA256_BLOCK_SIZE 64
#define PGFE_SHA224_BLOCK_SIZE PGFE_SHA256_BLOCK_SIZE
#define PGFE_SHA512_BLOCK_SIZE 128
#define PGFE_SHA384_BLOCK_SIZE PGFE_SHA512_BLOCK_SIZE
#define PGFE_SHA512_224_BLOCK_SIZE PGFE_SHA512_BLOCK_SIZE
#define PGFE_SHA512_256_BLOCK_SIZE PGFE_SHA512_BLOCK_SIZE

// SHA224
void pgfe_sha224_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha224_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha224_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha224_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha224_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

// SHA256
void pgfe_sha256_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha256_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha256_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha256_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha256_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

// SHA384
void pgfe_sha384_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha384_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha384_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha384_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha384_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

// SHA512
void pgfe_sha512_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha512_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha512_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha512_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha512_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

// SHA512-224

void pgfe_sha512_224_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha512_224_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha512_224_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha512_224_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha512_224_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

// SHA512-256

void pgfe_sha512_256_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha512_256_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha512_256_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha512_256_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha512_256_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

#ifdef __cplusplus
}
#endif

#endif