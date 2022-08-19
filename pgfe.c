/*
  libpgfe
  pgfe.c

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

#include "pgfe.h"

#include "md5.h"
#include "sha1.h"
#include "sha2.h"
#include "sha3.h"
#include "templates.c"

#define __PGFE_ENCODE_TL(order, name)                                                                                  \
    case order:                                                                                                        \
        efp = pgfe_##name##_encode_default;                                                                            \
        break

#define __PGFE_DEFAULT_CASE                                                                                            \
    default:                                                                                                           \
        break

void pgfe_encode(const pgfe_alg_option_t algorithm, const pgfe_encode_t input[], pgfe_encode_t output[]) {

    pgfe_encode_func *efp = NULL;

    switch (algorithm) {
        __PGFE_ENCODE_TL(MD5, md5);
        __PGFE_ENCODE_TL(SHA1, sha1);
        __PGFE_ENCODE_TL(SHA224, sha224);
        __PGFE_ENCODE_TL(SHA256, sha256);
        __PGFE_ENCODE_TL(SHA384, sha384);
        __PGFE_ENCODE_TL(SHA512, sha512);
        __PGFE_ENCODE_TL(SHA3_224, sha3_224);
        __PGFE_ENCODE_TL(SHA3_256, sha3_256);
        __PGFE_ENCODE_TL(SHA3_384, sha3_384);
        __PGFE_ENCODE_TL(SHA3_512, sha3_512);
        __PGFE_DEFAULT_CASE;
    }

    if (!efp) {
        return;
    }

    efp(input, output);
}