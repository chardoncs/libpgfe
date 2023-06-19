/*
  libpgfe
  mdtest.h

  Copyright (c) 2022-2023 Charles Dong
*/

#include "test.h"

#define TEST_FILE1_PATH "../tests/test.txt"

#include "libpgfe/hashes/md5.h"
#include "libpgfe/utils.h"

void md5test(ARGS) {
    pgfe_encode_t output[PGFE_MD5_DIGEST_SIZE];

    pgfe_md5_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_MD5_DIGEST_SIZE);
}

void md5_file_test(ARGS) {
    pgfe_encode_t output[PGFE_MD5_DIGEST_SIZE];

    FILE *fp = fopen(TEST_FILE1_PATH, "r");
    pgfe_md5_encode_f(fp, output);
    fclose(fp);

    pgfe_print_hash(output, PGFE_MD5_DIGEST_SIZE);
}