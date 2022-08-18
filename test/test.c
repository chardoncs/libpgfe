#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"

#define TEST_OPTION_START(name) if (!strcmp(option, name)) {
#define TEST_OPTION_END }
#include "hmactest.h"
#include "mdtest.h"
#include "otptest.h"
#include "shatest.h"
#include "utilstest.h"

int main(ARGS) {

    TEST_INIT;

    TEST_CASE("sha1", sha1_test)
    TEST_CASE("sha1_file", sha1_file_test)
    TEST_CASE("sha224", sha224_test)
    TEST_CASE("sha256", sha256_test)
    TEST_CASE("sha384", sha384_test)
    TEST_CASE("sha512", sha512_test)
    TEST_CASE("sha512_224", sha512_224_test)
    TEST_CASE("sha512_256", sha512_256_test)
    TEST_CASE("sha3_224", sha3_224_test)
    TEST_CASE("sha3_256", sha3_256_test)
    TEST_CASE("sha3_384", sha3_384_test)
    TEST_CASE("sha3_512", sha3_512_test)

    TEST_CASE("fe-sha256", sha256_fe_test)

    TEST_CASE("md5", md5test)

    TEST_CASE("hmac-md5", hmac_md5_test)
    TEST_CASE("hmac-md5-str", hmac_md5_str_test)

    TEST_CASE("string2hash", string2hash)
    TEST_CASE("hash_string_clean", hash_string_clean)
    TEST_CASE("hash_string_clean_inplace", hash_string_clean_inplace)
    TEST_CASE("hotp_hex", hotp_hex)
    TEST_CASE("hotp_hex_sha256", hotp_hex_sha256)
    TEST_CASE("hotp_hex_sha512", hotp_hex_sha512)

        ;

    printf("\n");

    return EXIT_SUCCESS;
}