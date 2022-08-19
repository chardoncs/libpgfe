#ifndef LIBPGFE_ALGORITHM_SELECTABLE_HPP
#define LIBPGFE_ALGORITHM_SELECTABLE_HPP
#ifdef __cplusplus

#include <cstring>

#include "algorithm-choice.h"
#include "generic.hpp"

namespace chardon55 {
namespace PGFE {

class AlgorithmSelectable
{
  protected:
    pgfe_algorithm_choice cur;

    pgfe_algorithm_choice convert_choice(std::string ch_s) {
        return pgfe_option_map[ch_s];
    }

    virtual void before_change_alg() {}
    virtual void after_change_alg() {}

  public:
    void select_algorithm(pgfe_algorithm_choice choice) {
        if (choice == cur) return;

        before_change_alg();
        cur = choice;
        after_change_alg();
    }
    inline void select_algorithm(const std::string &s) {
        return select_algorithm(convert_choice(s));
    }

    pgfe_algorithm_choice get_algorithm() {
        return cur;
    }
};
} // namespace PGFE
} // namespace chardon55

#endif
#endif