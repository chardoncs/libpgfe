/*
  libpgfe
  hotp.hpp

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_HOTP_HPP
#define LIBPGFE_HOTP_HPP
#ifdef __cplusplus

#include "abstract_otp.hpp"
#include "base32.hpp"

namespace chardon55 {
namespace PGFE {

class HOTP : public AbstractOTP
{
  private:
    pgfe_encode_multi_func *encode_func = nullptr;

    pgfe_encode_t *secret;
    size_t selen, digsz, blocksz;

    pgfe_otp_counter_t co;

    Base32 base32;

    void destroy_secret();

  protected:
    void after_change_alg();

    void init();

  public:
    HOTP();
    HOTP(const pgfe_encode_t *, size_t);
    HOTP(const char *);
    HOTP(std::string &);
    HOTP(SequentialData &);
    ~HOTP();

    void set_secret(const pgfe_encode_t *, size_t);
    void set_secret(const char *cs);
    void set_secret(std::string &);
    void set_secret(SequentialData &);

    void set_secret_from_base32(const char *);
    void set_secret_from_base32(std::string &);

    void set_counter(pgfe_otp_counter_t);

    pgfe_otp_t generate(uint8_t digit_count = 6);
    std::string generate_str(uint8_t digit_count = 6);
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif