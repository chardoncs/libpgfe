#include "sha1.h"

#include "generic-internal.h"

void pgfe_sha1_init(struct pgfe_sha1_ctx *ctx) {
    if (!ctx) return;

    ctx->len_low = ctx->len_high = 0;
    ctx->index = 0;

    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xEFCDAB89;
    ctx->state[2] = 0x98BADCFE;
    ctx->state[3] = 0x10325476;
    ctx->state[4] = 0xC3D2E1F0;
}

void pgfe_sha1_update(struct pgfe_sha1_ctx *ctx, const pgfe_encode_t input[], size_t length) {
    if (!length || !ctx || !input) return;

    pgfe_encode_t *inp = (pgfe_encode_t *)input;
    size_t i;
    int corrupt_flag = 0;

    for (i = 0; i < length && !corrupt_flag; i++) {
        ctx->block[ctx->index++] = (*inp & 0xFF);
        ctx->len_low += 8;
        if (!ctx->len_low) {
            ctx->len_high++;

            // Maybe removed later
            if (!ctx->len_high) {
                corrupt_flag = 1;
            }
        }

        // FIXME: Possible breakdown
        if (ctx->index == 64) {
            __pgfe_sha1_process_block(ctx);
        }

        inp++;
    }
}

void pgfe_sha1_digest(struct pgfe_sha1_ctx *ctx, pgfe_encode_t output[], size_t out_length) {
    if (!ctx || !output) return;

    int i;

    // Wipe data in the block
    __pgfe_sha1_padding(ctx);
    for (i = 0; i < PGFE_SHA1_BLOCK_SIZE; i++) {
        ctx->block[i] = 0;
    }
    ctx->len_low = ctx->len_high = 0;

    // Write output
    for (i = 0; i < out_length && i < PGFE_SHA1_DIGEST_SIZE; i++) {
        output[i] = ctx->state[i >> 2] >> 8 * (3 - (i & 3));
    }
}

void __pgfe_sha1_process_block(struct pgfe_sha1_ctx *ctx) {
    // Constants in SHA1
    static const pgfe_sha1_word_t K[] = {
        0x5A827999,
        0x6ED9EBA1,
        0x8F1BBCDC,
        0xCA62C1D6,
    };

    uint8_t i;
    pgfe_sha1_word_t tmp, ws[80], A, B, C, D, E;

    for (i = 0; i < 16; i++) {
        ws[i] = ctx->block[i * 4] << 24;
        ws[i] |= ctx->block[i * 4 + 1] << 16;
        ws[i] |= ctx->block[i * 4 + 2] << 8;
        ws[i] |= ctx->block[i * 4 + 3];
    }

    for (; i < 80; i++) {
        ws[i] = clshift(ws[i - 3] ^ ws[i - 8] ^ ws[i - 14] ^ ws[i - 16], 1);
    }

    A = ctx->state[0];
    B = ctx->state[1];
    C = ctx->state[2];
    D = ctx->state[3];
    E = ctx->state[4];

    for (i = 0; i < 20; i++) {
        tmp = clshift(A, 5) + ((B & C) | ((~B) & D)) + E + ws[i] + K[0];
        E = D;
        D = C;
        C = clshift(B, 30);
        B = A;
        A = tmp;
    }

    for (; i < 40; i++) {
        tmp = clshift(A, 5) + (B ^ C ^ D) + E + ws[i] + K[1];
        E = D;
        D = C;
        C = clshift(B, 30);
        B = A;
        A = tmp;
    }

    for (; i < 60; i++) {
        tmp = clshift(A, 5) + ((B & C) | (B & D) | (C & D)) + E + ws[i] + K[2];
        E = D;
        D = C;
        C = clshift(B, 30);
        B = A;
        A = tmp;
    }

    for (; i < 80; i++) {
        tmp = clshift(A, 5) + (B ^ C ^ D) + E + ws[i] + K[3];
        E = D;
        D = C;
        C = clshift(B, 30);
        B = A;
        A = tmp;
    }

    ctx->state[0] += A;
    ctx->state[1] += B;
    ctx->state[2] += C;
    ctx->state[3] += D;
    ctx->state[4] += E;

    ctx->index = 0;
}

void __pgfe_sha1_padding(struct pgfe_sha1_ctx *ctx) {
    ctx->block[ctx->index++] = 128;

    if (ctx->index > 56) {
        while (ctx->index < PGFE_SHA1_BLOCK_SIZE) {
            ctx->block[ctx->index++] = 0;
        }

        __pgfe_sha1_process_block(ctx);
    }

    while (ctx->index < 56) {
        ctx->block[ctx->index++] = 0;
    }

    ctx->block[56] = ctx->len_high >> 24;
    ctx->block[57] = ctx->len_high >> 16;
    ctx->block[58] = ctx->len_high >> 8;
    ctx->block[59] = ctx->len_high;

    ctx->block[60] = ctx->len_low >> 24;
    ctx->block[61] = ctx->len_low >> 16;
    ctx->block[62] = ctx->len_low >> 8;
    ctx->block[63] = ctx->len_low;

    __pgfe_sha1_process_block(ctx);
}