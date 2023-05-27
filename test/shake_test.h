/*
  libpgfe
  shake_test.h

  Copyright (c) 2022 Charles Dong
*/

#include "test.h"

#include <stdio.h>
#include <string.h>

#include "../include/libpgfe/sha3.h"
#include "../include/libpgfe/utils.h"

void shake_test(ARGS) {
    size_t bitsize;
    char alg[12];
    unsigned int hash_type;

    sscanf(argv[2], "%s", alg);
    sscanf(argv[3], "%u", &hash_type);
    sscanf(argv[4], "%lu", &bitsize);

    size_t byte_size = to_byte(bitsize);

    pgfe_encode_t out[byte_size + bit_rem(bitsize)];
    void (*func)(const pgfe_encode_t data_str[], pgfe_encode_t output[], size_t out_bitlength);

    alg[3] = 0;
    if (!strcasecmp(alg, "raw")) {
        switch (hash_type) {
        case 128:
            func = pgfe_rawshake128_encode_default;
            break;

        case 256:
            func = pgfe_rawshake256_encode_default;
            break;

        default:
            return;
        }
    }
    else {
        switch (hash_type) {
        case 128:
            func = pgfe_shake128_encode_default;
            break;

        case 256:
            func = pgfe_shake256_encode_default;
            break;

        default:
            return;
        }
    }

    func((pgfe_encode_t *)argv[5], out, bitsize);
    pgfe_print_hash(out, byte_size);
}

void shake_test_file(ARGS) {
    size_t bitsize;
    char alg[12];
    unsigned int hash_type;

    sscanf(argv[2], "%s", alg);
    sscanf(argv[3], "%u", &hash_type);
    sscanf(argv[4], "%lu", &bitsize);

    size_t byte_size = to_byte(bitsize);

    pgfe_encode_t out[byte_size + bit_rem(bitsize)];
    void (*func)(FILE * fp, pgfe_encode_t output[], size_t out_bitlength);
    func = NULL;

    FILE *fp = fopen("../test/test.txt", "r");

    alg[3] = 0;
    if (!strcasecmp(alg, "raw")) {
        switch (hash_type) {
        case 128:
            func = pgfe_rawshake128_encode_f;
            break;

        case 256:
            func = pgfe_rawshake256_encode_f;
            break;

        default:
            break;
        }
    }
    else {
        switch (hash_type) {
        case 128:
            func = pgfe_shake128_encode_f;
            break;

        case 256:
            func = pgfe_shake256_encode_f;
            break;

        default:
            break;
        }
    }

    if (!func) {
        fclose(fp);
        return;
    }
    func(fp, out, bitsize);
    fclose(fp);
    pgfe_print_hash(out, byte_size);
}