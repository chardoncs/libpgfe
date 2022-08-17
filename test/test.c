#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../hmac.h"
#include "../md5.h"
#include "../pgfe.h"
#include "../sha1.h"
#include "../sha2.h"
#include "../sha3.h"
#include "../utils.h"

#define TEST_OPTION_START(name) if (!strcmp(option, name)) {
#define TEST_OPTION_END }

int main(int argc, char **argv) {

    char *option = argv[1];
    char output_str[400];

    TEST_OPTION_START("sha1");

    pgfe_encode_t output[PGFE_SHA1_DIGEST_SIZE];

    pgfe_sha1_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA1_DIGEST_SIZE);

    TEST_OPTION_END

    else TEST_OPTION_START("sha1_file");

    pgfe_encode_t output[PGFE_SHA1_DIGEST_SIZE];

    FILE *fp = fopen("../test/test.txt", "r");
    pgfe_sha1_encode_default_f(fp, output);
    fclose(fp);

    pgfe_print_hash(output, PGFE_SHA1_DIGEST_SIZE);

    TEST_OPTION_END

    else TEST_OPTION_START("sha224");

    pgfe_encode_t output[PGFE_SHA224_DIGEST_SIZE];

    pgfe_sha224_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA224_DIGEST_SIZE);

    TEST_OPTION_END

    else TEST_OPTION_START("sha256");

    pgfe_encode_t output[PGFE_SHA256_DIGEST_SIZE];

    pgfe_sha256_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA256_DIGEST_SIZE);

    TEST_OPTION_END

    else TEST_OPTION_START("sha384");
    pgfe_encode_t output[PGFE_SHA384_DIGEST_SIZE];

    pgfe_sha384_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA384_DIGEST_SIZE);
    TEST_OPTION_END
    else TEST_OPTION_START("sha512");
    pgfe_encode_t output[PGFE_SHA512_DIGEST_SIZE];

    pgfe_sha512_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA512_DIGEST_SIZE);
    TEST_OPTION_END
    else TEST_OPTION_START("sha512_224");
    pgfe_encode_t output[PGFE_SHA512_224_DIGEST_SIZE];

    pgfe_sha512_224_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA512_224_DIGEST_SIZE);
    TEST_OPTION_END
    else TEST_OPTION_START("sha512_256");
    pgfe_encode_t output[PGFE_SHA512_256_DIGEST_SIZE];

    pgfe_sha512_256_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA512_256_DIGEST_SIZE);
    TEST_OPTION_END
    else TEST_OPTION_START("sha3_224");
    pgfe_encode_t output[PGFE_SHA3_224_DIGEST_SIZE];

    pgfe_sha3_224_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA3_224_DIGEST_SIZE);
    TEST_OPTION_END
    else TEST_OPTION_START("sha3_256");
    pgfe_encode_t output[PGFE_SHA3_256_DIGEST_SIZE];

    pgfe_sha3_256_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA3_256_DIGEST_SIZE);
    TEST_OPTION_END
    else TEST_OPTION_START("sha3_384");
    pgfe_encode_t output[PGFE_SHA3_384_DIGEST_SIZE];

    pgfe_sha3_384_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA3_384_DIGEST_SIZE);
    TEST_OPTION_END
    else TEST_OPTION_START("sha3_512");
    pgfe_encode_t output[PGFE_SHA3_512_DIGEST_SIZE];

    pgfe_sha3_512_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA3_512_DIGEST_SIZE);
    TEST_OPTION_END
    else TEST_OPTION_START("md5");
    pgfe_encode_t output[PGFE_MD5_DIGEST_SIZE];

    pgfe_md5_encode_default((pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_MD5_DIGEST_SIZE);
    TEST_OPTION_END
    else TEST_OPTION_START("fe-sha256");
    pgfe_encode_t output[PGFE_SHA256_DIGEST_SIZE];

    pgfe_encode(PGFE_SHA256, (pgfe_encode_t *)argv[2], output);
    pgfe_print_hash(output, PGFE_SHA256_DIGEST_SIZE);
    TEST_OPTION_END
    else TEST_OPTION_START("hmac-md5");

    char *key_s = argv[2], *data = argv[3];
    pgfe_encode_t key[128], out[PGFE_MD5_DIGEST_SIZE];

    pgfe_hex_string_to_hash(key_s, key);

    pgfe_hmac_md5(key, pgfe_hash_length(key_s), data, strlen(data), out, PGFE_MD5_DIGEST_SIZE);

    pgfe_print_hash(out, PGFE_MD5_DIGEST_SIZE);

    TEST_OPTION_END

    else TEST_OPTION_START("hmac-md5-str");

    char *key_s = argv[2], *data = argv[3];
    pgfe_encode_t key[128], out[PGFE_MD5_DIGEST_SIZE];

    // pgfe_hex_string_to_hash(key_s, key);

    pgfe_hmac_md5((pgfe_encode_t *)key_s, strlen(key_s), data, strlen(data), out, PGFE_MD5_DIGEST_SIZE);

    pgfe_print_hash(out, PGFE_MD5_DIGEST_SIZE);

    TEST_OPTION_END

    else TEST_OPTION_START("string2hash");
    char *s = argv[2];
    pgfe_encode_t hash[128];
    int s_len = strlen(s);

    pgfe_hex_string_to_hash(s, hash);
    pgfe_print_hash(hash, s_len / 2 + s_len % 2);
    TEST_OPTION_END
    else TEST_OPTION_START("hash_string_clean");
    char *s = argv[2], out[128];

    pgfe_hash_string_clean(s, out);
    puts(out);
    TEST_OPTION_END
    else TEST_OPTION_START("hash_string_clean_inplace");
    char *s = argv[2], out[128];
    strcpy(out, s);

    pgfe_hash_string_clean_(out);
    puts(out);
    TEST_OPTION_END

    printf("\n");

    return EXIT_SUCCESS;
}