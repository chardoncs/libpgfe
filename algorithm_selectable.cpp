#include "algorithm_selectable.hpp"

using namespace chardon55::PGFE;

pgfe_algorithm_choice AlgorithmSelectable::convert_choice(std::string ch_s) {
    return pgfe_option_map[ch_s];
}

void AlgorithmSelectable::select_algorithm(pgfe_algorithm_choice choice) {
    if (choice == cur) return;

    before_change_alg();
    cur = choice;
    after_change_alg();
}

void AlgorithmSelectable::select_algorithm(const char *cs) {
    std::string s(cs);
    return select_algorithm(convert_choice(s));
}

void AlgorithmSelectable::select_algorithm(std::string &s) {
    return select_algorithm(convert_choice(s));
}

pgfe_algorithm_choice AlgorithmSelectable::get_algorithm() {
    return cur;
}