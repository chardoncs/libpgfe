/*
  libpgfe
  base64.hpp

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_BASE64_HPP
#define LIBPGFE_BASE64_HPP
#ifdef __cplusplus

#include "abstract_base_encoding.hpp"

namespace chardon55 {
namespace PGFE {

class Base64 : public AbstractBaseEncoding
{
  private:
    bool _url_safe_mode;

  protected:
    void init_base_function(base_encode_func *&, base_decode_func *&);
    void init_size(base_short_size_t &, base_short_size_t &, base_short_size_t &, base_short_size_t &);

  public:
    Base64(bool url_safe_mode = false);

    bool is_url_safe_mode() {
        return _url_safe_mode;
    }
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif