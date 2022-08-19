#ifndef LIBPGFE_GENERIC_ENCODER_HPP
#define LIBPGFE_GENERIC_ENCODER_HPP
#ifdef __cplusplus

#include <cstring>
#include <string>

#include "generic.h"

namespace chardon55 {
namespace PGFE {

class AbstractEncoder
{
  public:
    virtual void reset() {}

    virtual void update(const pgfe_encode_t sequence[], size_t length) {}
    virtual inline void update(const char cs[]) {
        return update((const pgfe_encode_t *)cs, strlen(cs));
    }
    virtual inline void update(const std::string &cpp_s) {
        return update((const pgfe_encode_t *)cpp_s.c_str(), cpp_s.length());
    }

    virtual void get_digest(pgfe_encode_t out[], size_t length = 0) {}
}; // namespace AbstractEncoder

} // namespace PGFE
} // namespace chardon55
#endif
#endif