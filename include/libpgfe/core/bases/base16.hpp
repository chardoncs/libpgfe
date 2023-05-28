/*
  libpgfe
  base16.hpp

  Copyright (c) 2022-2023 Charles Dong
*/

#ifndef LIBPGFE_CORE_BASE16_HPP
#define LIBPGFE_CORE_BASE16_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

#include "libpgfe/core/abstract_base_encoding.hpp"

namespace libpgfe {

class Base16 : public AbstractBaseEncoding
{
protected:
    void init_base_function(base_encode_func *&, base_decode_func *&);
    void init_size(base_short_size_t &, base_short_size_t &, base_short_size_t &, base_short_size_t &);

public:
    Base16();
};

} // namespace libpgfe

#endif