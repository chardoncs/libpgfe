#include "generic_otp.hpp"

#include <cstring>

using namespace chardon55::PGFE;

inline void GenericOTP::set_secret(const char *cs) {
    this->set_secret((pgfe_encode_t *)cs, strlen(cs));
}

inline void GenericOTP::set_secret(const std::string &cpp_s) {
    this->set_secret((pgfe_encode_t *)cpp_s.c_str(), cpp_s.length());
}