/*
  libpgfe
  base16.cpp

  Copyright (c) 2022-2023 Charles Dong
*/

#include "libpgfe/base_encoding/base16.hpp"

#include "libpgfe/base_encoding/base16.h"

using namespace libpgfe;

void Base16::init_base_function(base_encode_func *&encode_f_ref, base_decode_func *&decode_f_ref) {
    encode_f_ref = pgfe_encode_base16;
    decode_f_ref = pgfe_decode_base16;
}

void Base16::init_size(
    base_short_size_t &unitsz, base_short_size_t &chunksz, base_short_size_t &bitsz, base_short_size_t &alphabetsz
) {
    unitsz = PGFE_BASE16_UNIT_SIZE;
    chunksz = PGFE_BASE16_CHUNK_COUNT;
    bitsz = PGFE_BASE16_BIT_SIZE;
    alphabetsz = PGFE_BASE16_ALPHABET_SIZE;
}

Base16::Base16() {
    init();
}