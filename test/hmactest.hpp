/*
  libpgfe
  hmactest.hpp

  Copyright (c) 2022 Charles Dong
*/

#include "test.h"

#include "../include/hmac_encoder.hpp"
#include "../include/utils.h"
#include "../include/utils.hpp"

void hmac_encoder_test(ARGS) {
    LIBPGFE_NAMESPACE

    HMACEncoder *encoder;

    if (argv[3][0] == '0' && argv[3][1] == 'x') {
        auto sd = utils::sequential_data::from_hex_string(argv[3]);
        encoder = new HMACEncoder(_algstr(argv[2]), *sd);
        delete sd;
    }
    else {
        encoder = new HMACEncoder(_algstr(argv[2]), argv[3]);
    }

    encoder->update(argv[4]);

    SequentialData sd{encoder->get_digest()};
    puts(sd.to_hex_cs());

    delete encoder;
}
