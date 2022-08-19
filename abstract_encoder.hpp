/*
  libpgfe
  abstract_encoder.hpp

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

#ifndef LIBPGFE_GENERIC_ENCODER_HPP
#define LIBPGFE_GENERIC_ENCODER_HPP
#ifdef __cplusplus

#include <cstring>
#include <string>

#include "generic.h"
#include "sequential_data.hpp"
#include "utils.hpp"

namespace chardon55 {
namespace PGFE {

class AbstractEncoder
{
  public:
    virtual void reset() {}

    virtual void update(const pgfe_encode_t sequence[], size_t length) {}

    virtual void update(const char cs[]) {
        return update((const pgfe_encode_t *)cs, strlen(cs));
    }
    virtual void update(std::string &cpp_s) {
        return update((const pgfe_encode_t *)cpp_s.c_str(), cpp_s.length());
    }
    virtual void update(SequentialData &sd) {
        size_t sz;
        update(sd.to_pgfe_seq(sz), sz);
    }

    virtual SequentialData get_digest() {
        return nullptr;
    }
}; // namespace AbstractEncoder

} // namespace PGFE
} // namespace chardon55
#endif
#endif