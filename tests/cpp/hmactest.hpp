/*
  libpgfe
  hmactest.hpp

  Copyright (c) 2022-2023 Charles Dong
*/

#include "test.h"

#include <memory>

#include "libpgfe/hmac/hmac_encoder.hpp"
#include "libpgfe/utils.h"
#include "libpgfe/utils.hpp"

void hmac_encoder_test(ARGS) {
    using namespace libpgfe;

    std::unique_ptr<HMACEncoder> encoder;
    std::unique_ptr<SequentialData> sd;

    if (argv[3][0] == '0' && argv[3][1] == 'x') {
        sd.reset(utils::sequential_data::from_hex_string(argv[3]));
        encoder = std::make_unique<HMACEncoder>(_algstr(argv[2]), *sd);
    }
    else {
        encoder = std::make_unique<HMACEncoder>(_algstr(argv[2]), (const char *)argv[3]);
    }

    encoder->update(argv[4]);

    sd = std::make_unique<SequentialData>(encoder->get_digest());
    std::cout << sd->hex_str() << std::endl;
}
