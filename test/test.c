#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../md5.h"
#include "../sha1.h"
#include "../sha2.h"
#include "../sha3.h"

int main(int argc, char **argv) {

    char *option = argv[1];
    char output_str[400];

    char expected1[] = "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d";

    char expected2[] = "65d7d52df994f64a0e993794222124645242e00f";

    char expected224[] = "ea09ae9cc6768c50fcee903ed054556e5bfc8347907f12598aa24193";
    char expected256[] = "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824";
    char expected384[] =
        "59e1748777448c69de6b800d7a33bbfb9ff1b463e44354c3553bcdb9c666fa90125a3c79f90397bdf5f6a13de828684f";
    char expected512[] = "9b71d224bd62f3785d96d46ad3ea3d73319bfbc2890caadae2dff72519673ca72323c3d99ba5c11d7c7acc6e14b8c"
                         "5da0c4663475c2e5c3adef46f73bcdec043";

    char expected3_224[] = "b87f88c72702fff1748e58b87e9141a42c0dbedc29a78cb0d4a5cd81";
    char expected3_256[] = "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824";
    char expected3_384[] =
        "720aea11019ef06440fbf05d87aa24680a2153df3907b23631e7177ce620fa1330ff07c0fddee54699a4c3ee0ee9d887";
    char expected3_512[] = "75d527c368f2efe848ecf6b073a36767800805e9eef2b1857d5f984f036eb6df891d75f72d9b154518c1cd58835"
                           "286d1da9a38deba3de98b5a53e5ed78a84976";

    char expected_md5[] = "5d41402abc4b2a76b9719d911017c592";

    if (!strcmp(option, "sha1")) {
        pgfe_encode_t output[PGFE_SHA1_DIGEST_SIZE];

        pgfe_sha1_encode_default((pgfe_encode_t *)argv[2], output);
        pgfe_print_hash(output, PGFE_SHA1_DIGEST_SIZE);
    }
    else if (!strcmp(option, "sha1_file")) {
        pgfe_encode_t output[PGFE_SHA1_DIGEST_SIZE];

        FILE *fp = fopen("../test/test.txt", "r");
        pgfe_sha1_encode_default_f(fp, output);
        fclose(fp);

        pgfe_print_hash(output, PGFE_SHA1_DIGEST_SIZE);
    }
    else if (!strcmp(option, "sha224")) {
        pgfe_encode_t output[PGFE_SHA224_DIGEST_SIZE];

        pgfe_sha224_encode_default((pgfe_encode_t *)argv[2], output);
        pgfe_print_hash(output, PGFE_SHA224_DIGEST_SIZE);
    }
    else if (!strcmp(option, "sha256")) {
        pgfe_encode_t output[PGFE_SHA256_DIGEST_SIZE];

        pgfe_sha256_encode_default((pgfe_encode_t *)argv[2], output);
        pgfe_print_hash(output, PGFE_SHA256_DIGEST_SIZE);
    }
    else if (!strcmp(option, "sha384")) {
        pgfe_encode_t output[PGFE_SHA384_DIGEST_SIZE];

        pgfe_sha384_encode_default((pgfe_encode_t *)argv[2], output);
        pgfe_print_hash(output, PGFE_SHA384_DIGEST_SIZE);
    }
    else if (!strcmp(option, "sha512")) {
        pgfe_encode_t output[PGFE_SHA512_DIGEST_SIZE];

        pgfe_sha512_encode_default((pgfe_encode_t *)argv[2], output);
        pgfe_print_hash(output, PGFE_SHA512_DIGEST_SIZE);
    }
    else if (!strcmp(option, "sha3_224")) {
        pgfe_encode_t output[PGFE_SHA3_224_DIGEST_SIZE];

        pgfe_sha3_224_encode_default((pgfe_encode_t *)argv[2], output);
        pgfe_print_hash(output, PGFE_SHA3_224_DIGEST_SIZE);
    }
    else if (!strcmp(option, "sha3_256")) {
        pgfe_encode_t output[PGFE_SHA3_256_DIGEST_SIZE];

        pgfe_sha3_256_encode_default((pgfe_encode_t *)argv[2], output);
        pgfe_print_hash(output, PGFE_SHA3_256_DIGEST_SIZE);
    }
    else if (!strcmp(option, "sha3_384")) {
        pgfe_encode_t output[PGFE_SHA3_384_DIGEST_SIZE];

        pgfe_sha3_384_encode_default((pgfe_encode_t *)argv[2], output);
        pgfe_print_hash(output, PGFE_SHA3_384_DIGEST_SIZE);
    }
    else if (!strcmp(option, "sha3_512")) {
        pgfe_encode_t output[PGFE_SHA3_512_DIGEST_SIZE];

        pgfe_sha3_512_encode_default((pgfe_encode_t *)argv[2], output);
        pgfe_print_hash(output, PGFE_SHA3_512_DIGEST_SIZE);
    }
    else if (!strcmp(option, "md5")) {
        pgfe_encode_t output[PGFE_MD5_DIGEST_SIZE];

        pgfe_md5_encode_default((pgfe_encode_t *)argv[2], output);
        pgfe_print_hash(output, PGFE_MD5_DIGEST_SIZE);
    }

    printf("\n");

    return EXIT_SUCCESS;
}