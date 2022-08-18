#ifndef LIBPGFE_GENERIC_HASH_ENCODER_HPP
#define LIBPGFE_GENERIC_HASH_ENCODER_HPP
#ifdef __cplusplus

#include <string>

#include "algorithm-choice.h"
#include "generic.h"
#include "generic.hpp"
#include "generic_encoder.hpp"

namespace chardon55 {
namespace PGFE {

class GenericHashEncoder : public GenericEncoder
{
  protected:
    pgfe_algorithm_choice cur;

    virtual pgfe_algorithm_choice convert_choice(std::string ch_s) {
        return pgfe_option_map[ch_s];
    }

  public:
    virtual void select_algorithm(pgfe_algorithm_choice) {}
    virtual inline void select_algorithm(const std::string &s) {
        return select_algorithm(convert_choice(s));
    }
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif