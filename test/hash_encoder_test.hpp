/*
  libpgfe
  hash_encoder_test.hpp

  Copyright (c) 2022 Charles Dong
*/

#include "test.h"

#include <iostream>
#include <string>

#include "../include/hash_encoder.hpp"
#include "../include/utils.h"
#include "../include/utils.hpp"

void hash_encoder_test(ARGS) {
    using namespace std;
    LIBPGFE_NAMESPACE
    LIBPGFE_UTILS_NAMESPACE

    unsigned long len_flag = 0UL;
    HashEncoder encoder{_algstr(argv[2])};

    if (argc >= 5) {
        sscanf(argv[3], "%lu", &len_flag);
    }

    encoder.update(argv[argc - 1]);

    auto sd = encoder.get_digest((uint64_t)len_flag);
    cout << *sd << endl;
}