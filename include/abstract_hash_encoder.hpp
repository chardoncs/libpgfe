/*
  libpgfe
  abstract_hash_encoder.hpp

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_GENERIC_HASH_ENCODER_HPP
#define LIBPGFE_GENERIC_HASH_ENCODER_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

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
protected:
    size_t digsz, blocksz;

public:
    size_t digest_size() const {
        return digsz;
    }

    size_t block_size() const {
        return blocksz;
    }
};

} // namespace PGFE
} // namespace chardon55

#endif