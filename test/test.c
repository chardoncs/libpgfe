/*
  libpgfe
  test.c

  Copyright (c) 2022 Charles Dong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"

#include "baseencodetest.h"
#include "hmactest.h"
#include "mdtest.h"
#include "otptest.h"
#include "shake_test.h"
#include "shatest.h"
#include "utilstest.h"

int main(ARGS) {

    TEST_INIT;

    TEST_CASE("sha1", sha1_test)
    TEST_CASE("sha1_file", sha1_file_test)

    TEST_CASE("sha224", sha224_test)
    TEST_CASE("sha256", sha256_test)
    TEST_CASE("sha256_file", sha256_file_test)
    TEST_CASE("sha384", sha384_test)
    TEST_CASE("sha512", sha512_test)
    TEST_CASE("sha512_file", sha512_file_test)
    TEST_CASE("sha512_224", sha512_224_test)
    TEST_CASE("sha512_256", sha512_256_test)

    TEST_CASE("sha3_224", sha3_224_test)
    TEST_CASE("sha3_224_file", sha3_224_file_test)
    TEST_CASE("sha3_256", sha3_256_test)
    TEST_CASE("sha3_256_file", sha3_256_file_test)
    TEST_CASE("sha3_384", sha3_384_test)
    TEST_CASE("sha3_384_file", sha3_384_file_test)
    TEST_CASE("sha3_512", sha3_512_test)
    TEST_CASE("sha3_512_file", sha3_512_file_test)
    TEST_CASE("shake-test", shake_test);
    TEST_CASE("shake-test_file", shake_test_file);

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

    TEST_CASE("base16-encode", base16_encode_test)
    TEST_CASE("base16-decode", base16_decode_test)
    TEST_CASE("base32-encode", base32_encode_test)
    TEST_CASE("base32-decode", base32_decode_test)
    TEST_CASE("base32hex-encode", base32hex_encode_test)
    TEST_CASE("base32hex-decode", base32hex_decode_test)
    TEST_CASE("base64-encode", base64_encode_test)
    TEST_CASE("base64url-encode", base64url_encode_test)
    TEST_CASE("base64-decode", base64_decode_test)

    TEST_END;

    return EXIT_SUCCESS;
}