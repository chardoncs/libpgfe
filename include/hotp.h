/*
  libpgfe
  hotp.h

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_HOTP_H
#define LIBPGFE_HOTP_H

#include "backend/generic-internal.h"
#include "backend/otp-generic.h"

#ifdef __cplusplus
extern "C" {
#endif

// Generic HOTP function suitable for various hash algorithm
pgfe_otp_t pgfe_hotp_generic(
    enum pgfe_algorithm_choice alg, const pgfe_encode_t secret[], size_t secret_length, pgfe_otp_counter_t counter,
    uint8_t digit_c
);

// Common HOTP using HMAC-SHA1 algorithm
pgfe_otp_t pgfe_hotp(const pgfe_encode_t secret[], size_t secret_length, pgfe_otp_counter_t counter, uint8_t digit_c);

pgfe_otp_t pgfe_hotp_4digits(const pgfe_encode_t secret[], size_t secret_length, pgfe_otp_counter_t counter);

pgfe_otp_t pgfe_hotp_6digits(const pgfe_encode_t secret[], size_t secret_length, pgfe_otp_counter_t counter);

pgfe_otp_t pgfe_hotp_8digits(const pgfe_encode_t secret[], size_t secret_length, pgfe_otp_counter_t counter);

pgfe_otp_t __pgfe_10pow(uint8_t p);

#ifdef __cplusplus
}
#endif

#endif