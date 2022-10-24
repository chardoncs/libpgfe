/*
  libpgfe
  otp-generic.h

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_OTP_GENERIC_H
#define LIBPGFE_OTP_GENERIC_H

#include <stdint.h>

#include "generic.h"
#include "hmac.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_OTP_MAX_LIMIT 2147483647L

#define PGFE_OTP_DIGIT_MAX_LIMIT 10

typedef uint32_t pgfe_otp_t;

typedef uint64_t pgfe_otp_counter_t;

typedef pgfe_encode_t pgfe_otp_secret_t;

// Performing dynamic truncation
pgfe_otp_t pgfe_dynamically_truncate(const pgfe_encode_t hash[], size_t length);

#ifdef __cplusplus
}
#endif

#endif