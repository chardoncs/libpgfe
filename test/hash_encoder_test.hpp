/*
  libpgfe
  hash_encoder_test.hpp

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

#include <string>

#include "../hash_encoder.hpp"
#include "../utils.h"

using namespace std;
using namespace chardon55::PGFE;

void hash_encoder_test(ARGS) {
    string option(argv[2]);
    HashEncoder encoder(option);

    encoder.update(argv[3]);
    auto sd = encoder.get_digest();

    // puts(sd.to_hex_cs());
    cout << sd << endl;
}