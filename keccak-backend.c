#include "keccak-backend.h"

#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define __PGFE_K_b __PGFE_KECCAK_b
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

void transform(pgfe_keccak_bitcube1600_t A, uint64_t RC) {
    pgfe_keccak_lane64_t C[5], D[5];
    pgfe_keccak_bitcube1600_t A2;
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
            A2[y][(2 * x + 3 * y) % 5] = clshift(A[x][y], _r[x][y]);
        }
    }

    // Chi
    for (x = 0; x < 5; x++) {
        for (y = 0; y < 5; y++) {
            A[x][y] = A2[x][y] ^ (~A2[(x + 1) % 5][y] & A2[(x + 2) % 5][y]);
        }
    }

    // Wipe sensitive data from RAM
    memset(A2, 0, 200);

    // Iota
    A[0][0] ^= RC;
}

int __pgfe_keccak_init(struct pgfe_keccak_sponge_ctx *ctx, uint32_t capacity) {
    if (capacity > _b1600) {
        return EXIT_FAILURE;
    }

    uint32_t r = _b1600 - capacity;

    if (r >= 1600 || r % 64) {
        return EXIT_FAILURE;
    }

    memset(ctx, 0, sizeof(*ctx));

    ctx->capacity = capacity;
    ctx->rate = r;
    ctx->nr = 24;

    return EXIT_SUCCESS;
}

void seq_to_state(const pgfe_encode_t input[], pgfe_keccak_bitcube1600_t A, uint32_t lane_count) {
    uint16_t x, y, idx;
    int i;
    const pgfe_encode_t *inp = input;

    idx = 0;
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 5; x++) {
            for (i = 56; i >= 0; i -= 8) {
                A[x][y] ^= (uint64_t)(*(inp++)) << i;
            }

            if (++idx >= lane_count) {
                goto __seq_to_state_end;
            }
        }
    }

__seq_to_state_end:;
}

void permutation(struct pgfe_keccak_sponge_ctx *ctx) {
    for (uint16_t i = 0; i < ctx->nr; i++) {
        transform(ctx->state, _RC[i]);
    }
}

void state_to_seq(const pgfe_keccak_bitcube1600_t A, pgfe_encode_t output[], uint32_t lane_count) {
    uint16_t x, y, idx;
    int i;
    pgfe_encode_t *outp = output;

    idx = 0;
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 5; x++) {
            for (i = 56; i >= 0; i -= 8) {
                *(outp++) = (pgfe_encode_t)(A[x][y] >> i);
            }

            if (++idx >= lane_count) {
                goto __state_to_seq_end;
            }
        }
    }

__state_to_seq_end:;
}

void absorb_queue(struct pgfe_keccak_sponge_ctx *ctx) {
    seq_to_state(ctx->data_queue, ctx->state, ctx->rate / 64);
    permutation(ctx);

    ctx->inqueue_bits = 0;
}

void padding(struct pgfe_keccak_sponge_ctx *ctx) {
    if (ctx->inqueue_bits + 1 == ctx->rate) {
        ctx->data_queue[to_byte(ctx->inqueue_bits)] |= 1 << (ctx->inqueue_bits % 8);
        absorb_queue(ctx);
        memset(ctx->data_queue, 0, to_byte(ctx->rate));
    }
    else {
        memset(
            ctx->data_queue + to_byte(ctx->inqueue_bits + 7), 0, to_byte(ctx->rate) - to_byte(ctx->inqueue_bits + 7)
        );
        ctx->data_queue[to_byte(ctx->inqueue_bits)] |= 1 << (ctx->inqueue_bits % 8);
    }

    ctx->data_queue[to_byte(ctx->rate - 1)] |= 1 << ((ctx->rate - 1) % 8);
    absorb_queue(ctx);

    state_to_seq(ctx->state, ctx->data_queue, ctx->rate / 64);
    ctx->squeezable = ctx->rate;
    ctx->squeezing = 1;
}

int __pgfe_keccak_absorb_b1600(struct pgfe_keccak_sponge_ctx *ctx, const pgfe_encode_t input[], size_t input_length) {
    uint64_t i, j, whole_blocks, bit_len = to_bit((uint64_t)input_length);
    uint32_t partial_block, partial_byte, rate_byte = to_byte(ctx->rate);
    uint8_t mask;
    const pgfe_encode_t *cur_data;

    if (ctx->inqueue_bits % 8 || ctx->squeezing) {
        return EXIT_FAILURE;
    }

    for (i = 0; i < bit_len;) {
        if (!ctx->inqueue_bits && bit_len >= ctx->rate && i <= bit_len - ctx->rate) {
            whole_blocks = (bit_len - i) / ctx->rate;
            cur_data = input + to_byte(i);

            for (j = 0; j < whole_blocks; j++, cur_data += to_byte(ctx->rate)) {
                seq_to_state(cur_data, ctx->state, ctx->rate / 64);
                permutation(ctx);
            }
            i += whole_blocks * ctx->rate;
        }
        else {
            partial_block = (uint32_t)(bit_len - i);
            if (partial_block + ctx->inqueue_bits > ctx->rate) {
                partial_block = ctx->rate - ctx->inqueue_bits;
            }

            partial_byte = partial_block % 8;
            partial_block -= partial_byte;
            memcpy(ctx->data_queue + to_byte(ctx->inqueue_bits), input + to_byte(i), to_byte(partial_block));
            ctx->inqueue_bits += partial_block;
            i += partial_block;
            if (ctx->inqueue_bits == ctx->rate) {
                absorb_queue(ctx);
            }

            if (partial_byte) {
                mask = (1 << partial_byte) - 1;
                ctx->data_queue[to_byte(ctx->inqueue_bits)] = input[to_byte(i)] & mask;
                ctx->inqueue_bits += partial_byte;
                i += partial_byte;
            }
        }
    }

    return EXIT_SUCCESS;
}

int __pgfe_keccak_squeeze_b1600(struct pgfe_keccak_sponge_ctx *ctx, pgfe_encode_t output[], size_t output_length) {
    uint64_t i, bit_len = to_bit((uint64_t)output_length);
    uint32_t partial_block;

    if (!ctx->squeezing) {
        padding(ctx);
    }

    if (bit_len % 8) return EXIT_FAILURE;

    for (i = 0; i < bit_len;) {
        if (!ctx->squeezable) {
            permutation(ctx);
            state_to_seq(ctx->state, ctx->data_queue, ctx->rate / 64);
            ctx->squeezable = ctx->rate;
        }

        partial_block = ctx->squeezable;
        if ((uint64_t)partial_block > bit_len - i) {
            partial_block = (uint32_t)(bit_len - i);
        }

        memcpy(output + to_byte(i), ctx->data_queue + to_byte(ctx->rate - ctx->squeezable), to_byte(partial_block));
        ctx->squeezable -= partial_block;
        i += partial_block;
    }

    return EXIT_SUCCESS;
}
