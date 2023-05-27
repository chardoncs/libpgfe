/*
  libpgfe
  totp.h

  Copyright (c) 2022 Charles Dong

*/

#ifndef LIBPGFE_TOTP_H
#define LIBPGFE_TOTP_H

#include <time.h>

#include "libpgfe/generic.h"
#include "libpgfe/otp_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef uint32_t pgfe_totp_interval_t;

typedef int32_t pgfe_totp_delta_t;

pgfe_otp_counter_t __pgfe_calc_periodic_counter(
    time_t realtime, pgfe_totp_interval_t interval, time_t initial_time, pgfe_totp_delta_t *delta_out
);

// Generic TOTP function suitable for various hash algorithm
pgfe_otp_t pgfe_totp_generic(
    enum pgfe_algorithm_choice alg, const pgfe_encode_t secret[], size_t secret_length, uint8_t digit_c,
    pgfe_totp_interval_t interval, time_t initial_time, pgfe_totp_delta_t *delta_out
);

// Common TOTP using HMAC-SHA1 algorithm
pgfe_otp_t pgfe_totp(
    const pgfe_encode_t secret[], size_t secret_length, uint8_t digit_c, pgfe_totp_interval_t interval,
    pgfe_totp_delta_t *delta_out
);

// Common TOTP/HMAC-SHA1 in 4 digits
pgfe_otp_t pgfe_totp_4digits(
    const pgfe_encode_t secret[], size_t secret_length, pgfe_totp_interval_t interval, pgfe_totp_delta_t *delta_out
);

// Common TOTP/HMAC-SHA1 in 6 digits
pgfe_otp_t pgfe_totp_6digits(
    const pgfe_encode_t secret[], size_t secret_length, pgfe_totp_interval_t interval, pgfe_totp_delta_t *delta_out
);

// Common TOTP/HMAC-SHA1 in 8 digits
pgfe_otp_t pgfe_totp_8digits(
    const pgfe_encode_t secret[], size_t secret_length, pgfe_totp_interval_t interval, pgfe_totp_delta_t *delta_out
);

#ifdef __cplusplus
}
#endif

#endif