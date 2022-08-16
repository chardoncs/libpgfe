#ifndef LIBPGFE_TEMPLATES_H
#define LIBPGFE_TEMPLATES_H

#ifdef __cplusplus
extern "C" {
#endif

#define __PGFE_FRONTEND_GEN(func_name, nettle_name)                                                                    \
    void pgfe_##func_name##_encode(const pgfe_encode_t input_string[], pgfe_encode_t output[], const size_t length) {  \
        struct nettle_name##_ctx ctx;                                                                                  \
                                                                                                                       \
        nettle_name##_init(&ctx);                                                                                      \
        nettle_name##_update(&ctx, strlen((const char *)input_string), input_string);                                  \
                                                                                                                       \
        nettle_name##_digest(&ctx, length, output);                                                                    \
    }                                                                                                                  \
                                                                                                                       \
    void pgfe_##func_name##_encode_f(FILE *fp, pgfe_encode_t output[], const size_t length) {                          \
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
    }

#define __PGFE_FRONTEND_DEFAULT_GEN(func, macro_n)                                                                     \
    inline void pgfe_##func##_encode_default(const pgfe_encode_t input_string[], pgfe_encode_t output[]) {             \
        pgfe_##func##_encode(input_string, output, macro_n);                                                           \
    }                                                                                                                  \
                                                                                                                       \
    inline void pgfe_##func##_encode_default_f(FILE *fp, pgfe_encode_t output[]) {                                     \
        pgfe_##func##_encode_f(fp, output, macro_n);                                                                   \
    }

#ifdef __cplusplus
}
#endif

#endif