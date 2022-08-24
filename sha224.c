/*
  libpgfe
  sha224.c

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

#include "sha2.h"

#include "sha2-backend.h"
#include "templates.c"

const pgfe_word_t __pgfe_sha224_H0[] = {0xC1059ED8, 0x367CD507, 0x3070DD17, 0xF70E5939,
                                        0xFFC00B31, 0x68581511, 0x64F98FA7, 0xBEFA4FA4};

__PGFE_FRONTEND_GEN2(sha224);
__PGFE_FRONTEND_DEFAULT_GEN2(sha224, SHA224);

__PGFE_SHA_INIT(sha224)
__PGFE_SHA_UPDATE(sha224, SHA224)

inline void pgfe_sha224_digest(struct pgfe_sha224_ctx *ctx, pgfe_encode_t output[]) {
    __pgfe_sha224n256_digest(ctx, output, PGFE_SHA224_DIGEST_SIZE);
}
