#include "hotp.hpp"

#include "hotp.h"
#include <cstring>

using namespace chardon55::PGFE;

void HOTP::destroy_secret() {
    if (!secret) return;

    delete secret;
    secret = nullptr;
    selen = 0;
}

HOTP::HOTP() {
    secret = nullptr;
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

void HOTP::set_secret(pgfe_encode_t *seq, size_t length) {
    destroy_secret();
    secret = new pgfe_encode_t[length + 1];
    memcpy(secret, seq, length);
    secret[length] = 0;
    selen = length;
}

inline void HOTP::set_secret(const char *cs) {
    this->AbstractOTP::set_secret(cs);
}

inline void HOTP::set_secret(const std::string &cpp_s) {
    this->AbstractOTP::set_secret(cpp_s);
}

void HOTP::set_counter(pgfe_otp_counter_t c) {
    this->co = c;
}

inline pgfe_otp_t HOTP::generate(uint8_t digit_count) {
    return pgfe_hotp(secret, selen, co, digit_count);
}

inline std::string HOTP::generate_str(uint8_t digit_count) {
    return this->AbstractOTP::generate_str(digit_count);
}