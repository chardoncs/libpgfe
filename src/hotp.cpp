/*
  libpgfe
  hotp.cpp

  Copyright (c) 2022 Charles Dong
*/

#include "hotp.hpp"

#include <cstring>

#include "generic.hpp"
#include "hotp.h"

using namespace chardon55::PGFE;

void HOTP::destroy_secret() {
    if (!secret) return;

    delete[] secret;
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
    __PGFE_BATCH_CASES(INIT_SIZE)
}

void HOTP::set_secret(const pgfe_encode_t *seq, size_t length) {
    destroy_secret();
    secret = new pgfe_encode_t[length + 1];
    memcpy(secret, seq, length);
    secret[length] = 0;
    selen = length;
}

void HOTP::set_secret(const char *cs, bool is_base32) {
    if (is_base32) {
        set_secret_from_base32(cs);
    }
    else {
        this->AbstractOTP::set_secret(cs);
    }
}

void HOTP::set_secret(std::string &cpp_s, bool is_base32) {
    if (is_base32) {
        set_secret_from_base32(cpp_s);
    }
    else {
        this->AbstractOTP::set_secret(cpp_s);
    }
}

void HOTP::set_secret(SequentialData &sd) {
    this->AbstractOTP::set_secret(sd);
}

void HOTP::set_counter(pgfe_otp_counter_t c) {
    this->co = c;
}

pgfe_otp_t HOTP::generate(uint8_t digit_count) {
    if (!secret) {
        throw NotInitializedException();
    }

    return pgfe_hotp_generic(cur, secret, selen, co, digit_count);
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