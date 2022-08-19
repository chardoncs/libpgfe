#ifndef LIBPGFE_GENERIC_OTP_HPP
#define LIBPGFE_GENERIC_OTP_HPP
#ifdef __cplusplus

#include <string>

#include "generic.h"
#include "otp-generic.h"

namespace chardon55 {
namespace PGFE {

class AbstractOTP
{
  public:
    virtual void set_secret(pgfe_encode_t *, size_t) {}
    virtual void set_secret(const char *cs);
    virtual void set_secret(const std::string &);

    virtual void set_counter(pgfe_otp_counter_t){};

    virtual pgfe_otp_t generate(uint8_t digit_count = 6) {
        return 0;
    }

    virtual std::string generate_str(uint8_t digit_count = 6) {
        std::string str = std::to_string(generate(digit_count));
        while (str.length() < 6) {
            str.insert(0, "0");
        }

        return str;
    }
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif