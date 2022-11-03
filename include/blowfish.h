#ifndef LIBPGFE_BLOWFISH_H
#define LIBPGFE_BLOWFISH_H
#ifdef __cplusplus
extern "C" {
#endif

#include "backend/generic-internal.h"

#define __PGFE_BF_N 16
#define __PGFE_BF_Np2 18
#define __PGFE_BF_S_ROW 4
#define __PGFE_BF_S_ENTRY 256

typedef uint32_t pgfe_blowfish_block_t;

struct pgfe_blowfish_ctx
{
    pgfe_blowfish_block_t P[__PGFE_BF_Np2], S[__PGFE_BF_S_ROW][__PGFE_BF_S_ENTRY];
};

void pgfe_blowfish_init(struct pgfe_blowfish_ctx *ctx, pgfe_encode_t key[], size_t key_length);

void pgfe_blowfish_encrypt_unit(const struct pgfe_blowfish_ctx *ctx, pgfe_fake_uint64_t *input);

void pgfe_blowfish_decrypt_unit(const struct pgfe_blowfish_ctx *ctx, pgfe_fake_uint64_t *input);

size_t pgfe_blowfish_encrypt(
    const struct pgfe_blowfish_ctx *ctx, const pgfe_encode_t input[], size_t length, pgfe_encode_t output[]
);

size_t pgfe_blowfish_decrypt(
    const struct pgfe_blowfish_ctx *ctx, const pgfe_encode_t input[], size_t length, pgfe_encode_t output[]
);

#ifdef __cplusplus
}
#endif
#endif