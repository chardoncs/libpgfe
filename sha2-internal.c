#include "sha2-internal.h"
#include "sha2.h"
#include "templates.c"

void __pgfe_sha256_process_block(struct pgfe_sha256_ctx *ctx) {
    static const pgfe_word_t K[] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

    size_t i, ix4;
    pgfe_word_t tmp1, tmp2, ws[PGFE_SHA256_BLOCK_SIZE], A, B, C, D, E, F, G, H;

    for (i = ix4 = 0; i < 16; i++, ix4 += 4) {
        ws[i] = ((pgfe_word_t)ctx->block[ix4]) << 24;
        ws[i] |= ((pgfe_word_t)ctx->block[ix4 + 1]) << 16;
        ws[i] |= ((pgfe_word_t)ctx->block[ix4 + 2]) << 8;
        ws[i] |= ((pgfe_word_t)ctx->block[ix4 + 3]);
    }

    for (; i < 64; i++) {
        ws[i] = sha256_sigma1(ws[i - 2]) + ws[i - 7] + sha256_sigma0(ws[i - 15]) + ws[i - 16];
    }

    A = ctx->state[0];
    B = ctx->state[1];
    C = ctx->state[2];
    D = ctx->state[3];
    E = ctx->state[4];
    F = ctx->state[5];
    G = ctx->state[6];
    H = ctx->state[7];

    for (i = 0; i < 64; i++) {
        tmp1 = H + sha256_SIGMA1(E) + sha_ch(E, F, G) + K[i] + ws[i];
        tmp2 = sha256_SIGMA0(A) + sha_maj(A, B, C);
        H = G;
        G = F;
        F = E;
        E = D + tmp1;
        D = C;
        C = B;
        B = A;
        A = tmp1 + tmp2;
    }

    ctx->state[0] += A;
    ctx->state[1] += B;
    ctx->state[2] += C;
    ctx->state[3] += D;
    ctx->state[4] += E;
    ctx->state[5] += F;
    ctx->state[6] += G;
    ctx->state[7] += H;

    ctx->index = 0;
}

void __pgfe_sha224n256_padding(struct pgfe_sha256_ctx *ctx) {
    ctx->block[ctx->index++] = __PGFE_PADDING_HEADER;

    // 56 = PGFE_SHA256_BLOCK_SIZE - 8
    if (ctx->index > 56) {
        memset(ctx->block + ctx->index, 0, PGFE_SHA256_BLOCK_SIZE - ctx->index);
        ctx->index = PGFE_SHA256_BLOCK_SIZE;
        __pgfe_sha256_process_block(ctx);
    }
    else if (ctx->index < 56) {
        memset(ctx->block + ctx->index, 0, 56 - ctx->index);
        ctx->index = 56;
    }

    ctx->block[56] = (uint8_t)(ctx->len_high >> 24);
    ctx->block[57] = (uint8_t)(ctx->len_high >> 16);
    ctx->block[58] = (uint8_t)(ctx->len_high >> 8);
    ctx->block[59] = (uint8_t)(ctx->len_high);

    ctx->block[60] = (uint8_t)(ctx->len_low >> 24);
    ctx->block[61] = (uint8_t)(ctx->len_low >> 16);
    ctx->block[62] = (uint8_t)(ctx->len_low >> 8);
    ctx->block[63] = (uint8_t)(ctx->len_low);

    __pgfe_sha256_process_block(ctx);
}

void __pgfe_sha224n256_digest(
    struct pgfe_sha256_ctx *ctx, pgfe_encode_t output[], size_t out_length, uint8_t digest_size
) {
    if (!ctx || !output) return;

    size_t i;

    __pgfe_sha224n256_padding(ctx);

    // Write output
    for (i = 0; i < out_length && i < digest_size; i++) {
        output[i] = (pgfe_encode_t)(ctx->state[i >> 2] >> 8 * (3 - (i & 3)));
    }

    // Wipe sensitive data from the RAM
    memset(ctx, 0, sizeof(*ctx));
}