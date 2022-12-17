/*
  libpgfe
  totp.hpp

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_TOTP_HPP
#define LIBPGFE_TOTP_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

#include "hotp.hpp"
#include "totp.h"

namespace libpgfe {

class TOTP : public HOTP
{
private:
    pgfe_totp_interval_t _interval;
    time_t _initial_time = 0, _update_time = 0;

    pgfe_totp_delta_t delta = 0;

public:
    TOTP(pgfe_totp_interval_t = 30, pgfe_algorithm_choice = SHA1);
    TOTP(const pgfe_encode_t *, size_t, pgfe_totp_interval_t = 30, pgfe_algorithm_choice = SHA1);
    TOTP(const char *, pgfe_totp_interval_t = 30, pgfe_algorithm_choice = SHA1);
    TOTP(std::string &, pgfe_totp_interval_t = 30, pgfe_algorithm_choice = SHA1);
    TOTP(SequentialData &, pgfe_totp_interval_t = 30, pgfe_algorithm_choice = SHA1);
    ~TOTP();

    void update_counter();

    pgfe_totp_interval_t interval() const;
    void set_interval(pgfe_totp_interval_t);

    time_t initial_time() const;
    void set_initial_time(time_t);

    time_t update_time() const;

    time_t remaining_time() const;
};

} // namespace libpgfe

#endif