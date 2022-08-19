#include <iostream>

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

            ;
    }
    catch (std::exception) {
        return EXIT_FAILURE;
    }

    printf("\n");

    return EXIT_SUCCESS;
}