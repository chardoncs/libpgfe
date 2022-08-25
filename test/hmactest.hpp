/*
  libpgfe
  hmactest.hpp

  Copyright (c) 2022 Charles Dong
*/

#include "test.h"

#include "../hmac_encoder.hpp"
#include "../utils.h"

using namespace chardon55::PGFE;

void hmac_encoder_test(ARGS) {
    HMACEncoder encoder;

    int c = 3;
    if (argc >= c) {
        encoder.select_algorithm(argv[c++ - 1]);
    }
    if (argc >= c) {
        encoder.set_key(argv[c++ - 1]);
    }
    if (argc >= c) {
        encoder.update(argv[c++ - 1]);
    }

    auto sd = encoder.get_digest();
    puts(sd.to_hex_cs());
}

void hmac_encoder_hex_test(ARGS) {
    HMACEncoder encoder;

    int c = 3;
    if (argc >= c) {
        encoder.select_algorithm(argv[c++ - 1]);
    }
    if (argc >= c) {
        auto sd = utils::sequential_data::from_hex_string(argv[c++ - 1]);
        encoder.set_key(sd);
    }
    if (argc >= c) {
        encoder.update(argv[c++ - 1]);
    }

    auto sd = encoder.get_digest();
    puts(sd.to_hex_cs());
}