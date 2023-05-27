/*
  libpgfe
  totp.c

  Copyright (c) 2022 Charles Dong
*/

#include "libpgfe/totp.h"

#include "../generic-internal.h"
#include "libpgfe/hotp.h"
#include "libpgfe/sha1.h"

pgfe_otp_counter_t __pgfe_calc_periodic_counter(
    time_t realtime, pgfe_totp_interval_t interval, time_t initial_time, pgfe_totp_delta_t *delta_out
) {
    time_t time_offset = realtime - initial_time;
    if (delta_out) {
        *delta_out = interval - time_offset % interval;
    }
    return time_offset / interval;
}

pgfe_otp_t pgfe_totp_generic(
    enum pgfe_algorithm_choice alg, const pgfe_encode_t secret[], size_t secret_length, uint8_t digit_c,
    pgfe_totp_interval_t interval, time_t initial_time, pgfe_totp_delta_t *delta_out
) {
    pgfe_otp_counter_t counter = __pgfe_calc_periodic_counter(pgfe_curtime(), interval, initial_time, delta_out);
    return pgfe_hotp_generic(alg, secret, secret_length, counter, digit_c);
}

inline pgfe_otp_t pgfe_totp(
    const pgfe_encode_t secret[], size_t secret_length, uint8_t digit_c, pgfe_totp_interval_t interval,
    pgfe_totp_delta_t *delta_out
) {
    return pgfe_totp_generic(SHA1, secret, secret_length, digit_c, interval, 0, delta_out);
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