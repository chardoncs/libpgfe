#ifndef LIBPGFE_ABSTRACT_SYMMETRIC_CRYPTER_HPP
#define LIBPGFE_ABSTRACT_SYMMETRIC_CRYPTER_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

#include <string>

#include "../sequential_data.hpp"

namespace chardon55 {
namespace PGFE {

class AbstractSymmetricCrypter
{
public:
    SequentialData encrypt(const std::string &);
    virtual SequentialData encrypt(const pgfe_encode_t *, size_t) {
        return SequentialData();
    }
    SequentialData encrypt(const char *);
    SequentialData encrypt(const SequentialData &);

    SequentialData decrypt(const std::string &);
    virtual SequentialData decrypt(const pgfe_encode_t *, size_t) {
        return SequentialData();
    }
    SequentialData decrypt(const char *);
    SequentialData decrypt(const SequentialData &);
};

} // namespace PGFE
} // namespace chardon55

#endif