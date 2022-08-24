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

typedef uint64_t pgfe_keccak_lane64_t;

typedef pgfe_keccak_lane64_t pgfe_keccak_bitcube1600_t[5][5];

struct pgfe_keccak_sponge_ctx
{
    pgfe_keccak_bitcube1600_t state;
    pgfe_encode_t data_queue[to_byte(__PGFE_KECCAK_MAX_RATE)];
    uint32_t rate, capacity, inqueue_bits, out_length;
    uint16_t nr;
    int squeezing;
    unsigned int squeezable;
};

int __pgfe_keccak_init(struct pgfe_keccak_sponge_ctx *ctx, uint32_t capacity);

int __pgfe_keccak_absorb_b1600(struct pgfe_keccak_sponge_ctx *ctx, const pgfe_encode_t input[], size_t input_length);

int __pgfe_keccak_squeeze_b1600(struct pgfe_keccak_sponge_ctx *ctx, pgfe_encode_t output[], size_t output_length);

#ifdef __cplusplus
}
#endif

#endif