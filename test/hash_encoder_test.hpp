/*
  libpgfe
  hash_encoder_test.hpp

  Copyright (c) 2022 Charles Dong
*/

#include "test.h"

#include <string>

#include "../include/hash_encoder.hpp"
#include "../include/utils.h"

using namespace std;
using namespace chardon55::PGFE;

void hash_encoder_test(ARGS) {
    int i = 2;
    string option(argv[i++]);
    uint64_t len_flag = 0UL;

    HashEncoder encoder(option);

    if (argc >= 5) {
        sscanf(argv[i++], "%lu", &len_flag);
    }

    encoder.update(argv[i++]);
    auto sd = encoder.get_digest(len_flag);

    // puts(sd.to_hex_cs());
    cout << sd << endl;
}