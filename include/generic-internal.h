/*
  libpgfe
  generic-internal.h

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_GENERIC_INTERNAL_H
#define LIBPGFE_GENERIC_INTERNAL_H

#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_HEX_UNKNOWN_CHAR 0xF1

#define PGFE_ENCODER_DEF_SIG pgfe_encode_multi_func *func, size_t block_size, size_t digest_size
#define PGFE_ENCODER_CALL_SIG func, block_size, digest_size

#define clshift(n, c) (((n) << (c)) | ((n) >> (to_bit(sizeof(n)) - (c))))
#define crshift(n, c) (((n) >> (c)) | ((n) << (to_bit(sizeof(n)) - (c))))

#define __pgfe_loop for (;;)

void __pgfe_arrinit(pgfe_encode_t arr[], size_t size);

void __pgfe_arrcpy(pgfe_encode_t dest[], size_t dest_s, const pgfe_encode_t src[], size_t src_s);

void __pgfe_ch2hex(char ch, pgfe_encode_t *hex);

void __pgfe_reverse_elements(pgfe_encode_t *low, pgfe_encode_t *high);

#ifdef __cplusplus
}
#endif

#endif