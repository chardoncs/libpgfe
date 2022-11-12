/*
  libpgfe
  hmactest.hpp

  Copyright (c) 2022 Charles Dong
*/

#include "test.h"

#include <memory>

#include "../include/hmac_encoder.hpp"
#include "../include/utils.h"
#include "../include/utils.hpp"

void hmac_encoder_test(ARGS) {
    LIBPGFE_NAMESPACE

    std::unique_ptr<HMACEncoder> encoder;
    std::unique_ptr<SequentialData> sd;

    if (argv[3][0] == '0' && argv[3][1] == 'x') {
        sd.reset(utils::sequential_data::from_hex_string(argv[3]));
        encoder.reset(new HMACEncoder(_algstr(argv[2]), *sd));
    }
    else {
        encoder.reset(new HMACEncoder(_algstr(argv[2]), argv[3]));
    }

    encoder->update(argv[4]);

    sd.reset(new SequentialData(encoder->get_digest()));
    std::cout << *sd << std::endl;
}
