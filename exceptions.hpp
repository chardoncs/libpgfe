#ifndef LIBPGFE_EXCEPTIONS_HPP
#define LIBPGFE_EXCEPTIONS_HPP
#ifdef __cplusplus

#include <stdexcept>

namespace chardon55 {
namespace PGFE {

class NotInitializedException : public std::exception
{
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif