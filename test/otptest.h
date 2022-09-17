/*
  libpgfe
  otptest.h

  Copyright (c) 2022 Charles Dong
*/

#include "test.h"

#include "../include/hotp.h"
#include "../include/sha2.h"
#include "../include/utils.h"

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