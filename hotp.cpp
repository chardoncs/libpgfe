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

HOTP::HOTP() {}

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
    this->GenericOTP::set_secret(cs);
}

inline void HOTP::set_secret(const std::string &cpp_s) {
    this->GenericOTP::set_secret(cpp_s);
}

void HOTP::set_counter(pgfe_otp_counter_t c) {
    this->co = c;
}

inline pgfe_otp_t HOTP::generate(uint8_t digit_count) {
    return pgfe_hotp(secret, selen, co, digit_count);
}

inline std::string HOTP::generate_str(uint8_t digit_count = 6) {
    return this->GenericOTP::generate_str(digit_count);
}