/*
  libpgfe
  keccak-backend.h

  Backend implementation of SHA3/Keccak algorithm

  Copyright (c) 2022-2023 Charles Dong
*/

#ifndef LIBPGFE_CORE_KECCAK_BACKEND_H
#define LIBPGFE_CORE_KECCAK_BACKEND_H

#include <stdint.h>

#include "libpgfe/core/hashes/sha3.h"

#include "../generic-internal.h"

#define KECCAK_b 1600

#ifdef __cplusplus
extern "C" {
#endif

int keccak_init(struct pgfe_keccak_sponge_ctx *ctx, uint32_t capacity);

int keccak_absorb_b1600(struct pgfe_keccak_sponge_ctx *ctx, const pgfe_encode_t input[], uint64_t bit_len);

int keccak_squeeze_b1600(struct pgfe_keccak_sponge_ctx *ctx, pgfe_encode_t output[]);

#ifdef __cplusplus
}
#endif

#endif