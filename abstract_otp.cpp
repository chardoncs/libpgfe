/*
  libpgfe
  abstract_otp.cpp

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

#include "abstract_otp.hpp"

#include <cstring>

#include "base-encoding.h"

using namespace chardon55::PGFE;

void AbstractOTP::set_secret(const char *cs) {
    set_secret((pgfe_encode_t *)cs, strlen(cs));
}

void AbstractOTP::set_secret(std::string &cpp_s) {
    set_secret((pgfe_encode_t *)cpp_s.c_str(), cpp_s.length());
}

void AbstractOTP::set_secret(SequentialData &sd) {
    size_t sz;
    set_secret(sd.to_pgfe_seq(sz), sz);
}

std::string AbstractOTP::generate_str(uint8_t digit_count) {
    std::string str = std::to_string(generate(digit_count));
    while (str.length() < digit_count) {
        str.insert(0, "0");
    }

    return str;
}

void AbstractOTP::set_secret_from_base32(const char *base32_cs) {}