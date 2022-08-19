/*
  libpgfe
  sequential_data.hpp

  Header of Sequential Data class

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

#ifndef LIBPGFE_SEQUENTIAL_DATA_HPP
#define LIBPGFE_SEQUENTIAL_DATA_HPP
#ifdef __cplusplus

#include <string>

#include "generic.h"

namespace chardon55 {
namespace PGFE {

typedef pgfe_encode_t seqdata_t;

class SequentialData
{
  private:
    seqdata_t *seq = nullptr;
    size_t sz = 0, hex_sz = 0;

    char *hex_str = nullptr;

  public:
    SequentialData(const pgfe_encode_t *, size_t);
    SequentialData(const char *);
    SequentialData(std::string &);
    ~SequentialData();

    const char *to_cs();
    std::string to_str();

    const char *to_hex_cs();
    std::string to_hex_str();

    const pgfe_encode_t *to_pgfe_seq();
    const pgfe_encode_t *to_pgfe_seq(size_t &);

    size_t length();
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif