/*
  libpgfe
  generic-internal.h

  Copyright (C) 2022 Charles Dong

  libpgfe is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
*/

#ifndef LIBPGFE_GENERIC_INTERNAL_H
#define LIBPGFE_GENERIC_INTERNAL_H

#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#if __x86_64__ || _M_AMD64 || __aarch64__ || __ppc64__ || __mips64__ || __mips64 || __MIPS64__
#define __PGFE_64Bit
#else
#define __PGFE_32Bit
#endif

#define PGFE_HEX_UNKNOWN_CHAR 0xF1

#define PGFE_ENCODER_DEF_SIG pgfe_encode_multi_func *func, size_t block_size, size_t digest_size
#define PGFE_ENCODER_CALL_SIG func, block_size, digest_size

#define clshift(n, c) (((n) << (c)) | ((n) >> (to_bit(sizeof(n)) - (c))))
#define crshift(n, c) (((n) >> (c)) | ((n) << (to_bit(sizeof(n)) - (c))))

typedef uint32_t pgfe_word_t;
#ifdef __PGFE_64Bit
typedef uint64_t pgfe_word64_t;
#endif

void __pgfe_arrinit(pgfe_encode_t arr[], size_t size);

void __pgfe_arrcpy(pgfe_encode_t dest[], size_t dest_s, const pgfe_encode_t src[], size_t src_s);

void __pgfe_ch2hex(char ch, pgfe_encode_t *hex);

void __pgfe_reverse_elements(pgfe_encode_t *low, pgfe_encode_t *high);

#ifdef __cplusplus
}
#endif

#endif