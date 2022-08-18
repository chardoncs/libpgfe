#ifndef LIBPGFE_GENERIC_ENCODER_HPP
#define LIBPGFE_GENERIC_ENCODER_HPP
#ifdef __cplusplus

#include <string>

#include "generic.h"

namespace chardon55 {
namespace PGFE {

class GenericEncoder
{
  public:
    virtual void reset() {}

    virtual void update(const pgfe_encode_t sequence[], size_t length) {}
    virtual void update(const char cs[]) {}
    virtual void update(const std::string &cpp_s) {}

    virtual void get_digest(pgfe_encode_t out[], size_t length = 0) {}
}; // namespace GenericEncoder

} // namespace PGFE
} // namespace chardon55
#endif
#endif