/*
  libpgfe
  sha1.c

  Copyright (c) 2022 Charles Dong
*/

#include "sha1.h"

#include "generic-internal.h"
#include "sha-internal.h"
#include "templates.c"

const pgfe_word_t __pgfe_sha1_H0[] = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0};

__PGFE_FRONTEND_GEN2(sha1)
__PGFE_FRONTEND_DEFAULT_GEN2(sha1, SHA1)

__PGFE_SHA_INIT(sha1)
__PGFE_SHA_UPDATE(sha1, SHA1)
__PGFE_SHA_DIGEST(sha1, SHA1)

void __pgfe_sha1_process_block(struct pgfe_sha1_ctx *ctx) {
    // Constants in SHA1
    static const pgfe_word_t K[] = {
        0x5A827999,
        0x6ED9EBA1,
        0x8F1BBCDC,
        0xCA62C1D6,
    };

    uint8_t i, ix4;
    pgfe_word_t tmp, ws[80], A, B, C, D, E;

    for (i = ix4 = 0; i < 16; i++, ix4 += 4) {
        ws[i] = (pgfe_word_t)ctx->block[ix4] << 24;
        ws[i] |= (pgfe_word_t)ctx->block[ix4 + 1] << 16;
        ws[i] |= (pgfe_word_t)ctx->block[ix4 + 2] << 8;
        ws[i] |= (pgfe_word_t)ctx->block[ix4 + 3];
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

    // Wipe sensitive data
    tmp = A = B = C = D = E = 0;
    memset(ws, 0, sizeof(ws));
}

void __pgfe_sha1_padding(struct pgfe_sha1_ctx *ctx) {
    ctx->block[ctx->index++] = __PGFE_PADDING_HEADER;

    // 56 = PGFE_SHA1_BLOCK_SIZE - 8
    if (ctx->index > 56) {
        memset(ctx->block + ctx->index, 0, PGFE_SHA1_BLOCK_SIZE - ctx->index);
        ctx->index = PGFE_SHA1_BLOCK_SIZE;
        __pgfe_sha1_process_block(ctx);
    }
    else if (ctx->index < 56) {
        memset(ctx->block + ctx->index, 0, 56 - ctx->index);
        ctx->index = 56;
    }

    ctx->block[56] = (uint8_t)(ctx->len_high >> 24);
    ctx->block[57] = (uint8_t)(ctx->len_high >> 16);
    ctx->block[58] = (uint8_t)(ctx->len_high >> 8);
    ctx->block[59] = (uint8_t)ctx->len_high;

    ctx->block[60] = (uint8_t)(ctx->len_low >> 24);
    ctx->block[61] = (uint8_t)(ctx->len_low >> 16);
    ctx->block[62] = (uint8_t)(ctx->len_low >> 8);
    ctx->block[63] = (uint8_t)ctx->len_low;

    __pgfe_sha1_process_block(ctx);
}