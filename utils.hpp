/*
  libpgfe
  utils.hpp

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

#ifndef LIBPGFE_UTILS_HPP
#define LIBPGFE_UTILS_HPP
#ifdef __cplusplus

#include <string>

#include "sequential_data.hpp"

namespace chardon55 {
namespace PGFE {
namespace utils {

SequentialData to_sequential_data(const pgfe_encode_t *pgfe_c_seq, size_t);
SequentialData to_sequential_data(const char *cs);
SequentialData to_sequential_data(std::string &);

namespace sequential_data {

SequentialData from_hex_string(const char *hex_cs);
SequentialData from_hex_string(std::string &hex_cpps);

} // namespace sequential_data

} // namespace utils
} // namespace PGFE
} // namespace chardon55

#endif
#endif