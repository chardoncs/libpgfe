#ifndef LIBPGFE_GENERIC_CPP
#define LIBPGFE_GENERIC_CPP

#include "generic.hpp"

#include "generic.h"

namespace chardon55 {
namespace PGFE {

pgfe_algorithm_choice string_to_algorithm_choice(const char *cs) {
    std::string s{cs};
    return string_to_algorithm_choice(s);
}

pgfe_algorithm_choice string_to_algorithm_choice(std::string cpp_s) {
    return pgfe_option_map.at(cpp_s);
}

} // namespace PGFE
} // namespace chardon55

#endif