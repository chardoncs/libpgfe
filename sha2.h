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

// SHA224
void pgfe_sha224_encode(const pgfe_encode_t input_string[], pgfe_encode_t output[], const size_t length);

void pgfe_sha224_encode_f(FILE *fp, pgfe_encode_t output[], const size_t length);

void pgfe_sha224_encode_default(const pgfe_encode_t input_string[], pgfe_encode_t output[]);

void pgfe_sha224_encode_default_f(FILE *fp, pgfe_encode_t output[]);

// SHA256
void pgfe_sha256_encode(const pgfe_encode_t input_string[], pgfe_encode_t output[], const size_t length);

void pgfe_sha256_encode_f(FILE *fp, pgfe_encode_t output[], const size_t length);

void pgfe_sha256_encode_default(const pgfe_encode_t input_string[], pgfe_encode_t output[]);

void pgfe_sha256_encode_default_f(FILE *fp, pgfe_encode_t output[]);

// SHA384
void pgfe_sha384_encode(const pgfe_encode_t input_string[], pgfe_encode_t output[], const size_t length);

void pgfe_sha384_encode_f(FILE *fp, pgfe_encode_t output[], const size_t length);

void pgfe_sha384_encode_default(const pgfe_encode_t input_string[], pgfe_encode_t output[]);

void pgfe_sha384_encode_default_f(FILE *fp, pgfe_encode_t output[]);

// SHA512
void pgfe_sha512_encode(const pgfe_encode_t input_string[], pgfe_encode_t output[], const size_t length);

void pgfe_sha512_encode_f(FILE *fp, pgfe_encode_t output[], const size_t length);

void pgfe_sha512_encode_default(const pgfe_encode_t input_string[], pgfe_encode_t output[]);

void pgfe_sha512_encode_default_f(FILE *fp, pgfe_encode_t output[]);

#ifdef __cplusplus
}
#endif

#endif