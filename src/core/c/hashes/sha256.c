/*
  libpgfe
  sha256.c

  Copyright (c) 2022-2023 Charles Dong
*/

#include "libpgfe/core/hashes/sha2.h"

#include <string.h>

#include "./sha2-backend.h"
#include "./templates.h"

static const pgfe_word_t H0[] = {
    0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A, 0x510E527F, 0x9B05688C, 0x1F83D9AB, 0x5BE0CD19,
};

FRONTEND_GEN2(sha256)
FRONTEND_GEN2_DEFAULT(sha256, SHA256)

SHA_INIT(sha256)
SHA_UPDATE(sha256, SHA256)

inline void pgfe_sha256_digest(struct pgfe_sha256_ctx *ctx, pgfe_encode_t output[]) {
    sha224n256_digest(ctx, output, PGFE_SHA256_DIGEST_SIZE);
}