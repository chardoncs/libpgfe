/*
  libpgfe
  shatest.h

  Copyright (c) 2022 Charles Dong
*/

#include "test.h"

#include "../include/sha1.h"
#include "../include/sha2.h"
#include "../include/sha3.h"
#include "../include/utils.h"

void sha1_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA1_DIGEST_SIZE];

    pgfe_sha1_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA1_DIGEST_SIZE);
}

void sha1_file_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA1_DIGEST_SIZE];

    FILE *fp = fopen("../test/test.txt", "r");
    pgfe_sha1_encode_f(fp, output);
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
    pgfe_sha256_encode_f(fp, output);
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
    pgfe_sha512_encode_f(fp, output);
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

void sha3_224_file_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA3_224_DIGEST_SIZE];

    FILE *fp = fopen("../test/test.txt", "r");
    pgfe_sha3_224_encode_f(fp, output);
    fclose(fp);

    pgfe_print_hash(output, PGFE_SHA3_224_DIGEST_SIZE);
}

void sha3_256_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA3_256_DIGEST_SIZE];

    pgfe_sha3_256_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA3_256_DIGEST_SIZE);
}

void sha3_256_file_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA3_256_DIGEST_SIZE];

    FILE *fp = fopen("../test/test.txt", "r");
    pgfe_sha3_256_encode_f(fp, output);
    fclose(fp);

    pgfe_print_hash(output, PGFE_SHA3_256_DIGEST_SIZE);
}

void sha3_384_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA3_384_DIGEST_SIZE];

    pgfe_sha3_384_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA3_384_DIGEST_SIZE);
}

void sha3_384_file_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA3_384_DIGEST_SIZE];

    FILE *fp = fopen("../test/test.txt", "r");
    pgfe_sha3_384_encode_f(fp, output);
    fclose(fp);

    pgfe_print_hash(output, PGFE_SHA3_384_DIGEST_SIZE);
}

void sha3_512_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA3_512_DIGEST_SIZE];

    pgfe_sha3_512_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA3_512_DIGEST_SIZE);
}

void sha3_512_file_test(ARGS) {
    pgfe_encode_t output[PGFE_SHA3_512_DIGEST_SIZE];

    FILE *fp = fopen("../test/test.txt", "r");
    pgfe_sha3_512_encode_f(fp, output);
    fclose(fp);

    pgfe_print_hash(output, PGFE_SHA3_512_DIGEST_SIZE);
}