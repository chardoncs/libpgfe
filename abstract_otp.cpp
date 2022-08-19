#include "abstract_otp.hpp"

#include <cstring>

using namespace chardon55::PGFE;

inline void AbstractOTP::set_secret(const char *cs) {
    set_secret((pgfe_encode_t *)cs, strlen(cs));
}

inline void AbstractOTP::set_secret(const std::string &cpp_s) {
    set_secret((pgfe_encode_t *)cpp_s.c_str(), cpp_s.length());
}

inline void AbstractOTP::set_secret(SequentialData &sd) {
    size_t sz;
    set_secret(sd.to_pgfe_seq(sz), sz);
}

std::string AbstractOTP::generate_str(uint8_t digit_count) {
    std::string str = std::to_string(generate(digit_count));
    while (str.length() < digit_count) {
        str.insert(0, "0");
    }

    return str;
}