/*
  libpgfe
  test.cpp

  Copyright (c) 2022 Charles Dong
*/

#include <iostream>

#include "base_multithread.hpp"
#include "base_test.hpp"
#include "hash_encoder_test.hpp"
#include "hmactest.hpp"
#include "otptest.hpp"
#include "test.h"

using namespace std;

int main(ARGS) {
    TEST_INIT;

    try {
        TEST_CASE("hash_encoder", hash_encoder_test)
        TEST_CASE("hmac_encoder", hmac_encoder_test)
        TEST_CASE("hmac_encoder_hex", hmac_encoder_hex_test)
        TEST_CASE("hotp_hex", hotp_hex_test)
        TEST_CASE("base16_encode", base16_encode_test)
        TEST_CASE("base16_decode", base16_decode_test)
        TEST_CASE("base32_encode", base32_encode_test)
        TEST_CASE("base32_decode", base32_decode_test)
        TEST_CASE("base32hex_encode", base32hex_encode_test)
        TEST_CASE("base32hex_decode", base32hex_decode_test)
        TEST_CASE("base64_encode", base64_encode_test)
        TEST_CASE("base64_decode", base64_decode_test)
        TEST_CASE("base64url_encode", base64url_encode_test)
        TEST_CASE("base64url_decode", base64url_decode_test)
        TEST_CASE("base_multithread1", base_multithread1)

        TEST_END;
    }
    catch (std::exception) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}