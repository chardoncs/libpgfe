#ifndef LIBPGFE_BASE_ENCODING_H
#define LIBPGFE_BASE_ENCODING_H

#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

// Base 64
size_t pgfe_encode_base64(const pgfe_encode_t input[], size_t input_length, char cs_out[]);

size_t pgfe_decode_base64(const char base64_cs[], pgfe_encode_t output[]);

// Base 32

size_t pgfe_encode_base32(const pgfe_encode_t input[], size_t input_length, char cs_out[]);

size_t pgfe_decode_base32(const char base32_cs[], pgfe_encode_t output[]);

// Base 16

size_t pgfe_encode_base16(const pgfe_encode_t input[], size_t input_length, char cs_out[]);

size_t pgfe_decode_base16(const char base16_cs[], pgfe_encode_t output[]);

#ifdef __cplusplus
}
#endif

#endif