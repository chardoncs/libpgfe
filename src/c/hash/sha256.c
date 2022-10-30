/*
  libpgfe
  sha256.c

  Copyright (c) 2022 Charles Dong
*/

#include "sha2.h"

#include "backend/sha2-backend.h"
#include "backend/templates.h"

const pgfe_word_t __pgfe_sha256_H0[] = {0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A,
                                        0x510E527F, 0x9B05688C, 0x1F83D9AB, 0x5BE0CD19};

__PGFE_FRONTEND_GEN2(sha256)
__PGFE_FRONTEND_DEFAULT_GEN2(sha256, SHA256)

__PGFE_SHA_INIT(sha256)
__PGFE_SHA_UPDATE(sha256, SHA256)

inline void pgfe_sha256_digest(struct pgfe_sha256_ctx *ctx, pgfe_encode_t output[]) {
    __pgfe_sha224n256_digest(ctx, output, PGFE_SHA256_DIGEST_SIZE);
}