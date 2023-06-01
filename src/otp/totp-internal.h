#ifndef LIBPGFE_OTP_TOTP_INTERNAL_H
#define LIBPGFE_OTP_TOTP_INTERNAL_H

#include <time.h>

#include "libpgfe/otp/totp.h"

#ifdef __cplusplus
extern "C" {
#endif

// Get current UNIX time
time_t curtime();

pgfe_otp_counter_t calc_periodic_counter(
    time_t realtime, pgfe_totp_interval_t interval, time_t initial_time, pgfe_totp_delta_t *delta_out
);

#ifdef __cplusplus
}
#endif

#endif