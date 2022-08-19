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
    TOTP(const std::string &, pgfe_totp_interval_t = 30);
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