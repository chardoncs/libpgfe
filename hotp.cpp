/*
  libpgfe
  hotp.cpp

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

#include "hotp.hpp"

#include <cstring>

#include "generic.hpp"
#include "hotp.h"

using namespace chardon55::PGFE;

void HOTP::destroy_secret() {
    if (!secret) return;

    delete secret;
    secret = nullptr;
    selen = 0;
}

void HOTP::init() {
    select_algorithm(SHA1);
}

HOTP::HOTP() {
    secret = nullptr;
    init();
}

HOTP::HOTP(const pgfe_encode_t *secret_seq, size_t length) : HOTP() {
    set_secret(secret_seq, length);
}

HOTP::HOTP(const char *secret_cs) : HOTP() {
    set_secret(secret_cs);
}

HOTP::HOTP(std::string &secret_cpp_s) : HOTP() {
    set_secret(secret_cpp_s);
}
HOTP::HOTP(SequentialData &sd) : HOTP() {
    set_secret(sd);
}

HOTP::~HOTP() {
    destroy_secret();
}

void HOTP::after_change_alg() {
    __PGFE_BATCH_CASES(MTFUNC_SET)
    __PGFE_BATCH_CASES(INIT_SIZE)
}

void HOTP::set_secret(const pgfe_encode_t *seq, size_t length) {
    destroy_secret();
    secret = new pgfe_encode_t[length + 1];
    memcpy(secret, seq, length);
    secret[length] = 0;
    selen = length;
}

void HOTP::set_secret(const char *cs) {
    this->AbstractOTP::set_secret(cs);
}

void HOTP::set_secret(std::string &cpp_s) {
    this->AbstractOTP::set_secret(cpp_s);
}

void HOTP::set_secret(SequentialData &sd) {
    this->AbstractOTP::set_secret(sd);
}

void HOTP::set_counter(pgfe_otp_counter_t c) {
    this->co = c;
}

pgfe_otp_t HOTP::generate(uint8_t digit_count) {
    if (!secret || !encode_func) {
        throw NotInitializedException();
    }

    return pgfe_hotp_generic(encode_func, blocksz, digsz, secret, selen, co, digit_count);
}

std::string HOTP::generate_str(uint8_t digit_count) {
    return this->AbstractOTP::generate_str(digit_count);
}

void HOTP::set_secret_from_base32(const char *cs) {
    auto sd = base32.decode(cs);
    set_secret(sd);
}

void HOTP::set_secret_from_base32(std::string &cpp_s) {
    auto sd = base32.decode(cpp_s);
    set_secret(sd);
}