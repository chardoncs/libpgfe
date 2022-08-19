#ifndef LIBPGFE_HOTP_HPP
#define LIBPGFE_HOTP_HPP
#ifdef __cplusplus

#include "abstract_otp.hpp"

namespace chardon55 {
namespace PGFE {

class HOTP : public AbstractOTP
{
  private:
    pgfe_encode_t *secret;
    size_t selen;

    pgfe_otp_counter_t co;

    void destroy_secret();

  public:
    HOTP();
    HOTP(pgfe_encode_t *, size_t);
    HOTP(const char *);
    HOTP(const std::string &);
    ~HOTP();

    void set_secret(pgfe_encode_t *, size_t);
    void set_secret(const char *cs);
    void set_secret(const std::string &);

    void set_counter(pgfe_otp_counter_t);

    pgfe_otp_t generate(uint8_t digit_count = 6);
    std::string generate_str(uint8_t digit_count = 6);
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif