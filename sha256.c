/*
  libpgfe
  sha256.c

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

#include "sha2-backend.h"
#include "sha2.h"
#include "templates.c"

const pgfe_word_t __pgfe_sha256_H0[] = {0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A,
                                        0x510E527F, 0x9B05688C, 0x1F83D9AB, 0x5BE0CD19};

__PGFE_FRONTEND_GEN2(sha256);
__PGFE_FRONTEND_DEFAULT_GEN2(sha256, SHA256);

__PGFE_SHA_INIT(sha256)
__PGFE_SHA_UPDATE(sha256, SHA256)

inline void pgfe_sha256_digest(struct pgfe_sha256_ctx *ctx, pgfe_encode_t output[]) {
    __pgfe_sha224n256_digest(ctx, output, PGFE_SHA256_DIGEST_SIZE);
}