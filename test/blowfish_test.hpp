/*
  libpgfe
  blowfish_test.hpp

  Copyright (c) 2022 Charles Dong
*/

#include "test.h"

#include <iostream>
#include <memory>
#include <string>

#include "../include/blowfish.hpp"
#include "../include/utils.hpp"

void blowfish_encrypt_test(ARGS) {
    using namespace libpgfe;
    using namespace std;

    Blowfish b(argv[2]);
    SequentialData sd = b.encrypt(argv[3]);
    cout << sd.hex_str() << endl;
}

void blowfish_decrypt_test(ARGS) {
    using namespace libpgfe;
    using namespace std;

    Blowfish b(argv[2]);
    std::unique_ptr<SequentialData> plain;
    plain.reset(utils::sequential_data::from_hex_string(argv[3]));

    SequentialData sd = b.decrypt(*plain);

    cout << sd << endl;
}