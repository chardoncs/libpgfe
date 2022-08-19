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

HOTP::HOTP(pgfe_encode_t *secret_seq, size_t length) : HOTP() {
    set_secret(secret_seq, length);
}

HOTP::HOTP(const char *secret_cs) : HOTP() {
    set_secret(secret_cs);
}

HOTP::HOTP(const std::string &secret_cpp_s) : HOTP() {
    set_secret(secret_cpp_s);
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

void HOTP::set_secret(const std::string &cpp_s) {
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