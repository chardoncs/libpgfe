/*
  libpgfe
  otp-generic.c

  Copyright (c) 2022-2023 Charles Dong
*/

#include "./otp-generic.h"

#define ENS_BIT 8
#define SIZE 4

pgfe_otp_t dynamically_truncate(const pgfe_encode_t hash[], size_t length) {
    uint8_t offset = hash[length - 1] & 0xF;
    pgfe_otp_t code = 0;

    for (size_t i = 0; i < SIZE; i++) {
        code <<= ENS_BIT;
        code |= hash[offset + i];
    }

    return code << 1 >> 1;
}

inline time_t curtime() {
    return time(NULL);
}

void otp_to_string(pgfe_otp_t otp, char *cs_out, size_t digit_c) {
    char *sp;

    for (sp = cs_out + digit_c - 1; sp >= cs_out; sp--) {
        *sp = (char)(otp % 10 + '0');
        otp /= 10;
    }

    cs_out[digit_c] = 0;
}