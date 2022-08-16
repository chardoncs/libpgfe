#include "generic.h"

#include <stdio.h>

void pgfe_hash_to_hex_string(const pgfe_encode_t hash[], const size_t hash_length, char out[]) {
    char *op = out, dual_hex[3];

    for (size_t i = 0; i < hash_length; i++) {
        sprintf(dual_hex, "%02x", hash[i]);
        *(op++) = dual_hex[0];
        *(op++) = dual_hex[1];
    }

    *op = 0;
}

void pgfe_print_hash(const pgfe_encode_t hash[], const size_t length) {
    for (size_t i = 0; i < length; i++) {
        printf("%02x", hash[i]);
    }
}