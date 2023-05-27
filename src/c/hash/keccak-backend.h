/*
  libpgfe
  keccak-backend.h

  Backend implementation of SHA3/Keccak algorithm

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_KECCAK_BACKEND_H
#define LIBPGFE_KECCAK_BACKEND_H

#include <stdint.h>

#include "libpgfe/sha3.h"

#include "../generic-internal.h"

#define __PGFE_KECCAK_b 1600

#ifdef __cplusplus
extern "C" {
#endif

int __pgfe_keccak_init(struct pgfe_keccak_sponge_ctx *ctx, uint32_t capacity);

int __pgfe_keccak_absorb_b1600(struct pgfe_keccak_sponge_ctx *ctx, const pgfe_encode_t input[], uint64_t bit_len);

int __pgfe_keccak_squeeze_b1600(struct pgfe_keccak_sponge_ctx *ctx, pgfe_encode_t output[]);

#ifdef __cplusplus
}
#endif

#endif