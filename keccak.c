#include "keccak.h"

#include <limits.h>
#include <string.h>

#define __PGFE_K_b 1600
#define __PGFE_K_w 64

#define _cmod(x, y) ((x) % (y) + ((x) < 0 ? 5 : 0))

pgfe_keccak_lane_t v_get(pgfe_keccak_lane_t lane, uint32_t z);

void v_set(pgfe_keccak_lane_t *lane, uint32_t z, pgfe_keccak_lane_t val_lane, uint32_t z1);

inline pgfe_keccak_lane_t v_get(pgfe_keccak_lane_t lane, uint32_t z) {
    return (lane >> (63 - z)) & 1;
}

inline void v_set(pgfe_keccak_lane_t *lane, uint32_t z, pgfe_keccak_lane_t val_lane, uint32_t z1) {
    *lane &= (val_lane << z1 >> z) | (z ? UINT64_MAX << (64 - z) : 0) | (z < 63 ? UINT64_MAX >> (z + 1) : 0);
}

void theta(pgfe_keccak_bitcube_t A, uint32_t w) {
    pgfe_keccak_lane_t C[5], D[5];
    int x, y;

    for (x = 0; x < 5; x++) {
        C[x] = A[x][0] ^ A[x][1] ^ A[x][2] ^ A[x][3] ^ A[x][4];
    }

    for (x = 0; x < 5; x++) {
        D[x] = C[(x - 1) % 5] ^ crshift(C[(x + 1) % 5], 1);
    }

    for (x = 0; x < 5; x++) {
        for (y = 0; y < 5; y++) {
            A[x][y] ^= D[x];
        }
    }
}

void rho(pgfe_keccak_bitcube_t A, uint32_t w) {
    pgfe_keccak_bitcube_t A_out;
    int x, y, z, t;

    x = 1;
    y = 0;

    for (t = 0; t < 24; t++) {
        for (z = 0; z < __PGFE_K_w; z++) {
            v_set(&A_out[x][y], z, A[x][y], _cmod(z - (t + 1) * (t + 2) / 2, w));
        }

        z = x;
        x = y;
        y = _cmod(2 * z + 3 * y, 5);
    }

    memcpy(A, A_out, sizeof(A));
}

void pi(pgfe_keccak_bitcube_t A, uint32_t w) {
    pgfe_keccak_bitcube_t A_out;
    int x, y;

    for (x = 0; x < 5; x++) {
        for (y = 0; y < 5; y++) {
            A_out[x][y] = A[(x + 3 * y) % 5][x];
        }
    }

    memcpy(A, A_out, sizeof(A));
}

void pgfe_keccak_init(struct pgfe_keccak_ctx *ctx, uint32_t capacity, uint32_t digest_length) {
    ctx->c = capacity;
    ctx->digsz = digest_length;
}