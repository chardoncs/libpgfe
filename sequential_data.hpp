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

#include <ostream>
#include <string>

#include "generic.h"
#include "utils.h"

namespace chardon55 {
namespace PGFE {

typedef pgfe_encode_t seqdata_t;

class SequentialData
{
  private:
    seqdata_t *seq = nullptr;
    size_t sz = 0, hex_sz = 0;

    char *hex_str = nullptr;

    bool _is_str = false;

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

    bool is_str();

    friend std::ostream &operator<<(std::ostream &os, const SequentialData &sd) {
        if (sd._is_str) {
            os << (char *)sd.seq;
        }
        else {
            if (!sd.hex_str) {
                size_t hex_size = sz * 2;
                char hex_s[] = new char[hex_size + 1];
                pgfe_hash_to_hex_string(sd.seq, sd.sz, hex_s);
                os << hex_s;
                delete hex_s;
            }
            else {
                os << sd.hex_str;
            }
        }
        return os;
    }
};

} // namespace PGFE
} // namespace chardon55

#endif
#endif