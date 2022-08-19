/*
  libpgfe
  otp-generic.c

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

#include "otp-generic.h"

pgfe_otp_t pgfe_dynamically_truncate(const pgfe_encode_t hash[], size_t length) {
    uint8_t offset = hash[length - 1] & 0xF;
    pgfe_otp_t code = 0;

    size_t ens = sizeof(pgfe_encode_t), sz = sizeof(pgfe_otp_t) / ens;
    for (size_t i = 0; i < sz; i++) {
        code <<= ens * 8;
        code |= hash[offset + i];
    }

    return code << 1 >> 1;
}