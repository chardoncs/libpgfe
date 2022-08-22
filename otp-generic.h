/*
  libpgfe
  otp-generic.h

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

#ifndef LIBPGFE_OTP_GENERIC_H
#define LIBPGFE_OTP_GENERIC_H

#include <stdint.h>

#include "generic.h"
#include "hmac.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_OTP_MAX_LIMIT 2147483647L

#define PGFE_OTP_DIGIT_MAX_LIMIT 10

#define _PGFE_CT(counter) to_pf64(counter)

typedef uint32_t pgfe_otp_t;

typedef pf_uint64_t pgfe_otp_counter_t;

typedef pgfe_encode_t pgfe_otp_secret_t;

// Performing dynamic truncation
pgfe_otp_t pgfe_dynamically_truncate(const pgfe_encode_t hash[], size_t length);

#ifdef __cplusplus
}
#endif

#endif