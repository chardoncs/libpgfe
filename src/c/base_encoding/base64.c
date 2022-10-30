/*
  libpgfe
  base64.c

  Copyright (c) 2022 Charles Dong
*/

#include "base-encoding.h"

#include <string.h>

#include "backend/base-encoding-internal.h"

// Base 64 alphabet
//                              0123456789ABCDEF
const char BASE64_ALPHABET[] = "ABCDEFGHIJKLMNOP" // 0X
                               "QRSTUVWXYZabcdef" // 1X
                               "ghijklmnopqrstuv" // 2X
                               "wxyz0123456789+/" // 3X
                               "=";               // Padding

// Base 64 alphabet (URL and filename safe)
//                                 0123456789ABCDEF
const char BASE64_ALPHABET_FS[] = "ABCDEFGHIJKLMNOP" // 0X
                                  "QRSTUVWXYZabcdef" // 1X
                                  "ghijklmnopqrstuv" // 2X
                                  "wxyz0123456789-_" // 3X
                                  "=";               // Padding

inline pgfe_encode_t pgfe_decode_base64_char(char base64_c) {
    pgfe_encode_t o;

    if (base64_c >= 'a' && base64_c <= 'z') {
        o = base64_c - 'a' + 26;
    }
    else if (base64_c >= '0' && base64_c <= '9') {
        o = base64_c - '0' + 52;
    }
    else if (base64_c >= 'A' && base64_c <= 'Z') {
        o = base64_c - 'A';
    }
    else if (base64_c == '+' || base64_c == '-') {
        o = 62;
    }
    else if (base64_c == '/' || base64_c == '_') {
        o = 63;
    }
    else if (base64_c == '=') {
        o = PGFE_BASE_PADDING_CODE;
    }
    else {
        o = PGFE_BASE_UNKNOWN_CODE;
    }

    return o;
}

inline size_t pgfe_encode_base64(const pgfe_encode_t input[], size_t input_length, char cs_out[]) {
    return __pgfe_encode_generic(PGFE_BASE_PARAMS(BASE64), BASE64_ALPHABET, input, input_length, cs_out);
}

inline size_t pgfe_encode_base64_url(const pgfe_encode_t input[], size_t input_length, char cs_out[]) {
    return __pgfe_encode_generic(PGFE_BASE_PARAMS(BASE64), BASE64_ALPHABET_FS, input, input_length, cs_out);
}

inline size_t pgfe_decode_base64(const char base64_cs[], pgfe_encode_t output[]) {
    return __pgfe_decode_generic(PGFE_BASE_PARAMS(BASE64), pgfe_decode_base64_char, base64_cs, output);
}