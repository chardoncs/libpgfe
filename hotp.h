/*
  libpgfe
  hotp.h

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

#ifndef LIBPGFE_HOTP_H
#define LIBPGFE_HOTP_H

#include "generic-internal.h"
#include "otp-generic.h"

#ifdef __cplusplus
extern "C" {
#endif

// Generic HOTP function suitable for various hash algorithm
pgfe_otp_t pgfe_hotp_generic(
    PGFE_ENCODER_DEF_SIG, const pgfe_encode_t secret[], size_t secret_length, pgfe_otp_counter_t counter,
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