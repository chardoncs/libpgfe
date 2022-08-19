/*
  libpgfe
  hmac_encoder.hpp

  Copyright (C) 2022 Charles Dong

  libpgfe is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
*/

#ifndef LIBPGFE_HMAC_ENCODER_HPP
#define LIBPGFE_HMAC_ENCODER_HPP
#ifdef __cplusplus

#include "abstract_hash_encoder.hpp"
#include "generic.h"
#include "generic.hpp"

namespace chardon55 {
namespace PGFE {

class HMACEncoder : public AbstractHashEncoder
{
  private:
    pgfe_encode_multi_func *encode_func;

    pgfe_encode_t *key, *data, *output;
    size_t key_len, data_len, digsz, blocksz;

    void destroy_key();
    void destroy_data();

  protected:
    void after_change_alg();

  public:
    HMACEncoder();
    ~HMACEncoder();

    void set_key(const pgfe_encode_t sequence[], size_t length);
    void set_key(const char cs[]);
    void set_key(std::string &cpp_s);
    void set_key(SequentialData &sd);

    void update(const pgfe_encode_t sequence[], size_t length);
    void update(const char cs[]);
    void update(std::string &cpp_s);
    void update(SequentialData &sd);

    SequentialData get_digest();

    size_t block_size() {
        return blocksz;
    }

    size_t digest_size() {
        return digsz;
    }
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif