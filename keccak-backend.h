/*
  libpgfe
  keccak-backend.h

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_KECCAK_BACKEND_H
#define LIBPGFE_KECCAK_BACKEND_H

#include <stdint.h>

#include "generic-internal.h"

#ifdef __cplusplus
extern "C" {
#endif

#define __pgfe_keccak_f_b1600(input, output) __pgfe_keccak_p_b1600(24, (input), (output))

#define __PGFE_KECCAK_b 1600
#define __PGFE_KECCAK_MAX_RATE 1536

typedef uint64_t pgfe_keccak_lane_t;

typedef pgfe_keccak_lane_t pgfe_keccak_bitcube_t[25];

typedef pgfe_encode_t pgfe_keccak_state_t[200];

// Generic Keccak Sponge Context
struct pgfe_keccak_sponge_ctx
{
    pgfe_keccak_state_t state;                                 // Keccak sponge state array
    pgfe_encode_t data_queue[to_byte(__PGFE_KECCAK_MAX_RATE)]; // Data queue
    uint32_t rate, capacity, inqueue_bits, out_length;         // Rate, capacity, bits in queue, output bit length
    uint16_t nr;                                               // Number of rounds (Usually 24)
    int squeezing;                                             // Is squeezing
    unsigned int squeezable;                                   // Size of squeezable bits
    pgfe_encode_t ap;                                          // Reserved appendix for adapting SHA-3
    uint8_t ap_len;                                            // Bit length of appendix
};

int __pgfe_keccak_init(struct pgfe_keccak_sponge_ctx *ctx, uint32_t capacity);

int __pgfe_keccak_absorb_b1600(struct pgfe_keccak_sponge_ctx *ctx, const pgfe_encode_t input[], uint64_t bit_len);

int __pgfe_keccak_squeeze_b1600(struct pgfe_keccak_sponge_ctx *ctx, pgfe_encode_t output[]);

#ifdef __cplusplus
}
#endif

#endif