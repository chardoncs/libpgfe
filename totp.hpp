/*
  libpgfe
  totp.hpp

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

#ifndef LIBPGFE_TOTP_HPP
#define LIBPGFE_TOTP_HPP
#ifdef __cplusplus

#include "hotp.hpp"
#include "totp.h"

namespace chardon55 {
namespace PGFE {

class TOTP : public HOTP
{
  private:
    pgfe_totp_interval_t interval;
    pgfe_time_t initial_time = 0, update_time = 0;

    pgfe_totp_delta_t delta;

  public:
    TOTP(pgfe_totp_interval_t = 30);
    TOTP(const pgfe_encode_t *, size_t, pgfe_totp_interval_t = 30);
    TOTP(const char *, pgfe_totp_interval_t = 30);
    TOTP(std::string &, pgfe_totp_interval_t = 30);
    TOTP(SequentialData &, pgfe_totp_interval_t = 30);
    ~TOTP();

    void update_counter();

    pgfe_totp_interval_t get_interval();
    void set_interval(pgfe_totp_interval_t);

    pgfe_time_t get_initial_time();
    void set_initial_time(pgfe_time_t);

    pgfe_time_t get_update_time();

    pgfe_time_t get_remain_time();
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif