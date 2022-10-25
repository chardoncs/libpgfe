/*
  libpgfe
  utils.hpp

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_UTILS_HPP
#define LIBPGFE_UTILS_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

#include <string>

#include "generic.hpp"
#include "sequential_data.hpp"

#define USE_PGFE_CPP_UTILS using namespace chardon55::PGFE::utils;

#define _algstr(str) string_to_algorithm_choice(str)

namespace chardon55 {
namespace PGFE {
namespace utils {

SequentialData *to_sequential_data(const pgfe_encode_t *pgfe_c_seq, size_t);
SequentialData *to_sequential_data(const char *cs);
SequentialData *to_sequential_data(std::string &);

pgfe_algorithm_choice string_to_algorithm_choice(const char *cs);
pgfe_algorithm_choice string_to_algorithm_choice(std::string cpp_s);

namespace sequential_data {

SequentialData *from_hex_string(const char *hex_cs);
SequentialData *from_hex_string(std::string &hex_cpps);

} // namespace sequential_data

} // namespace utils
} // namespace PGFE
} // namespace chardon55

#endif