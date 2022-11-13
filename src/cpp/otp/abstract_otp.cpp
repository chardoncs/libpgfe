/*
  libpgfe
  abstract_otp.cpp

  Copyright (c) 2022 Charles Dong
*/

#include "backend_cpp/abstract_otp.hpp"

#include <cstring>

#include "base-encoding.h"

using namespace chardon55::PGFE;

void AbstractOTP::set_secret(const char *cs) {
    set_secret((pgfe_encode_t *)cs, strlen(cs));
}

void AbstractOTP::set_secret(const std::string &cpp_s) {
    set_secret((pgfe_encode_t *)cpp_s.c_str(), cpp_s.length());
}

void AbstractOTP::set_secret(const SequentialData &sd) {
    size_t sz;
    set_secret(sd.to_pgfe_seq(sz), sz);
}

std::string AbstractOTP::generate_str(uint8_t digit_count) const {
    std::string str = std::to_string(generate(digit_count));
    while (str.length() < digit_count) {
        str.insert(0, "0");
    }

    return str;
}