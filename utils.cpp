/*
  libpgfe
  utils.cpp

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

#include "utils.hpp"

#include <cstring>

#include "utils.h"

namespace chardon55 {
namespace PGFE {
namespace utils {

SequentialData to_sequential_data(const pgfe_encode_t *pgfe_c_seq, size_t length) {
    SequentialData seq(pgfe_c_seq, length);
    return seq;
}

SequentialData to_sequential_data(const char *cs) {
    SequentialData seq(cs);
    return seq;
}

SequentialData to_sequential_data(std::string &cpp_s) {
    SequentialData seq(cpp_s);
    return seq;
}

SequentialData sequential_data::from_hex_string(const char *hex_cs) {
    size_t s_sz = strlen(hex_cs), sz = s_sz / 2 + s_sz % 2;
    pgfe_encode_t *h_out = new pgfe_encode_t[sz + 1];

    pgfe_hex_string_to_hash(hex_cs, h_out);
    h_out[sz] = 0;

    return to_sequential_data(h_out, sz);
}

SequentialData sequential_data::from_hex_string(std::string &hex_cpps) {
    return from_hex_string(hex_cpps.c_str());
}

} // namespace utils
} // namespace PGFE
} // namespace chardon55