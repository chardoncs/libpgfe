/*
  libpgfe
  base_test.hpp

  Copyright (c) 2022-2023 Charles Dong
*/

#include "test.h"

#include "../include/libpgfe/base16.hpp"
#include "../include/libpgfe/hashes/base32.hpp"
#include "../include/libpgfe/base64.hpp"

using namespace std;
using namespace libpgfe;

void base16_encode_test(ARGS) {
    Base16 base16;
    auto str = base16.encode(argv[2]);
    cout << str << endl;
}

void base16_decode_test(ARGS) {
    Base16 base16;
    auto sd = base16.decode(argv[2]);
    cout << sd << endl;
}

void base32_encode_test(ARGS) {
    Base32 base32;
    auto str = base32.encode(argv[2]);
    cout << str << endl;
}

void base32_decode_test(ARGS) {
    Base32 base32;
    auto sd = base32.decode(argv[2]);
    cout << sd << endl;
}

void base32hex_encode_test(ARGS) {
    Base32 base32(true);
    auto str = base32.encode(argv[2]);
    cout << str << endl;
}

void base32hex_decode_test(ARGS) {
    Base32 base32(true);
    auto sd = base32.decode(argv[2]);
    cout << sd << endl;
}

void base64_encode_test(ARGS) {
    Base64 base64;
    auto str = base64.encode(argv[2]);
    cout << str << endl;
}

void base64_decode_test(ARGS) {
    Base64 base64;
    auto sd = base64.decode(argv[2]);
    cout << sd << endl;
}

void base64url_encode_test(ARGS) {
    Base64 base64(true);
    auto str = base64.encode(argv[2]);
    cout << str << endl;
}

void base64url_decode_test(ARGS) {
    Base64 base64(true);
    auto sd = base64.decode(argv[2]);
    cout << sd << endl;
}