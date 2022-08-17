#ifndef LIBPGFE_GENERIC_H
#define LIBPGFE_GENERIC_H

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_BUFFER_SIZE 1024

// File reading behavior options
#define PGFE_FR_CURRENT_END 0
#define PGFE_FR_START_END -1

typedef uint8_t pgfe_encode_t;

typedef void pgfe_encode_func(const pgfe_encode_t input[], pgfe_encode_t output[]);

typedef void pgfe_encode_multi_func(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

#ifdef __cplusplus
}
#endif

#endif