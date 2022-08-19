/*
  libpgfe
  baseencodetest.h

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

#include "test.h"

#include <string.h>

#include "../base-encoding.h"

void base16_encode_test(ARGS) {
    char cs_out[700];

    pgfe_encode_base16((pgfe_encode_t *)argv[2], strlen(argv[2]), cs_out);
    puts(cs_out);
}

void base16_decode_test(ARGS) {
    pgfe_encode_t out[700];

    pgfe_decode_base16(argv[2], out);
    puts((char *)out);
}

void base32_encode_test(ARGS) {
    char cs_out[700];

    pgfe_encode_base32((pgfe_encode_t *)argv[2], strlen(argv[2]), cs_out);
    puts(cs_out);
}

void base32_decode_test(ARGS) {
    pgfe_encode_t out[700];

    pgfe_decode_base32(argv[2], out);
    puts((char *)out);
}

void base32hex_encode_test(ARGS) {
    char cs_out[700];

    pgfe_encode_base32hex((pgfe_encode_t *)argv[2], strlen(argv[2]), cs_out);
    puts(cs_out);
}

void base32hex_decode_test(ARGS) {
    pgfe_encode_t out[700];

    pgfe_decode_base32hex(argv[2], out);
    puts((char *)out);
}

void base64_encode_test(ARGS) {
    char cs_out[700];

    pgfe_encode_base64((pgfe_encode_t *)argv[2], strlen(argv[2]), cs_out);
    puts(cs_out);
}

void base64_decode_test(ARGS) {
    pgfe_encode_t out[700];

    pgfe_decode_base64(argv[2], out);
    puts((char *)out);
}

void base64url_encode_test(ARGS) {
    char cs_out[700];

    pgfe_encode_base64_url((pgfe_encode_t *)argv[2], strlen(argv[2]), cs_out);
    puts(cs_out);
}