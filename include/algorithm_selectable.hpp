/*
  libpgfe
  algorithm_selectable.hpp

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_ALGORITHM_SELECTABLE_HPP
#define LIBPGFE_ALGORITHM_SELECTABLE_HPP
#ifdef __cplusplus

#include <cstring>
#include <string>

#include "algorithm-choice.h"

namespace chardon55 {
namespace PGFE {

class AlgorithmSelectable
{
protected:
    pgfe_algorithm_choice cur;

    virtual void before_change_alg() {}
    virtual void after_change_alg() {}

    void select_algorithm(pgfe_algorithm_choice choice);

public:
    pgfe_algorithm_choice algorithm();
};
} // namespace PGFE
} // namespace chardon55

#endif
#endif