/*
  libpgfe
  hash_encoder.hpp

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

#ifndef LIBPGFE_HASH_ENCODER_HPP
#define LIBPGFE_HASH_ENCODER_HPP
#ifdef __cplusplus

#include "abstract_hash_encoder.hpp"

#include "generic.hpp"

namespace chardon55 {
namespace PGFE {

// Libpgfe - Hash Encoder
class HashEncoder : public AbstractHashEncoder
{

  private:
    void *ctx = nullptr;

    size_t digsz, blocksz;
    pgfe_encode_t *seq = nullptr;

    void load_algorithm();

    void destroy_context();

    void init();

  protected:
    void before_change_alg();
    void after_change_alg();

  public:
    HashEncoder(pgfe_algorithm_choice choice = SHA1);
    HashEncoder(std::string &choice);
    ~HashEncoder();

    void reset();

    void update(const pgfe_encode_t sequence[], size_t length);
    void update(const char cs[]);
    void update(std::string &cpp_s);
    void update(SequentialData &sd);

    SequentialData get_digest();

    size_t digest_size() {
        return digsz;
    }

    size_t block_size() {
        return blocksz;
    }
};

} // namespace PGFE
} // namespace chardon55
#endif
#endif