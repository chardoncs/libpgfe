/*
  libpgfe
  abstract_base_encoding.hpp

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

#ifndef LIBPGFE_ABSTRACT_BASE_ENCODING
#define LIBPGFE_ABSTRACT_BASE_ENCODING
#ifdef __cplusplus

#include <string>

#include "sequential_data.hpp"

namespace chardon55 {
namespace PGFE {

class AbstractBaseEncoding
{
    virtual std::string encode(pgfe_encode_t *, size_t);
    virtual std::string encode(const char *);
    virtual std::string encode(std::string &);
    virtual std::string encode(SequentialData &);

    virtual SequentialData decode(const char *);
    virtual SequentialData decode(std::string &);
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif