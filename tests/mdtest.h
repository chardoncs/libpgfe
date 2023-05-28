/*
  libpgfe
  mdtest.h

  Copyright (c) 2022-2023 Charles Dong
*/

#include "test.h"

#include "../include/libpgfe/core/hashes/md5.h"
#include "../include/libpgfe/core/utils.h"

void md5test(ARGS) {
    pgfe_encode_t output[PGFE_MD5_DIGEST_SIZE];

    pgfe_md5_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_MD5_DIGEST_SIZE);
}