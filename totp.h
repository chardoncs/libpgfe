/*
  libpgfe
  totp.h

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

#ifndef LIBPGFE_TOTP_H
#define LIBPGFE_TOTP_H

#include "otp-generic.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef uint32_t pgfe_totp_interval_t;

typedef int32_t pgfe_totp_delta_t;

pgfe_otp_counter_t __pgfe_calc_periodic_counter(
    pgfe_time_t realtime, pgfe_totp_interval_t interval, pgfe_time_t initial_time, pgfe_totp_delta_t *delta_out
);

// Generic TOTP function suitable for various hash algorithm
pgfe_otp_t pgfe_totp_generic(
    PGFE_ENCODER_DEF_SIG, const pgfe_encode_t secret[], size_t secret_length, uint8_t digit_c,
    pgfe_totp_interval_t interval, pgfe_time_t initial_time, pgfe_totp_delta_t *delta_out
);

// Common TOTP using HMAC-SHA1 algorithm
pgfe_otp_t pgfe_totp(
    const pgfe_encode_t secret[], size_t secret_length, uint8_t digit_c, pgfe_totp_interval_t interval,
    pgfe_totp_delta_t *delta_out
);

pgfe_otp_t pgfe_totp_4digits(
    const pgfe_encode_t secret[], size_t secret_length, pgfe_totp_interval_t interval, pgfe_totp_delta_t *delta_out
);

pgfe_otp_t pgfe_totp_6digits(
    const pgfe_encode_t secret[], size_t secret_length, pgfe_totp_interval_t interval, pgfe_totp_delta_t *delta_out
);

pgfe_otp_t pgfe_totp_8digits(
    const pgfe_encode_t secret[], size_t secret_length, pgfe_totp_interval_t interval, pgfe_totp_delta_t *delta_out
);

#ifdef __cplusplus
}
#endif

#endif