/*
  libpgfe
  utils.hpp

  Copyright (c) 2022-2023 Charles Dong
*/

#ifndef LIBPGFE_UTILS_HPP
#define LIBPGFE_UTILS_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

#include <string>

#include "libpgfe/generic.hpp"
#include "libpgfe/sequential_data.hpp"

namespace libpgfe {
namespace utils {

SequentialData *to_sequential_data(const pgfe_encode_t *pgfe_c_seq, size_t);
SequentialData *to_sequential_data(const char *cs);
SequentialData *to_sequential_data(std::string &);

namespace sequential_data {

SequentialData *from_hex_string(const char *hex_cs);
SequentialData *from_hex_string(std::string &hex_cpps);

} // namespace sequential_data

} // namespace utils
} // namespace libpgfe

#endif