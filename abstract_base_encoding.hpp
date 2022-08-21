/*
  libpgfe
  abstract_base_encoding.hpp

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

#ifndef LIBPGFE_ABSTRACT_BASE_ENCODING
#define LIBPGFE_ABSTRACT_BASE_ENCODING
#ifdef __cplusplus

#include <mutex>
#include <string>

#include "generic.h"
#include "sequential_data.hpp"

namespace chardon55 {
namespace PGFE {

typedef size_t base_encode_func(const pgfe_encode_t *, size_t, char *);
typedef size_t base_decode_func(const char *, pgfe_encode_t *);

typedef unsigned short base_short_size_t;

class AbstractBaseEncoding
{
  private:
    pgfe_encode_t *de_cache = nullptr;
    char *en_cache = nullptr;
    size_t encsz = 0, decsz = 0;

    std::mutex enc_mutex, dec_mutex;

    base_short_size_t unitsz, chunksz, bitsz, alphabetsz;

    void destroy_encode_cache();
    void destroy_decode_cache();

  protected:
    base_encode_func *encode_f;
    base_decode_func *decode_f;

    virtual void init_base_function(base_encode_func *&encode_f_ref, base_decode_func *&decode_f_ref) {}

    virtual void init_size(
        base_short_size_t &unitsz, base_short_size_t &chunksz, base_short_size_t &bitsz, base_short_size_t &alphabetsz
    ) {}

    void init();

  public:
    // AbstractBaseEncoding();
    ~AbstractBaseEncoding();

    std::string encode(const pgfe_encode_t *, size_t);
    std::string encode(const char *);
    std::string encode(std::string &);
    std::string encode(SequentialData &);

    SequentialData decode(const char *);
    SequentialData decode(std::string &);

    base_short_size_t unit_size();
    base_short_size_t chunk_size();
    base_short_size_t bit_size();
    base_short_size_t alphabet_size();
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif