/*
  libpgfe
  utils.h

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