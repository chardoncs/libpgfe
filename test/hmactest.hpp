/*
  libpgfe
  hmactest.hpp

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