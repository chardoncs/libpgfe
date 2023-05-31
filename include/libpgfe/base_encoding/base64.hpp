/*
  libpgfe
  base64.hpp

  Copyright (c) 2022-2023 Charles Dong
*/

#ifndef LIBPGFE_BASE64_HPP
#define LIBPGFE_BASE64_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

#include "libpgfe/base_encoding/abstract_base_encoding.hpp"

namespace libpgfe {

class Base64 : public AbstractBaseEncoding
{
private:
    bool _url_safe_mode;

protected:
    void init_base_function(base_encode_func *&, base_decode_func *&);
    void init_size(base_short_size_t &, base_short_size_t &, base_short_size_t &, base_short_size_t &);

public:
    Base64(bool url_safe_mode = false);

    bool is_url_safe_mode() const {
        return _url_safe_mode;
    }
};

} // namespace libpgfe

#endif