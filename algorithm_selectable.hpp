/*
  libpgfe
  algorithm_selectable.hpp

  Copyright (c) 2022 Charles Dong
*/

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

    pgfe_algorithm_choice convert_choice(std::string ch_s);

    virtual void before_change_alg() {}
    virtual void after_change_alg() {}

  public:
    void select_algorithm(pgfe_algorithm_choice choice);
    void select_algorithm(const char *cs);
    void select_algorithm(std::string &s);

    pgfe_algorithm_choice get_algorithm();
};
} // namespace PGFE
} // namespace chardon55

#endif
#endif