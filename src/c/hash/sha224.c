/*
  libpgfe
  sha224.c

  Copyright (c) 2022 Charles Dong
*/

#include "sha2.h"

#include "backend/sha2-backend.h"
#include "backend/templates.h"

const pgfe_word_t __pgfe_sha224_H0[] = {0xC1059ED8, 0x367CD507, 0x3070DD17, 0xF70E5939,
                                        0xFFC00B31, 0x68581511, 0x64F98FA7, 0xBEFA4FA4};

__PGFE_FRONTEND_GEN2(sha224)
__PGFE_FRONTEND_DEFAULT_GEN2(sha224, SHA224)

__PGFE_SHA_INIT(sha224)
__PGFE_SHA_UPDATE(sha224, SHA224)

inline void pgfe_sha224_digest(struct pgfe_sha224_ctx *ctx, pgfe_encode_t output[]) {
    __pgfe_sha224n256_digest(ctx, output, PGFE_SHA224_DIGEST_SIZE);
}
