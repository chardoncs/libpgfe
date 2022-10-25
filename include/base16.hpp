/*
  libpgfe
  base16.hpp

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_BASE16_HPP
#define LIBPGFE_BASE16_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

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