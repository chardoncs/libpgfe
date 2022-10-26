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
    int counter;
    sscanf(argv[3], "%i", &counter);

    pgfe_hex_string_to_hash(argv[2], key);
    pgfe_otp_t o = pgfe_hotp_8digits(key, 20, (pgfe_otp_counter_t)counter);
    printf("%d\n", o);
}

void hotp_hex_sha256(ARGS) {
    pgfe_encode_t key[100];
    int counter;
    sscanf(argv[3], "%i", &counter);

    pgfe_hex_string_to_hash(argv[2], key);
    pgfe_otp_t o = pgfe_hotp_generic(SHA256, key, 32, (pgfe_otp_counter_t)counter, 8);
    printf("%d\n", o);
}

void hotp_hex_sha512(ARGS) {
    pgfe_encode_t key[100];
    int counter;
    sscanf(argv[3], "%i", &counter);

    pgfe_hex_string_to_hash(argv[2], key);
    pgfe_otp_t o = pgfe_hotp_generic(SHA512, key, 64, (pgfe_otp_counter_t)counter, 8);
    printf("%d\n", o);
}