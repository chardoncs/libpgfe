#ifndef LIBPGFE_CORE_BASE32_H
#define LIBPGFE_CORE_BASE32_H

#include "libpgfe/core/generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_BASE32_UNIT_SIZE 5
#define PGFE_BASE32_CHUNK_COUNT 8
#define PGFE_BASE32_BIT_SIZE 5
#define PGFE_BASE32_ALPHABET_SIZE 32

// Base 32

// Encode input to standard Base 32
size_t pgfe_encode_base32(const pgfe_encode_t input[], size_t input_length, char cs_out[]);

// Encode input to Base 32-Hex
size_t pgfe_encode_base32hex(const pgfe_encode_t input[], size_t input_length, char cs_out[]);

// Decode standard Base 32
size_t pgfe_decode_base32(const char base32_cs[], pgfe_encode_t output[]);

// Decode Base 32-Hex
size_t pgfe_decode_base32hex(const char base32_cs[], pgfe_encode_t output[]);

#ifdef __cplusplus
}
#endif

#endif