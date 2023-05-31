/*
  libpgfe
  generic.cpp

  Copyright (c) 2022-2023 Charles Dong
*/

#ifndef LIBPGFE_GENERIC_CPP
#define LIBPGFE_GENERIC_CPP

#include "libpgfe/generic.hpp"

#include "libpgfe/generic.h"

namespace libpgfe {

pgfe_algorithm_choice _algstr(const char *cs) {
    std::string s{cs};
    return _algstr(s);
}

pgfe_algorithm_choice _algstr(std::string cpp_s) {
    return pgfe_option_map.at(cpp_s);
}

} // namespace libpgfe

#endif