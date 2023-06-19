/*
  libpgfe
  sha2-backend.c

  Copyright (c) 2022-2023 Charles Dong
*/

#include "./sha2-backend.h"

#include "./templates.h"
#include "libpgfe/hashes/sha2.h"

#include <string.h>

// SHA-224/256

void sha256_process_block(struct pgfe_sha256_ctx *ctx) {
    static const pgfe_word_t K[] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2,
    };

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

void sha224n256_padding(struct pgfe_sha256_ctx *ctx) {
    ctx->block[ctx->index++] = PADDING_HEADER;

    // 56 = PGFE_SHA256_BLOCK_SIZE - 8
    if (ctx->index > 56) {
        memset(ctx->block + ctx->index, 0, PGFE_SHA256_BLOCK_SIZE - ctx->index);
        ctx->index = PGFE_SHA256_BLOCK_SIZE;
        sha256_process_block(ctx);
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

    sha256_process_block(ctx);
}

void sha224n256_digest(struct pgfe_sha256_ctx *ctx, pgfe_encode_t output[], uint8_t digest_size) {
    if (!ctx || !output) return;

    size_t i;

    sha224n256_padding(ctx);

    // Write output
    for (i = 0; i < digest_size; i++) {
        output[i] = (pgfe_encode_t)(ctx->state[i >> 2] >> 8 * (3 - (i & 3)));
    }
}

// SHA-384/512

void sha384n512_process_block(struct pgfe_sha512_ctx *ctx) {
    static const pgfe_word_t K[] = {
        0xD728AE22, 0x428A2F98, 0x23EF65CD, 0x71374491, 0xEC4D3B2F, 0xB5C0FBCF, 0x8189DBBC, 0xE9B5DBA5, 0xF348B538,
        0x3956C25B, 0xB605D019, 0x59F111F1, 0xAF194F9B, 0x923F82A4, 0xDA6D8118, 0xAB1C5ED5, 0xA3030242, 0xD807AA98,
        0x45706FBE, 0x12835B01, 0x4EE4B28C, 0x243185BE, 0xD5FFB4E2, 0x550C7DC3, 0xF27B896F, 0x72BE5D74, 0x3B1696B1,
        0x80DEB1FE, 0x25C71235, 0x9BDC06A7, 0xCF692694, 0xC19BF174, 0x9EF14AD2, 0xE49B69C1, 0x384F25E3, 0xEFBE4786,
        0x8B8CD5B5, 0x0FC19DC6, 0x77AC9C65, 0x240CA1CC, 0x592B0275, 0x2DE92C6F, 0x6EA6E483, 0x4A7484AA, 0xBD41FBD4,
        0x5CB0A9DC, 0x831153B5, 0x76F988DA, 0xEE66DFAB, 0x983E5152, 0x2DB43210, 0xA831C66D, 0x98FB213F, 0xB00327C8,
        0xBEEF0EE4, 0xBF597FC7, 0x3DA88FC2, 0xC6E00BF3, 0x930AA725, 0xD5A79147, 0xE003826F, 0x06CA6351, 0x0A0E6E70,
        0x14292967, 0x46D22FFC, 0x27B70A85, 0x5C26C926, 0x2E1B2138, 0x5AC42AED, 0x4D2C6DFC, 0x9D95B3DF, 0x53380D13,
        0x8BAF63DE, 0x650A7354, 0x3C77B2A8, 0x766A0ABB, 0x47EDAEE6, 0x81C2C92E, 0x1482353B, 0x92722C85, 0x4CF10364,
        0xA2BFE8A1, 0xBC423001, 0xA81A664B, 0xD0F89791, 0xC24B8B70, 0x0654BE30, 0xC76C51A3, 0xD6EF5218, 0xD192E819,
        0x5565A910, 0xD6990624, 0x5771202A, 0xF40E3585, 0x32BBD1B8, 0x106AA070, 0xB8D2D0C8, 0x19A4C116, 0x5141AB53,
        0x1E376C08, 0xDF8EEB99, 0x2748774C, 0xE19B48A8, 0x34B0BCB5, 0xC5C95A63, 0x391C0CB3, 0xE3418ACB, 0x4ED8AA4A,
        0x7763E373, 0x5B9CCA4F, 0xD6B2B8A3, 0x682E6FF3, 0x5DEFB2FC, 0x748F82EE, 0x43172F60, 0x78A5636F, 0xA1F0AB72,
        0x84C87814, 0x1A6439EC, 0x8CC70208, 0x23631E28, 0x90BEFFFA, 0xDE82BDE9, 0xA4506CEB, 0xB2C67915, 0xBEF9A3F7,
        0xE372532B, 0xC67178F2, 0xEA26619C, 0xCA273ECE, 0x21C0C207, 0xD186B8C7, 0xCDE0EB1E, 0xEADA7DD6, 0xEE6ED178,
        0xF57D4F7F, 0x72176FBA, 0x06F067AA, 0xA2C898A6, 0x0A637DC5, 0xBEF90DAE, 0x113F9804, 0x131C471B, 0x1B710B35,
        0x23047D84, 0x28DB77F5, 0x40C72493, 0x32CAAB7B, 0x15C9BEBC, 0x3C9EBE0A, 0x9C100D4C, 0x431D67C4, 0xCB3E42B6,
        0x4CC5D4BE, 0xFC657E2A, 0x597F299C, 0x3AD6FAEC, 0x5FCB6FAB, 0x4A475817, 0x6C44198C,
    };

    int i, ix8, j;
    pgfe_word64_t tmp1, tmp2, tmp, ws[80], A, B, C, D, E, F, G, H;

    for (i = ix8 = 0; i < 16; i++, ix8 += 8) {
        ws[i] = 0;

        for (j = 0; j < 8; j++) {
            ws[i] |= (pgfe_word64_t)(ctx->block[ix8 + j]) << (56 - j * 8);
        }
    }

    for (; i < 80; i++) {
        ws[i] = sha512_sigma1(ws[i - 2]) + ws[i - 7] + sha512_sigma0(ws[i - 15]) + ws[i - 16];
    }

    A = ctx->state[0];
    B = ctx->state[1];
    C = ctx->state[2];
    D = ctx->state[3];
    E = ctx->state[4];
    F = ctx->state[5];
    G = ctx->state[6];
    H = ctx->state[7];

    for (i = 0; i < 80; i++) {
        memcpy(&tmp, &K[i * 2], 8);
        tmp1 = H + sha512_SIGMA1(E) + sha_ch(E, F, G) + ws[i] + tmp;

        tmp2 = sha512_SIGMA0(A) + sha_maj(A, B, C);
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

void sha384n512_update(struct pgfe_sha512_ctx *ctx, const pgfe_encode_t input[], size_t length) {
    if (!ctx || !input) return;

    const pgfe_encode_t *inp = input;
    int corrupt_flag = 0, tmpflag;
    uint64_t tmp_low;
    for (int i = 0; i < length && !corrupt_flag; i++) {
        ctx->block[ctx->index++] = *inp;

        tmp_low = ctx->len_low;
        ctx->len_low += 8;
        tmpflag = ctx->len_low < tmp_low;
        if (tmpflag) {
            ctx->len_high++;
            corrupt_flag = !ctx->len_high;
        }

        if (!corrupt_flag && ctx->index == PGFE_SHA512_BLOCK_SIZE) {
            sha384n512_process_block(ctx);
        }

        inp++;
    }
}

void sha384n512_padding(struct pgfe_sha512_ctx *ctx, pgfe_encode_t padding_byte) {
    ctx->block[ctx->index++] = padding_byte;

    // 112 = PGFE_SHA512_BLOCK_SIZE - 16
    if (ctx->index > 112) {
        memset(&ctx->block[ctx->index], 0, PGFE_SHA512_BLOCK_SIZE - ctx->index);
        ctx->index = PGFE_SHA512_BLOCK_SIZE;
        sha384n512_process_block(ctx);
    }
    else if (ctx->index < 112) {
        memset(&ctx->block[ctx->index], 0, 112 - ctx->index);
        ctx->index = 112;
    }

    ctx->block[112] = (uint8_t)(ctx->len_high >> 56);
    ctx->block[113] = (uint8_t)(ctx->len_high >> 48);
    ctx->block[114] = (uint8_t)(ctx->len_high >> 40);
    ctx->block[115] = (uint8_t)(ctx->len_high >> 32);
    ctx->block[116] = (uint8_t)(ctx->len_high >> 24);
    ctx->block[117] = (uint8_t)(ctx->len_high >> 16);
    ctx->block[118] = (uint8_t)(ctx->len_high >> 8);
    ctx->block[119] = (uint8_t)ctx->len_high;
    ctx->block[120] = (uint8_t)(ctx->len_low >> 56);
    ctx->block[121] = (uint8_t)(ctx->len_low >> 48);
    ctx->block[122] = (uint8_t)(ctx->len_low >> 40);
    ctx->block[123] = (uint8_t)(ctx->len_low >> 32);
    ctx->block[124] = (uint8_t)(ctx->len_low >> 24);
    ctx->block[125] = (uint8_t)(ctx->len_low >> 16);
    ctx->block[126] = (uint8_t)(ctx->len_low >> 8);
    ctx->block[127] = (uint8_t)ctx->len_low;

    sha384n512_process_block(ctx);
}

void sha384n512_digest(struct pgfe_sha512_ctx *ctx, pgfe_encode_t output[], uint8_t digest_size) {
    if (!ctx || !output) return;

    size_t i;

    sha384n512_padding(ctx, PADDING_HEADER);

    for (i = 0; i < digest_size; i++) {
        output[i] = (uint8_t)(ctx->state[i >> 3] >> (8 * (7 - (i % 8))));
    }
}