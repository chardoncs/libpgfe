/*
  libpgfe
  abstract_hash_encoder.hpp

  Copyright (c) 2022-2023 Charles Dong
*/

#ifndef LIBPGFE_GENERIC_HASH_ENCODER_HPP
#define LIBPGFE_GENERIC_HASH_ENCODER_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

#include <string>

#include "libpgfe/abstract_encoder.hpp"

#include "libpgfe/algorithm-choice.h"
#include "libpgfe/algorithm_selectable.hpp"
#include "libpgfe/generic.h"
#include "libpgfe/generic.hpp"

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