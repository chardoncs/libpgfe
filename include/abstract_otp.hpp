/*
  libpgfe
  abstract_otp.hpp

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_GENERIC_OTP_HPP
#define LIBPGFE_GENERIC_OTP_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

#include <string>

#include "algorithm_selectable.hpp"
#include "generic.h"
#include "otp-generic.h"
#include "sequential_data.hpp"

namespace chardon55 {
namespace PGFE {

class AbstractOTP : public AlgorithmSelectable
{
public:
    virtual void set_secret(const pgfe_encode_t *, size_t) {}
    virtual void set_secret(const char *cs);
    virtual void set_secret(std::string &);
    virtual void set_secret(SequentialData &);

    virtual void set_counter(pgfe_otp_counter_t){};

    virtual pgfe_otp_t generate(uint8_t digit_count = 6) {
        return 0;
    }

    virtual std::string generate_str(uint8_t digit_count = 6);
};

} // namespace PGFE
} // namespace chardon55

#endif