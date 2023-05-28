/*
  libpgfe
  sha224.c

  Copyright (c) 2022-2023 Charles Dong
*/

#include "libpgfe/core/hashes/sha2.h"

#include <string.h>

#include "./sha2-backend.h"
#include "./templates.h"

static const pgfe_word_t H0[] = {
    0xC1059ED8, 0x367CD507, 0x3070DD17, 0xF70E5939, 0xFFC00B31, 0x68581511, 0x64F98FA7, 0xBEFA4FA4,
};

FRONTEND_GEN2(sha224)
FRONTEND_GEN2_DEFAULT(sha224, SHA224)

SHA_INIT(sha224)
SHA_UPDATE(sha224, SHA224)

inline void pgfe_sha224_digest(struct pgfe_sha224_ctx *ctx, pgfe_encode_t output[]) {
    sha224n256_digest(ctx, output, PGFE_SHA224_DIGEST_SIZE);
}
