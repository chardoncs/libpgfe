#include "keccak-backend.h"

#include <limits.h>
#include <string.h>

#define __PGFE_K_b 1600
#define __PGFE_K_w 64

#define _cmod(x, y) ((x) % (y) + ((x) < 0 ? 5 : 0))

#define _b1600 1600

pgfe_keccak_lane64_t v_get(pgfe_keccak_lane64_t lane, uint32_t z);

void v_set(pgfe_keccak_lane64_t *lane, uint32_t z, pgfe_keccak_lane64_t val_lane, uint32_t z1);

uint32_t log2i(uint32_t n);

inline pgfe_keccak_lane64_t v_get(pgfe_keccak_lane64_t lane, uint32_t z) {
    return (lane >> (63 - z)) & 1;
}

inline void v_set(pgfe_keccak_lane64_t *lane, uint32_t z, pgfe_keccak_lane64_t val_lane, uint32_t z1) {
    *lane &= (val_lane << z1 >> z) | (z ? UINT64_MAX << (64 - z) : 0) | (z < 63 ? UINT64_MAX >> (z + 1) : 0);
}

inline uint32_t log2i(uint32_t n) {
    uint32_t i, pow = 1;

    for (i = 0; pow < n; i++) {
        pow *= 2;
    }

    return i - (pow > n);
}

void theta(pgfe_keccak_bitcube1600_t A, uint32_t w) {
    pgfe_keccak_lane64_t C[5], D[5];
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

    // Wipe sensitive data from RAM
    memset(C, 0, 40);
    memset(D, 0, 40);
}

void rho(pgfe_keccak_bitcube1600_t A, uint32_t w) {
    pgfe_keccak_bitcube1600_t A_out;
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

    memcpy(A, A_out, 200);

    // Wipe sensitive data from RAM
    memset(A_out, 0, 200);
}

void pi(pgfe_keccak_bitcube1600_t A, uint32_t w) {
    pgfe_keccak_bitcube1600_t A_out;
    int x, y;

    for (x = 0; x < 5; x++) {
        for (y = 0; y < 5; y++) {
            A_out[x][y] = A[(x + 3 * y) % 5][x];
        }
    }

    memcpy(A, A_out, 200);

    // Wipe sensitive data from RAM
    memset(A_out, 0, 200);
}

void chi(pgfe_keccak_bitcube1600_t A, uint32_t w) {
    pgfe_keccak_bitcube1600_t A_out;
    int x, y;

    for (x = 0; x < 5; x++) {
        for (y = 0; y < 5; y++) {
            A_out[x][y] = A[x][y] ^ (~A[(x + 1) % 5][y] & A[(x + 2) % 5][y]);
        }
    }

    memcpy(A, A_out, 200);

    // Wipe sensitive data from RAM
    memset(A_out, 0, 200);
}

uint8_t rc(int t) {
    int t_mod = _cmod(t, 255);

    if (!t_mod) return 1;

    uint16_t R = 0b10000000, b;
    int i;

    for (i = 0; i < t_mod; i++) {
        R &= 0b11111111;

        b = R & 1;
        R ^= (b << 8) | (b << 4) | (b << 3) | (b << 2);
        R >>= 1;
    }

    return (R >> 7) & 1;
}

void iota(pgfe_keccak_bitcube1600_t A, uint32_t w, int i_r) {
    uint64_t RC = 0, pow = 1;
    int j;

    for (j = 0; pow < w; j++, pow *= 2) {
        RC &= (((uint64_t)rc(j + 7 * i_r) | (UINT64_MAX << 1)) << (64 - pow)) | (UINT64_MAX >> pow);
        A[0][0] ^= RC;
    }

    // Wipe sensitive data from RAM
    RC = 0;
}

void transform(pgfe_keccak_bitcube1600_t A, uint32_t w, int i_r) {
    theta(A, w);
    rho(A, w);
    pi(A, w);
    chi(A, w);
    iota(A, w, i_r);
}

uint32_t pad101(uint32_t x, int64_t m, pgfe_encode_t output[]) {
    int j = _cmod(-m - 2, x), i;
    pgfe_encode_t *outp = output;

    for (i = -2; i < j;) {
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
        transform(A, w, i);
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
    struct pgfe_keccak_base_ctx *ctx, uint32_t capacity, const pgfe_encode_t input[], size_t input_length
) {
    pgfe_encode_t P[input_length + 256];
    uint32_t pad_len, n, r = _b1600 - capacity;
    size_t new_in_len = input_length;
    pgfe_encode_t P_seq[200], *S = ctx->S;
    int i, j;

    memcpy(P, input, input_length);
    pad_len = pad101(r, input_length, P + input_length);
    new_in_len += pad_len;
    n = new_in_len / to_byte(r);

    memset(P_seq, 0, 200);

    for (i = 0; i < n; i++) {
        memcpy(P_seq, &P[r * i], to_byte(r));

        for (j = 0; j < 200; j++) {
            S[j] ^= P_seq[j];
        }

        __pgfe_keccak_f_b1600(S, S);
    }
}

void __pgfe_keccak_sponge_squeeze_b1600(
    struct pgfe_keccak_base_ctx *ctx, uint32_t capacity, pgfe_encode_t output[], size_t output_length
) {
    uint32_t r = _b1600 - capacity;
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