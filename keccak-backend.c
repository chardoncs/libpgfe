/*
  libpgfe
  keccak-backend.c

  Copyright (c) 2022 Charles Dong
*/

#include "keccak-backend.h"

#include <stdlib.h>
#include <string.h>

#define _cmod(x, y) ((x) % (y) + ((x) < 0 ? (y) : 0))

const uint16_t _r[24] = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 2, 14, 27, 41, 56, 8, 25, 43, 62, 18, 39, 61, 20, 44};

const uint64_t _RC[24] = {0x0000000000000001, 0x0000000000008082, 0x800000000000808a, 0x8000000080008000,
                          0x000000000000808b, 0x0000000080000001, 0x8000000080008081, 0x8000000000008009,
                          0x000000000000008a, 0x0000000000000088, 0x0000000080008009, 0x000000008000000a,
                          0x000000008000808b, 0x800000000000008b, 0x8000000000008089, 0x8000000000008003,
                          0x8000000000008002, 0x8000000000000080, 0x000000000000800a, 0x800000008000000a,
                          0x8000000080008081, 0x8000000000008080, 0x0000000080000001, 0x8000000080008008};

const uint16_t _piln[24] = {10, 7, 11, 17, 18, 3, 5, 16, 8, 21, 24, 4, 15, 23, 19, 13, 12, 2, 20, 14, 22, 9, 6, 1};

void transform(pgfe_keccak_bitcube_t A, uint64_t RC) {
    pgfe_keccak_lane_t C[5];
    uint64_t t;
    uint16_t j;
    int x, y, z;

    // Theta
    for (x = 0; x < 5; x++) {
        C[x] = A[x][0] ^ A[x][1] ^ A[x][2] ^ A[x][3] ^ A[x][4];
    }

    for (x = 0; x < 5; x++) {
        t = C[(x + 4) % 5] ^ clshift(C[(x + 1) % 5], 1);
        for (y = 0; y < 5; y++) {
            A[x][y] ^= t;
        }
    }

    // Rho & Pi
    t = A[1][0];
    for (x = 0; x < 24; x++) {
        j = _piln[x];
        C[0] = A[j % 5][j / 5];
        A[j % 5][j / 5] = clshift(t, _r[x]);
        t = C[0];
    }

    // Chi
    for (y = 0; y < 5; y++) {
        for (x = 0; x < 5; x++) {
            C[x] = A[x][y];
        }
        for (x = 0; x < 5; x++) {
            A[x][y] ^= ~C[(x + 1) % 5] & C[(x + 2) % 5];
        }
    }

    // Wipe sensitive data from RAM
    memset(C, 0, 40);

    // Iota
    A[0][0] ^= RC;
}

int __pgfe_keccak_init(struct pgfe_keccak_sponge_ctx *ctx, uint32_t capacity) {
    uint32_t r = __PGFE_KECCAK_b - capacity;

    if (r >= __PGFE_KECCAK_b || r % 64) {
        return EXIT_FAILURE;
    }

    memset(ctx, 0, sizeof(*ctx));

    ctx->capacity = capacity;
    ctx->rate = r;
    ctx->nr = 24;

    return EXIT_SUCCESS;
}

void seq_to_state(const pgfe_encode_t input[], pgfe_keccak_bitcube_t A, size_t length) {
    pgfe_keccak_lane_t tmp;
    static const uint16_t lane_size = sizeof(pgfe_keccak_lane_t);
    int x, y;
    size_t i = 0;

    for (y = 0; y < 5; y++) {
        for (x = 0; x < 5; x++) {
            memcpy(&tmp, &input[i], lane_size);
            A[x][y] ^= tmp;
            i += lane_size;

            if (i >= length) {
                goto seq_to_state_jump_end;
            }
        }
    }

seq_to_state_jump_end:;
}

void permutation(pgfe_keccak_bitcube_t A, uint16_t nr) {
    for (uint16_t i = 0; i < nr; i++) {
        transform(A, _RC[i]);
    }
}

void state_to_seq(const pgfe_keccak_bitcube_t A, pgfe_encode_t output[], uint32_t lane_count) {
    pgfe_encode_t *outp = output;
    static const uint16_t lane_size = sizeof(pgfe_keccak_lane_t);
    int x, y, i = 0;

    for (y = 0; y < 5; y++) {
        for (x = 0; x < 5; x++) {
            memcpy(outp, &A[x][y], lane_size);
            outp += lane_size;

            if (++i >= lane_count) {
                goto state_to_seq_jump_end;
            }
        }
    }

state_to_seq_jump_end:;
}

void absorb(pgfe_keccak_bitcube_t state, const pgfe_encode_t input[], uint32_t lane_count, uint16_t nr) {
    seq_to_state(input, state, lane_count * 8);
    // For little endian
    permutation(state, nr);
}

void absorb_queue(struct pgfe_keccak_sponge_ctx *ctx) {
    absorb(ctx->state, ctx->data_queue, ctx->rate / 64, ctx->nr);
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

int __pgfe_keccak_absorb_b1600(struct pgfe_keccak_sponge_ctx *ctx, const pgfe_encode_t input[], uint64_t bit_len) {
    uint64_t i, j, whole_blocks;
    uint32_t partial_block, partial_byte;
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
                absorb(ctx->state, cur_data, ctx->rate / 64, ctx->nr);
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

int __pgfe_keccak_squeeze_b1600(struct pgfe_keccak_sponge_ctx *ctx, pgfe_encode_t output[]) {
    uint64_t i, bit_len = ctx->out_length;
    uint32_t partial_block;

    if (ctx->ap_len) {
        __pgfe_keccak_absorb_b1600(ctx, &ctx->ap, ctx->ap_len);
    }

    if (!ctx->squeezing) {
        padding(ctx);
    }

    for (i = 0; i < bit_len;) {
        if (!ctx->squeezable) {
            permutation(ctx->state, ctx->nr);
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
