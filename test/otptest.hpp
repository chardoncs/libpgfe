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