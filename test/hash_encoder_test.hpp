/*
  libpgfe
  hash_encoder_test.hpp

  Copyright (c) 2022 Charles Dong
*/

#include "test.h"

#include <string>

#include "../include/hash_encoder.hpp"
#include "../include/utils.h"
#include "../include/utils.hpp"

void hash_encoder_test(ARGS) {
    using namespace std;
    USE_PGFE_CPP
    USE_PGFE_CPP_UTILS

    int i = 2;
    uint64_t len_flag = 0UL;
    HashEncoder encoder{_algstr(argv[i++])};

    if (argc >= 5) {
        sscanf(argv[i++], "%lu", &len_flag);
    }

    encoder.update(argv[i++]);
    auto sd = encoder.get_digest(len_flag);

    // puts(sd.to_hex_cs());
    cout << *sd << endl;
    delete sd;
}