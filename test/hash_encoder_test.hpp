/*
  libpgfe
  hash_encoder_test.hpp

  Copyright (c) 2022 Charles Dong
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