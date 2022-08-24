/*
  libpgfe
  hmac.h

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

#ifndef LIBPGFE_HMAC_H
#define LIBPGFE_HMAC_H

#include "generic-internal.h"
#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define I_UNIT 0x36
#define O_UNIT 0x5c

void pgfe_hmac_generic(
    PGFE_ENCODER_DEF_SIG, const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length,
    pgfe_encode_t output[]
);

void pgfe_hmac_md5(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha1(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha224(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha256(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha384(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha512(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha512_224(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha512_256(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha3_224(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha3_256(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha3_384(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

void pgfe_hmac_sha3_512(
    const pgfe_encode_t key[], size_t key_length, const pgfe_encode_t data[], size_t length, pgfe_encode_t output[]
);

#ifdef __cplusplus
}
#endif

#endif