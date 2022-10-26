/*
  libpgfe
  base32.c

  Copyright (c) 2022 Charles Dong
*/

#include "base-encoding.h"

#include <string.h>

#include "base-encoding-internal.h"
#include "generic-internal.h"

// Base 32 alphabet
//                              0123456789ABCDEF
const char BASE32_ALPHABET[] = "ABCDEFGHIJKLMNOP" // 0X
                               "QRSTUVWXYZ234567" // 1X
                               "=";               // Padding

// Base 32 alphabet (Extended Hex)
//                                     0123456789ABCDEF
const char BASE32_ALPHABET_EXTHEX[] = "0123456789ABCDEF" // 0X
                                      "GHIJKLMNOPQRSTUV" // 1X
                                      "=";               // Padding

inline pgfe_encode_t pgfe_decode_base32_char(char base32_c) {
    pgfe_encode_t o;

    if (base32_c >= '2' && base32_c <= '7') {
        o = base32_c - '2' + 26;
    }
    else if (base32_c >= 'A' && base32_c <= 'Z') {
        o = base32_c - 'A';
    }
    else if (base32_c >= 'a' && base32_c <= 'z') {
        o = base32_c - 'a';
    }
    else if (base32_c == '=') {
        o = PGFE_BASE_PADDING_CODE;
    }
    else {
        o = PGFE_BASE_UNKNOWN_CODE;
    }

    return o;
}

inline pgfe_encode_t pgfe_decode_base32hex_char(char base32_c) {
    pgfe_encode_t o;

    if (base32_c >= '0' && base32_c <= '9') {
        o = base32_c - '0';
    }
    else if (base32_c >= 'A' && base32_c <= 'V') {
        o = base32_c - 'A' + 10;
    }
    else if (base32_c >= 'a' && base32_c <= 'v') {
        o = base32_c - 'a' + 10;
    }
    else if (base32_c == '=') {
        o = PGFE_BASE_PADDING_CODE;
    }
    else {
        o = PGFE_BASE_UNKNOWN_CODE;
    }

    return o;
}

inline size_t pgfe_encode_base32(const pgfe_encode_t input[], size_t input_length, char cs_out[]) {
    return __pgfe_encode_generic(PGFE_BASE_PARAMS(BASE32), BASE32_ALPHABET, input, input_length, cs_out);
}

inline size_t pgfe_encode_base32hex(const pgfe_encode_t input[], size_t input_length, char cs_out[]) {
    return __pgfe_encode_generic(PGFE_BASE_PARAMS(BASE32), BASE32_ALPHABET_EXTHEX, input, input_length, cs_out);
}

inline size_t pgfe_decode_base32(const char base32_cs[], pgfe_encode_t output[]) {
    return __pgfe_decode_generic(PGFE_BASE_PARAMS(BASE32), pgfe_decode_base32_char, base32_cs, output);
}

inline size_t pgfe_decode_base32hex(const char base32_cs[], pgfe_encode_t output[]) {
    return __pgfe_decode_generic(PGFE_BASE_PARAMS(BASE32), pgfe_decode_base32hex_char, base32_cs, output);
}