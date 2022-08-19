#include "abstract_otp.hpp"

#include <cstring>

using namespace chardon55::PGFE;

inline void AbstractOTP::set_secret(const char *cs) {
    this->set_secret((pgfe_encode_t *)cs, strlen(cs));
}

inline void AbstractOTP::set_secret(const std::string &cpp_s) {
    this->set_secret((pgfe_encode_t *)cpp_s.c_str(), cpp_s.length());
}

inline void AbstractOTP::set_secret(SequentialData &sd) {
    size_t sz;
    this->set_secret(sd.to_pgfe_seq(sz), sz);
}