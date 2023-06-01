/*
  libpgfe
  totp.c

  Copyright (c) 2022-2023 Charles Dong
*/

#include "libpgfe/otp/totp.h"

#include "../core/generic-internal.h"
#include "./otp-generic.h"
#include "./totp-internal.h"

#include "libpgfe/hashes/sha1.h"
#include "libpgfe/otp/hotp.h"

pgfe_otp_t pgfe_totp_generic(
    enum pgfe_algorithm_choice alg, const pgfe_encode_t secret[], size_t secret_length, uint8_t digit_c,
    pgfe_totp_interval_t interval, time_t initial_time, pgfe_totp_delta_t *delta_out
) {
    pgfe_otp_counter_t counter = calc_periodic_counter(curtime(), interval, initial_time, delta_out);
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