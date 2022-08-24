#ifndef LIBPGFE_KECCAK_BACKEND_H
#define LIBPGFE_KECCAK_BACKEND_H

#include <stdint.h>

#include "generic-internal.h"

#ifdef __cplusplus
extern "C" {
#endif

#define __pgfe_keccak_f_b1600(input, output) __pgfe_keccak_p_b1600(24, (input), (output))

struct pgfe_keccak_base_ctx
{
    pgfe_encode_t S[200];
    uint32_t capacity;
};

typedef uint64_t pgfe_keccak_lane64_t;

typedef pgfe_keccak_lane64_t pgfe_keccak_bitcube1600_t[5][5];

void __pgfe_keccak_p_b1600(uint32_t nr, const pgfe_encode_t *input, pgfe_encode_t *output);

void __pgfe_keccak_init(struct pgfe_keccak_base_ctx *ctx, uint32_t capacity);

void __pgfe_keccak_sponge_absorb_b1600(
    struct pgfe_keccak_base_ctx *ctx, const pgfe_encode_t input[], size_t input_length
);

void __pgfe_keccak_sponge_squeeze_b1600(struct pgfe_keccak_base_ctx *ctx, pgfe_encode_t output[], size_t output_length);

#ifdef __cplusplus
}
#endif

#endif