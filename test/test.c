/*
  libpgfe
  test.c

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"

#include "baseencodetest.h"
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

    TEST_CASE("base16-encode", base16_encode_test)
    TEST_CASE("base16-decode", base16_decode_test)
    TEST_CASE("base32-encode", base32_encode_test)
    TEST_CASE("base32-decode", base32_decode_test)
    TEST_CASE("base32hex-encode", base32hex_encode_test)
    TEST_CASE("base32hex-decode", base32hex_decode_test)
    TEST_CASE("base64-encode", base64_encode_test)
    TEST_CASE("base64url-encode", base64url_encode_test)
    TEST_CASE("base64-decode", base64_decode_test)

        ;

    printf("\n");

    return EXIT_SUCCESS;
}