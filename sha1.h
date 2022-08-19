/*
  libpgfe
  sha1.h

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

#ifndef LIBPGFE_SHA1_H
#define LIBPGFE_SHA1_H

#include <stdio.h>

#include <nettle/sha1.h>

#include "generic.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PGFE_SHA1_DIGEST_SIZE 20
#define PGFE_SHA1_BLOCK_SIZE 64

void pgfe_sha1_encode(const pgfe_encode_t data[], size_t length, pgfe_encode_t output[], size_t out_length);

void pgfe_sha1_encode_f(FILE *fp, pgfe_encode_t output[], size_t length);

void pgfe_sha1_encode_default(const pgfe_encode_t data_str[], pgfe_encode_t output[]);

void pgfe_sha1_encode_default_f(FILE *fp, pgfe_encode_t output[]);

void pgfe_sha1_encode_multiple(pgfe_encode_t output[], size_t out_length, size_t input_c, ...);

#ifdef __cplusplus
}
#endif

#endif