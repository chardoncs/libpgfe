/*
  libpgfe
  base_test.hpp

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

#include "../base16.cpp"
#include "../base32.hpp"
#include "../base64.hpp"

using namespace chardon55::PGFE;

void base16_encode_test(ARGS) {
    Base16 base16;
    auto str = base16.encode(argv[2]);
    std::cout << str << std::endl;
}

void base16_decode_test(ARGS) {
    Base16 base16;
    auto sd = base16.decode(argv[2]);
    std::cout << sd << std::endl;
}

void base32_encode_test(ARGS) {
    Base32 base32;
    auto str = base32.encode(argv[2]);
    std::cout << str << std::endl;
}

void base32_decode_test(ARGS) {
    Base32 base32;
    auto sd = base32.decode(argv[2]);
    std::cout << sd << std::endl;
}

void base32hex_encode_test(ARGS) {
    Base32 base32(true);
    auto str = base32.encode(argv[2]);
    std::cout << str << std::endl;
}

void base32hex_decode_test(ARGS) {
    Base32 base32(true);
    auto sd = base32.decode(argv[2]);
    std::cout << sd << std::endl;
}

void base64_encode_test(ARGS) {
    Base64 base64;
    auto str = base64.encode(argv[2]);
    std::cout << str << std::endl;
}

void base64_decode_test(ARGS) {
    Base64 base64;
    auto sd = base64.decode(argv[2]);
    std::cout << sd << std::endl;
}

void base64url_encode_test(ARGS) {
    Base64 base64(true);
    auto str = base64.encode(argv[2]);
    std::cout << str << std::endl;
}

void base64url_decode_test(ARGS) {
    Base64 base64(true);
    auto sd = base64.decode(argv[2]);
    std::cout << sd << std::endl;
}