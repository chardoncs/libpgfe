/*
  libpgfe
  utils.cpp

  Copyright (c) 2022 Charles Dong
*/

#include "utils.hpp"

#include <cstring>

#include "utils.h"

namespace chardon55 {
namespace PGFE {
namespace utils {

SequentialData *to_sequential_data(const pgfe_encode_t *pgfe_c_seq, size_t length) {
    return new SequentialData(pgfe_c_seq, length);
}

SequentialData *to_sequential_data(const char *cs) {
    return new SequentialData(cs);
}

SequentialData *to_sequential_data(std::string &cpp_s) {
    return new SequentialData(cpp_s);
}

SequentialData *sequential_data::from_hex_string(const char *hex_cs) {
    size_t s_sz = strlen(hex_cs), sz = s_sz / 2 + s_sz % 2;
    pgfe_encode_t h_out[sz + 1];

    sz = pgfe_hex_string_to_hash(hex_cs, h_out);
    h_out[sz] = 0;

    return to_sequential_data(h_out, sz);
}

SequentialData *sequential_data::from_hex_string(std::string &hex_cpps) {
    return from_hex_string(hex_cpps.c_str());
}

pgfe_algorithm_choice string_to_algorithm_choice(const char *cs) {
    std::string s{cs};
    return string_to_algorithm_choice(s);
}

pgfe_algorithm_choice string_to_algorithm_choice(std::string cpp_s) {
    return pgfe_option_map[cpp_s];
}

} // namespace utils
} // namespace PGFE
} // namespace chardon55