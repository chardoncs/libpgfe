/*
  libpgfe
  algorithm_selectable.cpp

  Copyright (c) 2022-2023 Charles Dong
*/

#include "libpgfe/core/algorithm_selectable.hpp"

using namespace libpgfe;

void AlgorithmSelectable::select_algorithm(pgfe_algorithm_choice choice) {
    if (choice == cur_alg) return;

    before_change_alg();
    cur_alg = choice;
    after_change_alg();
}

pgfe_algorithm_choice AlgorithmSelectable::algorithm() const {
    return cur_alg;
}