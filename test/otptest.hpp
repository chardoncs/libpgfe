/*
  libpgfe
  otptest.hpp

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

#include <iostream>

#include "../hotp.hpp"
#include "../utils.hpp"

using namespace chardon55::PGFE;

void hotp_hex_test(ARGS) {
    HOTP hotp;
    hotp.select_algorithm(argv[2]);

    auto sd = utils::sequential_data::from_hex_string(argv[3]);
    hotp.set_secret(sd);
    hotp.set_counter(1);

    std::cout << hotp.generate_str(8) << std::endl;
}