/*
  libpgfe
  otp-generic.h

  Generic implementation of HOTP/TOTP

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_OTP_GENERIC_H
#define LIBPGFE_OTP_GENERIC_H

#include <stdint.h>
#include <time.h>

#include "libpgfe/generic.h"
#include "libpgfe/hmac.h"
#include "libpgfe/otp_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_OTP_MAX_LIMIT 2147483647L

#define PGFE_OTP_DIGIT_MAX_LIMIT 10

// Performing dynamic truncation
pgfe_otp_t pgfe_dynamically_truncate(const pgfe_encode_t hash[], size_t length);

// Get current UNIX time
time_t pgfe_curtime();

void pgfe_otp_to_string(pgfe_otp_t otp, char *cs_out, size_t digit_c);

#ifdef __cplusplus
}
#endif

#endif