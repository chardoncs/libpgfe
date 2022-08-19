/*
  libpgfe
  base16.hpp

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

#ifndef LIBPGFE_BASE16_HPP
#define LIBPGFE_BASE16_HPP
#ifdef __cplusplus

#include "abstract_base_encoding.hpp"

namespace chardon55 {
namespace PGFE {

class Base16 : public AbstractBaseEncoding
{
  protected:
    void init_base_function(base_encode_func *&, base_decode_func *&);
    void init_size(base_short_size_t &, base_short_size_t &, base_short_size_t &, base_short_size_t &);

  public:
    Base16();
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif