/*
  libpgfe
  base64.cpp

  Copyright (c) 2022-2023 Charles Dong
*/

#include "libpgfe/base_encoding/base64.hpp"

#include "libpgfe/base_encoding/base64.h"

using namespace libpgfe;

void Base64::init_base_function(base_encode_func *&encode_f_ref, base_decode_func *&decode_f_ref) {
    if (_url_safe_mode) {
        encode_f_ref = pgfe_encode_base64_url;
    }
    else {
        encode_f_ref = pgfe_encode_base64;
    }
    decode_f_ref = pgfe_decode_base64;
}

void Base64::init_size(
    base_short_size_t &unitsz, base_short_size_t &chunksz, base_short_size_t &bitsz, base_short_size_t &alphabetsz
) {
    unitsz = PGFE_BASE64_UNIT_SIZE;
    chunksz = PGFE_BASE64_CHUNK_COUNT;
    bitsz = PGFE_BASE64_BIT_SIZE;
    alphabetsz = PGFE_BASE64_ALPHABET_SIZE;
}

Base64::Base64(bool url_safe_mode) {
    _url_safe_mode = url_safe_mode;
    init();
}