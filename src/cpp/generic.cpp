/*
  libpgfe
  generic.cpp

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_GENERIC_CPP
#define LIBPGFE_GENERIC_CPP

#include "generic.hpp"

#include "generic.h"

namespace chardon55 {
namespace PGFE {

pgfe_algorithm_choice _algstr(const char *cs) {
    std::string s{cs};
    return _algstr(s);
}

pgfe_algorithm_choice _algstr(std::string cpp_s) {
    return pgfe_option_map.at(cpp_s);
}

} // namespace PGFE
} // namespace chardon55

#endif