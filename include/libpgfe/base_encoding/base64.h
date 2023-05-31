#ifndef LIBPGFE_BASE64_H
#define LIBPGFE_BASE64_H

#include "libpgfe/generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_BASE64_UNIT_SIZE 3
#define PGFE_BASE64_CHUNK_COUNT 4
#define PGFE_BASE64_BIT_SIZE 6
#define PGFE_BASE64_ALPHABET_SIZE 64

// Base 64

// Encode input to standard Base 64
size_t pgfe_encode_base64(const pgfe_encode_t input[], size_t input_length, char cs_out[]);

// Encode input to the URL and Filename safe variant of Base 64
size_t pgfe_encode_base64_url(const pgfe_encode_t input[], size_t input_length, char cs_out[]);

// Decode Base 64 (for both standard and name-safe)
size_t pgfe_decode_base64(const char base64_cs[], pgfe_encode_t output[]);

#ifdef __cplusplus
}
#endif

#endif