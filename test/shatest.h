/*
  libpgfe
  shatest.h

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

#include "../pgfe.h"
#include "../sha1.h"
#include "../sha2.h"
#include "../sha3.h"
#include "../utils.h"

void sha1_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA1_DIGEST_SIZE];

    pgfe_sha1_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA1_DIGEST_SIZE);
}

void sha1_file_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA1_DIGEST_SIZE];

    FILE *fp = fopen("../test/test.txt", "r");
    pgfe_sha1_encode_default_f(fp, output);
    fclose(fp);

    pgfe_print_hash(output, PGFE_SHA1_DIGEST_SIZE);
}

void sha224_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA224_DIGEST_SIZE];

    pgfe_sha224_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA224_DIGEST_SIZE);
}

void sha256_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA256_DIGEST_SIZE];

    pgfe_sha256_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA256_DIGEST_SIZE);
}

void sha256_file_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA256_DIGEST_SIZE];

    FILE *fp = fopen("../test/test.txt", "r");
    pgfe_sha256_encode_default_f(fp, output);
    fclose(fp);

    pgfe_print_hash(output, PGFE_SHA256_DIGEST_SIZE);
}

void sha384_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA384_DIGEST_SIZE];

    pgfe_sha384_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA384_DIGEST_SIZE);
}

void sha512_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA512_DIGEST_SIZE];

    pgfe_sha512_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA512_DIGEST_SIZE);
}

void sha512_file_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA512_DIGEST_SIZE];

    FILE *fp = fopen("../test/test.txt", "r");
    pgfe_sha512_encode_default_f(fp, output);
    fclose(fp);

    pgfe_print_hash(output, PGFE_SHA512_DIGEST_SIZE);
}

void sha512_224_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA512_224_DIGEST_SIZE];

    pgfe_sha512_224_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA512_224_DIGEST_SIZE);
}

void sha512_256_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA512_256_DIGEST_SIZE];

    pgfe_sha512_256_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA512_256_DIGEST_SIZE);
}

void sha3_224_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA3_224_DIGEST_SIZE];

    pgfe_sha3_224_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA3_224_DIGEST_SIZE);
}

void sha3_256_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA3_256_DIGEST_SIZE];

    pgfe_sha3_256_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA3_256_DIGEST_SIZE);
}

void sha3_384_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA3_384_DIGEST_SIZE];

    pgfe_sha3_384_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA3_384_DIGEST_SIZE);
}

void sha3_512_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA3_512_DIGEST_SIZE];

    pgfe_sha3_512_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA3_512_DIGEST_SIZE);
}

void sha256_fe_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA256_DIGEST_SIZE];

    pgfe_encode(SHA256, (pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA256_DIGEST_SIZE);
}