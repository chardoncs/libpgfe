/*
  libpgfe
  base-encoding-internal.h

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_BASE_ENCODING_INTERNAL_H
#define LIBPGFE_BASE_ENCODING_INTERNAL_H

#include <stdbool.h>

#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_BASE_PADDING_CODE 0x00
#define PGFE_BASE_UNKNOWN_CODE 0xC0

#define PGFE_BASE_PARAMS(upper)                                                                                        \
    PGFE_##upper##_CHUNK_COUNT, PGFE_##upper##_UNIT_SIZE, PGFE_##upper##_BIT_SIZE, PGFE_##upper##_ALPHABET_SIZE

#define PGFE_BASE_PARAMS_DEF size_t chunk_count, size_t unit_size, size_t bit_size, size_t alphabet_size

pgfe_encode_t pgfe_decode_base64_char(char base64_c);

pgfe_encode_t pgfe_decode_base32_char(char base32_c);

pgfe_encode_t pgfe_decode_base32hex_char(char base32_c);

pgfe_encode_t pgfe_decode_base16_char(char base16_c);

size_t __pgfe_transform_codes(const pgfe_encode_t input[], size_t length, uint8_t chunk_size, pgfe_encode_t out[]);

size_t
__pgfe_unittostr(PGFE_BASE_PARAMS_DEF, const char alphabet[], const pgfe_encode_t unit[], char out[], bool padding);

size_t __pgfe_encode_generic(
    PGFE_BASE_PARAMS_DEF, const char alphabet[], const pgfe_encode_t input[], size_t input_length, char cs_out[]
);

size_t __pgfe_decode_generic(
    PGFE_BASE_PARAMS_DEF, pgfe_encode_t (*func)(char), const char basexx_cs[], pgfe_encode_t output[]
);

#ifdef __cplusplus
}
#endif

#endif