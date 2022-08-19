/*
  libpgfe
  abstract_otp.hpp

  Copyright (C) 2022 Charles Dong

  libpgfe is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
*/

#ifndef LIBPGFE_GENERIC_OTP_HPP
#define LIBPGFE_GENERIC_OTP_HPP
#ifdef __cplusplus

#include <string>

#include "algorithm_selectable.hpp"
#include "generic.h"
#include "otp-generic.h"
#include "sequential_data.hpp"

namespace chardon55 {
namespace PGFE {

class AbstractOTP : public AlgorithmSelectable
{
  public:
    virtual void set_secret(const pgfe_encode_t *, size_t) {}
    virtual void set_secret(const char *cs);
    virtual void set_secret(std::string &);
    virtual void set_secret(SequentialData &);

    virtual void set_secret_from_base32(const char *);
    virtual void set_secret_from_base32(std::string &);

    virtual void set_counter(pgfe_otp_counter_t){};

    virtual pgfe_otp_t generate(uint8_t digit_count = 6) {
        return 0;
    }

    virtual std::string generate_str(uint8_t digit_count = 6);
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif