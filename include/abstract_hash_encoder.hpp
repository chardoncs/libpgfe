/*
  libpgfe
  abstract_hash_encoder.hpp

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_GENERIC_HASH_ENCODER_HPP
#define LIBPGFE_GENERIC_HASH_ENCODER_HPP
#ifdef __cplusplus

#include <string>

#include "abstract_encoder.hpp"
#include "algorithm-choice.h"
#include "algorithm_selectable.hpp"
#include "generic.h"
#include "generic.hpp"

namespace chardon55 {
namespace PGFE {

class AbstractHashEncoder : public AbstractEncoder, public AlgorithmSelectable
{
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif