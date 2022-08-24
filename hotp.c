/*
  libpgfe
  hotp.c

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

#include "hotp.h"

#include <string.h>

#include "generic-internal.h"
#include "sha1.h"

//                 10 ^          0   1    2     3      4       5        6         7          8           9
const pgfe_otp_t DIGITS_POW[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

inline pgfe_otp_t __pgfe_10pow(uint8_t p) {
    return DIGITS_POW[p];
}

pgfe_otp_t pgfe_hotp_generic(
    PGFE_ENCODER_DEF_SIG, const pgfe_encode_t secret[], size_t secret_length, pgfe_otp_counter_t counter,
    uint8_t digit_c
) {
    static const size_t enc_s = 1, counter_len = 8;
    pgfe_encode_t counter_h[counter_len], out_hash[digest_size];
    pgfe_otp_t result;

    memcpy(counter_h, &counter, counter_len);
    __pgfe_reverse_elements(counter_h, counter_h + counter_len - 1);

    pgfe_hmac_generic(PGFE_ENCODER_CALL_SIG, secret, secret_length, counter_h, counter_len, out_hash);
    result = pgfe_dynamically_truncate(out_hash, digest_size);

    if (digit_c < PGFE_OTP_DIGIT_MAX_LIMIT) {
        result %= __pgfe_10pow(digit_c);
    }

    return result;
}

inline pgfe_otp_t
pgfe_hotp(const pgfe_encode_t secret[], size_t secret_length, pgfe_otp_counter_t counter, uint8_t digit_c) {
    return pgfe_hotp_generic(PGFE_ENCODER_SIG_SHA1, secret, secret_length, counter, digit_c);
}

inline pgfe_otp_t pgfe_hotp_4digits(const pgfe_encode_t secret[], size_t secret_length, pgfe_otp_counter_t counter) {
    return pgfe_hotp(secret, secret_length, counter, 4);
}

inline pgfe_otp_t pgfe_hotp_6digits(const pgfe_encode_t secret[], size_t secret_length, pgfe_otp_counter_t counter) {
    return pgfe_hotp(secret, secret_length, counter, 6);
}

inline pgfe_otp_t pgfe_hotp_8digits(const pgfe_encode_t secret[], size_t secret_length, pgfe_otp_counter_t counter) {
    return pgfe_hotp(secret, secret_length, counter, 8);
}