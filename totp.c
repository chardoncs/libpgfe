/*
  libpgfe
  totp.c

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

#include "totp.h"

#include "generic-internal.h"
#include "hotp.h"
#include "sha1.h"
#include "utils.h"

pgfe_otp_counter_t __pgfe_calc_periodic_counter(
    pgfe_time_t realtime, pgfe_totp_interval_t interval, pgfe_time_t initial_time, pgfe_totp_delta_t *delta_out
) {
    pgfe_time_t time_offset = realtime - initial_time;
    if (delta_out) {
        *delta_out = interval - time_offset % interval;
    }
    return time_offset / interval;
}

// Generic HOTP function suitable for various hash algorithm
pgfe_otp_t pgfe_totp_generic(
    PGFE_ENCODER_DEF_SIG, const pgfe_encode_t secret[], size_t secret_length, uint8_t digit_c,
    pgfe_totp_interval_t interval, pgfe_time_t initial_time, pgfe_totp_delta_t *delta_out
) {
    pgfe_otp_counter_t counter = __pgfe_calc_periodic_counter(pgfe_curtime(), interval, initial_time, delta_out);
    return pgfe_hotp_generic(PGFE_ENCODER_CALL_SIG, secret, secret_length, counter, digit_c);
}

// Common HOTP using HMAC-SHA1 algorithm
inline pgfe_otp_t pgfe_totp(
    const pgfe_encode_t secret[], size_t secret_length, uint8_t digit_c, pgfe_totp_interval_t interval,
    pgfe_totp_delta_t *delta_out
) {
    return pgfe_totp_generic(PGFE_ENCODER_SIG_SHA1, secret, secret_length, digit_c, interval, 0, delta_out);
}

inline pgfe_otp_t pgfe_totp_4digits(
    const pgfe_encode_t secret[], size_t secret_length, pgfe_totp_interval_t interval, pgfe_totp_delta_t *delta_out
) {
    return pgfe_totp(secret, secret_length, 4, interval, delta_out);
}

inline pgfe_otp_t pgfe_totp_6digits(
    const pgfe_encode_t secret[], size_t secret_length, pgfe_totp_interval_t interval, pgfe_totp_delta_t *delta_out
) {
    return pgfe_totp(secret, secret_length, 6, interval, delta_out);
}

inline pgfe_otp_t pgfe_totp_8digits(
    const pgfe_encode_t secret[], size_t secret_length, pgfe_totp_interval_t interval, pgfe_totp_delta_t *delta_out
) {
    return pgfe_totp(secret, secret_length, 8, interval, delta_out);
}