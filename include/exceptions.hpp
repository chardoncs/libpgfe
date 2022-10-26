/*
  libpgfe
  exceptions.hpp

  Copyright (c) 2022 Charles Dong

*/

#ifndef LIBPGFE_EXCEPTIONS_HPP
#define LIBPGFE_EXCEPTIONS_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

#include <stdexcept>

namespace chardon55 {
namespace PGFE {

class NotInitializedException : public std::exception
{
};

class EncodingCompletedException : public std::exception
{
};

} // namespace PGFE
} // namespace chardon55

#endif