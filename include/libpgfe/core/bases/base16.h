#ifndef LIBPGFE_CORE_BASE16_H
#define LIBPGFE_CORE_BASE16_H

#include "libpgfe/core/generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_BASE16_UNIT_SIZE 1
#define PGFE_BASE16_CHUNK_COUNT 2
#define PGFE_BASE16_BIT_SIZE 4
#define PGFE_BASE16_ALPHABET_SIZE 16

// Base 16

size_t pgfe_encode_base16(const pgfe_encode_t input[], size_t input_length, char cs_out[]);

size_t pgfe_decode_base16(const char base16_cs[], pgfe_encode_t output[]);

#ifdef __cplusplus
}
#endif

#endif