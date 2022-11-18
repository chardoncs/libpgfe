/*
  libpgfe
  hotp.cpp

  Copyright (c) 2022 Charles Dong
*/

#include "hotp.hpp"

#include <cstring>

#include "generic.hpp"
#include "hotp.h"

using namespace libpgfe;

HOTP::HOTP(pgfe_algorithm_choice algorithm) {
    select_algorithm(algorithm);
}

HOTP::HOTP(const pgfe_encode_t *secret, size_t length, pgfe_algorithm_choice algorithm) : HOTP(algorithm) {
    set_secret(secret, length);
}

HOTP::HOTP(const char *secret, pgfe_algorithm_choice algorithm) : HOTP(algorithm) {
    set_secret(secret);
}

HOTP::HOTP(std::string &secret, pgfe_algorithm_choice algorithm) : HOTP(algorithm) {
    set_secret(secret);
}

HOTP::HOTP(SequentialData &secret, pgfe_algorithm_choice algorithm) : HOTP(algorithm) {
    set_secret(secret);
}

void HOTP::after_change_alg() {
    __PGFE_BATCH_CASES(INIT_SIZE)
}

void HOTP::set_secret(const pgfe_encode_t *seq, size_t length) {
    secret = std::make_unique<SequentialData>(seq, length);
}

void HOTP::set_secret(const char *cs, bool is_base32) {
    if (is_base32) {
        set_secret_from_base32(cs);
    }
    else {
        this->AbstractOTP::set_secret(cs);
    }
}

void HOTP::set_secret(const std::string &cpp_s, bool is_base32) {
    if (is_base32) {
        set_secret_from_base32(cpp_s);
    }
    else {
        this->AbstractOTP::set_secret(cpp_s);
    }
}

void HOTP::set_secret(const SequentialData &sd) {
    this->AbstractOTP::set_secret(sd);
}

void HOTP::set_counter(pgfe_otp_counter_t c) {
    this->co = c;
}

pgfe_otp_t HOTP::generate(uint8_t digit_count) const {
    if (!secret.get()) {
        throw NotInitializedException();
    }

    return pgfe_hotp_generic(cur_alg, secret->to_pgfe_seq(), secret->length(), co, digit_count);
}

std::string HOTP::generate_str(uint8_t digit_count) const {
    return this->AbstractOTP::generate_str(digit_count);
}

void HOTP::set_secret_from_base32(const char *cs) {
    auto sd = base32.decode(cs);
    set_secret(sd);
}

void HOTP::set_secret_from_base32(const std::string &cpp_s) {
    auto sd = base32.decode(cpp_s);
    set_secret(sd);
}