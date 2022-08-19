/*
  libpgfe
  base16.c

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

#include "base-encoding.h"

#include "base-encoding-internal.h"

// Base 16 alphabet
const char BASE16_ALPHABET[] = "0123456789ABCDEF"
                               "0"; // Compatibility addition

inline pgfe_encode_t pgfe_decode_base16_char(char base16_c) {
    pgfe_encode_t o;

    if (base16_c >= '0' && base16_c <= '9') {
        o = base16_c - '0';
    }
    else if (base16_c >= 'A' && base16_c <= 'F') {
        o = base16_c - 'A' + 10;
    }
    else if (base16_c >= 'a' && base16_c <= 'f') {
        o = base16_c - 'a' + 10;
    }
    else {
        o = PGFE_BASE_UNKNOWN_CODE;
    }

    return o;
}

inline size_t pgfe_encode_base16(const pgfe_encode_t input[], size_t input_length, char cs_out[]) {
    return __pgfe_encode_generic(PGFE_BASE_PARAMS(BASE16), BASE16_ALPHABET, input, input_length, cs_out);
}

size_t pgfe_decode_base16(const char base16_cs[], pgfe_encode_t output[]) {
    return __pgfe_decode_generic(PGFE_BASE_PARAMS(BASE16), pgfe_decode_base16_char, base16_cs, output);
}