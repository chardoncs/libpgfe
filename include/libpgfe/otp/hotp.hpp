/*
  libpgfe
  hotp.hpp

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_HOTP_HPP
#define LIBPGFE_HOTP_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

#include <memory>

#include "libpgfe/abstract_otp.hpp"
#include "libpgfe/base32.hpp"

namespace libpgfe {

class HOTP : public AbstractOTP
{
private:
    std::unique_ptr<SequentialData> secret;
    size_t digsz, blocksz;

    pgfe_otp_counter_t co;

    Base32 base32;

protected:
    void after_change_alg() override;

public:
    HOTP(pgfe_algorithm_choice algorithm = SHA1);
    HOTP(const pgfe_encode_t *, size_t, pgfe_algorithm_choice = SHA1);
    HOTP(const char *, pgfe_algorithm_choice = SHA1);
    HOTP(std::string &, pgfe_algorithm_choice = SHA1);
    HOTP(SequentialData &, pgfe_algorithm_choice = SHA1);

    void set_secret(const pgfe_encode_t *, size_t) override;
    void set_secret(const char *cs, bool is_base32 = false);
    void set_secret(const std::string &, bool is_base32 = false);
    void set_secret(const SequentialData &) override;

    void set_secret_from_base32(const char *);
    void set_secret_from_base32(const std::string &);

    void set_counter(pgfe_otp_counter_t) override;

    pgfe_otp_t generate(uint8_t digit_count = 6) const override;
    std::string generate_str(uint8_t digit_count = 6) const override;
};

} // namespace libpgfe

#endif