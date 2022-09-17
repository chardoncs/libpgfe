/*
  libpgfe
  utils.hpp

  Copyright (c) 2022 Charles Dong
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