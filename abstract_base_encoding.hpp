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