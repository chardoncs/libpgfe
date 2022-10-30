/*
  libpgfe
  generic.h

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_GENERIC_H
#define LIBPGFE_GENERIC_H

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "algorithm-choice.h"

#ifdef __cplusplus
extern "C" {
#endif

// Common reading buffer size
#define PGFE_BUFFER_SIZE 1024

// byte -> bit (e.g. to_bit(4) = 32)
#define to_bit(value) ((value)*8)
// bit -> byte (e.g. to_byte(32) = 4)
#define to_byte(value) ((value) / 8)
// Remainder of bit
#define bit_rem(value) ((value) % 8)

// Common encoding character type in libpgfe
typedef uint8_t pgfe_encode_t;

typedef uint32_t pgfe_word_t;

typedef uint64_t pgfe_word64_t;

typedef void pgfe_encode_func(const pgfe_encode_t input[], pgfe_encode_t output[]);

typedef void pgfe_encode_multi_func(pgfe_encode_t output[], size_t input_c, ...);

// Common UNIX time type in libpgfe
typedef time_t pgfe_time_t;

#ifdef __cplusplus
}
#endif

#endif