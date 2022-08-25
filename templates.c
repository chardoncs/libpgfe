/*
  libpgfe
  templates.c

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_TEMPLATES_C
#define LIBPGFE_TEMPLATES_C

#ifdef __cplusplus
extern "C" {
#endif

#define __PGFE_FRONTEND_GEN(func_name, nettle_name)                                                                    \
    void pgfe_##func_name##_encode(                                                                                    \
        const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length                           \
    ) {                                                                                                                \
        struct nettle_name##_ctx ctx;                                                                                  \
                                                                                                                       \
        nettle_name##_init(&ctx);                                                                                      \
        nettle_name##_update(&ctx, length, data);                                                                      \
                                                                                                                       \
        nettle_name##_digest(&ctx, out_length, output);                                                                \
    }                                                                                                                  \
                                                                                                                       \
    void pgfe_##func_name##_encode_f(FILE *fp, pgfe_encode_t output[], size_t length) {                                \
        pgfe_encode_t buf[PGFE_BUFFER_SIZE];                                                                           \
        size_t size;                                                                                                   \
                                                                                                                       \
        struct nettle_name##_ctx ctx;                                                                                  \
                                                                                                                       \
        nettle_name##_init(&ctx);                                                                                      \
                                                                                                                       \
        do {                                                                                                           \
            size = fread(buf, 1, PGFE_BUFFER_SIZE, fp);                                                                \
            nettle_name##_update(&ctx, size, buf);                                                                     \
        } while (size >= PGFE_BUFFER_SIZE);                                                                            \
                                                                                                                       \
        nettle_name##_digest(&ctx, length, output);                                                                    \
    }                                                                                                                  \
    void pgfe_##func_name##_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...) {          \
        va_list vl;                                                                                                    \
        va_start(vl, input_c);                                                                                         \
                                                                                                                       \
        struct nettle_name##_ctx ctx;                                                                                  \
        pgfe_encode_t *input;                                                                                          \
        size_t input_s;                                                                                                \
                                                                                                                       \
        nettle_name##_init(&ctx);                                                                                      \
                                                                                                                       \
        for (int i = 0; i < input_c; i++) {                                                                            \
            input = va_arg(vl, pgfe_encode_t *);                                                                       \
            input_s = va_arg(vl, size_t);                                                                              \
            if (!input) continue;                                                                                      \
                                                                                                                       \
            nettle_name##_update(&ctx, input_s, input);                                                                \
        }                                                                                                              \
                                                                                                                       \
        va_end(vl);                                                                                                    \
        nettle_name##_digest(&ctx, out_length, output);                                                                \
    }

#define __PGFE_FRONTEND_DEFAULT_GEN(func, macro_n)                                                                     \
    inline void pgfe_##func##_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]) {                 \
        pgfe_##func##_encode(data_str, strlen((char *)data_str), output, macro_n);                                     \
    }                                                                                                                  \
                                                                                                                       \
    inline void pgfe_##func##_encode_default_f(FILE *fp, pgfe_encode_t output[]) {                                     \
        pgfe_##func##_encode_f(fp, output, macro_n);                                                                   \
    }

#ifdef __cplusplus
}
#endif

#endif