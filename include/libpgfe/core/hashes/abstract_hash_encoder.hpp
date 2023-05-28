/*
  libpgfe
  abstract_hash_encoder.hpp

  Copyright (c) 2022-2023 Charles Dong
*/

#ifndef LIBPGFE_CORE_GENERIC_HASH_ENCODER_HPP
#define LIBPGFE_CORE_GENERIC_HASH_ENCODER_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

#include <string>

#include "libpgfe/core/abstract_encoder.hpp"

#include "libpgfe/core/algorithm-choice.h"
#include "libpgfe/core/algorithm_selectable.hpp"
#include "libpgfe/core/generic.h"
#include "libpgfe/core/generic.hpp"

namespace libpgfe {

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

} // namespace libpgfe

#endif