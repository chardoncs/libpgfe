#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../md5.h"
#include "../pgfe.h"
#include "../sha1.h"
#include "../sha2.h"
#include "../sha3.h"

int main(int argc, char **argv) {

    char *option = argv[1];
    char output_str[400];

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
    else if (!strcmp(option, "sha512_224")) {
        pgfe_encode_t output[PGFE_SHA512_224_DIGEST_SIZE];

        pgfe_sha512_224_encode_default((pgfe_encode_t *)argv[2], output);
        pgfe_print_hash(output, PGFE_SHA512_224_DIGEST_SIZE);
    }
    else if (!strcmp(option, "sha512_256")) {
        pgfe_encode_t output[PGFE_SHA512_256_DIGEST_SIZE];

        pgfe_sha512_256_encode_default((pgfe_encode_t *)argv[2], output);
        pgfe_print_hash(output, PGFE_SHA512_256_DIGEST_SIZE);
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
    else if (!strcmp(option, "fe-sha256")) {
        pgfe_encode_t output[PGFE_SHA256_DIGEST_SIZE];

        pgfe_encode(PGFE_SHA256, (pgfe_encode_t *)argv[2], output);
        pgfe_print_hash(output, PGFE_SHA256_DIGEST_SIZE);
    }
    else if (!strcmp(option, "hmac-sha1")) {}

    printf("\n");

    return EXIT_SUCCESS;
}