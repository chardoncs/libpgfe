/*
  libpgfe
  generic.h

  Copyright (c) 2022-2023 Charles Dong
*/

#ifndef LIBPGFE_GENERIC_H
#define LIBPGFE_GENERIC_H

#include <stddef.h>
#include <stdint.h>

#include "libpgfe/algorithm-choice.h"

#ifdef __cplusplus
extern "C" {
#endif

// Default reading buffer size
#define PGFE_BUFFER_SIZE (1024)

// byte -> bit (e.g. to_bit(4) = 32)
#define pgfe_to_bit(value) ((value)*8)
// bit -> byte (e.g. to_byte(32) = 4)
#define pgfe_to_byte(value) ((value) / 8)
// Remainder of bit
#define pgfe_bit_rem(value) ((value) % 8)

typedef char pgfe_ascii_t;

typedef uint8_t pgfe_byte_t;

// Common encoding character type in libpgfe
typedef pgfe_byte_t pgfe_encode_t;

typedef uint32_t pgfe_word_t;

typedef uint64_t pgfe_word64_t;

typedef void pgfe_encode_func(const pgfe_encode_t input[], pgfe_encode_t output[]);

typedef void pgfe_encode_multi_func(pgfe_encode_t output[], size_t input_c, ...);

// Fake uint64
typedef struct
{
    // Little endian
    uint32_t right, left;
} pgfe_fake_uint64_t;

#ifdef __cplusplus
}
#endif

#endif