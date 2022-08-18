#include <iostream>

#include "hash_encoder_test.hpp"
#include "test.h"

using namespace std;

int main(ARGS) {
    TEST_INIT;

    TEST_CASE("hash_encoder", hash_encoder_test)

        ;

    printf("\n");

    return EXIT_SUCCESS;
}