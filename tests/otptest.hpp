/*
  libpgfe
  otptest.hpp

  Copyright (c) 2022-2023 Charles Dong
*/

#include "test.h"

#include <cstdio>
#include <iostream>

#include "../include/libpgfe/otp/hotp.hpp"
#include "../include/libpgfe/utils.hpp"

void hotp_hex_test(ARGS) {
    HOTP hotp{_algstr(argv[2])};

    int counter;
    sscanf(argv[4], "%i", &counter);

    auto sd = utils::sequential_data::from_hex_string(argv[3]);
    hotp.set_secret(*sd);
    hotp.set_counter((pgfe_otp_counter_t)counter);

    std::cout << hotp.generate_str(8) << std::endl;
    delete sd;
}