/*
  libpgfe
  otp-generic.c

  Copyright (c) 2022 Charles Dong
*/

#include "otp-generic.h"

pgfe_otp_t pgfe_dynamically_truncate(const pgfe_encode_t hash[], size_t length) {
    uint8_t offset = hash[length - 1] & 0xF;
    pgfe_otp_t code = 0;

    size_t ens = sizeof(pgfe_encode_t), sz = sizeof(pgfe_otp_t) / ens;
    for (size_t i = 0; i < sz; i++) {
        code <<= to_bit(ens);
        code |= hash[offset + i];
    }

    return code << 1 >> 1;
}