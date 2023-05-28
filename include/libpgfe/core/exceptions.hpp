/*
  libpgfe
  exceptions.hpp

  Copyright (c) 2022-2023 Charles Dong

*/

#ifndef LIBPGFE_CORE_EXCEPTIONS_HPP
#define LIBPGFE_CORE_EXCEPTIONS_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

#include <stdexcept>

namespace libpgfe {

class NotInitializedException : public std::exception
{
};

class EncodingCompletedException : public std::exception
{
};

} // namespace libpgfe

#endif