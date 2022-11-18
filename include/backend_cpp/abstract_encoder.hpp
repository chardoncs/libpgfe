/*
  libpgfe
  abstract_encoder.hpp

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_GENERIC_ENCODER_HPP
#define LIBPGFE_GENERIC_ENCODER_HPP
#ifndef __cplusplus
#error libpgfe error: C++ headers are not compatible with C source
#endif

#include <cstring>
#include <string>

#include "../generic.h"
#include "../sequential_data.hpp"
#include "../utils.hpp"

namespace libpgfe {

class AbstractEncoder
{
public:
    virtual void reset() {}

    virtual void update(const pgfe_encode_t sequence[], size_t length) {}

    virtual void update(const char cs[]) {
        return update((const pgfe_encode_t *)cs, strlen(cs));
    }
    virtual void update(std::string &cpp_s) {
        return update((const pgfe_encode_t *)cpp_s.c_str(), cpp_s.length());
    }
    virtual void update(SequentialData &sd) {
        size_t sz;
        update(sd.to_pgfe_seq(sz), sz);
    }

    virtual const SequentialData *get_digest() {
        return nullptr;
    }
}; // namespace AbstractEncoder

} // namespace libpgfe

#endif