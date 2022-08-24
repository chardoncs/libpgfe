/*
  libpgfe
  templates.c

  Copyright (C) 2022 Charles Dong

  libpgfe is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
*/

#ifndef LIBPGFE_TEMPLATES_C
#define LIBPGFE_TEMPLATES_C

#ifdef __cplusplus
extern "C" {
#endif

// NATIVE HASH BACKEND

#define __PGFE_FRONTEND_GEN2(name)                                                                                     \
    void pgfe_##name##_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]) {                     \
        struct pgfe_##name##_ctx ctx;                                                                                  \
                                                                                                                       \
        pgfe_##name##_init(&ctx);                                                                                      \
        pgfe_##name##_update(&ctx, data, length);                                                                      \
                                                                                                                       \
        pgfe_##name##_digest(&ctx, output);                                                                            \
    }                                                                                                                  \
                                                                                                                       \
    void pgfe_##name##_encode_f(FILE *fp, pgfe_encode_t output[]) {                                                    \
        pgfe_encode_t buf[PGFE_BUFFER_SIZE];                                                                           \
        size_t size;                                                                                                   \
                                                                                                                       \
        struct pgfe_##name##_ctx ctx;                                                                                  \
                                                                                                                       \
        pgfe_##name##_init(&ctx);                                                                                      \
                                                                                                                       \
        do {                                                                                                           \
            size = fread(buf, 1, PGFE_BUFFER_SIZE, fp);                                                                \
            pgfe_##name##_update(&ctx, buf, size);                                                                     \
        } while (size >= PGFE_BUFFER_SIZE);                                                                            \
                                                                                                                       \
        pgfe_##name##_digest(&ctx, output);                                                                            \
    }                                                                                                                  \
    void pgfe_##name##_encode_multiple(pgfe_encode_t output[], size_t input_c, ...) {                                  \
        va_list vl;                                                                                                    \
        va_start(vl, input_c);                                                                                         \
                                                                                                                       \
        struct pgfe_##name##_ctx ctx;                                                                                  \
        pgfe_encode_t *input;                                                                                          \
        size_t input_s;                                                                                                \
                                                                                                                       \
        pgfe_##name##_init(&ctx);                                                                                      \
                                                                                                                       \
        for (int i = 0; i < input_c; i++) {                                                                            \
            input = va_arg(vl, pgfe_encode_t *);                                                                       \
            input_s = va_arg(vl, size_t);                                                                              \
            if (!input) continue;                                                                                      \
                                                                                                                       \
            pgfe_##name##_update(&ctx, input, input_s);                                                                \
        }                                                                                                              \
                                                                                                                       \
        va_end(vl);                                                                                                    \
        pgfe_##name##_digest(&ctx, output);                                                                            \
    }

#define __PGFE_FRONTEND_DEFAULT_GEN2(name, upper)                                                                      \
    inline void pgfe_##name##_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]) {                 \
        pgfe_##name##_encode(data_str, strlen((char *)data_str), output);                                              \
    }

#define __PGFE_SHA_INIT(name)                                                                                          \
    void pgfe_##name##_init(struct pgfe_##name##_ctx *ctx) {                                                           \
        if (!ctx) return;                                                                                              \
                                                                                                                       \
        ctx->len_low = ctx->len_high = 0;                                                                              \
        ctx->index = 0;                                                                                                \
                                                                                                                       \
        memcpy(ctx->state, __pgfe_##name##_H0, sizeof(__pgfe_##name##_H0));                                            \
    }

#define __PGFE_SHA_UPDATE(name, upper)                                                                                 \
    void pgfe_##name##_update(struct pgfe_##name##_ctx *ctx, const pgfe_encode_t input[], size_t length) {             \
        if (!ctx || !input) return;                                                                                    \
                                                                                                                       \
        const pgfe_encode_t *inp = input;                                                                              \
        int corrupt_flag = 0;                                                                                          \
        uint32_t tmp_low;                                                                                              \
        for (int i = 0; i < length && !corrupt_flag; i++) {                                                            \
            ctx->block[ctx->index++] = *inp;                                                                           \
                                                                                                                       \
            tmp_low = ctx->len_low;                                                                                    \
            ctx->len_low += 8;                                                                                         \
            corrupt_flag = ctx->len_low < tmp_low && !(++ctx->len_high);                                               \
                                                                                                                       \
            if (!corrupt_flag && ctx->index == PGFE_##upper##_BLOCK_SIZE) {                                            \
                __pgfe_##name##_process_block(ctx);                                                                    \
            }                                                                                                          \
                                                                                                                       \
            inp++;                                                                                                     \
        }                                                                                                              \
    }

#define __PGFE_SHA_DIGEST(name, upper)                                                                                 \
    void pgfe_##name##_digest(struct pgfe_##name##_ctx *ctx, pgfe_encode_t output[]) {                                 \
        if (!ctx || !output) return;                                                                                   \
                                                                                                                       \
        size_t i;                                                                                                      \
                                                                                                                       \
        __pgfe_##name##_padding(ctx);                                                                                  \
                                                                                                                       \
        /* Wipe stored data */                                                                                         \
        memset(ctx->block, 0, sizeof(ctx->block));                                                                     \
        ctx->len_high = ctx->len_low = 0;                                                                              \
                                                                                                                       \
        /* Write output */                                                                                             \
        for (i = 0; i < PGFE_##upper##_DIGEST_SIZE; i++) {                                                             \
            output[i] = (pgfe_encode_t)(ctx->state[i >> 2] >> 8 * (3 - (i & 3)));                                      \
        }                                                                                                              \
    }

#ifdef __cplusplus
}
#endif

#endif