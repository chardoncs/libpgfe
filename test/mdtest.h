/*
  libpgfe
  mdtest.h

  Copyright (c) 2022 Charles Dong
*/

#include "test.h"

#include "../include/libpgfe/md5.h"
#include "../include/libpgfe/utils.h"

void md5test(ARGS) {
    pgfe_encode_t output[PGFE_MD5_DIGEST_SIZE];

    pgfe_md5_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_MD5_DIGEST_SIZE);
}