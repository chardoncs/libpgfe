/*
  libpgfe
  abstract_hash_encoder.hpp

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