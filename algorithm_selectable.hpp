/*
  libpgfe
  algorithm_selectable.hpp

  Copyright (C) 2022 Charles Dong

  libpgfe is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
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
    inline void select_algorithm(std::string &s) {
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