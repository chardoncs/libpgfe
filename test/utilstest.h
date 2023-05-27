/*
  libpgfe
  utilstest.h

  Copyright (c) 2022 Charles Dong
*/

#include "test.h"

#include "../include/libpgfe/utils.h"
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