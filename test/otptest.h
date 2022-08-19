/*
  libpgfe
  otptest.h

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

#include "test.h"

#include "../hotp.h"
#include "../sha2.h"
#include "../utils.h"

void hotp_hex(ARGS) {
    pgfe_encode_t key[100];
    pgfe_hex_string_to_hash(argv[2], key);
    pgfe_otp_t o = pgfe_hotp_8digits(key, 20, 1);
    printf("%d\n", o);
}

void hotp_hex_sha256(ARGS) {
    pgfe_encode_t key[100];
    pgfe_hex_string_to_hash(argv[2], key);
    pgfe_otp_t o = pgfe_hotp_generic(PGFE_ENCODER_SIG_SHA256, key, 32, 0x23523ED, 8);
    printf("%d\n", o);
}

void hotp_hex_sha512(ARGS) {
    pgfe_encode_t key[100];
    pgfe_hex_string_to_hash(argv[2], key);
    pgfe_otp_t o = pgfe_hotp_generic(PGFE_ENCODER_SIG_SHA512, key, 64, 0x23523EC, 8);
    printf("%d\n", o);
}