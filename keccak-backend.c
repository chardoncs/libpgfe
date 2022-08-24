#include "keccak-backend.h"

#include <limits.h>
#include <string.h>

#define __PGFE_K_b 1600
#define __PGFE_K_w 64

#define _cmod(x, y) ((x) % (y) + ((x) < 0 ? (y) : 0))

#define _b1600 1600

const uint64_t _r[5][5] = {
    {0,  36, 3,  41, 18},
    {1,  44, 10, 45, 2 },
    {62, 6,  43, 15, 61},
    {28, 55, 25, 21, 56},
    {27, 20, 39, 8,  14},
};

const uint64_t _RC[24] = {0x0000000000000001, 0x0000000000008082, 0x800000000000808A, 0x8000000080008000,
                          0x000000000000808B, 0x0000000080000001, 0x8000000080008081, 0x8000000000008009,
                          0x000000000000008A, 0x0000000000000088, 0x0000000080008009, 0x000000008000000A,
                          0x000000008000808B, 0x800000000000008B, 0x8000000000008089, 0x8000000000008003,
                          0x8000000000008002, 0x8000000000000080, 0x000000000000800A, 0x800000008000000A,
                          0x8000000080008081, 0x8000000000008080, 0x0000000080000001, 0x8000000080008008};

pgfe_keccak_lane64_t v_get(pgfe_keccak_lane64_t lane, uint32_t z);
void v_set(pgfe_keccak_lane64_t *lane, uint32_t z, pgfe_keccak_lane64_t val_lane, uint32_t z1);
uint32_t log2i(uint32_t n);

inline pgfe_keccak_lane64_t v_get(pgfe_keccak_lane64_t lane, uint32_t z) {
    return (lane >> (63 - z)) & 1;
}

inline void v_set(pgfe_keccak_lane64_t *lane, uint32_t z, pgfe_keccak_lane64_t val_lane, uint32_t z1) {
    *lane ^= (((*lane >> (63 - z)) & 1) ^ ((val_lane >> (63 - z1)) & 1)) << (63 - z);
}

inline uint32_t log2i(uint32_t n) {
    uint32_t i, pow = 1;

    for (i = 0; pow < n; i++) {
        pow *= 2;
    }

    return i - (pow > n);
}

void transform(pgfe_keccak_bitcube1600_t A, uint32_t w, uint64_t RC) {
    pgfe_keccak_lane64_t C[5], D[5];
    pgfe_keccak_bitcube1600_t A_out;
    int x, y, z, t;

    // Theta
    for (x = 0; x < 5; x++) {
        C[x] = A[x][0] ^ A[x][1] ^ A[x][2] ^ A[x][3] ^ A[x][4];
    }

    for (x = 0; x < 5; x++) {
        D[x] = C[(x + 4) % 5] ^ clshift(C[(x + 1) % 5], 1);
    }

    for (x = 0; x < 5; x++) {
        for (y = 0; y < 5; y++) {
            A[x][y] ^= D[x];
        }
    }

    // Wipe sensitive data from RAM
    memset(C, 0, 40);
    memset(D, 0, 40);

    // Rho & Pi
    for (x = 0; x < 5; x++) {
        for (y = 0; y < 5; y++) {
            A_out[y][_cmod(2 * x + 3 * y, 5)] = clshift(A[x][y], _r[x][y]);
        }
    }

    // Chi
    for (x = 0; x < 5; x++) {
        for (y = 0; y < 5; y++) {
            A[x][y] = A_out[x][y] ^ (~A_out[(x + 1) % 5][y] & A_out[(x + 2) % 5][y]);
        }
    }

    // Wipe sensitive data from RAM
    memset(A_out, 0, 200);

    // Iota
    A[0][0] ^= RC;
}

uint32_t pad101(uint32_t x, int64_t m, pgfe_encode_t output[]) {
    int j = _cmod(-m - 2, x), i;
    pgfe_encode_t *outp = output;

    for (i = -2; i < j; outp++) {
        *outp = 0;

        i += 8;
        if (i >= j) {
            *outp |= 1 << (i - j);
        }

        if (i == 6) {
            *outp |= 0b10000000;
        }
    }

    return j + 2;
}

void __pgfe_keccak_p_b1600(uint32_t nr, const pgfe_encode_t *input, pgfe_encode_t *output) {
    const pgfe_encode_t *inp = input;
    pgfe_encode_t *outp = output;
    pgfe_keccak_bitcube1600_t A;
    int x, y, i;
    static const uint32_t w = 64, l = 6;

    // Convert input into the state array
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 5; x++) {
            A[x][y] = 0;

            for (i = 56; i >= 0; i -= 8) {
                A[x][y] |= (uint64_t)(*(inp++)) << i;
            }
        }
    }

    // Transform n_r rounds
    for (i = 12 + 2 * l - nr; i < 12 + 2 * l; i++) {
        transform(A, w, _RC[i]);
    }

    // Retrieve result from the state array
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 5; x++) {
            for (i = 56; i >= 0; i -= 8) {
                *(outp++) = (pgfe_encode_t)(A[x][y] >> i);
            }
        }
    }

    // Wipe sensitive data from RAM
    memset(A, 0, 200);
}

void __pgfe_keccak_sponge_absorb_b1600(
    struct pgfe_keccak_base_ctx *ctx, const pgfe_encode_t input[], size_t input_length
) {
    pgfe_encode_t P[input_length + 256], P_seq[200], *S = ctx->S;
    uint32_t pad_len, r = _b1600 - ctx->capacity;
    uint64_t n;
    size_t new_in_len = input_length;
    int i, j;

    memcpy(P, input, input_length + 256);
    pad_len = pad101(r, input_length, P + input_length);
    new_in_len += to_byte(pad_len);
    n = to_bit(new_in_len / to_byte(r));

    memset(P_seq, 0, 200);

    for (i = 0; i < n; i++) {
        memcpy(P_seq, &P[to_byte(r * i)], to_byte(r));

        for (j = 0; j < 200; j++) {
            S[j] ^= P_seq[j];
        }

        __pgfe_keccak_f_b1600(S, S);
    }
}

void __pgfe_keccak_sponge_squeeze_b1600(
    struct pgfe_keccak_base_ctx *ctx, pgfe_encode_t output[], size_t output_length
) {
    uint32_t r = _b1600 - ctx->capacity;
    pgfe_encode_t *S = ctx->S, *outp;

    __pgfe_loop {
        memcpy(outp, S, to_byte(r));
        outp += to_byte(r);

        if (output_length <= outp - output) {
            break;
        }

        __pgfe_keccak_f_b1600(S, S);
    }
}

void __pgfe_keccak_init(struct pgfe_keccak_base_ctx *ctx, uint32_t capacity) {
    memset(ctx, 0, sizeof(*ctx));
    ctx->capacity = capacity;
}