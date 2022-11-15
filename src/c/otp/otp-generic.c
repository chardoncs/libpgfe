/*
  libpgfe
  otp-generic.c

  Copyright (c) 2022 Charles Dong
*/

#include "backend/otp-generic.h"

#define __ENS_BIT 8
#define __SIZE 4

pgfe_otp_t pgfe_dynamically_truncate(const pgfe_encode_t hash[], size_t length) {
    uint8_t offset = hash[length - 1] & 0xF;
    pgfe_otp_t code = 0;

    for (size_t i = 0; i < __SIZE; i++) {
        code <<= __ENS_BIT;
        code |= hash[offset + i];
    }

    return code << 1 >> 1;
}