/*
  libpgfe
  utilstest.h

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

#include "../utils.h"
#include <string.h>

void string2hash(ARGS) {
    char *s = argv[2];
    pgfe_encode_t hash[128];
    int s_len = strlen(s);

    pgfe_hex_string_to_hash(s, hash);
    pgfe_print_hash(hash, s_len / 2 + s_len % 2);
}

void hash_string_clean(ARGS) {
    char *s = argv[2], out[128];

    pgfe_hash_string_clean(s, out);
    puts(out);
}

void hash_string_clean_inplace(ARGS) {
    char *s = argv[2], out[128];
    strcpy(out, s);

    pgfe_hash_string_clean_(out);
    puts(out);
}