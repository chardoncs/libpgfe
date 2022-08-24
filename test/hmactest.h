/*
  libpgfe
  hmactest.h

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

#include "test.h"

#include "../hmac.h"
#include "../md5.h"
#include "../utils.h"

void hmac_md5_test(ARGS) {
    char *key_s = argv[2], *data = argv[3];
    pgfe_encode_t key[128], out[PGFE_MD5_DIGEST_SIZE];

    pgfe_hex_string_to_hash(key_s, key);

    pgfe_hmac_md5(key, pgfe_hash_length(key_s), (pgfe_encode_t *)data, strlen(data), out);

    pgfe_print_hash(out, PGFE_MD5_DIGEST_SIZE);
}

void hmac_md5_str_test(ARGS) {
    char *key_s = argv[2], *data = argv[3];
    pgfe_encode_t out[PGFE_MD5_DIGEST_SIZE];

    pgfe_hmac_md5((pgfe_encode_t *)key_s, strlen(key_s), (pgfe_encode_t *)data, strlen(data), out);

    pgfe_print_hash(out, PGFE_MD5_DIGEST_SIZE);
}