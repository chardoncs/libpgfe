/*
  libpgfe
  base-encoding.h

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_BASE_ENCODING_H
#define LIBPGFE_BASE_ENCODING_H

#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_BASE64_UNIT_SIZE 3
#define PGFE_BASE64_CHUNK_COUNT 4
#define PGFE_BASE64_BIT_SIZE 6
#define PGFE_BASE64_ALPHABET_SIZE 64

#define PGFE_BASE32_UNIT_SIZE 5
#define PGFE_BASE32_CHUNK_COUNT 8
#define PGFE_BASE32_BIT_SIZE 5
#define PGFE_BASE32_ALPHABET_SIZE 32

#define PGFE_BASE16_UNIT_SIZE 1
#define PGFE_BASE16_CHUNK_COUNT 2
#define PGFE_BASE16_BIT_SIZE 4
#define PGFE_BASE16_ALPHABET_SIZE 16

// Base 64

// Encode input to standard Base 64
size_t pgfe_encode_base64(const pgfe_encode_t input[], size_t input_length, char cs_out[]);

// Encode input to the URL and Filename safe variant of Base 64
size_t pgfe_encode_base64_url(const pgfe_encode_t input[], size_t input_length, char cs_out[]);

// Decode Base 64 (for both standard and name-safe)
size_t pgfe_decode_base64(const char base64_cs[], pgfe_encode_t output[]);

// Base 32

// Encode input to standard Base 32
size_t pgfe_encode_base32(const pgfe_encode_t input[], size_t input_length, char cs_out[]);

// Encode input to Base 32-Hex
size_t pgfe_encode_base32hex(const pgfe_encode_t input[], size_t input_length, char cs_out[]);

// Decode standard Base 32
size_t pgfe_decode_base32(const char base32_cs[], pgfe_encode_t output[]);

// Decode Base 32-Hex
size_t pgfe_decode_base32hex(const char base32_cs[], pgfe_encode_t output[]);

// Base 16

size_t pgfe_encode_base16(const pgfe_encode_t input[], size_t input_length, char cs_out[]);

size_t pgfe_decode_base16(const char base16_cs[], pgfe_encode_t output[]);

#ifdef __cplusplus
}
#endif

#endif