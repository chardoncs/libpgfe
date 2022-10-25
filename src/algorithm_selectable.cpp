#include "algorithm_selectable.hpp"

using namespace chardon55::PGFE;

void AlgorithmSelectable::select_algorithm(pgfe_algorithm_choice choice) {
    if (choice == cur) return;

    before_change_alg();
    cur = choice;
    after_change_alg();
}

pgfe_algorithm_choice AlgorithmSelectable::algorithm() {
    return cur;
}