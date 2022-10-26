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

namespace chardon55 {
namespace PGFE {

class TOTP : public HOTP
{
private:
    pgfe_totp_interval_t interval;
    pgfe_time_t initial_time = 0, update_time = 0;

    pgfe_totp_delta_t delta;

public:
    TOTP(pgfe_totp_interval_t = 30, pgfe_algorithm_choice = SHA1);
    TOTP(const pgfe_encode_t *, size_t, pgfe_totp_interval_t = 30, pgfe_algorithm_choice = SHA1);
    TOTP(const char *, pgfe_totp_interval_t = 30, pgfe_algorithm_choice = SHA1);
    TOTP(std::string &, pgfe_totp_interval_t = 30, pgfe_algorithm_choice = SHA1);
    TOTP(SequentialData &, pgfe_totp_interval_t = 30, pgfe_algorithm_choice = SHA1);
    ~TOTP();

    void update_counter();

    pgfe_totp_interval_t get_interval() const;
    void set_interval(pgfe_totp_interval_t);

    pgfe_time_t get_initial_time() const;
    void set_initial_time(pgfe_time_t);

    pgfe_time_t get_update_time() const;

    pgfe_time_t get_remain_time() const;
};

} // namespace PGFE
} // namespace chardon55

#endif