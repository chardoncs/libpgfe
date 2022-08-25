/*
  libpgfe
  utils.h

  Copyright (c) 2022 Charles Dong
*/

#ifndef LIBPGFE_UTILS_H
#define LIBPGFE_UTILS_H

#include "generic.h"
#include "otp-generic.h"

#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

// Convert SHA hash to a string represented by hexadecimal numbers
size_t pgfe_hash_to_hex_string(const pgfe_encode_t hash[], size_t hash_length, char out[]);

size_t pgfe_hex_string_to_hash(const char hash_s[], pgfe_encode_t hash_out[]);

// Print SHA hash
void pgfe_print_hash(const pgfe_encode_t hash[], size_t length);

// Clean non-hexadecimal characters and put it into `output'
size_t pgfe_hash_string_clean(const char hash_s[], char output[]);

// Clean non-hexadecimal characters and overwrite the string
size_t pgfe_hash_string_clean_(char hash_s[]);

// Calculate length of a hash represented by a string
size_t pgfe_hash_length(const char hash_s[]);

// Get current UNIX time
pgfe_time_t pgfe_curtime();

void pgfe_otp_to_string(pgfe_otp_t otp, char *cs_out, size_t digit_c);

#ifdef __cplusplus
}
#endif

#endif