/*
  libpgfe
  base32.cpp

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

#include "base32.hpp"

#include "base-encoding.h"

using namespace chardon55::PGFE;

void Base32::init_base_function(base_encode_func *&encode_f_ref, base_decode_func *&decode_f_ref) {
    if (hexm) {
        encode_f_ref = pgfe_encode_base32hex;
        decode_f_ref = pgfe_decode_base32hex;
    }
    else {
        encode_f_ref = pgfe_encode_base32;
        decode_f_ref = pgfe_decode_base32;
    }
}

void Base32::init_size(
    base_short_size_t &unitsz, base_short_size_t &chunksz, base_short_size_t &bitsz, base_short_size_t &alphabetsz
) {
    unitsz = PGFE_BASE32_UNIT_SIZE;
    chunksz = PGFE_BASE32_CHUNK_COUNT;
    bitsz = PGFE_BASE32_BIT_SIZE;
    alphabetsz = PGFE_BASE32_ALPHABET_SIZE;
}

Base32::Base32(bool hex_mode) {
    hexm = hex_mode;
    init();
}