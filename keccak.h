#ifndef LIBPGFE_KECCAK_H
#define LIBPGFE_KECCAK_H

#include <stdint.h>

#include "generic-internal.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef uint64_t pgfe_keccak_lane_t;

typedef pgfe_keccak_lane_t pgfe_keccak_bitcube_t[5][5];

struct pgfe_keccak_ctx
{
    pgfe_keccak_bitcube_t state;
    uint32_t c, digsz;
};

void pgfe_keccak_init(struct pgfe_keccak_ctx *ctx, uint32_t capacity, uint32_t digest_length);

void pgfe_keccak_update(struct pgfe_keccak_ctx *ctx, const pgfe_encode_t input[], size_t length);

void pgfe_keccak_digest(struct pgfe_keccak_ctx *ctx, pgfe_encode_t output[], uint32_t out_length);

#ifdef __cplusplus
}
#endif

#endif